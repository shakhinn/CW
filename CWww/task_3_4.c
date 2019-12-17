#include "task_3_4.h"

int countwords(Sentence* sent){
    int k = 0;
    wchar_t wstr[sent->lensent];
    wcscpy(wstr, sent->buf);
    wchar_t* tmp;
    wchar_t* pwc;
    pwc = wcstok (wstr,L" ", &tmp);
    while (pwc != NULL){
        if(!(wcslen(pwc)==1 && iswpunct(pwc[0]))) { //провека на одинокий знак препинания
            k += 1;
        }
        pwc = wcstok (NULL,L" ", &tmp);
    }
    sent->cntwords = k;
    return sent->cntwords;
}

int compar(const void* a, const void* b){
    Sentence* aa = *((Sentence**)a);
    Sentence* bb = *((Sentence**)b);
    return countwords(aa) - countwords(bb);
}

int task3(Text* text){
    qsort(text->sentences, text->sizetext, sizeof(Sentence*), compar);
    return 0;
}

void sentmove(Text* text, int index){
    for(int i = index; i < text->sizetext - 1; i++){
        text->sentences[i] = text->sentences[i+1];
    }
}

int task4(Text* text){
    for(int i = 0; i< text->sizetext; i++){
        if(countwords(text->sentences[i]) > 10){
            free(text->sentences[i]->buf);
            free(text->sentences[i]);
            sentmove(text, i);
            i--;
            text->sizetext--;
        }
    }
    text->sentences = (Sentence**)realloc(text->sentences, text->sizetext * sizeof(Sentence*));
    return 0;
}

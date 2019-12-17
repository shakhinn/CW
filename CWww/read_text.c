#include "read_text.h"

void makesent(Sentence* sent){
    sent->maxsizes = SENT_SIZE;
    sent->buf = (wchar_t*)malloc(sent->maxsizes * sizeof(wchar_t));
    sent->lensent = 0;
    sent->cntwords = 0;
}

void maketext(Text* text){
    text->maxsizet = TEXT_SIZE;
    text->sentences = (Sentence**)calloc(text->maxsizet, sizeof(Sentence*));
    text->sizetext = 0;
}

void readsent(Sentence* sent){
    wchar_t wc;
    int flag = 0;
    do {
        wc = getwchar();
        while (wcschr(L" \t", wc) && !flag) {
            wc = getwchar();
        }
        flag = 1;
        if (sent->lensent + 1 > sent->maxsizes) {
            sent->maxsizes *= 2;
            sent->buf = (wchar_t *)realloc(sent->buf, sent->maxsizes * sizeof(wchar_t));
        }
        sent->buf[sent->lensent++] = wc;
    }while (!wcschr(L".\n", wc));
    sent->buf[sent->lensent++] = L'\0';
}

int samecheck(Text* text, Sentence* sent){
    int res = 0;
    for(int i = 0; i < text->sizetext; i++){
        if(wcscasecmp(text->sentences[i]->buf, sent->buf) == 0)
            res = 1;
    }
    return res;
}

void readtext(Text* text){
    while(1){
        Sentence* sentence = (Sentence*)malloc(sizeof(Sentence));
        makesent(sentence);
        readsent(sentence);
        if(sentence->buf[0] == L'\n'){
            free(sentence->buf);
            free(sentence);
            break;
        }
        else{
            if(!samecheck(text, sentence)) {
                text->sentences[text->sizetext] = sentence;
                text->sizetext++;
                if (text->sizetext == text->maxsizet - 2) {
                    text->maxsizet *= 2;
                    text->sentences = (Sentence **) realloc(text->sentences, text->maxsizet * sizeof(Sentence *));
                }
            }
        }
    }
}

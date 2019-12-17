#include "task_1.h"

void change1(Sentence* sent, int i){
    wchar_t* letter = (wchar_t*)malloc((sent->lensent - i) * sizeof(wchar_t));
    wcscpy(letter, L"ь");
    wcscpy(letter + 1, sent->buf + i + 1);
    sent->lensent += 2;
    sent->buf = (wchar_t*)realloc(sent->buf, sent->lensent * sizeof(wchar_t));
    wcscpy(sent->buf + i + 1, letter);
    free(letter);
}

void change2(Sentence* sent, int i){
    for(int j = i + 1; j < sent->lensent; j++){
        sent->buf[j] = sent->buf[j+1];
    }
    sent->lensent -= 1;
}

void findtsja(Sentence* sent){
    for (int i = 1; i < sent->lensent - 3; i++){
        if(iswalnum(sent->buf[i - 1]) && sent->buf[i] == L'т' && sent->buf[i+1] == L'с' && sent->buf[i+2] == L'я' && (sent->buf[i+3] == L'.' || sent->buf[i+3] == L' ' || sent->buf[i+3] == ',')){
            change1(sent, i);
        }else if (iswalnum(sent->buf[i - 1]) && sent->buf[i] == L'т' && sent->buf[i+1] == L'ь' && sent->buf[i+2] == L'с' && sent->buf[i+3] == L'я' && (sent->buf[i+4] == L'.' || sent->buf[i+4] == L' ' || sent->buf[i+4] == ',')) {
            change2(sent, i);
        }
    }
}

int task1(Text* text){
    for(int i = 0; i < text->sizetext; i++){
        findtsja(text->sentences[i]);
    }
    return 0;
}

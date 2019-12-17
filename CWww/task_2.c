#include "task_2.h"

wchar_t* FindSecondWord(Sentence *sent){
    int i = 0;
    while (sent->buf[i] != L' ' && sent->buf[i] != L',' && sent->buf[i] != L'.' && i < sent->lensent) {
        i++;
    }
    if (sent->buf[i] == L'.')
        return NULL;
    int j = i+1;
    int n = 0;

    while (sent->buf[j] != L' ' && sent->buf[j] != L',' && sent->buf[j] != L'.' && j < sent->lensent) {
        n++;
        j++;
    }
    wchar_t *pwc = malloc((n+2)* sizeof(wchar_t));
    int a = 0;
    for (int k = i+1; k < n+i+1; k++){
        pwc[a] = sent->buf[k];
        a++;
    }

    pwc[n] = L'\0';
    return pwc;

}

int PrintWithSecondWord(Sentence* sent, wchar_t* word){
    size_t len = wcslen(sent->buf);
    size_t n = wcslen(word);
    wchar_t *pwc;
    size_t end = 0;
    pwc = wcsstr(sent->buf, word); // поиск первого вхождения слова
    if(pwc == NULL)
        return 0;
    while (pwc != NULL) { // пока есть слово выводим
        size_t dist = pwc - sent->buf;
        if ((sent->buf[dist + n] == L' ' || sent->buf[dist + n] == L',' || sent->buf[dist + n] == L'.') &&
            (sent->buf[dist - 1] == L' ' || dist == 0)) { // проверка что это слово а не просто вхлждение
            for (int i = end; i < dist; i++) {  // выводим символы до слова
                wprintf(L"%lc", sent->buf[i]);
            }
            for (int j = dist; j < dist + n; j++) { // выводим слово
                wprintf(L"\033[0;32m" L"%lc" "\033[0m", sent->buf[j]);
            }
            end = dist + n;
            pwc = wcsstr(pwc + 1, word); // проверяем есть ли ещё
        } else
            pwc = wcsstr(pwc + 1, word);
    }
    if((end < len) && (end != 0)){ // выводим то что после слова если оно не стоит в конце предложения
        for(int k = end; k < len; k++) {
            wprintf(L"%lc", sent->buf[k]);
        }
	wprintf(L"\n");
    }
    return 0;
}

int task2(Text* text){
    wchar_t * word;
    word = FindSecondWord(text->sentences[0]);
    if(word == NULL){
        return 1;
    }
    for(int i = 0; i<text->sizetext; i++) {
        PrintWithSecondWord(text->sentences[i], word);
    }
    free(word);
    return 0;
}


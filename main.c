#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include <stdio.h>

#define SENT_SIZE 10
#define TEXT_SIZE 10

typedef struct Sentence{
    wchar_t * buf;
    int maxsizes;
    int lensent;
    int cntwords;
}Sentence;

typedef struct Text{
    Sentence** sentences;
    int sizetext;
    int maxsizet;
}Text;

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

void printmenu(){
    wprintf(L"/==========================================================================================================================/\n/"
            "                                                         М Е Н Ю                                                          /\n/"
            "    1. Изменить все слова в тексте заканчивающиеся на “ться” так чтобы они заканчивались на “тся” и наоборот.             /\n/"
            "    2. Вывести все предложения в которых встречается второе слово первого предложения. (слово будет выделенно зелёным)    /\n/"
            "    3. Отсортировать предложения по возрастанию количества слов в предложении.                                            /\n/"
            "    4. Удалить все предложения в которых больше 10 слов.                                                                  /\n/"
            "    5. Вывести текст.                                                                                                     /\n/"
            "    6. Выход из программы.                                                                                                /\n/"
            "                                              Для выбора введите номер пункта                                             /\n/"
            "==========================================================================================================================/\n");
    fflush(stdin);
}



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

/////////////////////////////////////////////////////////////////////

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
    //sent->buf = (wchar_t*)realloc(sent->buf, sent->lensent * sizeof(wchar_t));
}

void findtsja(Sentence* sent){
    for (int i = 1; i < sent->lensent - 3; i++){
        if(iswalnum(sent->buf[i - 1]) && sent->buf[i] == L'т' && sent->buf[i+1] == L'с' && sent->buf[i+2] == L'я' && (sent->buf[i+3] == L'.' || sent->buf[i+3] == L' ' || sent->buf[i+3] == ',')){
            change1(sent, i);
        }else if (iswalnum(sent->buf[i - 1]) && sent->buf[i] == L'т' && sent->buf[i+1] == L'ь' && sent->buf[i+2] == L'с' && sent->buf[i+3] == L'я' && (sent->buf[i+4] == L'.' || sent->buf[i+4] == L' ' || sent->buf[i+4] == ',')) {
            change2(sent, i);
            /*if (iswalnum(sent->buf[i - 1]) && sent->buf[i] == L'т' && sent->buf[i+1] == L'ь' && sent->buf[i+2] == L'с' && sent->buf[i+3] == L'я' && (sent->buf[i+4] == L'.' || sent->buf[i+4] == L' ' || sent->buf[i+4] == ',')) {
                change2(sent, i);*/
        }
    }
}

int task1(Text* text){
    for(int i = 0; i < text->sizetext; i++){
        findtsja(text->sentences[i]);
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    setlocale( LC_ALL, "ru_RU.UTF-8");
    wprintf(L"Введите текст. Текст должен заканчитаться символом переноса строки\n");
    Text* text = (Text*)malloc(sizeof(Text));
    maketext(text);
    readtext(text);
    printmenu();
    //wprintf(L"Введите число: ");
    //task4(text);
    //task3(text); //работает
    task1(text);
    //task3(text);
    for(int i = 0; i < text->sizetext; i++) {
        wprintf(L"%ls\n", text->sentences[i]->buf);

    }



    return 0;
}

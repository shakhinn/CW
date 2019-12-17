#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>


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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

wchar_t* FindSecondWord(Sentence *sent) {
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

int PrintWithSecondWord(Sentence* sent, wchar_t* word) {
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
                wprintf(L"\033[0;30m" L"%lc", sent->buf[i]);
            }
            for (int j = dist; j < dist + n; j++) { // выводим слово
                wprintf(L"\033[0;32m" L"%lc", sent->buf[j]);
            }
            end = dist + n;
            pwc = wcsstr(pwc + 1, word); // проверяем есть ли ещё
        } else
            pwc = wcsstr(pwc + 1, word);
    }
    if((end < len) && (end != 0)){ // выводим то что после слова если оно не стоит в конце предложения
        for(int k = end; k < len; k++) {
            wprintf(L"\033[0;30m" L"%lc", sent->buf[k]);
        }
    }
    wprintf(L"\033[0;30m" L"\n");
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

void Free(Text* text){
    for(int i = 0; i < text->sizetext; i++){
        free(text->sentences[i]->buf);
        free(text->sentences[i]);
    }
    free(text->sentences);
}

///////////////////////////////////////    wprintf(L"test1");/////////////////////////////////////////
int main(){
    setlocale( LC_ALL, "ru_RU.UTF-8");
    int choice = 0;
    wprintf(L"Введите текст. Текст должен заканчиваться символом переноса строки\n");
    Text* text = (Text*)malloc(sizeof(Text));
    maketext(text);
    readtext(text);
    while(choice != 6){
        printmenu();
        wprintf(L"Номер: ");
        wscanf(L"%d", &choice);
        switch (choice){
            case 1:
                if(task1(text) == 0){
                    wprintf(L"\nЗаменено\n");
                } else
                    wprintf(L"\nError");
                break;
            case 2:
                if(task2(text) == 1){
                    wprintf(L"Второе слово не найденно, функция не может быть выполнена!\n");
                }
                break;

            case 3:
                if(task3(text) == 0){
                    wprintf(L"\nОтсортировано\n");
                } else
                    wprintf(L"\nError");
                break;
            case 4:
                if(task4(text) == 0){
                    wprintf(L"\nУдалено\n");
                } else
                    wprintf(L"\nError");
                break;
            case 5:
                for(int i = 0; i < text->sizetext; i++) {
                    wprintf(L"%ls\n", text->sentences[i]->buf);
                }
                break;
            case 6:
                Free(text);
                free(text);
                wprintf(L"Программа завершена\nДо свидания!");
                return 0;
            default:
                wprintf(L"\nError");
                return 0;
        }
    }
    return 0;
}
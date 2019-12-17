#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include "struct.h"
#include"read_text.h"
#include"task_3_4.h"
#include"task_1.h"
#include"task_2.h"
#include"free.h"

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
		Free(text);
                free(text);
                wprintf(L"\nError");
                return 0;
        }
    }
    return 0;
}

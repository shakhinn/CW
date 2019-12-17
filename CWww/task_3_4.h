#ifndef TASK_3_4_H
#define TASK_3_4_H
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include "struct.h"

int countwords(Sentence* sent);

int compar(const void* a, const void* b);

int task3(Text* text);

void sentmove(Text* text, int index);

int task4(Text* text);

#endif

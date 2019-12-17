#ifndef TASK_2_H
#define TASK_2_h
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include "struct.h"

wchar_t* FindSecondWord(Sentence *sent);

int PrintWithSecondWord(Sentence* sent, wchar_t* word);

int task2(Text* text);

#endif

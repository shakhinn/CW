#ifndef READ_TEXT_H
#define READ_TEXT_H

#define SENT_SIZE 10
#define TEXT_SIZE 10

#include <stdlib.h>
#include <wchar.h>
#include "struct.h"

void makesent(Sentence* sent);

void maketext(Text* text);

void readsent(Sentence* sent);

int samecheck(Text* text, Sentence* sent);

void readtext(Text* text);

#endif

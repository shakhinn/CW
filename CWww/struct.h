#ifndef STRUCT_H
#define STRUCT_H

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

#endif

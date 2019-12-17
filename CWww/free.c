#include "free.h"


void Free(Text* text){
    for(int i = 0; i < text->sizetext; i++){
        free(text->sentences[i]->buf);
        free(text->sentences[i]);
    }
    free(text->sentences);
}

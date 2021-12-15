#include "StringController.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>


int main (){
    char *word;
    char *txt;
    word= detectWord();
    txt =detectText();
    printf("%s \n",word);
    printf("%s \n",txt);
    gematriaFunc(txt,word);
    free(word);
    free(txt);
    word= NULL;
    txt= NULL;
    return 0 ;
}


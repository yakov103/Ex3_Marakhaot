
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#define TXT 1024
#define WORD 30
#define ASCII_MAX 256

#ifndef EX3_STRINGCONTROLLER_H
#define EX3_STRINGCONTROLLER_H

char * detectWord ();//done
char * detectText ();//done

int gematriaCalc (char *word);//done
void gematriaFunc (char *text, char *word);//done


char * atbashCalc (char *word);//done
char * wordReverse (char *word);//done
void adbashFunc (char *txt, char *word);

void anagram (char *txt ,char *word);





#endif //EX3_STRINGCONTROLLER_H

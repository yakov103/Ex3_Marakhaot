
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#define TXT 1024
#define WORD 30

#ifndef EX3_STRINGCONTROLLER_H
#define EX3_STRINGCONTROLLER_H

char * detectWord ();//done
char * detectText ();//done

int gematriaCalc (char *word);//done
void gematriaFunc (char *text, char *word);
void gematriaPrint (char *word , int start, int end);

char * atbashCalc (char *word);
char * wordReverse (char *word);
int adbashFunc (char *text);





#endif //EX3_STRINGCONTROLLER_H

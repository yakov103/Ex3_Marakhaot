#include "StringController.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

char *detectWord() {
    char *word = (char *) calloc(WORD, sizeof(char));
    if (word == NULL) {
        printf("failed to allocate a memory ");
    }
    scanf("%c", word);
    int i;
    for (i = 1; i < WORD; i++) {

        scanf("%c", &word[i]);
        if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n') {
            break;

        }

    }
    word[i] = '\0';

    return word;
}

char *detectText() {
    char *txt = (char *) calloc(TXT, sizeof(char));
    if (txt == NULL) {
        printf("failed to allocate a memory ");
    }
    scanf("%c", txt);
    int i;
    for (i = 1; i < TXT; i++) {

        scanf("%c", &txt[i]);
        if (txt[i] == '~') {
            break;

        }

    }
    txt[i] = '\0';

    return txt;
}

int gematriaCalc(char *word) {
    int ans = 0, i;
    int wordlen = strlen(word);
    for (i = 0; i < wordlen; i++) {
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            char c = toupper(word[i]);
            ans += c - 'A' + 1;
        }
    }
    return ans;

}

// we get word and text
// check gematria for the word
// we will itirate on the text , when sum is more that word_gematria than check and cut .  ;

// Gematria Sequences: a-bc,d~dbca~dcba
void gematriaFunc(char *txt, char *word) {
    int word_gematria = gematriaCalc(word);
    printf("Gematria Sequences: ");
    int lenText = strlen(txt), i, j, sum, first_word = 0;
    char *word_to_check;
    for (i = 0; i < lenText; i++) {
        word_to_check = (char *) calloc(WORD, sizeof(char));
        if (word_to_check == NULL) {
            printf("failed to allocate a memory ");
            return;
        }
        j = i;
        sum = 0;
        while (txt[j] != '\0' && sum < word_gematria) {
            if ((txt[j] >= 'a' && txt[j] <= 'z') || (txt[j] >= 'A' && txt[j] <= 'Z')) {
                char c = toupper(txt[j]);
                sum += c - 'A' + 1;

            } else if (sum == 0) {
                break;
            }
            j++;
        }

        if (sum == word_gematria) {
            if (first_word) {
                printf("~");
            } else {
                first_word = 1;
            }
            memcpy(word_to_check, &txt[i], j - i);
            printf("%s", word_to_check);
        }


        free(word_to_check);
    }
    word_to_check = NULL;
}


char * atbashCalc (char *word){
    char *atbashResult ;
    atbashResult = (char*) calloc(WORD , sizeof (char));
    if (atbashResult == NULL) {
        printf("failed to allocate a memory ");
        return NULL;
    }
    int  wordLen = strlen(word), i;
    for ( int i = 0 ; i < wordLen ; i++){
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            if ( (word[i] >= 'a' && word[i] <= 'z') ){
             atbashResult[i]= 'z'-word[i]+'a';
            }
            else{
                atbashResult[i]= 'Z'-word[i]+'A';
            }
        }
    }


return atbashResult;

}

void adbashFunc (char *txt, char *word){
    char *word_to_check;
    char *atbash_word = atbashCalc(word);
    char *revesed_atbash = wordReverse(atbash_word);
    printf("Atbash Sequences: ");
    int lenText = strlen(txt),atbashLen = strlen(atbash_word),  i, j, sum, first_word = 0 , send_to_print = 0;
    for ( i = 0; i < lenText ; i++){

        if ( txt[i] == atbash_word[0] ||  txt[i] == revesed_atbash[0]){
            word_to_check = (char *) calloc(WORD, sizeof(char));
            j=0;
            if (txt[i] == atbash_word[0]) {
                while (  txt[i + j] != '\0' && atbash_word[j] != '\0'){
                    if (txt[i + j] == atbash_word[j]) {
                        j++;
                        if (j == atbashLen) {
                            send_to_print = 1;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
            else if (txt[i] == revesed_atbash[0] ) {
                while (txt[i + j] != '\0' && atbash_word[j] != '\0') {
                    if (txt[i + j] == revesed_atbash[j]) {
                        j++;
                        if (j == atbashLen) {
                            send_to_print = 1;

                        }
                    }
                    else {
                        break;
                    }
                }
            }
            if (send_to_print){
                if (first_word) {
                    printf("~");
                } else {
                    first_word = 1;
                }
                memcpy(word_to_check, &txt[i], j);
                printf("%s", word_to_check);
                send_to_print = 0;
            }
            free(word_to_check);
            word_to_check = NULL ;
        }


        else {
            continue;
        }

    }
}



char *wordReverse(char *word) {
    char *reversedWord;
    int lenWord = strlen(word);
    reversedWord = (char *) calloc(lenWord, sizeof(char));
    if (reversedWord == NULL) {
        printf("error allocating memory");
        return NULL;
    }

    for (int i = lenWord - 1; i >= 0; i--) {
        reversedWord[lenWord - i - 1] = word[i];
    }
//    reversedWord[lenWord - 1] = '\0';
return reversedWord;
}















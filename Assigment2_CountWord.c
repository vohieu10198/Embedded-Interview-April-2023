#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char your_sentence[] = "She sells seashells on the seashore. The shells she sells are seashells";

int string_length(char *str){
    int str_length = 0; 
    int i=0; // 
    while(str[i] != '\0'){ 
        ++str_length;
        ++i;
    }
    return str_length;
}

void lowcase(char *str){
     for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    printf("%s", str);
}

void plit_word(char *str){
    char splitStrings[1000][1000]; 
    int cnt = 0;
    int j =0;
    int len = string_length(str);
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            splitStrings[cnt][j] = '\0';
            cnt++; 
            j = 0; 
        }
        else {
            splitStrings[cnt][j] = str[i];
            j++;
        }
    }
    for (int i = 0; i < cnt; i++)
        printf("%s\n", splitStrings[i]);
}

void count_word(char *str)



int main(int argc, char const *argv[])
{
	string_length(your_sentence);
	printf("\n");
	lowcase(your_sentence);
	printf("\n");
	plit_word(your_sentence);
    return 0;
}

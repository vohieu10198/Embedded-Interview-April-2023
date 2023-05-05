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
     int str_length = string_length(str);
     char *sub_str = (char*)malloc((str_length+1) * sizeof(char)); 
    sub_str[str_length] = '\0'; 
    for(int i=0; i <= str_length; ++i){ 
        if(str[i] >= 'A' && str[i] <= 'Z'){ 
            sub_str[i] = (str[i] + 32); 
        }
        else sub_str[i] = str[i]; 
    }
    printf("%s",sub_str);
    free(sub_str);
}

int main(int argc, char const *argv[])
{
	  string_length(your_sentence);
    lowcase(your_sentence);
	
    return 0;
}

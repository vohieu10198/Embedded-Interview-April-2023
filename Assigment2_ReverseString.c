 /*
* File: reverseString.c
* Author: Vo Minh Hieu
* Date: 30/04/2023
* Description: This file is used for reversing words in a given string
*/
 
 #include <stdio.h>

 /*
* Function: reverse
* Description: This function is aim to reverse any sequence
* Input:
*   begin - a pointer
*   end - an pointer
*/

void reverse(char* pBegin, char* pEnd)
{
	char temp;
	while (pBegin < pEnd) {
		temp = *pBegin;
		*pBegin++ = *pEnd;    
		*pEnd-- = temp;
	}
}

/*
* Function: reverseWords
* Description: This function is aim to to reverse words
* Input:
*   s - a pointer
*/

void reverseWords(char* s)
{
	char* word_begin = s;

	char* temp = s; // Word boundary

    

	while (*temp) { 
		temp++;
		if (*temp == '\0') {
			reverse(word_begin, temp - 1);
		}
		else if (*temp == ' ') {
			reverse(word_begin, temp - 1);
			word_begin = temp + 1;
		}
	}
	reverse(s, temp - 1); // Reverse the entire string
}


int main()
{
	char yourSentence[] = "She sells seashells on the seashore. The shells she sells are seashells";
   	reverseWords(yourSentence);
   	printf("%s", yourSentence);
   	return 0;
}

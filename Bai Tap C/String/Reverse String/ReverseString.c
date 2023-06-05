/*
* File: ReverseString.c
* Author: VO MINH HIEU
* Date: 02/06/2023
* Description: This is file for array handling
*/

#include <stdio.h>

/*
* Function: reverse
* Input:
*   char: begin
*   char: end
* Output:
*   return: none
*/

void reverse(char* begin, char* end)
{
	char temp;
	while (begin < end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}



/*
* Function: reverseString
* Input:
*   string - input string
* Output:
*   return: none
*/

void reverseString(char* string)
{
	char* word_begin = NULL;

	// /* temp is for word boundary */
	char* temp = string;


	while (*temp) {

		/*This condition is to make sure that the
		string start with valid character (not
		space) only*/
		if ((word_begin == NULL) && (*temp != ' ')) {
			word_begin = temp;
		}
		if (word_begin && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0'))) {
			reverse(word_begin, temp);
			word_begin = NULL;
		}
		temp++;
	} 


	reverse(string, temp - 1);
}

// Driver Code
int main()
{
	char string[] = "She sells seashells on the seashore. The shells she sells are seashells";
	char* temp = string;

	reverseString(string);
	printf("%s", string);
	return 0;
}

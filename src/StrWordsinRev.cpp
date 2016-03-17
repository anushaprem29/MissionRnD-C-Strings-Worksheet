/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *input, int start, int end){
	int iter;
	char temp;
	for (iter = start; iter < (start + end) / 2; iter++){
		temp = input[iter];
		input[iter] = input[end - iter + start - 1];
		input[end - iter + start - 1] = temp;
	}
}
void str_words_in_rev(char *input, int len){
	int iter, start = 0;
	char ch;
	if (input == NULL || len < 0)	return;
	for (iter = 0; iter<len / 2; iter++){
		ch = input[iter];
		input[iter] = input[len - iter - 1];
		input[len - iter - 1] = ch;
	}
	for (iter = 0; iter <= len; iter++){
		if (input[iter] == ' ' || input[iter]=='\0'){
			reverse(input, start, iter);
			start = iter + 1;
		}
	}
	if (iter - start == len) reverse(input, 0, len);

}

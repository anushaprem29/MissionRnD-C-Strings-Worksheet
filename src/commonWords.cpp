/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/
#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define SIZE 31
int noOfWords = 0;
char **output;
int ifAvaiable(char *str1, char *str2){
	int iter, count = 0;
	for (iter = 0; str1[iter] != NULL; iter++){
		if (str1[iter] == str2[count])
			count++;
		else
			count = 0;
		if (count == strlen(str2))	return 1;
	}
	return 0;
}

void check(char *str1, char *str2, int start, int end){
	if (start == end){
		return;
	}
	char *str = (char *)malloc(sizeof(char) *(end - start + 1));
	int iter;
	for (iter = start; iter <end; iter++){
		str[iter - start] = str2[iter];
	}
	str[iter] = '\0';
	if (ifAvaiable(str1, str)){
		strcpy(output[noOfWords], str);
		noOfWords++;
	}

}
char ** commonWords(char *str1, char *str2) {
	int iter, start = 0;
	if (str1 == NULL || str2 == NULL)	return NULL;
	for (iter = 0;; iter++){
		if (str2[iter] == ' ' || str2[iter] == NULL){
			check(str1, str2, start, iter);
			start = iter + 1;
			if (str2[iter] == NULL)	break;
		}
	}
	if(noOfWords>0) return  (char**)output;
	return NULL;
}
/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	int len;
	if (str==nullptr|| K<0 )	return '\0';
	for (len = 0; str[len] != '\0'; len++);
	if (len - K - 1 < 0)	return '\0';
	return str[len - K - 1];
}
/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	int iter, spaces = 0;
	if(str==nullptr) return '\0';
	for (iter = 0; str[iter] != '\0'; iter++){
		str[iter - spaces] = str[iter];
		if (str[iter] == ' ')	spaces++;

	}
	str[iter - spaces] = '\0';
}
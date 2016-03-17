/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;
NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int integer = (int)number,iter=integer,len=0,start=0;
	if (number < 0){
		str[0] = '-';
		number *= -1;
		integer *= -1;
		iter *= -1;
		start = 1;
	}
	float temp = number - integer;

	while (iter > 0){
		iter /= 10;
		len++;
	}
	for (iter = len-1+start; iter >=start; iter--){
		str[iter] = (integer%10) + '0';
		integer /= 10;
	}
	if (temp){
		iter = 0;
		str[len+start] = '.';
		while ( iter < afterdecimal){
			temp *= 10;
			integer = (int)temp;
			integer %= 10;
			str[len + (++iter)+start] = integer + '0';
		}
	}
	str[len + iter +1+start] = '\0';
}

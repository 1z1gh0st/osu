/* CS261- Assignment 1A - Question 3
   Name: Philip Warton 
   Date: 06/26/2020
   Solution description:
*/

#include <stdio.h>
#include <stdlib.h>

char toUpperCase(char ch) {
	return ch - 32;
}

char toLowerCase(char ch) {
	return ch + 32;
}

int stringLength(char s[]) {
	int length = 0, i = 0;                // Init variables to store the length and for the index
	while (s[i] != '\0') {
		length++;
		i++;
	}
	return length;
}

int isUpper(char ch) {
	return (ch > 64 && ch < 91);
}

int isLower(char ch) {
	return (ch > 96 && ch < 123);
}

int isLetter(char ch) {
	return (isUpper(ch) || isLower(ch));
}

void removeSpecialChars(char* word) {
	char result[100];								// Character array to store the final result of the function 
	int n = stringLength(word), i = 0, j = 0; 
	for (i = 0; i < n; i++) {
		if (isUpper(word[i])) {
			result[j] = toLowerCase(word[i]);
			j++;
		} 
		else if (isLower(word[i])) {
			result[j] = word[i];
			j++;
		}
		else if ((word[i] == ' ' || word[i] == '_') && 
				j > 0 && 
				i + 1 < n && 
				isLetter(word[i + 1])) {
			result[j] = '_';
			j++;
		}
	}
	result[j] = '\0';								// Add end of string character
	n = stringLength(result);
	for (i = 0; i < n; i++)	{
		word[i] = result[i];
	}
	word[n] = '\0';
}

void camelCase(char* word ) {
	char result[100];
	int n = stringLength(word), i = 0, j = 0;
	for (i = 0; i < n; i++) {
		if (i > 0 && word[i - 1] == '_') {
			result[j] = toUpperCase(word[i]);
			j++;
		}
		else if (word[i] != '_') {
			result[j] = word[i];
			j++;
		}
	}
	result[j] = '\0';
	n = stringLength(result);
	for (i = 0; i < n; i++) {
		word[i] = result[i];
	}
	word[n] = '\0';
}

int isValid(char* word) {
	int n = stringLength(word);
	if (n == 0) { return 0; }
	int numWords = 1, i = 0;
	for (i; i < n; i++) {
		numWords += (word[i] == '_');
	}
	return (numWords > 1);
}

int main() {
	printf("Enter your text: ");
	char input[100];
	if (fgets(input, sizeof(input), stdin) != NULL) {
		removeSpecialChars(input);	
		if (isValid(input)) {
			camelCase(input);
			printf("%s\n", input);
		}
		else
			printf("Invalid input.\n");
	}
	return 0;
}


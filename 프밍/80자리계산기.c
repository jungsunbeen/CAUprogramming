#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char input1[81];
	char input2[81];
	char sumResult[100];
	char diffResult[100];
	int len1, len2;
	int carry = 0;
	int borrow = 0;
	int index = 99;
	int switchOrder = 0;

	while (1) {
		printf("Enter  first number: ");
		scanf("%s", input1);
		len1 = strlen(input1);

		printf("Enter second number: ");
		scanf("%s", input2);
		len2 = strlen(input2);

		index = 99;
		carry = 0;
		borrow = 0;
		if (len1 < len2 || (len1 == len2 && strcmp(input1, input2) < 0)) {
			char tempInput[81];
			strcpy(tempInput, input1);
			strcpy(input1, input2);
			strcpy(input2, tempInput);
			len1 = strlen(input1);
			len2 = strlen(input2);
			switchOrder = 1;
		}

		while (len1 > 0 || len2 > 0 || carry > 0) {
			int digit1 = (len1 > 0) ? input1[--len1] - '0' : 0;
			int digit2 = (len2 > 0) ? input2[--len2] - '0' : 0;

			int sum = digit1 + digit2 + carry;
			int difference = digit1 - digit2 - borrow;

			carry = sum / 10;

			if (difference < 0) {
				difference += 10;
				borrow = 1;
			}
			else
				borrow = 0;

			sumResult[index] = (sum % 10) + '0';
			diffResult[index] = difference + '0';
			index--;
		}

		printf("Sum: ");
		for (int i = index + 1; i <= 99; i++) {
			printf("%c", sumResult[i]);
		}
		printf("\n");
		printf("Difference: ");
		if (switchOrder == 1)
			printf("-");
		for (int i = index + 1; i <= 99; i++) {
			printf("%c", diffResult[i]);
		}
		printf("\n");
	}
	return 0;
}

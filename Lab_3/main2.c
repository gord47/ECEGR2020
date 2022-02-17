#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void dispMen(){
	printf("A)  Count the number of vowels in the string\n");
	printf("B)  Count the number of consonants in the string\n");
	printf("C)  Convert the string to uppercase\n");
	printf("D)  Convert the string to lowercase\n");
	printf("E)  Display the current string\n");
	printf("F)  Enter another string\n \n");
	printf("M)  Display this menu\n");
	printf("X)  Exit the program\n");
}
int vowelCount(char *strArr){
	int arrSize = strlen(strArr);
	int vowelNum = 0;
	for(int i = 0; i<arrSize;i++){
		if(strArr[i] == 'a' || strArr[i] == 'e' || strArr[i] == 'i' || strArr[i] == 'o' || strArr[i] == 'u'){
			vowelNum++;
		}
		else if(strArr[i] == 'A' || strArr[i] == 'E' || strArr[i] == 'I' || strArr[i] == 'O' || strArr[i] == 'U'){
			vowelNum++;
		}
	}
	return vowelNum;
}
int consCount(char *strArr){
	int arrSize = strlen(strArr);
	int conson = 0;
	for(int i = 0; i<arrSize;i++){
		if(strArr[i] != 'a' && strArr[i] != 'e' && strArr[i] != 'i' && strArr[i] != 'o' && strArr[i] != 'u'){
			conson++;
		}
		else if(strArr[i] != 'A' && strArr[i] != 'E' && strArr[i] != 'I' && strArr[i] != 'O' && strArr[i] != 'U'){
			conson++;
		}
	}
	return conson;
}
void allUpper(char *strArr){
	puts(strupr(strArr));
}
void allLower(char *strArr){
	puts(strlwr(strArr));
}
void printStr(char *strArr){
	printf("%s\n", strArr);
}
void enterStr(char *strArr){
	printf("Enter a string:\n");
	char *newStr[100];
	scanf("%s", &newStr);
	strcpy(strArr, newStr);
}
void reverseStr(char *strArr){
	int count  = 0;
	while(strArr[count] != '\0'){
		count++;
	}
	char reverse[100];
	int i = count;
	int j = 0;
	while(i != 0){
		reverse[j++] = strArr[--i];
	}
	reverse[j] = '\0';
	strcpy(strArr, reverse);
}
int main(int argc, char **argv)
{
	char strArr[100];
	printf("hello world\n");
	printf("Enter a string:\n");
	scanf("%s", &strArr);
	printf("A)  Count the number of vowels in the string\n");
	printf("B)  Count the number of consonants in the string\n");
	printf("C)  Convert the string to uppercase\n");
	printf("D)  Convert the string to lowercase\n");
	printf("E)  Display the current string\n");
	printf("F)  Enter another string\n \n");
	printf("M)  Display this menu\n");
	printf("R) reverse the string\n");
	printf("X)  Exit the program\n");
	char userIn;
	do{
		printf("What do you want to do?\n");
		scanf("%c", &userIn);
		switch(userIn){
			case 'A':
				printf("%d\n", vowelCount(strArr));
				break;
			case 'B':
				printf("%d\n", consCount(strArr));
				break;
			case 'C':
				allUpper(strArr);
				break;
			case 'D':
				allLower(strArr);
				break;
			case 'E':
				printStr(strArr);
				break;
			case 'F':
				enterStr(strArr);
				break;
			case 'M':
				printf("A)  Count the number of vowels in the string\n");
				printf("B)  Count the number of consonants in the string\n");
				printf("C)  Convert the string to uppercase\n");
				printf("D)  Convert the string to lowercase\n");
				printf("E)  Display the current string\n");
				printf("F)  Enter another string\n \n");
				printf("M)  Display this menu\n");
				printf("R) reverse the string\n");
				printf("X)  Exit the program\n");
				break;
			case 'R':
				reverseStr(strArr);
				break;
		}
	}
	while(userIn != 'X');
	
	return 0;
}
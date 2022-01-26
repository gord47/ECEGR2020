#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void SizeOfVariables(void){
	char c;
	short s;  
	int i;  
	unsigned int ui;  
	unsigned long int ul; 
	float f;
	double d;  
	long double ld;
	void *ptr;  
	printf("The size of char is %d \n", sizeof(c));
	printf("The size of short is %d \n", sizeof(s));
	printf("The size of int is %d \n", sizeof(i));
	printf("The size of unsigned int is %d \n", sizeof(ui));
	printf("The size of unsigned long is %d \n", sizeof(ul));
	printf("The size of float is %d \n", sizeof(f));
	printf("The size of double is %d \n", sizeof(d));
	printf("The size of long double is %d \n", sizeof(ld));
	printf("The size of void is %d \n", sizeof(ptr));
}
int IsLeapYear(int aYear){
	//must be greater than 1752
	if(aYear>=1752){
		//every 4 years
		if((aYear % 4)==0){
			//if year is also completely divisible by 100
			if((aYear%100)==0){
				//and is divisible by 400, it is a leap year
				if((aYear%400)==0){
					printf("%d is a leap year \n", aYear);
					return 1;
				}
				//if it's not, then it isn't a leap year
				else{
					printf("%d is not a leap year \n", aYear);
					return 0;
				}
			}
			//if not perfectly fivisible by 100, then its a leap year
			else{
				printf("%d is a leap year \n", aYear);
				return 1;
			}
			
		}
		//if none of those checks hold, it's not a leap year
		else{
			printf("%d is not a leap year \n", aYear);
			return 0;
		}
	}
	return 0;
}
int IsVowel(char aLetter){
	//checks if its an ASCII letter
	if(!isalpha(aLetter)){
		printf("Not an aphabetical character \n");
		return 0;
	}
	//lowercase vowel check
	else if(aLetter == 'a'||aLetter == 'e'||aLetter == 'i'||aLetter == 'o'||aLetter == 'u'){
		printf("lowercase vowel \n");
		return 1;
	}
	//uppercase vowel check
	else if(aLetter == 'A'||aLetter == 'E'||aLetter == 'I'||aLetter == 'O'||aLetter == 'U'){
		printf("uppercase vowel \n");
		return 1;
	}
	//all other options exhausted, must be consonant
	else{
		printf("consonant \n");
		return 0;
	}
}
void ReverseNumber(long aNumber){
	//variable that stores the reverse num
	long reverse = 0;
	//checker that see if the original number is negative
	int isNeg = 0;
	printf("The original number is %d \n", aNumber);
	if(aNumber<0){
		isNeg = 1;
		aNumber *=-1;
	}
	//runs this loop until all digits of the original number are in the reverse number
	while(aNumber != 0){
		reverse = reverse*10+aNumber%10;
		aNumber /= 10;
	}
	//applies negative to reverse if original is negative
	if(isNeg == 1){
		reverse *= -1;
	}
	printf("The reverse number is %d \n", reverse);
}

int main(int argc, char **argv)
{
	int num1, num2;  
    float fraction;     
    char character;
    char str[50];   // char array of size 50
    printf("Enter two numbers\n");
    
    // Taking integer as input from user
    scanf(" %d%i", &num1, &num2);
    printf("\n\nThe two numbers You have entered are %d and %i\n\n", num1, num2);
    // Taking float or fraction as input from the user
    printf("\n\nEnter a Decimal number\n");
    scanf(" %f", &fraction); 
    printf("\n\nThe float or fraction that you have entered is %f", fraction);
    // Taking Character as input from the user
    printf("\n\nEnter a Character\n");
    scanf(" %c",&character);
    printf("\n\nThe character that you have entered is %c and the ASCII number is %d", character, character);
    getchar();
    printf("\n\nEnter your complete name:\n\n\n");
    gets(str);
    printf("\n\nWelcome to ECEGR 2020  %s\n\n\n", str);
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
	SizeOfVariables();
	for(int i = 0; i < 10; i++){
		int yearNum; 
		yearNum = rand() % 310+1700;
		int isLeap = IsLeapYear(yearNum);
	}
	
	char aLetter;
	printf("Please enter a character: ");
	scanf("%c", &aLetter);
	IsVowel(aLetter);
	
	long aNumber;
	printf("please enter a number \n");
	scanf("%ld", &aNumber);
	ReverseNumber(aNumber);
    printf("Press Enter to quit");
    scanf("%c",&character);
    return 0;
}

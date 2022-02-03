#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
long Factorial(long num){
	long total = 1;
	for(int i = 1; i < num+1; i++){
		total *= i;
	}
	printf(" original: %ld \n", num);
	printf("factorial: %ld \n", total);
	return total;
}

int isPalindrome(long value){
	long orig = value;
	long reverse = 0;
	while(value != 0){
		reverse = reverse*10+value%10;
		value /= 10;
	}
	printf("%ld is the number given \n", orig);
	if(orig == reverse){
		printf("The number given is a palindrome\n");
		return 1;
	}
	else{
		printf("The number given is not a palindrome\n");
		return 0;
	}
}

int HighestBit(int value){
	int counter;
	printf("original value: %d\n", value);
	int a[10];
	for(counter = 0; value > 0; counter++){
		a[counter] = value%2;
		value/=2;
	}
	printf("The binary value is: ");
	for(counter = counter-1; counter >=0; counter--){
		printf("%d", a[counter]);
	}
	printf("\n");
	int arrSize = sizeof(a)/sizeof(a[0]);
	int highBit;
	for(int i = 0; i < arrSize; i++){
		if(a[i] == 1){
			highBit = i+1;
		}
	}
	printf("The highest bit index is: %d\n",highBit);
	return 0;
}

void ReverseIt(void){
	FILE *reversing;
	reversing = fopen("Lab_2/file2.txt","w+");
	float store[5];
	for(int i = 0; i < 5; i++){
		printf("Enter a float value: \n");
		float aVal;
		scanf("%f",&aVal);
		store[i] = aVal;
		fprintf(reversing, "%f\n",aVal);
	}
	for(int j = 5; j > 0; j--){
		printf("%f\n",store[j-1]);
		fprintf(reversing,"%f\n", store[j-1]);
	}
		
}

void ReverseItAgain(void){
	FILE *reverseAg = fopen("Lab_02/file2.txt", "r");
	char buff[255];
	fgets(buff, 255, reverseAg);
	printf("%s\n", buff);
	fgets(buff, 255, reverseAg);
	printf("%s\n", buff);
	/*char c;
	while((c=fgetc(reverseAg)) != EOF){
		printf("%c", c);
	}
	float num0, num1, num2, num3, num4, rev0, rev1, rev2, rev3, rev4;
	fscanf(reverseAg,"%f%f%f%f%f%f%f%f%f%f",&num0,&num1,&num2,&num3,&num4,&rev0,&rev1,&rev2,&rev3,&rev4);
	printf("%f%f%f%f%f%f%f%f%f%f\n", num0, num1, num2, num3, num4, rev0, rev1, rev2, rev3, rev4);*/
	fclose(reverseAg);
}

void Pyramid(int lines){
	FILE *pyra; 
	pyra = fopen("Lab_2/file1.txt", "w+");
	for(int i = 1; i < lines+1; i++){
		for(int j = 0; j < lines-i;j++){
			fprintf(pyra," ");
			printf(" ");
		}
		for(int k = 0; k < 2*i-1; k++){
			fprintf(pyra,"*");
			printf("*");
		}
		for(int j = 0; j < lines-i;j++){
			fprintf(pyra," ");
			printf(" ");
		}
		fprintf(pyra,"\n");
		printf("\n");
	}
	fclose(pyra);
}
int main(int argc, char **argv)
{
	printf("hello world\n");
	long aNumber;
	printf("enter in a number: \n");
	scanf("%ld", &aNumber);
	long thingy = Factorial(aNumber);
	long aPalin;
	printf("enter in a number: \n");
	scanf("%ld", &aPalin);
	isPalindrome(aPalin);
	HighestBit(17);
	ReverseIt();
	ReverseItAgain();
	Pyramid(11);
	return 0;
}
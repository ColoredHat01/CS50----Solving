#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkCardNum(int v[], int n) {
    int k1, k2, sum1=0,sum2=0;
    for(k1 =1 ;k1 < n; k1+=2) {
        v[k1] *= 2;
        if (v[k1] >= 10) v[k1] -= 9;
        sum1 += v[k1];                      //Deal with odd digit
    }
    for(k2 = 0;k2 < n; k2+=2) {
        sum2 += v[k2];                      //Deal with even digit
    }
    if ((sum1 + sum2) % 10 == 0)            //Check if sum div 10 == 0
        return 1;
    else return 0; //return to check
}

int* convert(char* c)                       //Convert string array to int array
{
	int len=strlen(c),i;
	int *a=(int*)malloc(len*sizeof(int));
	for(i=0;i<len;i++) {
		a[i]=c[i]-48;
	}
	return a;
}

int main(int argc, char const *argv[])
{
    printf("Input credit card number: ");
	char c[100];
	scanf("%s",c);
	int *a=convert(c), numb = strlen(c);
	int *b=convert(c);                      //array b is copy string of array a
    int check = checkCardNum(a,numb);
    if (check ==1 ) {                       //check credit card criteria
        if (numb == 15) {
            if (b[0] == 3 && (b[1] == 4 || b[1] == 7))
                printf("Amex");
        }
        if (numb == 16) {
            if (b[0] == 5 && (b[1]==1 || b[1]==2 || b[1]==3 || b[1]==4 || b[1] ==5))
                printf("Mastercard");
            else if (b[0] ==4) printf ("Visa");
        }
        if (numb == 13) {
            if (b[0] == 4) printf("Visa");
        }
    }
    else printf("INVALID");
	return 0;
}
// Code by Hung Le Ba

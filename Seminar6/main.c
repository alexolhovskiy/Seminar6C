#include <stdio.h>      
#include <stdlib.h>
#include <locale.h>


void printDig(int num) {

    if (num/10 > 0) {
        printDig(num/10);
    }
    printf("%d ", num % 10);
}

void printNums1(int num, int border,int coef) {

    if (num> 0) {
        printNums1(num-1,border,coef);
    }
    printf("%d ", num*coef+border);
}


void printFromAToB(int num1,int num2) {
    if (num1 > num2) {
        printNums1(num1 - num2,num1,-1);
    }
    else {
        printNums1(num2-num1,num1,1);
    }
}

void addOne(int*arr,int size,int index) {
    if (index < size) {
        arr[index] += 1;
        if (arr[index] == 2) {
            arr[index] = 0;
            addOne(arr,size,index+1);
        }
    }
    else {
        return;
    }
}

int numsOfOnes(int num) {
    int i,count=0, arr[64];
    for (i = 0; i < 64; i++) {
        arr[i] = 0;
    }
    for (i = 0; i < num; i++) {
        addOne(arr,64,0);
    }
    for (i = 63; i >=0; i--) {
        if (arr[i] == 1) {
            count++;
        }
        //printf("%d",arr[i]);
    }
    //printf("\n");
    return count;
}

void getEven(char* ptr1,int cnt ) {
    int i;
    long int num3 = 0;
    char* ptr2;
    for (i = 0; i < cnt; i++) {
        num3 = strtol(ptr1, &ptr2, 10);
        ptr1 = ptr2 + 1;
        if (num3 % 2 == 0) {
            printf("%d ", num3);
        }
    }
}

int acounter(char* str, int size) {
    int i,count=0;
    for (i = 0; i < size; i++) {
        if (str[i] == 'a') {
            count++;
        }
    }
    return count;
}

int recurs_power(int n, int p) {
    int mult = 1;
    if (p > 1) {
        mult=recurs_power(n, p-1);
    }
    return n * mult;
}


int main(void)
{
    setlocale(LC_ALL, "Rus");

   
    //1
    printf("Task #1\n"); 
    int num = 0;
    printf("Enter number\n");
    scanf_s("%d",&num);
    printDig(num);
    printf("\n\n");


    //2
    printf("Task #2\n");
    int num1 = 0, num2 = 0;
    printf("Enter 2 numbers: A and B\n");
    scanf_s("%d %d", &num1,&num2);
    printFromAToB(num1,num2);
    printf("\n\n");


    //3
    printf("Task #3\n");
    printf("Enter number\n");
    scanf_s("%d", &num);
    printf("%d\n",numsOfOnes(num));
    printf("\n\n");


    //4
    printf("Task #4\n");
    printf("Enter numbers\n");
    int count = 0,cnt = 0;
    char c,str[256];
    getchar();
    while (((c = getchar())!='\n')||(count>256)) {
        if (c == ' ') {
            cnt++;
        }
        str[count++] = c;
    }
    getEven(str, cnt);
    printf("\n\n");


    //5
    printf("Task #5\n");
    printf("Enter string till '.'\n");
    count = 0;
    while (((c = getchar()) != '.') || (count > 256)) {
        str[count++] = c;
    }
    printf("%d\n", acounter(str, count));
    printf("\n\n");



    //6
    printf("Task #6\n");
    int num4=0, mypow = 0;
    printf("Enter number and pow\n");
    scanf_s("%d %d", &num4,&mypow);
    printf("%d\n", recurs_power(num4,mypow));
    printf("\n\n");


    return 0;
}

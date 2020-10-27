//
//  main.c
//  Tutorials2
//
//  Created by Jakub Korkosz on 19/10/2020.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double power(double x,int y){
    double result=1;
    for(int i=0;i<y;i++){
        result=result*x;
    }
    return result;
}

double power_recurision(double x,int y){
    if (y==0) return 1.0;
    if (y==1) return x;
    else
        return power_recurision(x, y-1)*x;
}

bool is_prime(int n){
    
    for (int i=2; i<= sqrt(n); i++)
        if (n%i==0) return false;
    return true;
}

double calculate(double a, double b, char s){
    if (s=='+') {
        return a+b;
    }
    if (s=='-') {
        return a-b;
    }
    if (s=='*') {
        return a*b;
    }
    if (s=='/') {
        return a/b;
    }
    return 0;
}

double mean(double values[] ,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+values[i];
    }
    return sum/n;
}

double standard_deviation(double data[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+data[i];
    }
    double mean= sum/n;
    double powsum=0;
    for(int i=0;i<n;i++){
        powsum=powsum+pow(data[i]-mean, 2);
    }
    return sqrt(powsum/n);
}
void empty(){
    printf("%c",' ');
}
void star(){
    printf("%c",'*');
}

void printNCharacters(char c, int n) {
    for (int j = 0; j < n; j++) {
        printf("%c", c);
    }
}

void outStarPadded(int padding, int starCount) {
    printNCharacters(' ', padding);
    printNCharacters('*', starCount);
    printf("\n");
}

void printDiamond(int size) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            outStarPadded(size - i, 2 * i - 1);
        }
        for (int i = size; i > 0; i--) {
            outStarPadded(size - i, 2 * i - 1);
        }
    } else {
        printf("Must be a positive number");
    }
}

bool is_leap(int year){
    if (year%4==0 && (year%100!=0 || year%400==0)) {
        return true;
    }
    return false;
}

void day_of_the_week(int day,int month,int year){
    int number=(day+month+year)%7;
    switch (number) {
        case 0:
            printf("Saturday\n");
            break;
        case 1:
            printf("Sunday\n");
            break;
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
    }
}

void calendar(int day,int month,int year){
    printf("The date is: %d %d %d ",day,month,year);
    day_of_the_week(day, month, year);
    
}



int main(int argc, const char * argv[]) {
//double data[4];
// data[0]=3;
// data[1]=2;
// data[2]=4;
// data[3]=3;
//  printf("%lf\n",power(5, 4));
//  printf("%lf\n",power_recurision(5, 4));
//if(is_prime(13)==true) printf("Liczba jest pierwsza.\n");
//  else printf("Liczba nie jest pierwsza.\n");
//  printf("%lf\n",calculate(4, 5, '*'));
//  printf("%lf\n",standard_deviation(data, 4));
//    printDiamond(1);
//    is_leap(2020)?printf("Year %d is a leap year.\n",2020):printf("Year is not a leap year.\n");
    int day,month,year;
    scanf("%d%d%d",&day,&month,&year);
    calendar(day, month, year);
    // The method for counting the day of the week is wrong.
    return 0;
}

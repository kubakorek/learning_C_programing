//
//  main.c
//  Tutorial_3
//
//  Created by Jakub Korkosz on 23/10/2020.
//

#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void swap_cycic(int *a, int *b, int *c){
    int d=*a;
    *a=*c;
    *c=*b;
    *b=d;
}

bool analize_digits(int n){
    int a=0;
    bool T[10];
    for (int i=0; i<10; i++) {
        T[i]=false;
    }
    while (n>0) {
        a=n%10;
        if (T[a]==true) {
            printf("The number has repeated digits, ex. %i\n",a);
            return true;
        }
        else T[a]=true;
        n=n/10;
    }
    printf("The number does not have repeated digits.\n");
    return false;
}

void digits_statistic(int n){
    int a=0,max=0;
    int T[10];
    for (int i=0; i<10; i++) {
        T[i]=0;
    }
    while (n>0) {
        a=n%10;
        T[a]++;
        n=n/10;
    }
    for (int i=0; i<10; i++) {
        if (max<T[i]) {
            max=T[i];
        }
        printf("Digit %d occures %d times.\n",i,T[i]);
    }
}

void print_name_age(int age[],char *names[]){
    for (int i=0; i<5; i++) {
        if (age[i]>20 && names[i][0]=='A') {
            printf("%s\n",names[i]);
        }
    }
}

void delete_element(int arr[],int size,int element){
    for(int i=element-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("Elements of array after delete are:\n");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

double weighed_mean(double A[],double W[],int n){
    double weightsum=0,denominator=0;
    for(int i=0;i<n;i++){
        weightsum+=A[i]*W[i];
        denominator+=W[i];
    }
    return weightsum/denominator;
}

void rewrite_arrays(double A[], double B[], int n){
    for(int i=0; i<n;i++){
        B[i] = A[n-1-i];
    }
    
}
void task_9(int A[],int n){
    int min=A[0],max=A[0];
    for(int i=1;i<n;i++){
        if(min>A[i]){
            min=A[i];
        }
        if (max<A[i]) {
            max=A[i];
        }
    }
    printf("Max=%d\tMin=%d\n",max,min);
}
void read_array(double A[3][5]){
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            printf("\nWprowadź liczbę [%d][%d]:",i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
    }
}

void print_array(double A[3][5]){
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            printf("%lf\t",A[i][j]);
        }
        printf("\n");
    }
}

void mean_of_subset(double A[3][5],int n){
    int mean=0;
    for(int i=0;i<5;i++){
        mean=A[n-1][i]+mean;
    }
    mean=mean/5;
    printf("Mean of %d subset is equal to %d\n",n,mean);
}

void mean_of_all(double A[3][5]){
    int mean=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            mean=mean+A[i][j];
        }
    }
    mean=mean/15;
    printf("Mean of all values is equal to %d\n",mean);
}

void maximum_value(double A[3][5]){
    int max=A[0][0];
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if (max<A[i][j]) {
                max=A[i][j];
            }
        }
    }
    printf("Maximum value is equal to %d\n",max);
}

int main(int argc, const char * argv[]) {
//    int a=7,b=4,c=9;
    
//    task_1
    
   /* printf("Before swap: %d %d\n",a,b);
    swap(&a,&b);
    printf("After swap: %d %d\n",a,b); */
    
//    task_2
    
    /*int n;
    printf("Wprowadź liczbę cykli:");
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        swap_cycic(&a, &b, &c);
        printf("After %d swap cycle: %d %d %d\n",n,a,b,c);
    }  */
    
//    task_3
    
//    analize_digits(1234);
    
//    task_4
    
//    digits_statistic(1223338);
    
//    task_5
    
   /* int ages[]={43,23,21,89,2};
    char *names[]={"Alan","Frank","Ann","John","Andrew"};
    print_name_age(ages, names); */
    
//    task_6
    
   /* int size=4,arr[]={3,5,7,1},element=2;
    delete_element(arr, size, element); */
    
//    task_7
    
   /* double A[]={4.0,6.0,8.0},W[]={1.0,3.0,1.0};
    int n=3;
    printf("%lf\n",weighed_mean(A, W, n)); */
    
//    task_8
    
    double A[]={1,2,3,4}, B[]={5,2,7,5};
    int n=4;
    rewrite_arrays(A, B, 4);
    for (int i=0; i<n; i++) {
        printf("%lf\t",A[i]);
    }
    
//    task_9
    
    /*int A[]={3,9,31,53,9};
    task_9(A, 5);*/
    
//    task_10
    
   /* double A[3][5];
    read_array(A);
    print_array(A);
    mean_of_subset(A, 1);
    mean_of_all(A);
    maximum_value(A); */
    
    
    
    
    
    
    return 0;
}

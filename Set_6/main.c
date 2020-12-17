//
//  main.c
//  Set_6
//
//  Created by Jakub Korkosz on 04/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MARK: -Task 2
int* arrayOfIntegers(int num, int start, int step){
    int* ptr = (int*)calloc(num,sizeof(int));
    if (ptr == NULL) return NULL;
    ptr[0] = start;
    for (int i = 1; i<num; i++) {
        ptr[i]=ptr[i-1]+step;
    }
    return ptr;
}
//MARK: - Task 3
int* arrayFromInt(int number){
    int lenght = 1;
    int n = number;
    while(number != 0){
        lenght++;
        number /=10;
    }
    int *array = calloc(lenght, sizeof(int));
    for (int i = lenght-2; i>= 0; i--) {
        array[i] = n%10;
        n = n/10;
    }
    array[lenght-1]= -1;
    return array;
}
//MARK: - Task 4
char* noSpaces(const char* str){
    int len = 0;
    int i =0;
    while( str[i] != '\0'){
        if (str[i] != ' ') {
            len ++;
            i++;
        }
        else{
            i++;
        }
    }
    char* result = (char*)calloc((len+1), sizeof(char));
   // if(result == NULL) return NULL;
    int j = 0;
    for(int a = 0; str[a] != '\0'; a++){
        if (str[a] == ' ')
            ;
        else{
            result[j]=str[a];
            j++;
        }
    }
    result[len+1]='\0';
    return result;
}
// MARK: -Task 5

char* concateteStrings(char* str1, char* str2){
    int len1 = 0;
    int len2 = 0;
    for(int i = 0; str1[i] != '\0';i++){
        len1 ++;
    }
    for(int i = 0; str2[i] != '\0';i++){
        len2 ++;
    }
    char * result = calloc((len1+len2+1), sizeof(char));
    for(int i = 0; i<len1; i++){
        result[i]= str1[i];
    }
    for (int i = 0; i<= len2; i++) {
        result[i+len1]= str2[i];
    }
    return result;
}


// MARK: -Task 6
typedef struct{
    double Re, Im;
}CMPLX;
typedef struct CMPLX_SET{
    CMPLX* a;
    int size;
}CMPLX_SET;

void create_random_set(CMPLX_SET* pcs,int num){
    pcs->a = (CMPLX*)malloc(num*sizeof(CMPLX));
    if (pcs->a == NULL) {
        pcs->size = 0;
    }
    else{
        pcs->size = num;
    }
}

void change_set_size(CMPLX_SET* pcs, int num){
    pcs-> = realloc(pcs, num*sizeof(CMPLX));
    pcs->size = num;
}

void delete_random_set(CMPLX_SET* pcs){
    free(pcs->a);
    pcs->a = NULL;
    pcs->size = 0;
}

void print_random_set(CMPLX_SET* cs){
    for (int i = 0; i<cs->size; i++) {
        printf("Re: %lf | Im: %lf\n",(cs->a[i]).Re,(cs->a[i]).Im);
    }
}

int main(int argc, const char * argv[]) {
    //MARK: -Task 1
    /*int size;
    scanf("%d",&size);
    double* ptr = (double*)malloc(size* sizeof(double));
    if (ptr != NULL) {
        for(int i = 0; i<size;i++){
            scanf("%lf",ptr + i);
        }
        for(int i = 0; i<size;i++){
            printf("%lf\t",ptr[i]);
        }
        
        free(ptr);
    }
    else
        puts("error");
     */
    
    //MARK: - Task 2
//    int* arr = arrayOfIntegers(3, 1, 5);
//    for(int i = 0; i<3;i++){
//        printf("%d\t",arr[i]);
//    }
//    free(arr);
    
    //MARK: - Task 3
//    int * array = arrayFromInt(12345);
//    for(int i = 0; i<6; i++){
//        printf("%d\t",array[i]);
//    }
//    free(array);
    
    //MARK: - Task 4
    /*
    char* string = "St r i ng  la";
    char * str2 = noSpaces(string);
    printf("%s\n",str2);
    free(str2);
   */
    
    //MARK: -Task 5
   /*
    char * str1 = "Ten brodacz";
    char * str2 = " oszukuje w karty.";
    char * concave = concateteStrings(str1, str2);
    printf("%s\n%s\n%s\n",str1,str2,concave);
    free(concave);
    
    */
    //MARK: - Task 6
    CMPLX_SET set1;
    int size = 4;
    create_random_set(&set1, size);
    print_random_set(&set1);
    change_set_size(&set1, 5);
    print_random_set(&set1);
    delete_random_set(&set1);
   
    return 0;
}

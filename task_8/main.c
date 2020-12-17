#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct polynomial{
    int* coeff;
    int deg;
} Poly;

void initialize_poly(Poly* p){
    p->coeff = NULL;
    p->deg = -1;
}
void print_poly(Poly* p){
    if(p->deg == -1){
        printf("Empty polynomial\n");
    }
    else{
        for(int i = 0 ; i < p->deg; i++){
            if(p->coeff[i]==0){
                continue;
            }
            printf("%dx^%d",p->coeff[i],p->deg-i);
            if(p->coeff[i-1]>0){
                printf("+");
            }
        }
        printf("%d\n",p->coeff[p->deg]);
    }
}
void fill_poly(Poly* p, int deg, int* coeff){
    p->deg = deg;
    p->coeff = calloc(deg+1, sizeof(int));
    p->coeff = coeff;
}
void fill_poly_rand(Poly* p, int deg){
    p->deg = deg;
    p->coeff = calloc(deg+1, sizeof(int));
    for(int i = 0; i < p->deg;i++){
        p->coeff[i] = rand()%10;
    }
}
void clean_poly(Poly* p){
    if(p->deg == -1){
        
    }
    else{
        p->deg = -1;
        free(p->coeff);
        p->coeff = NULL;
    }
}
void extend_poly(Poly* p, int new_deg){
    int tmp = p->deg;
    p->deg = new_deg;
    realloc(p->coeff, (new_deg+1)*sizeof(int));
    for(int i = tmp; i<new_deg; i++){
        p->coeff[i] = 0;
    }
}
int evaluate_poly(Poly* p, int x){
    int result = 0;
    for(int i = p->deg;i>=0; i--){
        result = result + p->coeff[i]*pow(x, i);
    }
    return result;
}
void sum_polly(Poly* p1, Poly* p2, Poly* p3){
    if(p1->deg >= p2->deg){
        p3->deg = p1->deg;
        p3->coeff = calloc(p1->deg+1, sizeof(int));
        for(int i = p2->deg; i >= 0; i--){
            p3->coeff[i] = p1->coeff[i]+p2->coeff[i];
        }
    }
    else{
        p3->deg = p2->deg;
        p3->coeff = calloc(p2->deg+1, sizeof(int));
        for(int i = p1->deg; i >= 0; i--){
            p3->coeff[i] = p1->coeff[i]+p2->coeff[i];
        }
    }
}


int main()
{

    Poly p1, p2, p3;

    printf("\n************** Task 1 (1 points) **************\n");
    initialize_poly(&p1);
    initialize_poly(&p2);
    initialize_poly(&p3);
    printf("p1: "); print_poly(&p1);

    printf("\n************** Task 2 (2 points) **************\n");
    int coeff[] = {1, -2, 3, -4, 5, -6};
    fill_poly(&p1, 5, coeff);
    fill_poly_rand(&p2, 2);
    printf("p1: "); print_poly(&p1);
    printf("p2: "); print_poly(&p2);
    
    printf("\n************** Task 3 (1 points) **************\n");
    extend_poly(&p2,4);
    printf("p2: "); print_poly(&p2);
    
    printf("\n************** Task 4 (2 points) **************\n");
    printf("p1(1): "); printf("%d\n", evaluate_poly(&p1, 1));
  
    printf("\n************** Task 5 (2 points) **************\n");
    sum_polly(&p1, &p2, &p3);
    printf("p1: "); print_poly(&p1);
    printf("p2: "); print_poly(&p2);
    printf("p1+p2: "); print_poly(&p3);
    sum_polly(&p2, &p1, &p3);
    printf("p2+p1: "); print_poly(&p3);
//    clean_poly(&p1);
//    clean_poly(&p2);
//    clean_poly(&p3);

    return 0;
}

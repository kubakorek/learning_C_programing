//
//  main.c
//  Task_12
//
//  Created by Jakub Korkosz on 25/01/2021.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    double data;
    struct node* next;
} node;

typedef struct {
    node* top;
} stack;

void printArray(const char* filename){
    FILE *f = fopen(filename, "rb+");
    if(f == NULL){
        printf("Unable to read file.\n");
        return;
    }
    double x;
    while(fread(&x, sizeof(double), 1, f) == 1){
        printf("%lf\t",x);
    }
    if(!feof(f)){
        printf("Failed to read the dara.\n");
    }
    fclose(f);
    printf("\n");
}
int isEmpty(const stack* s){
    //returns 0 if is empty;
    if(s->top == NULL){
        return 0;
    }
    return 1;
}
void push(stack* s, double data){
    node *tmp = malloc(sizeof(node));
    tmp->data = data;
    if(isEmpty(s) == 0){
        s->top = tmp;
        return;
    }
    tmp->next = s->top;
    s->top = tmp;
}
double pop(stack* s){
    if(s->top == NULL){
        printf("The stack is empty\n");
        return -1;
    }
    if(s->top->next == NULL){
        double value = s->top->data;
        free(s->top);
        s->top = NULL;
        return value;
    }
    node *tmp = malloc(sizeof(node));
    tmp = s->top;
    s->top = s->top->next;
    double value = tmp->data;
    free(tmp);
    return value;
}
void print_stack(const stack* s){

    if (isEmpty(s) == 0) {
        printf("The stack is empty!\n");
        return;
    }

    node *curr = s->top;
    while (curr) {
        printf("%lf ",curr->data);
        curr = curr->next;
    }
}
stack build_stack(const char* filename){
    stack s = {NULL};
    FILE *f = fopen(filename, "rb+");
    if(f == NULL){
        printf("Unable to read file.\n");
        return s;
    }
    double x;
    while(fread(&x, sizeof(double), 1, f) == 1){
        push(&s, x);
    }
    if(!feof(f)){
        printf("Failed to read the dara.\n");
    }
    fclose(f);
    return s;
}
void dump_stack(stack* s, const char* filename){
    FILE *f = fopen(filename, "w+");
    if(f == NULL){
        printf("Unable to use the file.\n");
        return;
    }
    while(isEmpty(s)){
        double x = pop(s);
        if(fprintf(f, "%lf\n",x) < 0){
            printf("Failed to write to file");
            fclose(f);
            return;
        }
    }
    fclose(f);
}
stack build_stack_n(const char* filename, int n){
    stack s = {NULL};
    FILE *f = fopen(filename, "rb+");
    if(f == NULL){
        printf("Unable to read file.\n");
        return s;
    }
    double x;
    while(fread(&x, sizeof(double), 1, f) == 1){
        push(&s, x);
        fseek(f, (n-1)*sizeof(double), SEEK_CUR);
    }
    if(!feof(f)){
        printf("Failed to read the dara.\n");
    }
    fclose(f);
    return s;

}

int main()
{
    // Part 1
    
    puts("********** Part 1 **********");
    printArray("/Users/jakub/Desktop/array.bin");
    

    // Part 2
    
    puts("\n\n********** Part 2 **********");
    stack s = { NULL };
    push(&s, 2);
    push(&s, 4);
    push(&s, 6);
    print_stack(&s);
    putchar('\n');
    double data = pop(&s);
    print_stack(&s);
    putchar('\n');
    data = pop(&s);
    print_stack(&s);
    putchar('\n');
    data = pop(&s);
    print_stack(&s);
    

    // Part 3
    
    puts("\n********** Part 3 **********");
    s = build_stack("/Users/jakub/Desktop/array.bin");
    print_stack(&s);
    

    // Part 4
    
    puts("\n********** Part 4 **********");
    dump_stack(&s, "/Users/jakub/Desktop/stack.txt");
    print_stack(&s);
    

    // Part 5
    
    puts("\n********** Part 5 **********");
    s = build_stack_n("/Users/jakub/Desktop/array.bin", 2);
    print_stack(&s);
    

    return 0;
}


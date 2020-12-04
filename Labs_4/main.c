//
//  main.c
//  Labs_4
//
//  Created by Jakub Korkosz on 27/11/2020.
//

#include <stdio.h>
#include <string.h>
#define MAX_TITLE_SIZE 80

enum Status{
    Borrowed = 0,
    Available = 1,
};

struct Book{
    char title[MAX_TITLE_SIZE];
    int year;
    enum Status status; // 0 for borrowed, 1 for avaliable
};

int readBook(struct Book* book){
    if(scanf("%s",book->title)==1){
        if(scanf("%d",&book->year)==1){
            if (scanf("%d",&book->status)==1) {
                return 1;
            }
        }
    }
    return 0;
}

void printBook(struct Book* book){
    printf("Title: %s\t Year: %d\t Status: %d\n",book->title,book->year, book->status);
}

void copyBooks(struct Book* book1,struct Book* book2){
    book1->status = book2->status;
    strcpy(book1->title, book2->title);
    book1->year = book1->year;
}

int compareBook(struct Book* book1,struct Book* book2){
    if(book1->status == book2->status){
        if (book1->year==book2->year) {
            return (strcmp(book1->title, book2->title));
            
        }
        return (book1->year < book2->year) ? -1 : 1;
    }
    return (book1->status < book2->status)? -1 : 1;
}

void sortBooks(struct Book* book){
    for (int i = 1;i != '\0'; i++) {
        for (int j = i-1; j>=0 && compareBook(&book[j],&book[j+1])>0; j--) {
            struct Book tmp = book[j];
            book[j]=book[j+1];
            book[j+1] = tmp;
            }
    }
}

int main(int argc, const char * argv[]) {
    struct Book book;
    readBook(&book);
    printBook(&book);
    struct Book book2;
    readBook(&book2);
    printBook(&book2);
    printf("%d\n",compareBook(&book, &book2));
    return 0;
}


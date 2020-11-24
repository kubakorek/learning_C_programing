//
//  main.c
//  Tutorials_4
//
//  Created by Jakub Korkosz on 06/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_ARRAY_SIZE 32

int mystrlen(const char* src) {
int i = 0;
while (src[i] != '\0') {
i++;
}
return i;
}

void mystrcpy(char* dest, const char* src) {
int i = 0;
while (src[i] != '\0') {
dest[i] = src[i];
i++;
}
dest[i] = '\0';
}

int areequal(char* dest, const char* src) {
for (int i = 0; i <= mystrlen(src) / 2; i++) {
if (dest[i] != src[i]) {
return -1;
break;
}
}
return 0;
}

int mystrncmp(char* dest, const char* src, size_t n) {
for (unsigned int i = 0; i < n; i++) {
if (dest[i] != src[i]) {
return -1;
break;
}
}
return 0;
}

char* concatenate(char* dest, const char* src) {
int l1 = mystrlen(dest);
int l2 = mystrlen(src);
for (int i = l1; i < l1 + l2; i++) {
dest[i] = src[i - l1];
}
return dest;
}
char* mystrchr(const char* src, int c) {
for (int i = 0; i < mystrlen(src); i++) {
if (src[i] == c) {
return &src[i];
break;
}
}
return NULL;
}

int isPalindrome(char* str) {
for (int i = 0; i <= mystrlen(str) / 2; i++) {
if (str[i] != str[mystrlen(str) - i-1]) {
return 0;
break;
}
}
return 1;
}

void deleteOnPosition(char* str, int position) {
for (int i = position - 1; i <= mystrlen(str); i++) {
str[i] = str[i + 1];
}
}

void deleteFirstOccurance(char* str, char c) {
for (int i = 0; i < mystrlen(str); i++) {
if (str[i] == c) {
deleteOnPosition(str, i+1);
break;
}
}
}
void deleteEveryOccurance(char* str, char c) {
for (int i = 0; i < mystrlen(str); i++) {
if (str[i] == c) {
deleteOnPosition(str, i + 1);
i--;
}
}
}

void removeUppercase(char* str) {
for (int i = 0; i < mystrlen(str); i++) {
if (str[i] >= 'A' && str[i] <= 'Z') {
deleteOnPosition(str, i + 1);
i--;
}
}
}

void removePhrase(char* str, int start, int lenght) {
for (int i = start - 1; i <= start + lenght; i++) {
str[i] = str[i + lenght];
}
}

void removeStringFromString(char* str, const char* toremove) {
for (int i = 0; i < mystrlen(str); i++) {
if (str[i] == *toremove) {
removePhrase(str, i + 1, mystrlen(toremove));
}
}
}

int replaceChar(char* str, char toreplace, char replacewith) {
int result = 0;
for (int i = 0; i < mystrlen(str); i++) {
if (str[i] == toreplace) {
str[i] = replacewith;
result++;
}
}
return result;
}

void toUpperCase(char* str) {
for (int i = 0; i < mystrlen(str); i++) {
if (str[i] >= 'a' && str[i] <= 'z') {
str[i] = str[i] - 32;
}
}
}

void strrplcch(char* str, int start, int length, const char* replacement) {
char ending[MAX_ARRAY_SIZE];
for (int i = start + length - 1; i <= mystrlen(str)+1; i++) {
ending[i+1 - start - length] = str[i];
}
removePhrase(str, start, length);
for (int i = start-1; i <= start + mystrlen(replacement); i++) {
str[i] = replacement[i + 1 - start];
}
for (int i = start + mystrlen(replacement) - 1; i < start + mystrlen(replacement) + mystrlen(ending); i++) {
str[i] = ending[i - start - mystrlen(replacement) + 1];
}
}

int strrplcstr(char* src, const char* toreplace, const char* replacewith) {
    int result = 0;
for (int i = 0; i < mystrlen(src); i++) {
if (src[i] == *toreplace) {
strrplcch(src, i+1, mystrlen(toreplace), replacewith);
    result += 1;
}
}
    return result;
}

void replaceNumbers(char* str) {
for (int i = 0; i < mystrlen(str); i++) {
strrplcstr(str, " 2 ", " two ");

}
}



int main(void) {

char string[MAX_ARRAY_SIZE] = "Numba";
char string2[MAX_ARRAY_SIZE] = "NumString";
printf("%d\t%d\n", mystrlen(string), mystrlen(string2));
mystrcpy(string, string2);
printf("%s\t%s\t%d\n", string, string2, areequal(string, string2));
printf("%s\t%s\t%d\n", string, string2, mystrncmp(string, string2, 3));
printf("%s\n", concatenate(string, string2));
printf("%p\t%p\t%p\n", mystrchr(string, 'm'), mystrchr(string, 'u'), mystrchr(string, 'N'));
printf("%d\n", isPalindrome("alalal"));
char string3[MAX_ARRAY_SIZE] = "Stringiingrg";
printf("%s\t", string3);
deleteOnPosition(string3, 4);
printf("%s\n", string3);
deleteFirstOccurance(string3, 'r');
printf("%s\n", string3);
deleteEveryOccurance(string3, 'i');
printf("%s\n", string3);
char string4[MAX_ARRAY_SIZE] = "upDFGFDperlEeRFttCertHeSDst";
removeUppercase(string4);
printf("%s\n", string4);
removePhrase(string4, 3, 6);
printf("%s\n", string4);
removeStringFromString(string4, "ter");
printf("%s\n", string4);
char string5[MAX_ARRAY_SIZE] = "stringstoss";
int b = replaceChar(string5, 's', 'a');
printf("%s\t%d\n", string5,b);
toUpperCase(string5);
printf("%s\n", string5);

char string6[MAX_ARRAY_SIZE] = "Stringreplacement";
strrplcch(string6, 5, 7, "NOWYToReplace");
printf("%s\n", string6);
char string7[MAX_ARRAY_SIZE] = "StringReplaceSReplaceReplace";
strrplcstr(string7, "Replace", "NEW");
printf("%s\n", string7);
    
return 0;
}


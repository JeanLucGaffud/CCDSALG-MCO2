#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_1D_ARRAY 16384
#define MAX_STRING 256
typedef char string[MAX_STRING];

typedef struct {
    string key;
    int value;
} HashTable;

string convertStringToNumber(string str){
    int arrNum[MAX_STRING];
    string appendedNum;

    for(int i = 0; i < len(str); i++){
        appendedNum[i] = (int)str[i];
    }
}




HashTable *createHashTable(int n, string *words){
    HashTable *hashTable = (HashTable *)malloc(n * sizeof(HashTable));

    return hashTable;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_1D_ARRAY 16384
#define MAX_STRING 16
typedef char string[MAX_STRING];

typedef struct {
    string key;
    int value;
    HashTable *next;
} HashTable;

int convertAndAppend(char* words) {
    int length = strlen(words);
    char result[MAX_STRING] = ""; // Allocate enough space for the new string
    char temp[5]; // Temporary string to hold the ASCII value of the current character
    int index = 0;
    // Loop through each character in the words string
    for (int i = 0; i < length; i++) {
        int ascii = (int)words[i]; // Get the ASCII value of the current character
        printf("%d\n", ascii);
        snprintf(temp, sizeof(temp), "%d", ascii); // Convert the ASCII value to a string
        strcat(result, temp); // Append the string to the new string
        printf("%s\n", result);
    }

    return atoi(result); // Convert the new string to an integer
}

HashTable *createHashTable(string *words, int tableSize){
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable) * tableSize);
    
    return hashTable;
}

int HashFunction(string key, int tableSize){
    int index = convertAndAppend(key) % tableSize;
    return index;
}

/*
returns the index of the key in the linked list.

*/
int collissionresolution(HashTable **hashTable, int index, string key){
    do{
        if(hashTable[index].next == NULL && hashTable[index].key != key){
            hashTable[index].next = (HashTable *)malloc(sizeof(HashTable));
        }
        else if(hashTable[index].key == key){
            return index;
        }
    }while(hashTable[index].key != key);
}



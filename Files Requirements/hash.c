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
} HashTable;

int convertAndAppend(char* words) {
    int length = strlen(words);
    int index = 0;

    char result[MAX_STRING * 4] = ""; // Allocate enough space for the new string
    char temp[10]; // Temporary string to hold the ASCII value of the current character

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

HashTable *createHashTable(string *words, int arraySize, int *tableSize){
    int num = 1.1 * (int)round(arraySize);
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable) * num);
    for(int i = 0; i < num; i++){ // Corrected loop condition
        strcpy(hashTable[i].key, "");
        hashTable[i].value = -1;
    }
    *tableSize = num;
    return hashTable;
}

int HashFunction(string key, int tableSize){
    int index = convertAndAppend(key) % tableSize;
    return index;
}

/*
returns the index of the key in the linked list.

*/
int collissionresolution(HashTable *hashTable, int index, string key, int size){
    int i = 0;
    while(hashTable[index].value != -1){
        index = (index + i) % size;
        i++;
    }
    return index;
}

int Search(HashTable *hashTable, int tableSize, string key){
    int index = HashFunction(key, tableSize);
    int i = 0;
    if(strcmp(hashTable[index].key, key) == 0){
        return index;
    } else {
        while(hashTable[index].value != -1 && i < tableSize){
            index = (index + i) % tableSize;
            if(strcmp(hashTable[index].key, key) == 0){
                return index;
            }
            i++;
        }
    }
    return -1;
}

int *HashArray(string *words, int n, HashTable *hashTable){
    for(int i = 0; i < n; i++){
        int index = HashFunction(words[i], n);
        if(Search(hashTable, n, words[i]) == -1){
            hashTable[index].value = 1;
            strcpy(hashTable[index].key, words[i]);
        } else {
            index = collissionresolution(hashTable, index, words[i], n);
            hashTable[index].value = 1;
            strcpy(hashTable[index].key, words[i]);
        }
    }
    return 0; // Added return statement to avoid warning
}



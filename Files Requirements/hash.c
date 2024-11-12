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
    char result[length + 1]; // Allocate enough space for the new string
    char temp[5]; // Temporary string to hold the ASCII value of the current character
    int index = 0;
    // Loop through each character in the words string
    for (int i = 0; i < length; i++) {
        int ascii = (int)words[i]; // Get the ASCII value of the current character
        snprintf(temp, sizeof(temp), "%d", ascii); // Convert the ASCII value to a string
        strcat(result, temp); // Append the string to the new string
    }

    return atoi(result); // Convert the new string to an integer
}




HashTable *createHashTable(string *words){
    HashTable *hashTable = (HashTable *)malloc(strlen(*words) * sizeof(HashTable));
    
    return hashTable;
}




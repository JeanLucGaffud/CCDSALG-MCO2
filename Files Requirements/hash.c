#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_1D_ARRAY 16384
#define MAX_STRING 256
typedef char string[MAX_STRING];

typedef struct {
    string key;
    int value;
} HashTable;

int convertAndAppend(char* words) {
    string result;
    int length = strlen(words);
    int index = 0; // Index for the new string

    // Loop through each character in the words string
    for (int i = 0; i < length; i++) {
        int asciiValue = (int)words[i];    // Convert character to its ASCII integer value
        char convertedChar = (char)asciiValue; // Convert the ASCII value back to a char
        result[index++] = convertedChar;   // Append the character to the new string
    }

    result[index] = '\0'; // Null-terminate the new string
    return atoi(result); // Convert the new string to an integer
}




HashTable *createHashTable(string *words){
    HashTable *hashTable = (HashTable *)malloc(strlen(*words) * sizeof(HashTable));
    
    return hashTable;
}




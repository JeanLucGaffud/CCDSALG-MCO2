#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library
#include <string.h> // Include string library
#include <math.h>   // Include math library
#include <stdbool.h>    // Include boolean library

#define MAX_1D_ARRAY 16384 // Maximum size of 1D array
#define MAX_STRING 16  // Maximum size of string
typedef char string[MAX_STRING]; // Define string as char array

/*
    this struct is used to store the key, value, and number of comparisons
    key: string
    value: integer
    compares: integer
*/
typedef struct {
    string key;
    int value;
    int compares;
} HashTable;

// Function prototypes
HashTable *createHashTable(int arraySize, int *tableSize);
int findPrime(int n);
int hashFunction(char *key, int tableSize);
int collisionResolution(int index, int tableSize, int i);
int search(HashTable *hashTable, int tableSize, string key);
unsigned long djb2(unsigned char *str);
void insert(HashTable *hashTable, int tableSize, string key, int value);
void delete(HashTable *hashTable, int tableSize, string key);

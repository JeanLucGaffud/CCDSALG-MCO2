#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX_1D_ARRAY 16384
typedef char string[16];

typedef struct {
    string key;
    int value;
} HashTable;

HashTable createHashTable(int tableSize, string hashTable[]);
int findPrime(int n);
int hashFunction(char *key, int tableSize);
int collisionResolution(int index, int tableSize, int i);
int search(HashTable *hashTable, int tableSize, string key);
unsigned long djb2(unsigned char *str);
void insert(HashTable *hashTable, int tableSize, string key, int value);
void delete(HashTable *hashTable, int tableSize, string key);

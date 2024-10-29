#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_1D_ARRAY 16384
typedef char string[100];

int findPrime(int n);
int hashFunction(char *key, int tableSize);
int collisionResolution(int index, int tableSize, int i);
int search(string key, int tableSize, string hashTable[]);

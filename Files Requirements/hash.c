#include "hash.h"

int search(string key, int tableSize, string hashTable[]) {
    int index = hashFunction(key, tableSize);
    int i = 0;
    while (i < tableSize) {
        if (strcmp(hashTable[index], key) == 0) {
            return index;
        }
        index = collisionResolution(index, tableSize, i);
        i++;
    }
    return -1;
}
int findPrime(int n)
{
    
}
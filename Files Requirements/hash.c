#include "hash.h"

int search(HashTable *hashTable, int tableSize, string key) {
    int index = hashFunction(key, tableSize);
    int i = 0;
    while (i < tableSize) {
        if (strcmp(hashTable[index].key, key) == 0) {
            return index;
        }
        index = collisionResolution(index, tableSize, i);
        i++;
    }
    return -1;
}

int collisionResolution(int index, int tableSize, int i) {
    return (index + i * i) % tableSize;
}

unsigned long djb2(unsigned char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

int hashFunction(char *key, int tableSize) {
    return djb2((unsigned char *)key) % tableSize;
}

HashTable createHashTable(int tableSize, string hashTable[]) {
    HashTable ht;
    for (int i = 0; i < tableSize; i++) {
        strcpy(hashTable[i], "");
    }
    return ht;
}

void insert(HashTable *hashTable, int tableSize, string key, int value) {
    int index = hashFunction(key, tableSize);
    int i = 0;
    while (i < tableSize) {
        if (strcmp(hashTable[index].key, "") == 0) {
            strcpy(hashTable[index].key, key);
            hashTable[index].value = value;
            return;
        }
        index = collisionResolution(index, tableSize, i);
        i++;
    }
    printf("Hash table is full\n");
}

void delete(HashTable *hashTable, int tableSize, string key) {
    int index = search(hashTable, tableSize, key);
    if (index != -1) {
        strcpy(hashTable[index].key, "");
        hashTable[index].value = 0;
    } else {
        printf("Key not found\n");
    }
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int findPrime(int n) {
    int candidate = n + 1;
    while (!isPrime(candidate)) {
        candidate++;
    }
    return candidate;
}
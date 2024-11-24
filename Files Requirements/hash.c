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
    int compares;
} HashTable;


bool isPrime(int num){
    if (num <= 1) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int primeNumberAbove(int num){
    while(!isPrime(num)){
        num++;
    }
    return num;
}

HashTable *createHashTable(int arraySize, int *tableSize){
    int num = primeNumberAbove(1.1 * (int)round(arraySize));
    
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable) * num);
    
    for(int i = 0; i < num; i++){ 
        strcpy(hashTable[i].key, "");
        hashTable[i].value = -1;
    }

    *tableSize = num;
    return hashTable;
}

unsigned int HashFunction(const char* key, int tableSize) {
    unsigned int index = 0;
    for (size_t i = 0; i < strlen(key); i++) { // Use size_t for loop index
        index += key[i] * (i + 1); //Linear Probing
        index %= tableSize; // Use modulo to wrap around the table    
    }
    return index % tableSize;
}


int collisionresolution(HashTable *hashTable, int index, int tableSize){
    int i = 1; 
    while(hashTable[index].value != -1){
        index = (index + i) % tableSize; // Use linear probing for collision resolution
        i++;
    }
    return index;
}
/*
    @param words: Array of strings
    @param num: Number of words
    @param hashTable: HashTable
    @param tableSize: Size of the HashTable
    @param nKeys: Number of keys
    @param nHome: Number of keys at home position
    @param nColns: Number keys with collisions
*/

void HashArray(string *words, int num, HashTable *hashTable, int tableSize,int *nKeys, int *nHome, int *nColns){
    int nKeys1 = 0;
    int nColns1= 0;
    int nHome1= 0;
    for(int i = 0; i < num; i++){
        int index = HashFunction(words[i], tableSize);
        if(hashTable[index].value == -1){ //Checks if the index is empty then inserts the word
            hashTable[index].value = 1;
            strcpy(hashTable[index].key, words[i]);
            nKeys1++;
            nHome1++;
        } else if( strcmp(hashTable[index].key, words[i]) != 0){ //Checks if the index is not empty and the word is not the same then inserts the word
            int newIndex = collisionresolution(hashTable, index, tableSize);
            hashTable[newIndex].value = 1;
            strcpy(hashTable[newIndex].key, words[i]);
            nKeys1++;
            nColns1++;
        }
        hashTable[index].compares = 0; //Sets the number of comparisons to 0 for default value
    }
    *nHome = nHome1;
    *nColns = nColns1;
    *nKeys = nKeys1;
}

int Search(HashTable *hashTable, int tableSize, string key){
    int index = HashFunction(key, tableSize);
    int i = 1;
    if(strcmp(hashTable[index].key, key) == 0){
        return index;
    } else {
        while(hashTable[index].value != -1 && i < tableSize){
            index = (index + i) % tableSize; // Use linear probing for collision resolution
            if(strcmp(hashTable[index].key, key) == 0){
                hashTable[index].compares = i; //Sets the number of comparisons
                return index;
            }
            i++;
        }
    }
    return -1;
}
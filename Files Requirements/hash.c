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

unsigned int HashFunction(string key, int tableSize){
    unsigned int index = 0, i;
    for(i = 1; i < strlen(key); i++){
        index += key[i-1] * i;
    }
    return index % tableSize;
}

int collisionresolution(HashTable *hashTable, int index, int tableSize){
    int i = 1; 
    while(hashTable[index].value != -1){
        index = (index + i * i) % tableSize; // Use quadratic probing to handle collisions
        i++;
    }
    return index;
}

void HashArray(string *words, int num, HashTable *hashTable, int tableSize){
    for(int i = 0; i < num; i++){
        int index = HashFunction(words[i], tableSize);
        if(hashTable[index].value == -1 || strcmp(hashTable[index].key, words[i]) == 0){    
            hashTable[index].value = 1;
            strcpy(hashTable[index].key, words[i]);
        } else {
            int newIndex = collisionresolution(hashTable, index, tableSize);
            hashTable[newIndex].value = 1;
            strcpy(hashTable[newIndex].key, words[i]);
        }
    }
}

// int Search(HashTable *hashTable, int tableSize, string key){
//     int index = HashFunction(key, tableSize);
//     int i = 0;
//     if(strcmp(hashTable[index].key, key) == 0){
//         return index;
//     } else {
//         while(hashTable[index].value != -1 && i < tableSize){
//             index = (index + i) % tableSize;
//             if(strcmp(hashTable[index].key, key) == 0){
//                 return index;
//             }
//             i++;
//         }
//     }
//     return -1;
// }

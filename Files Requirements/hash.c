#include "hash.h"
#include <stdbool.h>
#include <string.h>

bool isUniqque(string *words, int n, string key){
    for(int i = 0; i < n; i++){
        if(strcmp(words[i], key) == 0){
            return false;
        }
    }
    return true;
}

int collisionResolution(HashTable *hashTable, int tableSize, string key, int value){
    int index = hashFunction(key, tableSize);
    int i = 0;
    while(hashTable[index].value != -1){
        index = (index + 1) % tableSize; // Linear probing
        i++;
    }
    strcpy(hashTable[index].key, key);
    hashTable[index].value = value;
    return index;
}

int search(HashTable *hashTable, int tableSize, string key){
    int index = hashFunction(key, tableSize);
    int i = 0;
    while(hashTable[index].value != -1){ // While the index is not empty
        if(strcmp(hashTable[index].key, key) == 0){
            return index;
        }
        index = (index + 1) % tableSize; // Linear probing
        i++;
    }
    return -1;
}

int hashFunction(string key, int tableSize){
    // Implement your hash function here
}

void insert(HashTable *hashTable, int tableSize, string key, int value){
    int index = hashFunction(key, tableSize);
    if(hashTable[index].value != -1){
        index = collisionResolution(hashTable, tableSize, key, value);
    } else {
        strcpy(hashTable[index].key, key);
        hashTable[index].value = value;
    }
}

void delete(HashTable *hashTable, int tableSize, string key){
    int index = search(hashTable, tableSize, key);
    if(index != -1){
        strcpy(hashTable[index].key, "");
        hashTable[index].value = -1;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "hash.c"

int inputFile(string name, string **words){
    FILE *f = fopen(name, "r");
    int num = 0, i = 0;
    string temp;

    if(f == NULL){
        printf("File not found\n");
        return 0;
    }

    fscanf(f, "%d", &num);

    *words = (string *)malloc(sizeof(string) * num);

    while(fscanf(f, "%s", temp) == 1) {
        strcpy((*words)[i], temp);
        i++;
    }

    fclose(f);
    return num;
}

void outputFile(string name, HashTable *hashTable, int nRead, int nKeys, int nHome, int nCollisions){
    FILE *f = fopen(name, "w");

    if(f == NULL){
        printf("File not found\n");
        return;
    }

    fprintf(f, "%d\n", nRead);
    fprintf(f, "%d\n",nKeys);
    fprintf(f, "%d\n", nHome);
    fprintf(f, "%d\n", nCollisions);
    fprintf(f, "%.6f\n\n");

    fclose(f);
}

void printHashTable(HashTable *hashTable, int n){
    for(int i = 0; i < n; i++){
        if(hashTable[i].value != -1){
            printf("%d.Key: |%s| Value: %d\n", i+1, hashTable[i].key, hashTable[i].value);
        }
    }
}

void printArray(string *words, int n){
    for(int i = 0; i < n; i++){
        printf("%s \n", words[i]);
    }
}

int main() {
    string name = "input1.txt";
    string output = "output.txt";
    string *words;
    HashTable *hashTable;
    int nWords, tableSize, nHome, nColns, nKeys;
    
    // printf("Enter the name of the file: ");
    // scanf("%s", name);

    nWords = inputFile(name, &words);

    hashTable = createHashTable(nWords, &tableSize); 

    HashArray(words, nWords, hashTable, tableSize,&nKeys, &nHome, &nColns);
    printHashTable(hashTable, tableSize);
    printf("Number of keys: %d\n", nKeys);
    printf("Number of keys in home position: %d\n", nHome);
    printf("Number of collisions: %d\n", nColns);
    // printf("Enter the name of the output file: ");
    // scanf("%s", output);

    // outputFile(output, hashTable, nWords, tableSize, nKeys, nHome, nCollisions);

    free(words);
    free(hashTable);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "hash.c"

typedef char string[MAX_STRING];

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

void printHashTable(HashTable *hashTable, int n){
    for(int i = 0; i < n; i++){
        if(hashTable[i].value != -1){
            printf("%s %d\n", hashTable[i].key, hashTable[i].value);
        }
    }
}

void printArray(string *words, int n){
    for(int i = 0; i < n; i++){
        printf("%s \n", words[i]);
    }
}

int main() {
    string name = "input.txt";
    string output = "output.txt";
    string *words;
    HashTable *hashTable;
    int num;
    
    // printf("Enter the name of the file: ");
    // scanf("%s", name);

    num = inputFile(name, &words);
    printArray(words, num);

    *hashTable = *createHashTable(words, num);
    

    HashArray(words, num, hashTable);
    printHashTable(hashTable, num);

    printf("Enter the name of the output file: ");
    scanf("%s", output);

    outputFile(output, hashTable, num);

    free(words);
    free(hashTable);

    return 0;
}

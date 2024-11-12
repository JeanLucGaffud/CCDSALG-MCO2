#include <stdio.h>
#include <stdlib.h>
#include "hash.c"

int inputFile(string name, string *words){
    FILE *f = fopen(name, "r");
    int num = 0, i = 0;
    string temp;

    if(f == NULL){
        printf("File not found\n");
        return 0;
    }

    fscanf(f, "%d", &num);

    while(fscanf(f, "%s", temp) == 1) {
        strcpy(words[i], temp);
        i++;
    }

    fclose(f);
    return num;
}

void printArray(string *words, int n){
    for(int i = 0; i < n; i++){
        printf("%s \n", words[i]);
    }
}

int main() {
    string name = "input.txt";
    string words[MAX_1D_ARRAY];
    //HashTable *hashTable;


    int num = inputFile(name, words);
	//printArray(words, num);
    //HashTable hashTable = *createHashTable(num, words);
    
    printf("Hello %d", convertAndAppend("abc"));
    return 0;
}

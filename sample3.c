#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "hash.c"

// Function to read input file
int inputFile(string name, string **words) {
    FILE *f = fopen(name, "r");
    int num = 0, i = 0;
    string temp;

    if (f == NULL) {
        printf("File not found\n");
        return 0;
    }

    fscanf(f, "%d", &num);

    *words = (string *)malloc(sizeof(string) * num);

    while (fscanf(f, "%s", temp) == 1) {
        strcpy((*words)[i], temp);
        i++;
    }

    fclose(f);
    return num;
}

// Function to output hash table and statistics to a file
void outputFile(string name, HashTable *hashTable, int nRead, int nKeys, int nHome, int nCollisions) {
    FILE *f = fopen(name, "w");

    if (f == NULL) {
        printf("File not found\n");
        return;
    }

    fprintf(f, "%d\n", nRead);
    fprintf(f, "%d\n", nKeys);
    fprintf(f, "%d\n", nHome);
    fprintf(f, "%d\n", nCollisions);
    fprintf(f, "%.6f\n\n", (double)(nCollisions) / nKeys); // Assuming average comparison logic here

    fclose(f);
}

// Function to print the hash table
void printHashTable(HashTable *hashTable, int n) {
    for (int i = 0; i < n; i++) {
        if (hashTable[i].value != -1) {
            printf("%d. Key: |%s| Value: %d\n", i + 1, hashTable[i].key, hashTable[i].value);
        }
    }
}

// Function to print the array of words
void printArray(string *words, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s \n", words[i]);
    }
}

int main() {
    string name = "input1.txt";
    string output;
    string *words;
    HashTable *hashTable;
    int nWords, tableSize, nHome, nColns, nKeys;

    nWords = inputFile(name, &words);

    // Create hash table based on number of words
    hashTable = createHashTable(nWords, &tableSize); 

    // Hash the words and update the stats
    HashArray(words, nWords, hashTable, tableSize, &nKeys, &nHome, &nColns);

    // Print hash table stats
    printHashTable(hashTable, tableSize);
    printf("Number of keys: %d\n", nKeys);
    printf("Number of keys in home position: %d\n", nHome);
    printf("Number of collisions: %d\n", nColns);

    // Ask for output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output);

    // Write the results to the output file
    outputFile(output, hashTable, nWords, nKeys, nHome, nColns);

    // Free allocated memory
    free(words);
    free(hashTable);

    return 0;
}

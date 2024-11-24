#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "hash.c"  // header for hash file and hash table

// Read words from the input file
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

// results listed in the output file
void outputFile(string name, HashTable *hashTable, int tableSize, int nRead, int nKeys, int nHome, int nCollisions, double avgComparisons) {
    FILE *f = fopen(name, "w");

    if (f == NULL) {
        printf("Error: Unable to create output file.\n");
        return;
    }

    // Summary details
    fprintf(f, "Summary:\n");
    fprintf(f, "Number of strings read: %d\n", nRead);
    fprintf(f, "Number of strings stored in hash table: %d\n", nKeys);
    fprintf(f, "Number of strings in their home addresses: %d\n", nHome);
    fprintf(f, "Number of collisions: %d\n", nCollisions);
    fprintf(f, "Average number of string comparisons: %.6f\n\n", avgComparisons);

    // Table headers
    fprintf(f, "Index    Key               Home Index    In Home    Comparisons\n");
    fprintf(f, "-------------------------------------------------------------\n");

    // Hash Table information
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i].value != -1) {
            int homeIndex = HashFunction(hashTable[i].key, tableSize);
            bool inHome = (homeIndex == i);
            int comparisons = inHome ? 1 : abs(homeIndex - i) + 1;

            // format
            fprintf(f, "%-8d %-17s %-13d %-10s %-11d\n",
                    i, hashTable[i].key, homeIndex, inHome ? "YES" : "NO", comparisons);
        } else {
            // hash table empty slots
            fprintf(f, "%-8d %-17s %-13s %-10s %-11s\n", i, "---", "---", "---", "---");
        }
    }

    fclose(f);
}

int main() {
    string name;
    string output;
    string *words;
    HashTable *hashTable;
    int nWords, tableSize, nHome, nCollisions, nKeys, totalComparisons = 0;

    // read input file
    printf("Enter the name of the input file: ");
    scanf("%s", name);

    nWords = inputFile(name, &words);
    if (nWords == 0) {
        return 1; // exit if cannot be read
    }

    // Hash table creation
    hashTable = createHashTable(nWords, &tableSize);

    // Hashing and insertion of words in the hash table
    HashArray(words, nWords, hashTable, tableSize, &nKeys, &nHome, &nCollisions);

    // Total comparisons calculation
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i].value != -1) {
            int homeIndex = HashFunction(hashTable[i].key, tableSize);
            totalComparisons += (homeIndex == i) ? 1 : abs(homeIndex - i) + 1;
        }
    }

    // Avergae number of comparisons
    double avgComparisons = (double)totalComparisons / nKeys;

    // Output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output);

    outputFile(output, hashTable, tableSize, nWords, nKeys, nHome, nCollisions, avgComparisons);

    free(words);
    free(hashTable);

    return 0;
}


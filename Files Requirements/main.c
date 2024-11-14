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

    fprintf(f, "Number of strings read: %d\n", nRead);

    for(int i = 0; i < nRead; i++){
        if(hashTable[i].value != -1){
            fprintf(f, "%s %d\n", hashTable[i].key, hashTable[i].value);
        }
    }

    fclose(f);
}

void printHashTable(HashTable *hashTable, int n){
    for(int i = 0; i < n; i++){
        if(hashTable[i].value != -1){
            printf("@Key: %s @Value: %d\n", hashTable[i].key, hashTable[i].value);
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
    int nWords, tableSize;
    
    // printf("Enter the name of the file: ");
    // scanf("%s", name);

    nWords = inputFile(name, &words);

    hashTable = createHashTable(words, nWords, &tableSize); 

    HashArray(words, nWords, hashTable, tableSize);
    printHashTable(hashTable, tableSize);
    // printf("Enter the name of the output file: ");
    // scanf("%s", output);

    // outputFile(output, hashTable, nWords, tableSize, nKeys, nHome, nCollisions);

    // free(words);
    // free(hashTable);

    return 0;
}

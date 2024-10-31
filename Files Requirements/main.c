#include "hash.c"

int main() {
    int tableSize = 11; // Example table size
    HashTable hashTable[tableSize];

    // Initialize hash table
    createHashTable(tableSize, (string *)hashTable);

    // Insert elements
    insert(hashTable, tableSize, "key1", 1);
    insert(hashTable, tableSize, "key2", 2);
    insert(hashTable, tableSize, "key3", 3);

    // Search for elements
    int index = search(hashTable, tableSize, "key2");
    if (index != -1) {
        printf("Found key2 at index %d with value %d\n", index, hashTable[index].value);
    } else {
        printf("key2 not found\n");
    }

    // Delete an element
    delete(hashTable, tableSize, "key2");
    index = search(hashTable, tableSize, "key2");
    if (index == -1) {
        printf("key2 successfully deleted\n");
    } else {
        printf("Failed to delete key2\n");
    }

    // Insert more elements to test collision resolution
    insert(hashTable, tableSize, "key4", 4);
    insert(hashTable, tableSize, "key5", 5);

    // Print the hash table
    for (int i = 0; i < tableSize; i++) {
        if (strcmp(hashTable[i].key, "") != 0) {
            printf("Index %d: Key = %s, Value = %d\n", i, hashTable[i].key, hashTable[i].value);
        }
    }

    return 0;
}

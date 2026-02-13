#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

// Structure for hash table
typedef struct {
    int key;
    int value;
    int used;
} Hash;

Hash hashTable[SIZE];

// Simple hash function
int hashFunction(int key) {
    return abs(key) % SIZE;
}

// Insert into hash table
void insert(int key, int value) {
    int index = hashFunction(key);
    
    while (hashTable[index].used) {
        index = (index + 1) % SIZE;  // Linear probing
    }
    
    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].used = 1;
}

// Search in hash table
int search(int key) {
    int index = hashFunction(key);
    
    while (hashTable[index].used) {
        if (hashTable[index].key == key)
            return hashTable[index].value;
        
        index = (index + 1) % SIZE;
    }
    
    return -1;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        int foundIndex = search(complement);

        if (foundIndex != -1) {
            printf("Indices: [%d, %d]\n", foundIndex, i);
            return 0;
        }

        insert(nums[i], i);
    }

    return 0;
}

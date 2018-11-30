//
// Created by Mayna on 11/30/2018.
//

#ifndef PLAGIARISMCATCHER_HASHMAP_H
#define PLAGIARISMCATCHER_HASHMAP_H
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include "HashEntry.h"
using namespace std;
const int TABLE_SIZE = 129;

class HashMap {
private:
    HashEntry **table;

public:
    HashMap() {
        table = new HashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL) {
                HashEntry *prev = NULL;
                HashEntry *entry = table[i];
                while (entry != NULL) {
                    prev = entry;
                    entry = entry->next;
                    delete prev;
                }
            }
            delete[] table;
        }
    }

    /*
     * Hash Function
     */
    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    /*
     * Insert Element at a key
     */
    void Insert(int key, int value) {
        int hash_val = HashFunc(key);
        if (table[hash_val] == NULL)
            table[hash_val] = new HashEntry(key, value);
        else {
            HashEntry *entry = table[hash_val];
            while (entry->next != NULL)
                entry = entry->next;
            if (entry->key == key)
                entry->value = value;
            else
                entry->next = new HashEntry(key, value);
        }
    }

    /*
     * Search Element at a key
     */
    int Find(int key) {
        int hash_val = HashFunc(key);
        if (table[hash_val] == NULL)
            return -1;
        else {
            HashEntry *entry = table[hash_val];
            while (entry != NULL && entry->key != key)
                entry = entry->next;
            if (entry == NULL)
                return -1;
            else
                return entry->value;
        }
    }

    /*
     * Delete Element at a key
     */
    void Delete(int key) {
        int hash_val = HashFunc(key);
        if (table[hash_val] != NULL) {
            HashEntry *entry = table[hash_val];
            HashEntry *prev = NULL;
            while (entry->next != NULL && entry->key != key) {
                prev = entry;
                entry = entry->next;
            }
            if (entry->key == key) {
                if (prev == NULL) {
                    HashEntry *next = entry->next;
                    delete entry;
                    table[hash_val] = next;
                } else {
                    HashEntry *next = entry->next;
                    delete entry;
                    prev->next = next;
                }
            }
        }
    }
};


#endif //PLAGIARISMCATCHER_HASHMAP_H

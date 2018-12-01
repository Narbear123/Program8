//
// Created by Mayna on 11/30/2018.
//

#ifndef PLAGIARISMCATCHER_HASHMAP_H
#define PLAGIARISMCATCHER_HASHMAP_H
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cstdio>
#include <list>
#include<stdio.h>
#include<vector>
#include"HashEntry.h"
using namespace std;

class Hash
{
   // int BUCKET = 128;    // No. of buckets

    // Pointer to an array containing buckets
    std::vector<HashEntry> table;

public:
    Hash();  // Constructor

    // inserts a key into hash table
    void insertItem(string str, int value);

    // deletes a key from hash table
 //   void deleteItem(int key);

    // hash function to map values to key; take string and convert to int index, map to index, value is the document
    int hashFunction(string str) {
        int n = str.length();
        char array[n+1];
        strcpy(array, str.c_str());
        int sum = 0;

        for(int i=0;i<n;i+5){
            sum = sum + array[i];
        }

        return  sum;
    }


    void displayHash();
};

Hash::Hash()
{
 //   this->BUCKET;
   // table = new vector<HashEntry>;
    for (int i=0; i<20000; i++) {
        HashEntry x(0,-1);
        table.push_back(x);
    }

}
// Insert a value (the document index) to the key's index in the hash table
void Hash::insertItem(string str, int value)
{
    int index = hashFunction(str);
   // table[index].push_back(value);
    HashEntry h(index, value);
    if(table[index].value == -1){
        table[index] = h;
    }
    else
    {
        // = table[index];
        HashEntry *temp = new HashEntry;
        temp->value = value;
        temp->next = NULL;
        HashEntry *ptr = table[index];

        while(ptr != NULL){

        }
    }
}


// function to display hash table
void Hash::displayHash() {
    for (int i = 0; i < 20; i++) {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}



#endif //PLAGIARISMCATCHER_HASHMAP_H

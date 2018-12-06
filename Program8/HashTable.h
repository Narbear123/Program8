//
// Created by Naris on 12/1/2018.
//

#ifndef PROGRAM8_HASHTABLE_H
#define PROGRAM8_HASHTABLE_H
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cstdio>
#include <list>
#include<stdio.h>
#include<vector>
#include "HashEntry.h"

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
    int numSim(int x, int y);

    // deletes a key from hash table
    //   void deleteItem(int key);

    // hash function to map values to key; take string and convert to int index, map to index, value is the document
    int hashFunction(string str) {
        //int n = str.size();
        //char array[n];
        //strcpy(array, str.c_str());
        unsigned int sum = 31;

        for(int i=0;i<str.length();i = i+1){
            sum = 31 * sum + str[i];
        }

        return  sum % 700241;
    }


    void displayHash();
};

Hash::Hash()
{
    //   this->BUCKET;
    // table = new vector<HashEntry>;
    for (int i=0; i<700241; i++) {
        HashEntry x(0,-1);
        table.push_back(x);
    }

}
// Insert a value (the document index) to the key's index in the hash table
void Hash::insertItem(string str, int val)
{
    int index = hashFunction(str);
    HashEntry *temp = new HashEntry;
    temp->value = val;
    temp->key = index;
    temp->next = NULL;
    HashEntry h(index, val);
    // table[index].push_back(value);
    //   HashEntry h(index, value);

    if(table[index].value == -1){
        table[index] = h;
    }
    else
    {
        // = table[index];

        HashEntry *ptr;
        //HashEntry *tail = NULL;
        ptr = &table[index];

        while(ptr -> next != NULL){
            //tail = ptr;
            ptr = ptr->next;
        }
        //tail->next = temp;
        ptr -> next = temp;
    }
}
int Hash::numSim(int x, int y){
    int count = 0;
    int flag;
    for(int i = 0; i< 700241; i++) {
        flag = 0;
        if (table[i].value != -1) {
            HashEntry *ptr;
            ptr = &table[i];

            while (ptr != NULL) {
                if (ptr->value == x || ptr->value == y) {
                    flag++;
                }
                ptr = ptr->next;
            }
            if (flag == 2) {
                count++;
            }
        }
    }
    return count;
}



// function to display hash table






#endif //PROGRAM8_HASHTABLE_H

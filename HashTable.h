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
    std::vector<HashEntry> table;

public:
    Hash();  // Constructor

    // inserts a key into hash table
    void insertItem(string str, int value);
    int numSim(int x, int y);
    //large prime number for table size
    const int tableSize = 700241;

    //Function: hashFunction
    // Hash function to map values to key; take string and convert to int index through sum function, return index
    int hashFunction(string str) {

        unsigned int sum = 31; //unique starting sum

        for(int i=0;i<str.length();i = i+1){
            sum = 31 * sum + str[i];
        }

        return  sum % tableSize;
    }

};
// Function: constructor
// creates a table with # of tableSize elements and stores 0 as the key and -1 as the value for each index of the vector
Hash::Hash()
{
    for (int i=0; i<tableSize; i++) {
        HashEntry x(0,-1);
        table.push_back(x);
    }

}
// Function: insertItem
// Inserts a value (the document index) to the key's index in the hash table
void Hash::insertItem(string str, int val)
{
    int index = hashFunction(str);
    HashEntry *temp = new HashEntry;
    temp->value = val;
    temp->key = index;
    temp->next = NULL;
    HashEntry h(index, val);


    // if there is nothing previously entered, put into the first slot
    if(table[index].value == -1){
        table[index] = h;
    }
    else
    {
        HashEntry *ptr;
        ptr = &table[index];

        while(ptr -> next != NULL){
            ptr = ptr->next;
        }
        ptr -> next = temp;
    }
}
//Function: numSim
//counts number of similarities between two indexes x and y
int Hash::numSim(int x, int y){
    int count = 0;
    int flag;
    for(int i = 0; i< tableSize; i++) {
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


#endif //PROGRAM8_HASHTABLE_H
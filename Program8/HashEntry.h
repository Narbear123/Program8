//
// Created by Naris on 12/1/2018.
//

#ifndef PROGRAM8_HASHENTRY_H
#define PROGRAM8_HASHENTRY_H
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

class HashEntry {
public:
    int key;
    int value;
    HashEntry *next;
    HashEntry(){
        int key = 0;
        int value = 0;

    };
    HashEntry(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};
#endif //PROGRAM8_HASHENTRY_H

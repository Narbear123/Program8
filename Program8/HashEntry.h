//
// Created by Mayna on 11/30/2018.
//

#ifndef PLAGIARISMCATCHER_HASHENTRY_H
#define PLAGIARISMCATCHER_HASHENTRY_H
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
    HashEntry(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};


#endif //PLAGIARISMCATCHER_HASHENTRY_H

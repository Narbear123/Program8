#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include "HashTable.h"
#include "HashEntry.h"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}


void checker(vector<vector<string >>& s, int &t, int &o);


vector<string> files;
int main(int argc, char *argv[]) {
    string dir = string(argv[1]);
    int n = atoi(argv[2]);
    int threshold = atoi(argv[3]);

    getdir(dir, files);


    vector<vector<string >> words;
    for (unsigned int i = 0; i < files.size(); i++) {
        vector<string> newC;
        words.push_back(newC);
        fstream file;
        string word, filename;
        filename = dir + files.at(i);
        file.open(filename.c_str());
        int j = 0;
        while (file >> word) {
            // displaying content
            //cout << word << endl;
            words.at(i).push_back(word);
            j++;
        }
    }


    vector<vector<string >> seg;
    for (unsigned int i = 0; i < files.size(); i++) {
        vector<string> row;
        seg.push_back(row);
        string str;
        int sizet = words.at(i).size() - n + 1;
        int x = 0;
        while (x < sizet && sizet > 0){

            str = "";
            for (int a = 0; a < n; a++) {
                str = str + words[i][x + a];
            }
        seg.at(i).push_back(str);
        x = x + 1;
        }

    }
    int mat = seg.size();
    checker(seg, mat, threshold);

    cout << "done \n";
    return 0;
}




void checker(vector<vector<string >>& s, int &t, int &o){
    Hash cheat;
        for(int i = 0; i<s.size(); i++){    //first text
            for(int j = 0; j<s.at(i).size(); j++){
                cheat.insertItem(s.at(i).at(j), i);
            }
        }
        int cou = 0;
        int res[t][t];
        for(int i = 0 ; i < t; i++){
            for(int j = i+1; j < t; j++){
                res[i][j] = cheat.numSim(i,j);
                if(res[i][j]>o){
                    cout << files[i] << " and " << files[j] << " " <<  res[i][j] <<" times\n";
                    cou++;
                }
            }
    }

    cout << cou << "sets \n";



}


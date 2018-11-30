#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

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


bool checker(string x[],string y[], int s){
    for(int i = 0; i < s; i++){
        if(x[i]!= y[i]){
            return false;
        }
    }
    return true;
}


int main() {
    string dir = string("sm_doc_set");
    vector<string> files;
    int n = 6;

    getdir(dir, files);

    for (unsigned int i = 0; i < files.size(); i++) {
        cout << files[i] << endl;
    }

    vector<vector<string >> words;
    for (unsigned int i = 0; i < files.size(); i++) {
        vector<string> newC;
        words.push_back(newC);
        fstream file;
        string word,  filename;
        filename = "sm_doc_set/" + files.at(i);
        file.open(filename.c_str());
        int j = 0;
        while (file >> word) {
            // displaying content
            //cout << word << endl;
            words.at(i).push_back(word);
            j++;
        }
    }


    int f1 = 0;
    int l1 = n;
    int f2 = 0;
    int l2 = n;

    string arr1[n];
    string arr2[n];
    for(int i = 2; i < files.size(); i++) {
        //first txt
        for (int j = i + 1; j < files.size(); j++) { //second txt
            int x = 0;
            int sizef = words.at(i).size() - n + 1;
            int sizes = words.at(j).size() - n + 1;
            while (x < sizef) {
                for (int a = 0; a < n; a++) {     //first 6 words of first txt
                    arr1[a] = words[i][x + a];
                }
                int y = x;
                while (y < sizes) {
                    for (int b = 0; b < n; b++) {     //first 6 words of second txt
                        arr2[b] = words[j][y + b];
                    }
                    if (checker(arr1, arr2, n) == true) {
                        //insert to hash
                    }
                    y++;
                }
                x++;

            }
            int pp =1;

        }
        int yy = 1;
    }






    return 0;
}


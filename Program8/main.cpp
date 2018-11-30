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


    int f = 0;
    int l = n;
    string arr1[n];
    string arr2[n];
    for(int i = 2; i < files.size(); i++){
        for(int j = i + 1; j < files.size(); j++){

            for(int a = 0; a<(l-f); a++){
                arr1[a]= words[i][f + a];
                arr2[a]= words[j][f + a];
            }

        }
    }





    return 0;
}


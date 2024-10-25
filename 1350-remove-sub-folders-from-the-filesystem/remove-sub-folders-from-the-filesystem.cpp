#include <string.h>
#include <stdio.h>
using namespace std;
class Trie {
public:
    unordered_map<string, Trie*> children;
    bool endOfWord = false;

public:
    void add(string s){
        cout << s;
        Trie* curr = this;
        stringstream st(s);
        string t;
        while (getline(st, t, '/')){
            if (!curr->children.contains(t)) curr->children[t] = new Trie();
            curr = curr->children[t];
        }
        curr->endOfWord = true;
    }

    bool prefix(string s){
        Trie* curr = this;
        vector<string> temp;
        stringstream ss(s);
        string t;
        while (getline(ss, t, '/')) temp.push_back(t);
        temp.pop_back();
        for(string sss: temp){
            curr = curr->children[sss];
            if (curr->endOfWord) return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* curr = new Trie();
        vector<string> result;
        for (string temp: folder)
            curr->add(temp);

        for (string temp: folder)
            if(! curr->prefix(temp)) result.push_back(temp);

        return result;
    }

    // vector<string> removeSubfolders(vector<string>& folder) {
    //     vector<string> result;
    //     unordered_set<string> cache;
    //     for (string i: folder) cache.insert(i);
    //     for (string i: folder){
    //         result.push_back(i);
    //         for (int j = 0; j < i.length(); j++){
    //             if (i[j] == '/' && cache.contains(i.substr(0, j))){
    //                 result.pop_back();
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }
};
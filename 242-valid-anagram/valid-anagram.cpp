#include<map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> h_s;
        map<char, int> h_t;
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++){
            if (h_s.count(s[i])){
                h_s[s[i]] = h_s[s[i]] + 1;
            }else{
                h_s[s[i]] = 1;
            }
            if (h_t.count(t[i])){
                h_t[t[i]] = h_t[t[i]] + 1;
            }else{
                h_t[t[i]] = 1;
            }
        }
        for(auto k: h_s){
            if(!h_t.count(k.first) || h_s[k.first] != h_t[k.first]) return false;
        }
        return true;
    }
};
#include<unordered_map>

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length() || t == "") return "";

        unordered_map<char, int> history;
        unordered_map<char, int> windows;

        for(char c: t){
            if (history.contains(c)) history[c] +=1;
            else history[c] = 1;
        }

        int l = 0;
        int having = 0;
        int required = history.size();
        int rl = -1;
        int rr = -1;
        int rlen = INT_MAX;

        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            if (windows.contains(c)) windows[c] +=1;
            else windows[c] = 1;

            if (history.contains(c) && history[c] == windows[c]) having += 1;

            while(having == required){
                if((r-l+1)<rlen){
                    rl = l;
                    rr = r;
                    rlen = (r-l+1);
                }
                c = s[l];
                windows[c] -= 1;
                if (history.contains(c) && windows[c] < history[c]) having -= 1;
                l += 1;
            }
            

        }

        cout << required;
        if (rlen != INT_MAX) return s.substr(rl, (rr+1) - rl);
        else return "";
    }
};
#include<stack>
#include<unordered_map>
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen = {{'}','{'}, {']','['}, {')','('}};
        stack<char> st = {};
        for(char c: s){
            if (closeToOpen.find(c) != closeToOpen.end()){
                if (st.size()!=0 && closeToOpen[c] == st.top()) st.pop();
                else return false;
            }
            else st.push(c);
        }
        if(!st.size()) return true;
        else return false; 
    }
};
#include<stack>
#include<cstring>


class Solution {

public:
    stack<char> s;
    vector<string> result;
    
public:
void backTracking(int o, int c, int n){
        cout << o <<" " << c << "\n";
        if(o == c && c == n){

            stack<char> temp = s;
            string temp1;

            while(!temp.empty()){
                temp1 = temp.top() + temp1;
                temp.pop();
            }
            result.push_back(temp1);
        }
        if(o<n){
            s.push('(');
            backTracking(o + 1, c, n);
            s.pop();
        }
        if(c<o){
            s.push(')');
            backTracking(o, c + 1, n);
            s.pop();
        }
    }
    vector<string> generateParenthesis(int n) {
        backTracking(0, 0, n);
        return result;
    }
};
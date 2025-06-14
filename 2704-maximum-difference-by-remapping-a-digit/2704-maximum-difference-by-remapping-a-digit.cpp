class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxi = s, mini = s;
        for (char c: s){
            if (c != '9'){
                replace(maxi.begin(), maxi.end(), c, '9');
                break;
            }
        }
        replace(mini.begin(), mini.end(), s[0], '0');
        return stoi(maxi) - stoi(mini); 
    }
};
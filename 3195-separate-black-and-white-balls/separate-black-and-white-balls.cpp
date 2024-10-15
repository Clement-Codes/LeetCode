class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;
        long long white = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '0'){
                swaps += i - white;
                white += 1;
            }
        }

        return swaps;
    }
};
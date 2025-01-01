class Solution {
public:
    int maxScore(string s) {
        int zero = 0;
        int one = 0;
        for (char c: s)
            if (c == '1')
                one += 1;
        
        int result = 0;
        
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == '0')
            {
                zero += 1;
            }
            else{
                one -= 1;
            }
            result = max(result, zero + one);
        }

        return result;  
    }
};
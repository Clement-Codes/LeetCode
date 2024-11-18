class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++)
            if (k > 0)
                for (int j = i + 1; j < i + k + 1; j++)
                    result[i] += code[j % n];
            else if (k < 0)
                for (int j = i - 1; j > i - abs(k) -1 ; j--)
                    result[i] += code[(j + n)% n];                    
        return result;
    }
};

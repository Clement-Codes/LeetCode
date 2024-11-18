class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        int l = 0;
        int sum = 0;
        vector<int> result(n, 0);
        for (int r = 0; r < n + abs(k); r++){
            sum += code[r % n];
            if (r - l + 1 > abs(k)){
                sum -= code[l];
                l = (l + 1) % n;
            }

            if (r - l + 1 == abs(k)){
                if (k > 0){
                    result[(l - 1 + n) % n] = sum;
                }
                else if (k < 0){
                    result[(r + 1 + n) % n] = sum;
                }
            }

        }
        return result;

        // Using loops
        // int n = code.size();
        // vector<int> result(n, 0);
        // for (int i = 0; i < n; i++)
        //     if (k > 0)
        //         for (int j = i + 1; j < i + k + 1; j++)
        //             result[i] += code[j % n];
        //     else if (k < 0)
        //         for (int j = i - 1; j > i - abs(k) -1 ; j--)
        //             result[i] += code[(j + n)% n];                    
        // return result;
    }
};

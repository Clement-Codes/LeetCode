class Solution {
public:
    char recurssion(int length, int k){
        if (length == 1) return '0';
        int half = length / 2;
        if (k <= half){
            return recurssion(half, k);
        }
        else if (k > half + 1){
            int res = recurssion(half, 1 + length - k );
            return res == '1' ? '0' : '1';
        }
        else{
            return '1';
        }
    }

    char findKthBit(int n, int k) {
        int length = pow(2, n) - 1;
        return recurssion(length, k);
    }
};
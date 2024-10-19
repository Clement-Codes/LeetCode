class Solution {
public:
    // recursion with variable
    // char recurssion(int length, int k){
    //     if (length == 1) return '0';
    //     int half = length / 2;
    //     if (k <= half){
    //         return recurssion(half, k);
    //     }
    //     else if (k > half + 1){
    //         int res = recurssion(half, 1 + length - k );
    //         return res == '1' ? '0' : '1';
    //     }
    //     else{
    //         return '1';
    //     }
    // }

    // recurssion without variable
    // char recurssion(int length, int k, bool invert){
    //     if (length == 1) return invert == false ? '0' : '1';
    //     int half = length / 2;
    //     if (k <= half) return recurssion(half, k, invert);
    //     else if (k > half + 1) return recurssion(half, 1 + length - k, !invert);
    //     else return invert == false ? '1' : '0';
    // }


    char findKthBit(int n, int k) {
        int length = pow(2, n) - 1;
        // return recurssion(length, k, false);
        // iterative
        bool invert = false;
        while (length > 1){
            int half = length / 2;
            if (k <= half) length = half;
            else if (k > half + 1){
                k = 1 + length - k;
                length = half;
                invert = !invert;
            }
            else return invert == false ? '1' : '0';
        }
        return invert == false ? '0' : '1';
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int add = 1, i = 0;
        while (add > 0){
            if (i < digits.size()){
                if (digits[i] == 9){
                    digits[i] = 0;
                }
                else{
                    digits[i] += add;
                    add = 0;
                }
            }
            else{
                digits.push_back(1);
                add = 0;
            }
            i += 1;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
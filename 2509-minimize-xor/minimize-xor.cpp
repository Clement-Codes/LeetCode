class Solution {
public:

    int countBit(int n)
    {
        int result = 0;
        while (n > 0){
            result += n & 1;
            n = n >> 1;
        }
        return result;
    }

    int minimizeXor(int num1, int num2) {
        int count1 = countBit(num1), count2 = countBit(num2);
        int result = num1;
        int i = 0;
        unsigned long long temp = 1;
        while (count1 != count2)
        {
            if (count1 > count2 && result & (1 << i)){
                result = result ^ (1 << i);
                count1 -= 1;
            }
            else if (count1 < count2 && (int(result & (temp << i)) == 0)){
                result = result ^ (temp << i);
                count1 += 1;
                cout << "hey";
            }
            i += 1;
        }
        return result;
    }
};
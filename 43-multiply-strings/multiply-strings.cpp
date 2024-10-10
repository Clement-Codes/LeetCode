class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int* temp = new int[num1.length() + num2.length()]();

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.length(); i++){
            for (int j = 0; j < num2.length(); j++){
                int k = (num1[i] - '0') * (num2[j] - '0');
                temp[i + j] += k;
                temp[i + j + 1] += temp[i + j] / 10;
                temp[i + j] = temp[i + j] % 10;
            }
        }
        reverse(temp, temp + num1.length() + num2.length());



        int begin = 0;
        while (begin < (num1.length() +  num2.length()) && temp[begin] == 0)
            begin += 1;

        stringstream result;
        for (int i = begin; i < (num1.length() + num2.length()); i++)
            result << temp[i];
        return result.str();
    }
};
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        while(s.length() > 0){
            int skip = 1;
            if (s[0] == 'M'){
                result += 1000;
            }
            else if(s[0] == 'D'){
                result += 500;
            }
            else if(s[0] == 'C'){
                if (s.length() > 1 && s[1] == 'D'){
                    result += 400;
                    skip+=1;
                }
                else if (s.length() > 1 && s[1] == 'M'){
                    result += 900;
                    skip += 1;
                }
                else{
                    result += 100;
                }
            }
            else if (s[0] == 'L'){
                result += 50;
            }
            else if (s[0] == 'X'){
                if (s.length() > 1 && s[1] == 'L'){
                    result += 40;
                    skip += 1;
                }
                else if (s.length() > 1 && s[1] == 'C'){
                    result += 90;
                    skip += 1;
                }
                else{
                    result += 10;
                }
            }
            else if (s[0] == 'V'){
                result += 5;
            }
            else if (s[0] == 'I'){
                if (s.length() > 1 && s[1] == 'V'){
                    result += 4;
                    skip += 1;
                }
                else if (s.length() > 1 && s[1] == 'X'){
                    result += 9;
                    skip += 1;
                }
                else{
                    result += 1;
                }
                    
            }
            s.erase(0, skip);
        }
        return result;
    }
};
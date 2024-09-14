class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> temp;
        while(i<j){
            if(numbers[i] + numbers[j] > target) j-=1;
            else if(numbers[i] + numbers[j] < target) i+=1;
            else{
                temp.push_back(i + 1);
                temp.push_back(j + 1);
                return temp;
            } 
        }
        return temp;
    }
};
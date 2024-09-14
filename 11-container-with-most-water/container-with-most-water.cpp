class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i<j){
            result = max((j - i) * min(height[i], height[j]), result);
            if (height[i] > height[j]) j-=1;
            else i+=1;
        }
        return result;
    }
};
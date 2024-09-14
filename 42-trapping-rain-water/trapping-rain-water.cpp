class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxl = height[l];
        int maxr = height[r];
        int result = 0;
        while(l<r){
            if (height[l] < height[r]){
                l += 1;
                maxl = max(maxl, height[l]);
                result += maxl - height[l];
            }
            else{
                r -= 1;
                maxr = max(maxr, height[r]);
                result += maxr - height[r];
            }
        }
        return result;
    }
};
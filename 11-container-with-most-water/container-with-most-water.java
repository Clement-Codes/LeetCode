class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        int i = 0;
        int j = height.length - 1;
        while(i<j){
            result = Math.max(Math.min(height[i], height[j]) * (j - i), result);
            if (height[i]>height[j]) j-=1;
            else i+=1;
        }
        return result;
    }
}
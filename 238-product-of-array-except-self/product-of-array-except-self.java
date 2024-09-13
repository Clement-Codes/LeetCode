class Solution {
    public int[] productExceptSelf(int[] nums) {
        int product[] = new int[nums.length];
        for(int i = 0; i < nums.length; i++) product[i] = 1;
        int prefix = 1;
        for(int i = 0; i < nums.length; i++){
            product[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for(int i = nums.length - 1; i >=0; i--){
            product[i] *= postfix;
            postfix *= nums[i];
        }
        return product;        
    }
}
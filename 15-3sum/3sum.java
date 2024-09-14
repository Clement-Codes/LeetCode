class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = nums.length - 1;
            while(j<k){
                if(nums[i] + nums[j] + nums[k] > 0) k-=1;
                else if(nums[i] + nums[j] + nums[k] < 0) j+=1;
                else{
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[k]);
                    j += 1;
                    k -= 1;
                    result.add(temp);
                    while (nums[j] == nums[j-1] && j<k) j+= 1;
                }
            }
        }        
        return result;
    }
}
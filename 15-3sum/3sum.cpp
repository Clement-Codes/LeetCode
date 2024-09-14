class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >0) break;
    
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = nums.size() - 1;

            while(j<k){
                if (nums[i] + nums[j] + nums[k] >0) k-=1;
                else if (nums[i] + nums[j] + nums[k] <0) j+=1;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    result.push_back(temp);
                    j +=1;
                    k -=1;
                    while (nums[j] == nums[j-1] && j<k) j+=1;
                }
            } 
        }
        return result;
    }
};
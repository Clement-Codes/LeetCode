#include<map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        vector<int> bucket[nums.size() + 1];
        vector<int> result;

        for(int i: nums){
            if(count.find(i) == count.end()){
                count[i] = 1;
            }
            else{
                count[i] += 1;
            }
            vector<int> temp;
        }
        for(auto kv: count){
            // cout << bucket[kv.second];
            
            //temp.push
            if (bucket[kv.second].size() == 0){
                vector<int> temp;
                temp.push_back(kv.first);
                bucket[kv.second] = temp;
            }else{
                bucket[kv.second].push_back(kv.first);
            }
        } 
        for(int i = nums.size(); i>=0; i--){
            if(bucket[i].size()){
                for(int j: bucket[i]){
                    result.push_back(j);
                }
                if(result.size()==k){
                    break;
                }
            }
        }
        return result;
    }
};
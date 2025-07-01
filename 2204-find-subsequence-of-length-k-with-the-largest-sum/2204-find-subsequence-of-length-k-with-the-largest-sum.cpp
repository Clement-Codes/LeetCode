class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> preserve_position;
        for(int i=0; i<nums.size(); i++){
            preserve_position.push_back({i, nums[i]});
        }
        sort(preserve_position.begin(), preserve_position.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;
        });
        preserve_position.resize(k);
        sort(preserve_position.begin(), preserve_position.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first < b.first;
        });
        vector<int> result;
        for (pair<int,int>& a:  preserve_position)
            result.push_back(a.second);
        return result;
    }
};
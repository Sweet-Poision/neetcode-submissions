class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        vector<vector<int>> bucket(n);
        vector<int> ans;


        for(auto &it: nums) mp[it]++;
        for(auto &it: mp) bucket[n - it.second].push_back(it.first);
        for(auto &it: bucket) {
            if(k == 0) break;
            for(auto &i : it) {
                ans.push_back(i);
                k--;
            }
        }
        return ans;

    }
};

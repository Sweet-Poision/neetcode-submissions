class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int ans = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(s.find(nums[i]-1) != s.end()) continue;
            int len = 0;
            int val = nums[i];
            while(s.find(val++) != s.end()) len++;
            ans = max(len, ans);
        }
        return ans;
    }
};

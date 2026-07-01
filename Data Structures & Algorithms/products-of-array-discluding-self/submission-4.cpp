class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size(); 

        vector<pair<int, int>> dp(n, {1, 1});
        vector<int> ans;

        for(int i = 1; i < n; ++i) {
            dp[i].first *= dp[i-1].first * nums[i-1];
            dp[n-i-1].second *= dp[n-i].second * nums[n-i];
        }

        for(auto &it: dp) {
            ans.push_back(it.first * it.second);
        }

        return ans;

    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        if(n.size() == 0) return 0;
        if(n.size() == 1) return 1;
        set<int> s (n.begin(), n.end());
        vector<int> nums;
        for(auto &it: s) nums.push_back(it);

        int ans = 1, i = 1;
        while(i < nums.size()) {
            if(nums[i] - nums[i-1] != 1) {
                i++;
                continue;
            }
            int len = 1;
            while(i < nums.size() && nums[i] - nums[i-1] == 1) {
                i++;
                len++;
            }
            ans = max(ans , len);
        }

        return ans;
    }
};

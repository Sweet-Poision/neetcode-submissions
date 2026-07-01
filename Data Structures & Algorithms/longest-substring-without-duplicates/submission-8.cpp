class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128, 0);
        int i = 0, j = 0, ans = 0;
        while(j < s.size()) {
            while(v[s[j]] != 0) {
                v[s[i]]--;
                i++;
            }
           
            v[s[j]]++;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

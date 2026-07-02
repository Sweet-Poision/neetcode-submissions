class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, ans = 0, r = 0, current_max = 0;
        vector<int> v(26, 0);
        while(j < s.size()) {
            v[s[j]-'A']++;
            current_max = max(v[s[j]-'A'], current_max);
            r = (j - i + 1) - current_max;
            if(r > k) {
                v[s[i++]-'A']--;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

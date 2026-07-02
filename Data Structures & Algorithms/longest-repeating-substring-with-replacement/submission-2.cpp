class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int> v(26, 0);
        for(int i = 0, j = 0, cm = 0; j < s.size(); j++) {
            v[s[j]-'A']++;
            cm = max(v[s[j]-'A'], cm);
            if((j - i + 1) - cm > k) v[s[i++]-'A']--;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

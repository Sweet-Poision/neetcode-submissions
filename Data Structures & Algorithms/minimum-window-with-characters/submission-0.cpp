class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int> a(128, 0), b(128, 0);
        for(auto &it: t) a[it]++;
        int m = 0, ans = INT_MAX, init = 0;
        for(int i = 0, j = 0; j < s.size(); ++j) {
            m += (b[s[j]]++ < a[s[j]]);
            while(m == t.size()) {
                if(j - i + 1 < ans ) {
                ans = j - i + 1;
                init = i;
            }
                m -= (b[s[i]]-- <= a[s[i]]);
                i++;
            }
            
        }
        return (ans==INT_MAX)?"":s.substr(init, ans);
    }
};

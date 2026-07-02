class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int matches = 0;
        vector<int> a(128, 0), b(128, 0);
        for(auto &it: s1) a[it]++;
        for(int i = 0; i < s1.size(); ++i) {
            if(a[s2[i]] > b[s2[i]]) matches++;
            b[s2[i]]++;
        }
        if(matches == s1.size()) return true;
        for(int i = 0, j = s1.size(); j < s2.size(); ++i, ++j) {
            if(a[s2[j]] > b[s2[j]]) matches++;
            b[s2[j]]++;
            if(a[s2[i]] >= b[s2[i]]) matches--;
            b[s2[i]]--;
            if(matches == s1.size()) return true;
        }
        return false;
    }
};

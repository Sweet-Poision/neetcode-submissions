class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> a(128, 0), b(128, 0);
        for(auto &it: s1) a[it]++;
        for(int i = 0; i < s1.size(); ++i) {
            b[s2[i]]++;
        }
        if(a == b) return true;
        for(int i = 0, j = s1.size(); j < s2.size(); ++i, ++j) {
            b[s2[j]]++;
            b[s2[i]]--;
            if(a == b) return true;
        }
        return false;
    }
};

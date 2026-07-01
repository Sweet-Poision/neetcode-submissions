class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        string n = "00000000000000000000000000", w = "00000000000000000000000000";
        
        for(auto &it: s1) n[it-'a']++;

        for(int i = 0; i < s2.size(); ++i) {
            w[s2[i]-'a']++;
            if (i >= s1.size()) w[s2[i-s1.size()] - 'a']--;
            if(w==n) return true;
        } 
        return false;
    }
};


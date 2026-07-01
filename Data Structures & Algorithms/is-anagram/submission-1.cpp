class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26);
        for(char &it: s) v[it-'a']++;
        for(char &it: t) v[it-'a']--;
        for(int &x: v) if(x) return false;
        return true;
    }
};

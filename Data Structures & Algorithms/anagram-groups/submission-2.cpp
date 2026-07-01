class Solution {
public:
    struct ArrayHasher {
        size_t operator()(const array<int, 26>& a) const {
            size_t h = 0;
            for (int e : a) {
                h ^= hash<int>()(e) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHasher> mp;
        for(auto &it: strs) {
            array<int, 26> v = {0};
            for(auto &i: it) v[i-'a']++;
            mp[v].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto &it: mp) ans.push_back(it.second);
        return ans;
    }
};

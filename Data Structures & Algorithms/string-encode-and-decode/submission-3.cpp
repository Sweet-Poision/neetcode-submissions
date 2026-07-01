class Solution {
public:

    string encode(vector<string>& strs) {
        string joiner = "{/}{/}";
        string ans = "";
        for(auto &it: strs) ans += (it + joiner);
        return ans;
    }

    vector<string> decode(string s) {
        string joiner = "{/}{/}";
        vector<string> ans;
        string temp = "";
        int match_count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == joiner[match_count]) {
                match_count++;
            }
            temp += s[i];
            if(match_count == 6) {
                ans.push_back(temp.substr(0, temp.size()-6));
                temp = "";
                match_count = 0;
            }
        }
        return ans;
    }
};

class TimeMap {

private:
    unordered_map<string, vector<pair<int, string>>> mp; 

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) { 
        if(mp.find(key) == mp.end()) return "";
        string ans = "";
        int l = 0, r = mp[key].size()-1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            int value = mp[key][mid].first;
            if(timestamp == value) return mp[key][mid].second;
            else if(timestamp > value) {
                ans = mp[key][mid].second;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> s;
        vector<pair<int, int>> v;
        for(int i = 0; i < position.size(); ++i) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); ++i) {
            double time = (double)(target - v[i].first) / v[i].second;
            while(!s.empty() && s.top() <= time) {
                s.pop();
            }
            s.push(time);
        }
        return s.size();
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<pair<int, int>> s;
        int ans = 0;
        for(int i = 0; i < heights.size(); ++i) {
            int p = i;
            while(!s.empty() && heights[i] <= s.top().first ) {
                ans = max(ans, (i - s.top().second)  * s.top().first);
                p = s.top().second;
                s.pop();
            }
            s.push({heights[i], p});
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int seen = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > seen) ans = max(ans, prices[i]-seen);
            else if(prices[i] < seen) seen = prices[i];
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& h) {
        int prevH = 0, lastH = 0;
        int i = 0, j = h.size() - 1;
        int ans = 0;
        
        while(i <= j) {
            int nextPrevH = max(prevH, h[i]);
            int nextLastH = max(lastH, h[j]);
            if(min(nextPrevH, nextLastH) > min(prevH, lastH)) {
                ans -= min(prevH, lastH) * (j - i + 1);
                ans += min(nextPrevH, nextLastH) * (j - i + 1);
            }

            if(h[i] <= h[j]) {
                ans -= h[i];
                prevH = nextPrevH;
                lastH = nextLastH;
                i++;
            }
            else {
                ans -= h[j];
                prevH = nextPrevH;
                lastH = nextLastH;
                j--;
            }
        }
        return ans;
    }
};
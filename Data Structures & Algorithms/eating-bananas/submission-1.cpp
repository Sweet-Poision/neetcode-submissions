class Solution {
public:

    bool checkAbility(vector<int> & piles, int max, int total) {
        long long h = 0;
        for(int &b: piles) {
            h += ceil(b / (double)max);
        }
        return h <= total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = (*max_element(piles.begin(), piles.end()));
        while(l < r) {
            int mid = l + (r-l)/ 2;
            bool canEat = checkAbility(piles, mid, h);
            if(canEat) {
                r = mid ;
            }
            else l = mid + 1;
        }
        return l;
    }
};

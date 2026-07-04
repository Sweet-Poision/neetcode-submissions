class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        bool isOdd = (m+n) & 1;
        int tL = (m + n + 1)/2;
        int l = 0, r = m;
        while(l <= r) {
            int p = l + (r - l)/2;

            int al = (p == 0) ? INT_MIN : nums1[p-1];
            int ar = (p == m) ? INT_MAX : nums1[p];
            int bl = (tL-p == 0) ? INT_MIN : nums2[tL-p-1];
            int br = (tL-p == n) ? INT_MAX : nums2[tL-p];

            if(al <= br && bl <= ar) {
                if(isOdd) return max(al, bl);
                return (max(al, bl) + min(ar, br)) / 2.0;
            }
            else if(al > br) r = p - 1;
            else l = p + 1;
        }
        return -1;
    }
};

class Solution {
public:

    int binary_search(vector<int> & nums, int l, int r, int k) {
        if(l > r) return -1;
        int mid = l + (r - l) / 2;
        if(nums[mid] == k) return mid;
        if(nums[mid] > k) return binary_search(nums, l, mid-1, k);
        return binary_search(nums, mid+1, r, k);
    }

    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);
    }
};

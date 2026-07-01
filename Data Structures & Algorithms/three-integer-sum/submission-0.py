class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        pairs = []
        nums = sorted(nums)
        for i, num in enumerate(nums):
            left = i+1
            right = len(nums) - 1
            rem = 0 - num
            while(left < right):
                if (nums[left] + nums[right] > rem):
                    right -= 1
                elif (nums[left] + nums[right] < rem):
                    left += 1
                else:
                    pairs.append(sorted([nums[i], nums[left], nums[right]]))
                    left += 1
                    right -= 1

        unique_lists = [list(x) for x in set(tuple(l) for l in pairs)]
        return unique_lists

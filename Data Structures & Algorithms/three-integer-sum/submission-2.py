class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        pairs = []
        nums = sorted(nums)
        for i, num in enumerate(nums):
            if (i >= 1 ) and nums[i] == nums[i-1]:
                continue
            left = i+1
            right = len(nums) - 1
            rem = 0 - num
            leftpass = False
            rightpass = False
            while(left < right):
                if leftpass == True and (nums[left] == nums[left-1]):
                    left += 1
                    continue
                if rightpass == True and (nums[right] == nums[right + 1]):
                    right -= 1
                    continue 
                if (nums[left] + nums[right] > rem):
                    right -= 1
                    rightpass = True
                elif (nums[left] + nums[right] < rem):
                    left += 1
                    leftpass = True
                else:
                    pairs.append(sorted([nums[i], nums[left], nums[right]]))
                    left += 1
                    right -= 1
                    leftpass = True
                    rightpass = True

        # unique_lists = [list(x) for x in set(tuple(l) for l in pairs)]
        return pairs

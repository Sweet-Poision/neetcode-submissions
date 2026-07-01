class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        freq = []
        for num in nums:
            if num in freq:
                return True
            freq.append(num)

        return False

        
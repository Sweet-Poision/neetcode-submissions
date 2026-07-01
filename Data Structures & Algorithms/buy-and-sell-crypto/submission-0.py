class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        current = 0
        left = 0
        right = 1
        while( left < right and left < len(prices) and right < len(prices)):
            current = max(current, prices[right]-prices[left])
            if(prices[right] < prices[left]):
                left = right
                right = left + 1
            else:
                right += 1
        return current
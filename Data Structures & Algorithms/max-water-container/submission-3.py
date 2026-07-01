class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) -1 
        ans = 0
        while(left < right) :
            ans = max(ans, 
                abs(right-left) * int(min(heights[left], heights[right])))
            if(heights[left] >= heights[right]):
                right -= 1
            else:
                left += 1
                
        return ans
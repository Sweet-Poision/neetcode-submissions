class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        keys = defaultdict(int)
        if s == '':
            return 0
        ans = 1
        left, right = 0, 0
        while (left < len(s) and right < len(s)):
            if s[right] in keys:
                ans = max(ans, right-left)
                keys.pop(s[left], None)
                left += 1
            else:
                keys[s[right]] = right
                right += 1

        ans = max(ans, right - left)
        return ans
            
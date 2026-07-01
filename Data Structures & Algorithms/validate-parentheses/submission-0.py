class Solution:
    def isValid(self, s: str) -> bool:
        open_lst = {')':'(', '}':'{', ']':'['}
        stack = deque()
        for c in s:
            if len(stack) != 0 and c in open_lst and stack[-1] == open_lst[c]:
                stack.pop()
            else:
                stack.append(c)
        if len(stack) == 0:
            return True
        return False
                
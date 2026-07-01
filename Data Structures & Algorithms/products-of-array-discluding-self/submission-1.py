class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        list_num = []
        zeros = nums.count(0)
        if zeros > 1:
            return list(0 for _ in range(len(nums)))
        product = 1
        product_actual = 1
        for num in nums:
            product_actual *= num
            if num != 0:
                product *= num
        for num in nums:
            if num != 0:
                list_num.append(int(product_actual/num))
            else:
                list_num.append(int(product))
        return list_num
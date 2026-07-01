class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mylist = defaultdict(int)
        for num in nums:
            mylist[num] += 1

        sorted_my_list = sorted(mylist, key = mylist.get, reverse = True)
        return sorted_my_list[:k]
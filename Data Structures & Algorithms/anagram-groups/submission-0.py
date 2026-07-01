class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mylist = defaultdict(list)
        for str in strs:
            mylist[''.join(sorted(str))].append(str)
        list2= []
        for item in mylist.values():
            list2.append(item)

        return list2

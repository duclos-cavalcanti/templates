import ipdb

class Solution(object):
    def containsDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # ipdb.set_trace()
        before = len(nums)
        prev = []
        for i,n in enumerate(nums):
            if n in prev: 
                nums.pop(i)
            else:
                prev.append(n)
        after = len(nums)
        return not (after == before)


if __name__ == "__main__":
    ipdb.set_trace()
    input =[1, 2, 3, 4] 
    s = Solution()
    s.containsDuplicates(input)

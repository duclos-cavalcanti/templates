import ipdb

def inc(val):
    return val + 1

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ipdb.set_trace()
        prev = -101
        i = 0
        for n in nums:
            if n == prev:
                del nums[i]
            else:
                prev = n
            i = i + 1
        return len(nums)


if __name__ == "__main__":
    s = Solution()

    nums = [0,0,1,1,1,2,2,3,3,4]
    print("IN: \t[ ", end='')
    for n in nums:
        print(f"{n} ", end='')
    print("]")

    ret = s.removeDuplicates(nums)

    print(f"RET:\t {ret}")
    print("OUT: \t[ ", end='')
    for n in nums:
        print(f"{n} ", end='')
    print("]")

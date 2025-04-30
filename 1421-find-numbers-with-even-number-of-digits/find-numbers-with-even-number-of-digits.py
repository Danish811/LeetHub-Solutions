class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        cnt = 0
        for i in nums:
            if floor(log10(i))&1:
                cnt+=1

        return cnt
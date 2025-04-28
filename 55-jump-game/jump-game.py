class Solution:
    def canJump(self, nums: List[int]) -> bool:
        reach = [False]*len(nums)
        reach[0] = True
        n = len(nums)
        for i in range(len(nums)):
            if not reach[i]:
                continue
            jump = nums[i]
            for j in range(i, min(n, i+jump+1)):
                reach[j] = True
                if reach[-1] == True:
                    return True

        return False
        

            
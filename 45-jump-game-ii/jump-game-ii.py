class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = [float(inf)]*n
        cnt[0] = 0
        for i in range(n):
            for j in range(nums[i]+1):
                if i+j < n:
                    cnt[i+j] = min(cnt[i+j], cnt[i]+1)
        return cnt[-1]
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        maxi = 0
        Count = dict()
        for i in nums:
            maxi = max(maxi, i)
            Count[i] = 0
        
        Ans = 0
        i=0
        while i < n and Count[maxi] < k:
            Count[nums[i]]+=1
            i+=1
        
        if Count[maxi]<k:
            return 0
        
        Ans += n-i+1
        for j in range(0,n):
            Count[nums[j]] -= 1
            while i<n and Count[maxi] < k:
                Count[nums[i]]+=1
                i+=1
            
            if Count[maxi]>=k:
                Ans += n-i+1
        
        return Ans



        
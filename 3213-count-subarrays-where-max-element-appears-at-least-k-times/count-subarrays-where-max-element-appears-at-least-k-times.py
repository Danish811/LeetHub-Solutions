class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        maxi = 0
        maxCount = 0
        for i in nums:
            maxi = max(maxi, i)
        
        Ans = 0
        i=0
        while i < n and maxCount < k:
            if nums[i] == maxi:
                maxCount+=1
            i+=1
        
        if maxCount<k:
            return 0
        
        Ans += n-i+1
        for j in range(0,n):
            if nums[j] == maxi:
                maxCount -= 1
            while i<n and maxCount < k:
                if nums[i] == maxi:
                    maxCount += 1
                i+=1
            
            if maxCount>=k:
                Ans += n-i+1
        
        return Ans



        
class Solution:
    def binarysearch(self, pref, rem, k, left):
        l = left
        r = len(pref)-1
        A = -1
        while(l <= r):
            mid = (l+r)//2
            if (pref[mid]-rem) * (mid-left+1) < k:
                A = mid
                l = mid+1
            else:
                r = mid-1
        
        return A
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
    
        pref = [0]*n
        pref[0] = nums[0]
        for i in range(1,n):
            pref[i] = pref[i-1] + nums[i]
        
        rem = 0
        left = 0
        right = n-1
        ans = 0
        while left < n:
            right = self.binarysearch(pref, rem, k, left)
            print(left, " " , right)
            if right!=-1:
                ans += right - left + 1
            
            rem += nums[left]
            left+=1
        
        return ans

        
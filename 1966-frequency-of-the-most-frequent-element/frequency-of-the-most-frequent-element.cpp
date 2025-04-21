class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int l=0,r=0;
        long long sum=0;
        int maxlen=0;
        while( r < nums.size()){
            sum += nums[r];

            while(l<r && 1LL*nums[r]*(r-l+1) > sum+k){
                sum -= nums[l];
                l++;
            }

            
                maxlen = max(maxlen, r-l+1);
                r++;
        }
        return maxlen;
    }
};
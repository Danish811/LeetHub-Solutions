class Solution {
public:
    int sum;
    bool half(vector<int>&nums, int i,int S,vector<vector<int>> &dp){
        if(2*S == sum) return true;
        if(S > sum) return false;
        if(i>=nums.size()) return false;
        if(dp[i][S] != -1) return dp[i][S];
        bool A = half(nums, i+1, S, dp);
        bool B = half(nums, i+1, S+nums[i], dp);
        return dp[i][S] = A || B;
    }
    bool canPartition(vector<int>& nums) {
        sum = 0;
        for(auto num : nums){
            sum += num;
        }
        vector<vector<int>> dp(nums.size(), vector<int> (sum+1, -1));
        if(sum&1) return false;
        return half(nums,0,0, dp);
    }
};
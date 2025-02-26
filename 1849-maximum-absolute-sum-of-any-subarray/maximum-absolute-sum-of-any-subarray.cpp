class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int maxsum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] < 0) {
                sum = 0;
                continue;
            }
            sum += nums[i];
            maxsum = max(maxsum , sum);
        }
        sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] > 0){
                sum = 0;
                continue;
            }
            sum += nums[i];
            maxsum = max(-sum , maxsum);
        }
        return maxsum;
    }
};
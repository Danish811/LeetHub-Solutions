
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> SumCnt;
        SumCnt[0] = 1; 
        int sum = 0;
        int count = 0;
        
        for (int num : nums) {
            sum += num;
            if (SumCnt.find(sum - k) != SumCnt.end()) {
                count += SumCnt[sum - k];
            }
            SumCnt[sum]++;
        }
        
        return count;
    }
};
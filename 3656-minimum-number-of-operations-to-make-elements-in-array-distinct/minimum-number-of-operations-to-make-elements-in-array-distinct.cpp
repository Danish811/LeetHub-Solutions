class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int> M;
        for(auto num: nums){
            M[num]++;
        }
        int k = 0;
        int cnt = 0;
        for(auto num: nums){
            while(M[num] > 1 && k<nums.size()){
                cnt++;
                M[nums[k]]--;
                k++;
                if(k >= nums.size()) break;
                M[nums[k]]--;
                k++;
                if(k >= nums.size()) break;
                M[nums[k]]--;
                k++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    bool check(vector<int>& nums) {
        int swich = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1] < nums[i]) swich--;
            if(swich < 0) return false;
        }
        if(swich == 0 && nums.back() > nums.front()) return false;
        return true;
    }
};
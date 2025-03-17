class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int key = nums[0];
        for(int i=0; i<nums.size(); i++){
            count += (key == nums[i])? 1 : -1;
            if(count<=0){
                key = nums[i];
                count = 1;
            }
        }
        return key;
    }
};
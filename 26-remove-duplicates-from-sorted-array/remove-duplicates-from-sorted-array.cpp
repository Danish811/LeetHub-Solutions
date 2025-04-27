class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int k=0;
       while(i < nums.size() && k < nums.size()){
          nums[i] = nums[k];
          while(k<nums.size() && nums[i] == nums[k]) k++;
           i++;
       }
       return i;
    }
};
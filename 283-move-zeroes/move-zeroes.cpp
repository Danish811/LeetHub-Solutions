class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int idx= 0;
        
        while(idx < nums.size()){
           if(nums[idx] != 0) {
              swap(nums[idx],nums[i]);
              i++;   
           }
           idx++;
        }
        
    }
};
class Solution {
public:
    int X;
    void func(vector<int> &nums, int i, int Xor){
        if(i == nums.size()) return;
        func(nums,i+1, Xor);
     //   X += Xor;
        Xor ^= nums[i];
        func(nums,i+1,Xor);
        X += Xor;
    }
    int subsetXORSum(vector<int>& nums) {
        X = 0;
        func(nums,0,0);
        return X;
    }
};
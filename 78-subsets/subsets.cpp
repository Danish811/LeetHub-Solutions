class Solution {
public:
    void Rec(vector<int>& nums, vector<int> Arr, vector<vector<int>> &Res, int i){
        if(i==nums.size()) {
             Res.push_back(Arr);
             return;
        }
        Arr.push_back(nums[i]);
       
        Rec(nums,Arr,Res,i+1);
        Arr.pop_back();
        Rec(nums,Arr,Res,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> Res;
        vector<int> Arr;
        Rec(nums, Arr, Res, 0);
        return Res;
    }
};
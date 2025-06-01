class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        vector<pair<long long, int>> DP(nums.size(), {0,0});
        for(int i=0; i<nums.size(); i++){
            DP[i] = {nums[i], 1<<i};
        }
        int Mask = 0;
        for(int i=0; i<nums.size(); i++){
            int j=0;
            int S = DP.size();
            while(j<DP.size()){
                if(i == j) {j++; continue;}
                if(DP[j].second & 1<<i) {j++; continue;}
               if (DP[j].first > target || nums[i] > target || DP[j].first > target / nums[i]){j++; continue;}
                 long long newProduct = DP[j].first * nums[i];
                DP.push_back({newProduct, DP[j].second | (1 << i)});

                if(DP.back().first == target){
                    Mask = DP.back().second;
                    break;
                }
                j++;
            }
        }
        long long Alt = 1;
        if(Mask == 0) return false;
        for(int i=0; i<nums.size(); i++){
            if(!(Mask & 1<<i)){
                Alt *= nums[i];
            }
        }
        if(Alt == target) return true;
        return false;
      
    }
};
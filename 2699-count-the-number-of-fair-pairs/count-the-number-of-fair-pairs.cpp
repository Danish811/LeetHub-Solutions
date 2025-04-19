class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int l = 0;
        int r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        int Low=l+1;
        while(l < r){
            Low=l+1;
            while(r>l && nums[l] + nums[r] > upper) r--;
             
            if(nums[l] + nums[r] >= lower && nums[l] + nums[r] <= upper){
                cout << nums[l] << " " << nums[r] << endl;
                while(Low<r && nums[Low] + nums[l] < lower) Low++;
                cnt += r-Low+1;
            }
            l++;
        }
        return cnt;
    }
};
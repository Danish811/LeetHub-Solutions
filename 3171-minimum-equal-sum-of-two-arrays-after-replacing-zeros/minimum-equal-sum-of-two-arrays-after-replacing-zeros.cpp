class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1 = 0, sum1 =0;
        for(auto &ele : nums1){
            if(ele == 0) z1 += 1;
            else sum1 += ele;
        }
        long long z2 = 0,sum2=0;
        for(auto &ele : nums2){
            if(ele == 0) z2++;
            else sum2 += ele;
        }
        if(sum2 < sum1+z1 && z2==0) return -1;
        if(sum2+z2 > sum1 && z1==0) return -1;
        return max(sum1+z1, sum2+z2);
    }
};
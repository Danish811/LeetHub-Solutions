class Solution {
public:
    const int mod = 1e9 + 7;
     
    long long Expo(int x){
        long long Res= 1;
        long long key=2;
        while(x>0){
            if(x%2==0) {
                key*=key;
                key%=mod;
                x/=2;
            }
            else{
            Res = (Res*key)%mod;
            x--;
            }
        }
        return Res%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        int L = 0,  R = nums.size()-1;
        sort(nums.begin(),nums.end());
        long long ans =0;
        while(L<=R){
            if(nums[L] + nums[R] > target) R--;
            else{
                int x = R-L;
                ans += Expo(x);
                ans%=mod;
                L++;
            }
        }
        return ans;
    }
};
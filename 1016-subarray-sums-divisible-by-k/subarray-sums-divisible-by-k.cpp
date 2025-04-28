class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> Rem;
        int n = nums.size();
        int sum = 0;
        int cnt =0;
        Rem[0] = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(Rem.find((sum%k + k) % k) != Rem.end()){
                cnt += Rem[((sum%k) + k) % k];
            }
            Rem[(sum%k + k) % k]++;
        }
        return cnt;
    }
};
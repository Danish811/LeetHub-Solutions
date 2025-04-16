class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        int n = nums.size();
        long long ans =0 ;
        map<int,int> M;
         long long pairs=0;
         
         int idx=-1;
         
         for(int j=0; j<n; j++){
             pairs += M[nums[j]];
             M[nums[j]]++;
             if(pairs>=k) {idx = j;break;}
          }
          if(idx != -1) {
            ans +=  n-idx;
            cout << "initial : " << ans << endl;
            int i;
          for(i=0; i<n-1; i++){
              M[nums[i]]--;
              pairs -= M[nums[i]];
              while(idx<n-1 && pairs < k){
                 idx++;
                 pairs += M[nums[idx]];
                 M[nums[idx]]++;
              }
              if(pairs>=k) ans += n - idx;
            //   else break;
              }
          }
          
        return ans;
    }

};
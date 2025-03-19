class Solution {
public:
    vector<int> countBits(int n) {
       int pow = 0;
       vector<int> Res(n+2,0);
       Res[0] = 0;
       Res[1] = 1;
       for(int i=1; i<=n/2; i++){
           Res[i*2] = Res[i];
           Res[i*2 + 1] = Res[i] + 1;
       }
        Res.pop_back();
       return Res;
    }
};
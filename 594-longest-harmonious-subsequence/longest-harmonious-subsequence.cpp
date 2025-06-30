class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> M;
        for(auto &i: nums){
            M[i]++;
        }
       
        int cnt =0;
        for(auto &i: M){
           if(M.find(i.first - 1) != M.end()){
              cnt = max(cnt, i.second + M[i.first - 1]);
           }
        }
        
        
        return cnt;
    }
};
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> M;
        int ans = 0;
        for(int  num : answers){
            if(num == 0){
                ans++;
                continue;
            }
            M[num]++;
        }
       
        for(auto num : M){
            while(num.second > 0){
                ans += num.first + 1;
                num.second -= (num.first+1); 
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<set<int>, int> M;
        for(int i=0; i<dominoes.size(); i++){
            set<int> temp(dominoes[i].begin(), dominoes[i].end());
            M[temp]++;
        }
        int cnt =0 ;
        for(auto ele: M){
            cnt += (ele.second*(ele.second-1))/2;
        }
        return cnt;
    }
};
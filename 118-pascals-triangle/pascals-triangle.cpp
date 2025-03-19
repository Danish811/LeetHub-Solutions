class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Res;
        Res.emplace_back();
        Res[0].push_back(1);
        for(int i=1; i<numRows; i++){
            Res.emplace_back();
            Res[i].push_back(1);
            for(int j=1; j<=i; j++){
                int res = Res[i-1][j-1];
                if(j<i) res += Res[i-1][j];
                Res[i].push_back(res);
            }
        }
        return Res;
    }
};
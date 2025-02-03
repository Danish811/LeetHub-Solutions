class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<vector<int>> pref(wall.size());
        for(int i=0; i<wall.size(); i++){
            pref[i].resize(wall[i].size());
            pref[i][0] = wall[i][0];
            for(int j=1; j<wall[i].size(); j++){
                pref[i][j] = wall[i][j] + pref[i][j-1];
            }
        }
        int cnt = INT_MAX;
        map<int,int> M;
        int maxi = 0;
        for(int i=0; i<wall.size(); i++){
            for(int j=0; j<wall[i].size()-1; j++){
                M[pref[i][j]]++;
                maxi = max(maxi,M[pref[i][j]]);
            }
            cnt = min(cnt, (int)wall.size() - maxi);
        }
        return cnt;
    }
};
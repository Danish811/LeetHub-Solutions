class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
       
        for(int i=0; i<wall.size(); i++){
            for(int j=1; j<wall[i].size(); j++){
                wall[i][j] += wall[i][j-1];
            }
        }

        map<int,int> M;
        int maxi = 0;
        for(int i=0; i<wall.size(); i++){
            for(int j=0; j<wall[i].size()-1; j++){
                M[wall[i][j]]++;
                maxi = max(maxi,M[wall[i][j]]);
            }
        }
        return wall.size() - maxi;
    }
};
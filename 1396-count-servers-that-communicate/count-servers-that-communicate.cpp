class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map<int,int> rows;
        map<int,int> cols;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    if(rows[i] > 1 || cols[j]>1) cnt++;
                }
            }
        }
        return cnt;
    }
};
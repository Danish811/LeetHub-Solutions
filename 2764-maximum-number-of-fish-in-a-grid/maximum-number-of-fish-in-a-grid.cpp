class Solution {
public:
    int n,m;
    vector<vector<int>> Visi;
    int BFS(vector<vector<int>> &grid, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(grid[i][j] == 0) return 0;
        if(Visi[i][j]) return 0;
        Visi[i][j] = true;
        int cnt = grid[i][j];
        cnt += BFS(grid,i-1,j);
        cnt += BFS(grid,i+1,j);
        cnt += BFS(grid,i,j+1);
        cnt += BFS(grid,i,j-1);
        return cnt;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        Visi.resize(n);
        for(auto &v: Visi){
            v.resize(m);
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!Visi[i][j] && grid[i][j]!=0){
                    maxi = max(maxi, BFS(grid,i,j));
                }
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int n,m;
    int DFS(vector<vector<int>> &grid, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(grid[i][j] == 0) return 0;
       
        int cnt = grid[i][j];
        grid[i][j] = 0;
        cnt += DFS(grid,i-1,j);
        cnt += DFS(grid,i+1,j);
        cnt += DFS(grid,i,j+1);
        cnt += DFS(grid,i,j-1);
        return cnt;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
      
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( grid[i][j]!=0){
                    maxi = max(maxi, DFS(grid,i,j));
                }
            }
        }
        return maxi;
    }
};
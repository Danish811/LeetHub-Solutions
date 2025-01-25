class Solution {
public:
    int n,m;
    const int INF = 10;
    vector<vector<int>> time;
    void dfs(vector<vector<int>> &grid, int i, int j,int distance){
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j] == 0) return; 
        if(grid[i][j] == 2 && distance>0) return;
        if(distance > time[i][j]) return;
        
        time[i][j] = distance;

        dfs(grid,i+1,j,distance+1);
        dfs(grid,i-1,j,distance+1);
        dfs(grid,i,j+1,distance+1);
        dfs(grid,i,j-1,distance+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
         time.resize(n);
        for(auto &t: time){
            t.assign(m,INT_MAX);
        }
        int Min = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) dfs(grid,i,j,0); 
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) continue;
                Min = max(Min, time[i][j]);
            }
        }
        if(Min == INT_MAX) return -1;
        return Min;
    }
};
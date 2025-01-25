class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n= board.size();
        int m = board[0].size();
        int cnt =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='X'){
                    queue<pair<int,int>> Q;
                    Q.push({i,j});
                    board[i][j] = ' ';
                    cnt++;

                    while(!Q.empty()){
                        auto [row,col] = Q.front();
                        Q.pop();
                        if(row > 0 && board[row-1][col] == 'X'){
                            Q.push({row-1, col});
                            board[row-1][col] = ' ';
                        }
                        if(row < n-1 && board[row+1][col] == 'X'){
                            Q.push({row+1, col});
                            board[row+1][col] = ' ';
                        }
                        if(col < m-1 && board[row][col+1] == 'X'){
                            Q.push({row, col+1});
                            board[row][col+1] = ' ';
                        }
                        if(col > 0 && board[row][col-1] == 'X'){
                            Q.push({row, col-1});
                            board[row][col-1] = ' ';
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
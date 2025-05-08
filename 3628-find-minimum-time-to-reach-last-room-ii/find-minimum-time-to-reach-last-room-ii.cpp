class Solution {
public:
typedef pair<int,pair<int,int>> P;
int n,m;
int ValidPos(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    return 1;
}
    vector<vector<int>> dirs = {
       {-1, 0}, {0, -1}, {0, 1}, {1, 0}
    };
    int minTimeToReach(vector<vector<int>>& moveTime) {
         n = moveTime.size();
         m = moveTime[0].size();
        int wait = 0;
        vector<vector<int>> result(n, vector<int>(m,INT_MAX));
        result[0][0] = 0;
        priority_queue<P, vector<P>, greater<P>> PQ;
        PQ.push({0, {0,0}});
        while(!PQ.empty()){
            int currtime = PQ.top().first;
            pair<int,int> ij = PQ.top().second;
            int i = ij.first;
            int j= ij.second;
            if(i == n-1 && j==m-1) return currtime;
            PQ.pop();
            for (auto &dir: dirs){
                int i_  = i+dir[0];
                int j_ =  j+dir[1];
                if(ValidPos(i_,j_)){
                    if((i_+j_)%2==0) wait=2;
                    else wait = 1;
                    int arrTime = max(currtime,  moveTime[i_][j_]) + wait;
                    if(arrTime < result[i_][j_]){
                        result[i_][j_] = arrTime;
                        PQ.push({arrTime, {i_,j_}});
                    }
                    
                }
            }
        }
         return -1;
    }
};
class Solution {
public:
    vector<bool> Vis;
    vector<int> Res;
    void DFS(int node, vector<vector<int>> &List){
        if(Vis[node]) return;
        Res.push_back(node);
        Vis[node] = true;

        for(auto child: List[node]){
            DFS(child,List);
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Vis.assign(n+1,false);
        vector<vector<int>> List(n);
        vector<vector<int>> matrix(n+1,vector<int> (n+1,0));
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0], v = edges[i][1];
            List[u].push_back(v);
            List[v].push_back(u);
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
       // vector<int> Res;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!Vis[i]){
                bool Complete = true;
                Res.clear();
                DFS(i,List);
                for(int j=0; j<Res.size() ; j++){
                    for(int k=0; k<Res.size(); k++){
                        if(Res[j] != Res[k] && matrix[Res[j]][Res[k]]==0){
                            Complete = false;
                            break;
                        }
                    }
                }
                if(Complete) cnt++;
            }
        }
        return cnt;
    }
};
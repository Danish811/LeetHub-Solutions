class Solution {
public:
    vector<int> vis;
    bool Cycle(vector<int> List[],int node, int parent){
        if(vis[node] == 1) return true;

        vis[node] = 1;
        for(auto child:List[node]){
            if(child == parent) continue;
            if(Cycle(List,child,node)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vis.assign(edges.size()+1,0);
        int n = edges.size();
        vector<int> List[n+1];
        bool found = false;
        vector<int> Ans(2);
        for(int i=0; i<edges.size(); i++){
            vis.assign(edges.size()+1,0);
            int u,v;
            u = edges[i][0];
            v = edges[i][1];
            List[u].push_back(v);
            List[v].push_back(u);
           
            if(Cycle(List,u,-1) && !found){
                 found = true;
                 Ans[0] = u;
                 Ans[1] = v;
            }
        }
        return Ans;
    }
};
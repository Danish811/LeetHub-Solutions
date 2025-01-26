class Solution {
public:
    vector<int> Visi;
    vector<int> List[2001];
    bool DFS(int node, vector<int> List[]){
        if(Visi[node] == 2){
            return false;
        }
        if(Visi[node]==1) return true;
        Visi[node] = 2;
        bool ans = true;
        for(auto child: List[node]){
            if(!DFS(child, List)){
                return false;
            }
        }
        Visi[node] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        Visi.assign(n,0);
        for(int i=0; i<n; i++) List[i].clear();

        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            if(u == v) return false;
            List[u].push_back(v);
        }
        for(int i=0; i<n; i++){
            if(Visi[i]==0 && !DFS(i,List)) return false;
        }
        return true;
        // return false;
    }
};
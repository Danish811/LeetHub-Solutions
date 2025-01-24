class Solution {
public:
    vector<int> Safes;
    bool rec(vector<vector<int>>& graph, int node){
        if(Safes[node]!=-1) return Safes[node];
        Safes[node] = 0;
        for(auto child: graph[node]){
            if (!rec(graph,child)){
               return Safes[node] = 0;
            }
        }
        return Safes[node] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> Ans;
        Safes.assign(graph.size(),-1);

        for(int i=0; i<graph.size() ; i++){
            if(rec(graph,i)){
                Ans.push_back(i);
            }
        }
        return Ans;
    }
};
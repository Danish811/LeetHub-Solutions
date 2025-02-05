class Solution {
public:
    vector<bool> Visited;
    set<int> keys;
    void DFS(vector<int> List[], int node, int parent){
        if(Visited[node]) return;
        Visited[node] = true;
        for(auto child: List[node]){
            if(child == parent)continue;
            DFS(List,child,node);
        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> List[1001];
        Visited.assign(1001,false);
        for(int i=0; i<rooms.size(); i++){
            for(auto &num: rooms[i]){
                List[i].push_back(num);
            }
        }
        DFS(List,0,-1);
        for(int i=0; i<rooms.size(); i++){
            if(!Visited[i]) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        queue<int> Q;
        vector<int> List[n];
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            List[v].push_back(u);
            indegree[u]++;
        }


        for(int i=0; i<n; i++){
            if(indegree[i]==0) Q.push(i);
        }
        int processed = 0;
        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            processed++;

            for(int child: List[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    Q.push(child);
                }
            }
        }

        return processed == n;
    }
};
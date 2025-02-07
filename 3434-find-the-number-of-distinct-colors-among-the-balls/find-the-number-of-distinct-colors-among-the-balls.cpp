class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> Color;
        map<int,int> clrcnt;
       
        vector<int> Ans;
        for(auto query: queries){
            int x = query[0];
            int y = query[1];
            if(clrcnt[Color[x]] > 0) clrcnt[Color[x]]--;
            if(clrcnt[Color[x]] == 0) clrcnt.erase(Color[x]);
            Color[x] = y;
            clrcnt[y]++;
            Ans.push_back(clrcnt.size());
        }
        return Ans;
    }
};
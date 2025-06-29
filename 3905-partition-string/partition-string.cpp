class Solution {
public:
    vector<string> partitionString(string s) {
       // set<string> Words;
        map<string, int> Words;
        string temp;
        int prev = -1;
        for(int i=0;i<s.size(); i++){
            temp+=s[i];
            if(Words.find(temp)==Words.end()){
                Words[temp] = prev;
                prev = i+1;
                temp = "";
            }
        }
        vector<pair<int,string>> V;
        for(auto &p : Words){
            V.push_back({p.second,p.first});
        }
        sort(V.begin(),V.end());
        vector<string> Ans;
        for(auto &i: V){
            Ans.push_back(i.second);
        }
        return Ans;
    }
};
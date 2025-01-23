

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> M;
        vector<string> Res;
       // if(s.size() < 10) return Res;
        for(int i=0; i+9 < s.size(); i++){
            M[s.substr(i,10)]++;
        }
        
        for(auto ele: M){
            if(ele.second > 1){
                Res.push_back(ele.first);
            }
        }
        return Res;
    }
};
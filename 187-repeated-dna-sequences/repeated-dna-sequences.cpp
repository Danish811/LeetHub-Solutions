

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> M;
        vector<string> Res;
        string temp = s.substr(0,10);
       // if(s.size() < 10) return Res;
        for(int i=0; i+9 < s.size(); i++){
            if(i!=0){
                temp += s[i+9];
                temp.erase(0,1);
            } 
            M[temp]++;
        }
        
        for(auto ele: M){
            if(ele.second > 1){
                Res.push_back(ele.first);
            }
        }
        return Res;
    }
};
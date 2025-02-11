class Solution {
public:
    string removeOccurrences(string s, string part) {
        bool flag = true;
        while(flag){
          auto pos = s.find(part);
          if(pos == string::npos) break;
          s.erase(pos,part.size());
        }
        
        return s;
    }
};
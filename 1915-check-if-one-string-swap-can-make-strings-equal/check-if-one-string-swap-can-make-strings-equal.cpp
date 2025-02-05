class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char,int> Set1;
        map<char,int> Set2;
        for(auto &c: s1) Set1[c]++;
        for(auto &c: s2) Set2[c]++;
        if(Set1 != Set2) return false;
        int cnt = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) cnt++;
        }
        if(cnt > 2 || cnt==1) return false;
        return true;
    }
};
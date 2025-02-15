class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> M;
        for(int i=0; i<s.size(); i++){
            int c = s[i];
            M[c]++;
        }
        for(int i=0; i<s.size(); i++){
            if(M[s[i]] == 1) return i;
        }
        return -1;
    }
};
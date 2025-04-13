class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> M;
        for(auto c: s) M[c]++;
        string temp="";
        char single = 'N';
        for(auto ele: M){
            if(ele.second & 1) single = ele.first;
            for(int i=0; i<ele.second/2; i++){
                temp += ele.first;
            }
        }
        string temp2 = temp;
        if(single!='N') temp+=single;
        reverse(temp2.begin(),temp2.end());
        temp += temp2;
        return temp;
    }
};
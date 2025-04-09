class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        map<char,int> M;
        int len = 0;
        while(end<s.size()){
            M[s[end]]++;
            while(start<end && M[s[end]] > 1){
                M[s[start]]--;
                start++;
            }
            end++;
            len = max(len, end - start );        
        }
        return len;
    }
};
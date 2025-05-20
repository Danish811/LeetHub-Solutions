class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int len=0;
        string ans = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            len = 1;
            int left = i;
            int right = i;
            while(left>=0 && right<n && s[left] == s[right]){
                    len+=2;
                    left--;
                    right++;
            }
            if(len > maxlen){
                maxlen = len;
                ans = s.substr(left+1, right-left-1);
            }
        }
        for(int i=1; i<n; i++){
            len = 2;
            int left = i-1;
            int right = i;
            while(left>=0 && right<n && s[left] == s[right]){
                    len+=2;
                    left--;
                    right++;
            }
            if(len > maxlen){
                maxlen = len;
                ans = s.substr(left+1, right-left-1);
            }
        }
        
        return ans;
    }
};
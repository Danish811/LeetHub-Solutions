class Solution {
public:
    int same(string a,string b){
        int i=0;
        while(i<a.size() && i<b.size() && a[i]==b[i]) {
            i++;
        }
        return i;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n= words.size();
        if(n==1) return {0};
        vector<int> pref(n,0),suff(n,0);
        for(int i=1; i<n; i++){
            pref[i] = max(pref[i-1], same(words[i], words[i-1]));
        }
    
        for(int i=n-2; i>=0; i--){
            suff[i] = max(suff[i+1], same(words[i],words[i+1]));
        }
        vector<int> ans(n,0);
        ans[0] = suff[1];
        ans[n-1] = pref[n-2];

        for(int i=1; i<n-1; i++){
            ans[i] = max(same(words[i-1],words[i+1]) , max(pref[i-1], suff[i+1]));
        }
        return ans;
    }
};
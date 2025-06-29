class Solution {
public:
    static bool compare(const pair<int,int> &a,const pair<int,int> &b){
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> Res;
        for(int i=0; i<n; i++){
            Res.push_back({nums[i],i});
        }
        sort(Res.begin(),Res.end(),greater<pair<int,int>>());
        while(Res.size() > k){
            Res.pop_back();
        }
        sort(Res.begin(),Res.end(), compare);
        vector<int> A(k);
       for(int i=0; i<k; i++){
         A[i] = Res[i].first;
       }
       return A;
    }
};
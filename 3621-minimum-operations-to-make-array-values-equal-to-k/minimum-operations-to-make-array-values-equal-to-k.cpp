class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        vector<int> temp;
        for(auto i: nums){
            if(s.count(i)>0) continue;
            temp.push_back(i);
            s.insert(i);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        int i=0;
        int n = temp.size();
        while(i<n && temp[i] > k){
            i++;
        }
        if(temp.back() < k){
            return -1;
        }
        return i;
    }
};
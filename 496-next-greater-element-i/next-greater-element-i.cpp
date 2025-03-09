class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        vector<int> Suff(nums2.size(), nums2.back());
        for(int i=nums2.size()-2; i>=0; i--){
            Suff[i] = min(Suff[i+1],nums2[i]);
        }
        map<int,int> M;
        for(int i=0; i < nums2.size(); i++){
            M[nums2[i]] = i;
        }
        for(int i=0; i<nums1.size(); i++){
            int j = M[nums1[i]];
            while(j<nums2.size() && nums2[j] <= nums1[i]){ j++; }
            if(j<nums2.size()){
                res[i] = nums2[j];
            }
        }
        return res;
    }
};
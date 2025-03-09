class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        for(int i=0; i<nums1.size(); i++){
            int j=0;
            while(j<nums2.size() && nums1[i]!=nums2[j]) j++;
            
            while(j<nums2.size() && nums2[j] <= nums1[i]) j++;
            if(j<nums2.size()){
                res[i] = nums2[j];
            }
        }
        return res;
    }
};
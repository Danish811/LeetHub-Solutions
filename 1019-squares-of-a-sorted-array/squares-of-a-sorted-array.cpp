class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> st;
        int first = 0;
        int last = nums.size()-1;
        while(first<=last){
            if(abs(nums[first]) > nums[last]){
                st.push(nums[first]*nums[first]);
                first++;
            } 
            else{
                st.push(nums[last]*nums[last]);
                last--;
            }
        }
        int i=0;
        while(!st.empty()){
            nums[i++] = st.top();
            st.pop();
        }
        return nums;
    }
};
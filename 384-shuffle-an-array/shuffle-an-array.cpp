class Solution {
public: 
    vector<int> Arr;
    Solution(vector<int>& nums) {
        Arr = nums;
    }
    
    vector<int> reset() {
        return Arr;
    }
    
    vector<int> shuffle() {
        vector<int> temp;
        set<int> done;

        while(temp.size() < Arr.size()){
            int k = rand()%(Arr.size());
            if(done.find(Arr[k]) != done.end()) continue;
            temp.push_back(Arr[k]);
            done.insert(Arr[k]);
        }
        return temp;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
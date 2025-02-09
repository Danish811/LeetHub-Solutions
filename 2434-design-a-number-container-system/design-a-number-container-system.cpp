class NumberContainers {
public:
    map<int,int> N;
    map<int,set<int>> M;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(N.find(index) == N.end()){
            N[index] = number;
            M[number].insert(index);
        }
        else{
            M[N[index]].erase(index);
            if(M[N[index]].empty()) M.erase(N[index]);
            N[index] = number;
            M[number].insert(index);
        }
    }
    
    int find(int number) {
        if(M.find(number) == M.end()) return -1;
        return *M[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
class NumberContainers {
public:
    NumberContainers() {
        
    }
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> res;
    unordered_map<int, int> index_val;
    
    void change(int index, int number) {
        if(index_val.count(index))
        {
            int prenum=index_val[index];
            if(prenum==number)return;
            res[prenum].push(INT_MAX);
        }
        res[number].push(index);
        index_val[index]=number;
    }
    
    int find(int number) {
        while (!res[number].empty() && index_val[res[number].top()] != number) {
            res[number].pop();
        }
        return res[number].empty() ? -1 : res[number].top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
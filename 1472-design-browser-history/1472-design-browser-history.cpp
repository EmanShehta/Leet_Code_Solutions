class BrowserHistory {
public:
        stack<string> fw, bw;
    string cur;
    BrowserHistory(string homepage) {
                cur = homepage;

    }
    
    void visit(string url) {
          fw = stack<string>(); //there is no stack::clear()!
        bw.push(cur);
        cur = url;
    }
    
    string back(int steps) {
         while(!bw.empty() && steps-- > 0){
            fw.push(cur);
            cur = bw.top(); bw.pop();
        }
        
        return cur;
        
    }
    
    string forward(int steps) {
         while(!fw.empty() && steps-- > 0){
            bw.push(cur);
            cur = fw.top(); fw.pop();
        }
        
        return cur;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
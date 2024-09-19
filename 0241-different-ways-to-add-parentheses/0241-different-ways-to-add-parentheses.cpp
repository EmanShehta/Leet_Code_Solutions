class Solution {
public:
    int operate(int x,int y,char op)
    {
        if(op=='+') return x+y;
        if(op=='-') return x-y;
        if(op=='*') return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        bool isentirelynumber=true;
        
        for(int i =0;i<expression.length();i++)
        {
            if(!isdigit(expression[i]))
            {
                isentirelynumber=false;
                 vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1,expression.length()));
                
                for(int x:left)
                {
                    for(int y :right)
                        res.push_back(operate(x,y,expression[i]));
                }

                
            }
        }
        if(isentirelynumber)
            res.push_back(stoi(expression));
        return res;
        
    }
};
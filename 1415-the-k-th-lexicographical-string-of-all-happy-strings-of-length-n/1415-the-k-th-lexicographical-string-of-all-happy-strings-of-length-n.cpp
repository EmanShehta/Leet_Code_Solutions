class Solution {
public:
    void dfs (string current,int n , vector<string>&happystrings)
    {
        if(current.length()==n)
        {
            happystrings.push_back(current);
            return;
        }
        for (auto ch :{'a','b','c'})
        {
            if (current.empty() || current.back() != ch) { 
            
                dfs(current+ch,n,happystrings);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>happystrings;
        dfs("",n,happystrings);
        return (k <= happystrings.size()) ? happystrings[k - 1] : "";
    }

};


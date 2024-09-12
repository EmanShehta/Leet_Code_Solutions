class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
     int ch[26]={0};
        for (auto c:allowed)
        {
            ch[c-'a']=1;
        }
        int cnt=0;
        for (auto word:words)
        {
             int flag=1;
            for(auto c:word)
            {
               
                if(ch[c-'a']==0)
                {
                    flag=0;
                }
            }
            cnt+=flag;
        }
        return cnt;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
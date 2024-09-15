class Solution {
public:
    int findTheLongestSubstring(string s) {
     int n=s.length();
        int mask=0,mxlen=0;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i =0;i<n;i++)
        {
            if(s[i]=='a')mask^=(1<<0);
            if(s[i]=='e')mask^=(1<<1);
            if(s[i]=='i')mask^=(1<<2);
            if(s[i]=='o')mask^=(1<<3);
            if(s[i]=='u')mask^=(1<<4);
            
            if(m.find(mask)!=m.end())
            {
                mxlen=max(mxlen,i-m[mask]);
            }
            else
            {
                m[mask]=i;
            }

        }
        return mxlen;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
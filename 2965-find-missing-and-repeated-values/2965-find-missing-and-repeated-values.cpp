class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        int a ,b ;
        for(auto x :grid)
        {
            for(int v:x)
            {
                if(mp[v]) a=v;
                mp[v]=1;
            }
        }
        int n =grid.size();
        for (int i= 1;i<=n*n;i++)
        {
            if (!mp[i])b=i;


        }
        return {a,b};
    }
};
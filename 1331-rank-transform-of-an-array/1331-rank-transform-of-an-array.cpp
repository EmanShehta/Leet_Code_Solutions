class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       
        vector<int> sortedArr = arr;
           sort(sortedArr.begin(),sortedArr.end());
          map<int,int>mp;
        int rank=1;
        for(auto x:sortedArr)
        {
            if(mp.find(x) ==mp.end())
            {
                mp[x]=rank++;
            }
        }
         vector<int> result;
        for(auto num :arr)
        {
            result.push_back(mp[num]);
        }
        return result;
        
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
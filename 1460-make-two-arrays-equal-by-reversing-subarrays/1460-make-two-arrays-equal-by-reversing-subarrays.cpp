class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size(),m=arr.size();
        if(n!=m)return false;
      vector<int> ans(1002) ;
        for(int i=0;i<n;i++)
        {
            ans[target[i]]++;
            ans[arr[i]]--;
        }
        for(int i=0;i<n;i++)
        {
            if(ans[target[i]]!=0 || ans[arr[i]]!=0)
            {
                return false;
            }
        }
        return true;
    }
    
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>v=nums;
        int countones=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            countones+=nums[i];
            v.push_back(nums[i]);
        }
        int ans=INT_MAX,idx=0,i=0,windowonecount=0;
        while(idx<countones)
            windowonecount+=v[idx++];
        ans=min(ans,countones-windowonecount);
        int sz=2*n;
        while(idx<sz)
        {
            if(v[idx++])windowonecount++;
            if(v[i++])windowonecount--;
            ans=min(ans,countones-windowonecount);
        }
        return ans;
    }
};
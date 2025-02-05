class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxlen=1,inc=1,dec=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])inc++,dec=1;
            else if(nums[i]<nums[i-1])inc=1,dec++;
            else inc=1,dec=1;

                 maxlen=max(maxlen,max(inc,dec));

        }
        return maxlen;
    }
};
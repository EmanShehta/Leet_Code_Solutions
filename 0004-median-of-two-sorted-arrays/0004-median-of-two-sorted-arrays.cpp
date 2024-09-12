class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        int m= nums2.size();
        int total=n+m;
        double ans;
        vector<int>nums;
        for(auto x:nums1)
        {
            nums.push_back(x);
        }
        for(auto x:nums2)
        {
            nums.push_back(x);
        }
        sort(nums.begin(),nums.end());
        if(total%2 !=0)
        {
            ans=nums[total/2];
        }
        else
        {
        ans = (nums[total / 2] + nums[(total / 2) - 1]) / 2.0;  
        }
        return ans;
    }
};

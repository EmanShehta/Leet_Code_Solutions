class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int mn = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i] > mn){
                // check profit at every possible big day
                diff = max({nums[i] - mn, diff});
            }

            // check if we can be able to buy on lesser amount day
            if(nums[i] < mn){mn = nums[i];}
        }

        return diff;
    }
};
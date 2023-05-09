class Solution {
public:
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> output;
        sort(begin(nums), end(nums)); 
        gen_pre(nums,output,0);
        return output;
    }
    void gen_pre(vector<int>nums ,vector<vector<int>>& output ,int idx)
    {
        if(idx==size(nums))
        {
            output.push_back(nums);
        }
        for(int i=idx;i<size(nums);i++)
        {
            if(i !=idx && nums[i]==nums[idx]) continue;
            swap(nums[i],nums[idx]);
            gen_pre(nums,output,idx+1);
        }
    }
};
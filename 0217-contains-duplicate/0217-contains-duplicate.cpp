class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> mapp;
        for(int i=0;i<nums.size();i++)
        {
            if(mapp[nums[i]])
            return true ;
            mapp[nums[i]]=true;
        }
        return false ;
    }
};
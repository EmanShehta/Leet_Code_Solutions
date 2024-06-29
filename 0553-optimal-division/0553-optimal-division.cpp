class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string str="";
        
        int len=nums.size();
        if (len == 1)
        return to_string(nums[0]);
                if (len == 2)
        return to_string(nums[0])+'/'+to_string(nums[1]);
        
for (int i=0;i<len;i++)
{
   str+=to_string(nums[i])+"/";
    if(i==0)
        str+='(';
}
        str[str.size()-1]=')';
    return str;
    }
};
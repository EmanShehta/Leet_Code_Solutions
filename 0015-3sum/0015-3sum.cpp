class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++){
            if(i>0&& nums[i]==nums[i-1])
            {
                continue;
            }
           int j=i+1;
           int  k=nums.size()-1;
            while(j<k)
            {
                int sm=nums[i]+nums[j]+nums[k];
                if(sm==0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    if (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                    while (nums[k] == nums[k+1] && j < k) {
                        k--;
                    }
                }
                else if(sm<0)
                {
                   j++; 
                }
                else 
                {
                    k--;
                }
            }
        }
       
        return res;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
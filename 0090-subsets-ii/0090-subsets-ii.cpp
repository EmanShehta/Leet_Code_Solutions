class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      
    int n =nums.size();
    vector<vector<int>>v;
    set<vector<int>>s;
    for (int mask = 0; mask < (1<<n); ++mask) {
        vector<int>tmp;
        for (int i = 0; i <n; ++i) {
            if(mask &(1<<i)) {
                tmp.push_back(nums[i]);
            }
        }
        sort(tmp.begin(),tmp.end());
        s.insert(tmp);

    }
    for (auto m:s) {
        v.push_back(m);
    }
    return v;
}
    
};
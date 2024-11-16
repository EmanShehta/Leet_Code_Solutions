class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), count{1};
        vector<int> res(n - k + 1, -1);
        for (int i{1}; i < k; i++) 
            count = (nums[i] == nums[i - 1] + 1) ? count + 1 : 1;
        if (count == k) res[0] = nums[k - 1];
        for (int i = k; i < n; i++) {
            count = (nums[i] == nums[i - 1] + 1) ? count + 1 : 1;
            if (count >= k) res[i - k + 1] = nums[i];
        }
        return res;
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
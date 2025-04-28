class Solution {
    public:
        using ll = long long;
        long long countSubarrays(vector<int>& nums, long long k) {
            ll count = 0;
            for (int right = 0; right < nums.size(); right++) {
                ll sum = 0;
                for (int left = right; left < nums.size(); left++) {
                    sum += nums[left];
                    if (sum * (left - right + 1) < k) {
                        ++count;
                    }
                }
            }
            return count;
        }
    };
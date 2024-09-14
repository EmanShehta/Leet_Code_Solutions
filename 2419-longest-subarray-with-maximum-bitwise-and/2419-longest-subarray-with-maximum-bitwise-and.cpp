class Solution {
public:
   int longestSubarray(std::vector<int>& nums) {
        int max_val = nums[0];
        int max_len = 1;
        int current_len = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > max_val) {
                max_val = nums[i];
                max_len = 1;
                current_len = 1;
            } else if (nums[i] == max_val) {
                current_len++;
                max_len = std::max(max_len, current_len);
            } else {
                current_len = 0;
            }
        }

        return max_len;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
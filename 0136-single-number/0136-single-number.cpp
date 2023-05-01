class Solution {
public:
        int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int x: nums) {
            res ^= x;
        }
        return res;
    }
    
};
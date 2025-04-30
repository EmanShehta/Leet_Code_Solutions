class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i : nums) {
            int digits = log10(i) + 1;
            if (digits % 2 == 0) ++count;
        } 
        return count;
    }
};
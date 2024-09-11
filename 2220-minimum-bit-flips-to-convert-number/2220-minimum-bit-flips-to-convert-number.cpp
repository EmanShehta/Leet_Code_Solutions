class Solution {
public:
      int minBitFlips(int start, int goal) {
        int count = 0;
        while (start != 0 || goal != 0) {
            count += (start & 1) ^ (goal & 1);
            start = start >> 1;
            goal = goal >> 1;
        }
        return count;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
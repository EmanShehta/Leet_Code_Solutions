class Solution {
public:
    long long distributeCandies(int n, int m) {
        long long res = (n + 2LL) * (n + 1) / 2;
        for (int i = 1; i <= 3; i++) {
            long long rem = n - 1LL * i * (m + 1);
            if (rem < 0) break;
            long long val = (rem + 2) * (rem + 1) / 2;
            long long c = (i < 3 ? 3 : 1);
            res += (i % 2 ? -c * val : c * val);
        }
        return res;
    }
};
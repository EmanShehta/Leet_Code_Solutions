class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) {
            return 0;
        }

        vector<int> pair_sums;
        for (size_t i = 0; i < weights.size() - 1; ++i) {
            pair_sums.push_back(weights[i] + weights[i + 1]);
        }

        sort(pair_sums.begin(), pair_sums.end());

        long long min_score = accumulate(pair_sums.begin(), pair_sums.begin() + (k - 1), 0LL);
        long long max_score = accumulate(pair_sums.end() - (k - 1), pair_sums.end(), 0LL);

        return max_score - min_score;
    }
};
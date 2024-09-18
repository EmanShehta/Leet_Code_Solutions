class Solution {
public:
   const int TOTAL_MINS_DAY = 60 * 24;

int minDiff(string &t1, string &t2) {
    int totalMins1 = 60 * stoi(t1.substr(0, 2)) + stoi(t1.substr(3, 2));
    int totalMins2 = 60 * stoi(t2.substr(0, 2)) + stoi(t2.substr(3, 2));
    int diff = abs(totalMins1 - totalMins2);
    return min(diff, TOTAL_MINS_DAY - diff);
}

int findMinDifference(vector<string>& tp) {
    sort(tp.begin(), tp.end());
    int n = tp.size();
    int res = INT_MAX;
    for(int i=0;i<n;i++){
        int diff = minDiff(tp[i], tp[(i + n - 1) % n]);
        res = min(res, diff);
    }
    return res;
}
};
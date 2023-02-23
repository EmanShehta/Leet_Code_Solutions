class Solution {
public:
   

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    priority_queue<int> maxprofit;
    int sz = profits.size();
    vector<pair<int, int>> pro(sz);
    for (int i = 0; i < sz; i++) {
        pro[i] = {capital[i], profits[i]};
    }
    sort(pro.rbegin(), pro.rend());
    while (k--) {
        while (!pro.empty() && pro.back().first <= w) {
            maxprofit.push(pro.back().second);
            pro.pop_back();
        }
        if (maxprofit.empty())break;

        w += maxprofit.top();
        maxprofit.pop();
    }
    return w;
}

};
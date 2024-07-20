class Solution {
public:
    int maxCostSubstring(const vector<int>& costs) {
        int n = costs.size();
        if (n == 0) return 0;

        int maxCost = 0;
        int currentCost = 0;

        for (int i = 0; i < n; i++) {
            currentCost = max(costs[i], currentCost + costs[i]);
            maxCost = max(maxCost, currentCost);
        }

        return maxCost;
    }

    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        map<char, int> mp;

        for (int i = 0; i < chars.size(); i++) {
            mp[chars[i]] = vals[i];
        }

        vector<int> costs(n);
        
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                costs[i] = mp[s[i]]; // Cost from the map
            } else {
                costs[i] = s[i] - 'a' + 1; // Default cost for characters not in chars
            }
        }
        int result = maxCostSubstring(costs);
        return result;
    }
};

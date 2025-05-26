class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
            dp[i][colors[i] - 'a'] = 1;
        }

        int visited = 0;
        int maxColor = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited++;

            for (int neighbor : adj[node]) {
                for (int c = 0; c < 26; ++c) {
                    int inc = (colors[neighbor] - 'a' == c) ? 1 : 0;
                    dp[neighbor][c] = max(dp[neighbor][c], dp[node][c] + inc);
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }

            maxColor = max(maxColor, *max_element(dp[node].begin(), dp[node].end()));
        }

        return visited == n ? maxColor : -1;
    }
};
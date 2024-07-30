class Solution {
public:
    using int2 = pair<int, int>;
    array<vector<int2>, 26> adj;
           int arr[26][26];

    void Dijkstra(int x) {
        int* dist=arr[x];
        priority_queue<int2, vector<int2>, greater<int2>> pq(adj[x].begin(), adj[x].end());
        while (!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();
            if (d > dist[i])
                continue;
            for (auto& [w, j] : adj[i]) {
                int d2 = d + w;
                if (d2 < dist[j]) {
                    dist[j] = d2;
                    pq.emplace(d2, j);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    fill(&arr[0][0], &arr[0][0] + 26 * 26, INT_MAX);
    for(int i=0;i<26;i++)
    {
       arr[i][i]=0;
    }
         const int sz = original.size();
 for(int i=0;i<sz;i++)
    {
        int row=original[i]-'a';
        int col=changed[i]-'a';
        arr[row][col]=min(arr[row][col], cost[i]);
    }
     for (int i=0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (arr[i][j] != INT_MAX && i!= j) {
                    adj[i].emplace_back(arr[i][j], j);
                }
            }
        }
        for (int i= 0; i< 26; i++) {
            Dijkstra(i);
        }
         const int n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int row = source[i] - 'a';
            int col = target[i] - 'a';
            if (arr[row][col] == INT_MAX) return -1;
            ans += arr[row][col];
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
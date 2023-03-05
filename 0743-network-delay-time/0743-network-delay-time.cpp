class Solution {
private:
    vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>dis(adj.size(), INT_MAX);
    dis[src]=0;
    pq.push({dis[src],src});
    while(!pq.empty()){
      auto tp=pq.top();
      pq.pop();
      auto costSoFar=tp.first;
      auto node=tp.second;
      if(costSoFar > dis[node]) continue;
      for(auto& edge : adj[node]){
        auto neigh=edge.first;
        auto cost=edge.second;
        if(dis[neigh] > dis[node] + cost){
          dis[neigh] = dis[node] + cost;
          pq.push({dis[neigh], neigh});
        }
      }
    }
    return dis;
  }
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int,int>>>adj(n);
      for(auto& time : times){
        int from=time[0]-1, to=time[1]-1, c=time[2];
        adj[from].push_back({to,c});
      }
      auto dis=dijkstra(k-1,adj);
      auto mx=*max_element(dis.begin(), dis.end());
      if(mx==INT_MAX) return -1;
      return mx;
  }
};
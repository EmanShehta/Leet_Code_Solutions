class Solution {
    private :
    vector<long long> dijkstra (int src , vector<vector<pair<int,int>>>& adj){
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long>dis(adj.size(),LLONG_MAX);
    dis[src]=0;
    pq.push({dis[src],src});
    while(!pq.empty())
    {
        auto cost_far=pq.top().first;
                auto node=pq.top().second;

        pq.pop();
       if(cost_far>dis[node])
       {
           continue;
       }
        for(auto & edge :adj[node])
        {
            auto neigh =edge.first;
            auto cost=edge.second;
            if(dis[node]+cost<dis[neigh])
            {
               dis[neigh]=dis[node]+cost;
                pq.push({dis[neigh],neigh});
            }
        }
    }

     return dis;   
        
        
}
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
              vector<vector<pair<int,int>>>adj(n), inverseAdj(n);
              for(auto & edge : edges)
              {
                  int from=edge[0],to =edge[1],cost=edge[2];
                  adj[from].push_back({to,cost});
                  inverseAdj[to].push_back({from,cost}); 
              }
        auto src1Dis=dijkstra(src1,adj);
        auto src2Dis=dijkstra(src2,adj);
        auto desDis=dijkstra(dest,inverseAdj);
        long long ans=LLONG_MAX;
      for(int u=0; u<n; u++){
        if(src1Dis[u]==LLONG_MAX || src2Dis[u]==LLONG_MAX || desDis[u]==LLONG_MAX) continue;
        ans=min(ans, src1Dis[u] + src2Dis[u] + desDis[u]);
      }
      if(ans==LLONG_MAX) return -1;
      return ans;
  }
};
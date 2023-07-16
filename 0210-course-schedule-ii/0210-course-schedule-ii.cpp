class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int>ans,indgree(numCourses);
      
    for(auto & pre:prerequisites){
        const int u=pre[1];
       const int v=pre[0];
        g[u].push_back(v);
        indgree[v]++;
    }
    queue<int>q;
    for (int i = 0; i < numCourses; ++i) {
        if(indgree[i]==0)
            q.push(i);
    }
    while (!q.empty())
    {
        auto cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(auto nc:g[cur])
        {
            if(--indgree[nc]== 0)
            {
                q.push(nc);
            }
        }
    }
      return ans.size()==numCourses?ans:vector<int>();
  }


};
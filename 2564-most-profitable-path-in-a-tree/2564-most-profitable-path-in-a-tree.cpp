    vector<int>BobT,parent;

class Solution {
public:
    void bobdfs(int i,int p,vector<vector<int>>& adj)
    {
        parent[i]=p;
        for(int j:adj[i])
        {
           if(j==p)
           {
            continue;
           }
           bobdfs(j,i,adj);
        }
    }
    int AliceDfs(int n,int p,vector<vector<int>>&adj,int AliceT,vector<int>& amount){
        int AliceM = 0;
        if(AliceT < BobT[n])AliceM = amount[n];
        if(AliceT ==  BobT[n])AliceM = amount[n]/2;
        if(adj[n].size() == 1 && n != 0)return AliceM;
        int mx = -1e9;
        for(int ch : adj[n]){
            if(ch == p)continue;
            mx=max(mx, AliceDfs(ch,n,adj,AliceT+1,amount));
        }
        return mx + AliceM;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount)   
    {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto it :edges)
        {
         adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);

        }
        BobT=parent=vector<int>(n,1e9);
        bobdfs(0,-1,adj);
        int time = 0;
        for(int i = bob ; i !=-1 ; i = parent[i])
            BobT[i] = time++;
        return AliceDfs(0,-1,adj,0,amount);

    }
};
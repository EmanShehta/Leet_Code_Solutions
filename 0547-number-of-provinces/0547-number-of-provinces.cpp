class Solution {
private:
  int findParent(int node, vector<int>& par){
    if(node==par[node]) return node;
    return par[node]=findParent(par[node], par);
  }

  void join(int node1, int node2, vector<int>& par, vector<int>& sz){
    node1=findParent(node1, par);
    node2=findParent(node2, par);
    if(node1!=node2){
      if(sz[node2] > sz[node1]) swap(node1,node2);
      par[node2]=node1;
      sz[node1]+=sz[node2];
    }
  }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>par(n), sz(n,1);
        iota(par.begin(), par.end(), 0);
        for(int i=0; i<n; i++)
          for(int j=0; j<n; j++)
            if(isConnected[i][j])
              join(i,j,par,sz);
        unordered_set<int>st;
        for(int i=0; i<n; i++)
          st.insert(findParent(i,par));
        return st.size();
    }
};
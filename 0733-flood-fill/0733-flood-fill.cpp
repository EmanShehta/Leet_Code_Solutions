class Solution {
private:
  int dr[4]={0,0,1,-1};
  int dc[4]={1,-1,0,0};

  bool inBorders(int n, int m, int r, int c){
    return r>=0 && r<n && c>=0 && c<m;
  }

  void DFS(int nodeR, int nodeC, vector<vector<int>>& image, int newColor, vector<vector<bool>>& vis){
    vis[nodeR][nodeC]=1;
    for(int i=0; i<4; i++){
      int neighR=nodeR+dr[i];
      int neighC=nodeC+dc[i];
      if(inBorders(image.size(), image[0].size(), neighR, neighC) && vis[neighR][neighC]==0 && image[neighR][neighC]==image[nodeR][nodeC])
        DFS(neighR, neighC, image, newColor, vis);
    }
    image[nodeR][nodeC]=newColor;
  }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>>vis(image.size(), vector<bool>(image[0].size(), 0));
        DFS(sr,sc,image,newColor,vis);
        return image;
    }
};
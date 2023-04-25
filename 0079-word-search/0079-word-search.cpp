class Solution {
public:
    
    bool bfs (vector<vector<char>>&board,string & word,int i,int j,int pos)
    {
        if(pos==word.length())return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return false;
        if(board [i][j]==word[pos])
        {
            board[i][j]='*';
            if(bfs(board,word,i-1,j,pos+1)||
              bfs(board,word,i+1,j,pos+1)||
               bfs(board,word,i,j-1,pos+1)||
               bfs(board,word,i,j+1,pos+1)) 
                return true;
            board[i][j]=word[pos];
            return false;
        }
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
           for(int j=0;j<board[i].size();j++){
               if(bfs(board,word,i,j,0)) return true;
           }
       }
        return false;
        
    }
};
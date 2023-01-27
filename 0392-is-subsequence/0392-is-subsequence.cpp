class Solution {
public:
    bool isSubsequence(string s, string t) {
         int x=0;
       for(int i=0;i<t.length();i++){
          if(t[i]==s[x]){
              x++;
          }
       } 
        if(x!=s.length())
            return false;
        else
            return true;
    }
};
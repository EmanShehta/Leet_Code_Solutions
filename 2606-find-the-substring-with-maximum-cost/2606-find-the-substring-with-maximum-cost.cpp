class Solution {
public:
     int maximumCostSubstring(string s, string chars, vector<int>& vals) {
       vector<int>ch(26);  //set
        for(int i=0;i<26;i++)
        {
            ch[i]=i+1;
        }
        int cnt =0;
        for(char c:chars)   //update
        {
           ch[c-'a'] =vals[cnt++];
        }
         int maxsub=0;
         int cur=0;
         for(char c:s)
         {
             cur+=ch[c-'a'];
             if(cur<0)
             {
                 cur=0;
             }
             maxsub=max(maxsub,cur);
         }
         return maxsub;
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int cnt=0;
        int len=0;
        for(int i=0;i<chars.size();)
        {
           char temp =chars[i];
            
            while(i<chars.size()&&chars[i]==temp)
            {
                cnt++;
                i++;
            }
           chars[len++]=temp;
            if(cnt>1)
            for(auto &c : to_string( cnt))
                chars[len++]=c;
            cnt=0;
        }
       return len;
    }
};
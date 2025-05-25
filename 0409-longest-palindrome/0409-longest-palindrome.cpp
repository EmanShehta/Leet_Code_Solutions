class Solution {
public:
    int longestPalindrome(const std::string& s) {
        std::unordered_set<char>st;
        int len=0;
        for(char c:s)
        {
            if(st.find(c)!=st.end())
            {
                st.erase(c);
                len+=2;

            }
            else{
                st.insert(c);
            }
        }
        if(!st.empty()) len++;
        return len;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        if (haystack.size() < len) return -1;
        for (int idx=0; idx <= haystack.size()- len; idx++){
            if (string (haystack.begin()+idx, haystack.begin()+idx+len) == needle) return idx;
        }
        return -1;
    }
};
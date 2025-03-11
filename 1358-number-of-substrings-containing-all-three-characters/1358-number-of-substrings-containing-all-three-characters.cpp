class Solution {
public:
    int mp[3];

    inline bool checkmap()
    {
        if(mp[0] >= 1 && mp[1] >= 1 && mp[2] >= 1)
            return true;
        return false;
    }

    int numberOfSubstrings(string s) {
        int left = 0, right = 0, counter = 0, n = s.size();

        while (right < s.size())
        {
            mp[s[right] - 'a']++;
            while(checkmap())
            {
                counter += n - right;
                mp[s[left] - 'a']--;
                left++;
            }
            right++;
        }

        return counter;
    }
};
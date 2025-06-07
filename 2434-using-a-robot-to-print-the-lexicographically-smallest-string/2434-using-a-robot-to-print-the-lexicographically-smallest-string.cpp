class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        string t = "";
        
        unordered_map<char, int> frq;
        for (char c : s) {
            frq[c]++;
        }

        char sml = 'a';

        for (char c : s) {
            // if current char is smallest, push to ans directly
            if (c == sml) {
                ans += c;
            } 
            else {
                t.push_back(c);
            }

            // decrease used frequency
            frq[c]--;
            if (frq[c] == 0) {
                frq.erase(c);
            }

            // update sml to next smallest available char
            while (sml <= 'z' && frq.count(sml) == 0) {
                sml++;
            }

            // pop from t if top <= sml
            while (!t.empty() && t.back() <= sml) {
                ans += t.back();
                t.pop_back();
            }
        }

        // empty the remaining stack
        while (!t.empty()) {
            ans += t.back();
            t.pop_back();
        }

        return ans;
    }
};
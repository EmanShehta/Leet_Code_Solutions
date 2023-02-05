class Solution {
public:
   vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> answer;
    vector<int> pre(words.size() + 1, 0);

    for (int i = 0; i < words.size(); i++) {
        char fl = words[i][0];
        char ll = words[i][words[i].length() - 1];
        if (fl == 'a' || fl == 'e' || fl == 'i' || fl == 'o' || fl == 'u') {
            if (ll == 'a'||  ll == 'e' ||  ll == 'i'||  ll == 'o' || ll == 'u') {
                pre[i + 1] = pre[i] + 1;
            } else {
                pre[i + 1] = pre[i];
            }
        } else {
            pre[i + 1] = pre[i];
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        answer.push_back(pre[r + 1] - pre[l]);
    }
    return answer;
}
};
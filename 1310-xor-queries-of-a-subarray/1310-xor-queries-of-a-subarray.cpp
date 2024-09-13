class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pre(n);
        vector<int> ans(queries.size());
        
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = arr[i] ^ pre[i - 1];
        }
        
        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            
            if (left == 0) {
                ans[i] = pre[right];
            } else {
                ans[i] = pre[right] ^ pre[left - 1];
            }
        }
        
        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
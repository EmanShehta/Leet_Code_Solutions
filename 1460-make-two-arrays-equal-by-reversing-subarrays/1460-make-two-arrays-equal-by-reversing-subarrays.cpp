class Solution {
public:
    bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
        int n = target.size();
        int m = arr.size();

        if (n != m) {
            return false;
        }

        std::vector<int> ans(1001, 0);

        for (int i = 0; i < n; i++) {
            ans[target[i]]++;
            ans[arr[i]]--;
        }

        for (int i = 0; i < n; i++) {
            if (ans[target[i]] != 0 || ans[arr[i]] != 0) {
                return false;
            }
        }

        return true;
    }
    
};
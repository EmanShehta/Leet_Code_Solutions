class Solution {
public:
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
      unordered_map<int, priority_queue<int, vector<int>, greater<int>>> digitMap;
        int maxResult = -1;

        for (int num : nums) {
            int sum = digitSum(num);
            digitMap[sum].push(num);
            
            if (digitMap[sum].size() > 2) {
                digitMap[sum].pop();
            }
        }

        for (auto& [sum, pq] : digitMap) {
            if (pq.size() == 2) {  
                int first = pq.top(); pq.pop();  
                int second = pq.top();           
                maxResult = max(maxResult, first + second);
            }
        }

        return maxResult;
    }
};
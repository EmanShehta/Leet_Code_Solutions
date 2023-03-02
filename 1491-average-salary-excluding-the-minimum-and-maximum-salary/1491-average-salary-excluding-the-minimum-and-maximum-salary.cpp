class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
       double c=accumulate(salary.begin()+1,salary.end()-1,0);
            return c/(salary.size()-2);
    }
};
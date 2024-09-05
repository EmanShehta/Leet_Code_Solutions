class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total_size=rolls.size()+n;
        int total_sum=mean* total_size;
        int  observed_sum=0;
        for(auto it:rolls)
        {
            observed_sum+=it;
        }
        int missing=total_sum-observed_sum;
        if(missing<n||missing>6*n)
        {
            return {};
        }
        vector<int>result(n,1);
        missing-=n;
        for(int i=0;i<n;i++)
        {
            int addnum=min(5,missing);
            result[i]+=addnum;
            missing-=addnum;
            if(missing==0)break;
        }
        return result;
    }
};
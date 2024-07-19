class Solution {
public:
    int lstocc(char ch, string word)
    {
        int n=word.length();
        int lo=0, hi=n-1, mid;
        int ans;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(word[mid]==ch)
            {
                if(mid==n-1 || word[mid]!=word[mid+1])
                return mid;
                else
                {
                    lo=mid+1;
                }
            }
            else if(word[mid]>ch)
            {
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }       
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=words.size();
        vector<int>freq(n);
        for(int i=0;i<n;i++)
        {
            sort(words[i].begin(), words[i].end()); //n log n 
            int lst= lstocc(words[i][0], words[i]); // log n
            freq[i]=lst+1;
        }
        sort(freq.begin(), freq.end());
        int m=queries.size();
        vector<int>result(m);
        for(int i=0;i<m;i++)
        {
            sort(queries[i].begin(), queries[i].end());
            int lst=lstocc(queries[i][0], queries[i]);
            auto it= upper_bound(freq.begin(), freq.end(), lst+1);
            if(it==freq.end())
            result[i]=0;
            else
            result[i]=n-(it-freq.begin());
        }
        return result;
    }
};
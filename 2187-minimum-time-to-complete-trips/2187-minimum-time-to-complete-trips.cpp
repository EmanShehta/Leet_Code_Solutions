class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo=0,hi=1ll*mintime(time)*totalTrips;
        long long res=0;
        while(lo<=hi)
        {
      long long      mid=(lo+hi)/2;
            if(numoftrips(mid,time)>=totalTrips)
            {
                res=mid;
                hi=mid-1;
                
            }
            else
            {
                lo=mid+1;
            }
        }
        return res;
    }
    long long numoftrips(long long tt,vector<int>&time)
    {
        long long counter =0;
        for(int t:time)
        {
            counter+=tt/t;
        }
        return counter;
    }
     long long mintime(vector<int>&time){
         return *min_element(time.begin(),time.end());
    
     }
    
    
    
};
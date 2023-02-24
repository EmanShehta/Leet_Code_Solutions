class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0,hi=(int)arr.size()-1,mid;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1] )
            {
               return mid; 
            }
             if(arr[mid]>arr[mid-1]){
                 lo=mid;
             }
            else
            {
                hi=mid-1;
            }
                
        }
        return lo;
        
    }
};
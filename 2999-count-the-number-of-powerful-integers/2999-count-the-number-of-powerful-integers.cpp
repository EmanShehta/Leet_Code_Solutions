long long tens[17];
long long powB[17];
class Solution {
public:
    void compute_tens(){
        if (tens[0]==1) return;
        tens[0]=1;
        for(int i=1; i<17; i++)
            tens[i]=tens[i-1]*10LL;
    }
    void compute_powB(int B){
        powB[0]=1;
        for(int i=1; i<17; i++)
            powB[i]=powB[i-1]*B;
    }

    long long cnt(long long x, long long sn, int ds, int limit){
        if (x<sn) return 0;
        long long x0=x, rem=x0%tens[ds];
        x0/=tens[ds];
        int d=lower_bound(tens, tens+17, x0)-tens;
        long long cnt=0;
        for( int i=d; i>=0; i--){//MSDF
            auto [q, r]=ldiv(x0, tens[i]);
            if (q>limit){
                cnt+=powB[i+1];
                return cnt;
            }
            cnt+=powB[i]*q;
            x0-=q*tens[i];
        }
        return cnt+(rem>=sn);
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string& s) {
        compute_tens();
        compute_powB(limit+1);
        long long sn=stoll(s);
        int ds=s.size(), d0=log10(start)+1, d1=log10(finish)+1;
        return cnt(finish, sn, ds, limit)-cnt(start-1, sn, ds, limit);
    }
};
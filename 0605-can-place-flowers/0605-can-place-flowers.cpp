class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0 ;
        int s = flowerbed.size();
        for(int i = 0 ; i < s ; i++ ){
            if(flowerbed[i] == 0){      // when a place is
                bool leftflag = (i == 0) || (flowerbed[i-1] == 0);  //check whether left is empty 
                bool rightflag = (i == s-1) || (flowerbed[i+1] == 0); //check whether left is empty 
                
                if(leftflag && rightflag){  // updation
                    flowerbed[i] = 1;
                    count++;
                    if(count >= n){
                        return true;
                    }
                }
            }
        }
        return count>=n;
    }
};
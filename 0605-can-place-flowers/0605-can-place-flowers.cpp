class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int N = flowerbed.size();
        int count = 0;
        int i = 0;
        while (i < N)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == N - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i++] = 1;
                count++;
            }
            if (count >= n)
                return true;

            i++;
        }

        return false;
    }
};
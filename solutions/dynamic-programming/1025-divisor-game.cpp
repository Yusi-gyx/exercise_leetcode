#include <vector>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> if_win(n);
        if(n == 1) return false;
        if_win[0] = false;
        if(n == 2) return true;
        if_win[1] = true;
        for(int i = 3 ; i <= n ; i ++)
        {
            //find factors and check
            for(int j = 1; j < i ; j ++)
            {
                if(i % j == 0)   //j is a factor of i
                {
                    if(!if_win[i - j - 1]) 
                    {
                        if_win [i - 1] = true;
                        break;
                    }
                }
            }
        }
        return if_win[n - 1];
    }
};
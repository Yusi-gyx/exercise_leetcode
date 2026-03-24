//方法一：递推+动态规划
/*
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n ;
        int * arr = new int [n] ;
        for(int i = 0 ; i < 2 ; i ++)
            arr [i] = i + 1 ;
        for(int i = 2 ; i < n ; i ++)
            arr [i] = arr [i - 1] + arr [i - 2] ;
        return arr [n - 1] ;
    }
};
*/

//方法二：滚动数组+动态规划
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n ;
        int p = 1 , q = 2 , r = 0 ;
        for(int i = 3 ; i <= n ; i ++)
        {
            r = p + q ;
            p = q ;
            q = r ;
        }
        return r ;
    }
};


#include<iostream>

int main ()
{
    Solution sol ;
    std::cout << "n = 5" << " " << sol.climbStairs(5) << std::endl ;
    std::cout << "n = 10" << " " << sol.climbStairs(10) << std::endl ;
    std::cout << "n = 45" << " " << sol.climbStairs(45) << std::endl ;
    return 0 ;
}
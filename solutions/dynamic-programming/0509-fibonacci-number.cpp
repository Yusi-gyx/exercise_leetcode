class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0 ;
        if(n == 1) return 1 ;
        int i = 0 , j = 1 ;
        int m ;
        for(int k = 1 ; k <= n - 1 ; k ++)
        {
            m = i + j ;
            i = j ;
            j = m ;
        }
        return m ;
    }
};

//这种有递推关系的题目，可以建立递推关系，然后用矩阵快速幂的方法进行快速求解
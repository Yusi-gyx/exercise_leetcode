class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        int r = 0, s = 1, t = 1;
        for(int i = 3; i <= n ; i ++)
        {
            int temp = r + s + t;
            r = s, s = t, t = temp;
        }
        return t;
    }
};


//矩阵快速幂
#include <vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        vector<vector<long>> q = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};    //乘幂矩阵
        vector<vector<long>> res = pow(q, n);    //求矩阵的n次幂
        return res[0][2];
    }

    vector<vector<long>> pow(vector<vector<long>>& a, long n) {
        vector<vector<long>> ret = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {                    //查看数字的二进制最低位是不是1
                ret = multiply(ret, a);            //如果是1，则将矩阵a乘进结果中
            }
            n >>= 1;                               //将n右移1位，相当于除以2
            a = multiply(a, a);                    //将矩阵a平方，判断下一个二进制位是否需要乘进结果中
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {        //定义矩阵相乘的方法
        vector<vector<long>> c(3, vector<long>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
            }
        }
        return c;
    }
};
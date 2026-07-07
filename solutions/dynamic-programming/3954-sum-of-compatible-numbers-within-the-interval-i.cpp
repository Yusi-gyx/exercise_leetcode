//方法一：暴力枚举
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int i = n - k; i <= n + k; i ++)
            if((i > 0) && ((n & i) == 0)) sum += i;            //==的运算优先级比&高，注意这个问题
        return sum;
    }
};

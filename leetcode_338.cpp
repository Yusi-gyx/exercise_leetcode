//方法一：布莱恩克尼汉算法（按位与操作，每次去掉数字最右边的1，重复1的个数次）
/*
class Solution {
public:
    #include<vector>
    vector<int> countBits(int n) {
        vector<int> bits(n + 1) ;
        for(int i = 0 ; i <= n ; i ++)
        {
            int count = 0 , x = i ;
            while(x)                      //当数字的所有1都变成0之后就停止
            {
                count ++ ;
                x = x & (x - 1) ;         //核心：按位与操作，将最右边的1变成0
            }
            bits [i] = count ;
        }
        return bits ;
    }
};
*/

//思考：每次数数字最右边的1


//方法二：最高有效位

/*
class Solution {
public:
    #include<vector>
    vector<int> countBits(int n) {
        vector<int> bits(n + 1) ;
        int maxbits = 0 ;
        for(int i = 1 ; i <= n ; i ++)
        {
            if((i & (i - 1)) == 0)   //注意：==的优先级高于&，所以这里加了括号才正确
            {
                bits [i] = 1 ;
                maxbits = i ;
            }
            else 
            {
                bits [i] = bits [i - maxbits] + 1 ;
            }
        }

        return bits ;
    }
};

更简洁的写法：
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        int highBit = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            bits[i] = bits[i - highBit] + 1;    //将两种情况进行合并
        }
        return bits;
    }
};
*/

//思考：及时更新第一位1代表的数字，减去这个数字之后，剩下的数字的1的个数已经计算过了，再加上第一个1就好

//方法三：最低有效位
/*
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i >> 1] + (i & 1);         //数字右移1位相当于将数字除以2，奇数少了一个1，偶数没有少
        }
        return bits;
    }
};
*/

//思考：将最后一个（有效）位去掉后，数字也一定变小了，可以利用以前的数据

//方法四：最低设置位

class Solution {
public:
    #include<vector>
    vector<int> countBits(int n) {
        vector<int> bits(n + 1) ;
        for(int i = 1 ; i <= n ; i ++)
        {
            bits [i] = bits [i & (i - 1)] + 1 ;
        }
        return bits ;
    }
};

//思考：方法三中去掉的是数字的最后一位（无论是0还是1），去掉后有奇偶的差别，而方法四去掉数字最右边的1，都需要小数字加上一个1
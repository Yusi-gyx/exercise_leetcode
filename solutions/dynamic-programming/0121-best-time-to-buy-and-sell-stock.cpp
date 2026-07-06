//方法一：暴力解法 O(n2)
/*
class Solution {
public:
    #include<vector>
    int maxProfit(vector<int>& prices) {
        int income = 0 ;
        for(int i = 0 ; i < prices.size() - 1 ; i ++)
        {
            for(int j = i + 1 ; j < prices.size() ; j ++)
            {
                if(prices [j] - prices [i] > income) income = prices [j] - prices [i] ;
            }
        }
        return income ;
    }
};
*/

//方法二：dp
/*
class Solution {
public:
    #include<vector>
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp (n , vector<int>(2)) ;
        dp [0][0] = 0 ;                      //卖股票
        dp [0][1] = prices [0] ;           //买股票
        for(int i = 1 ; i < n ; i ++)
        {
            dp [i][0] = max(dp [i - 1][0] , prices [i] - dp [i - 1][1]) ;
            dp [i][1] = min(dp [i - 1][1] , prices [i]) ;
        }
        return dp [n - 1][0] ;
    }
};
*/

//方法二优化：
class Solution {
public:
    #include<vector>
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        int maxprice = 0 ;
        int mincost = prices [0] ;
        for(int i = 1 ; i < n ; i ++)
        {
            maxprice = max(maxprice , prices [i] - mincost) ;
            mincost = min(prices [i] , mincost) ;
        }
        return maxprice ;
    }
};

//思考：本题只能买进或者卖出一次，需要找到最低买进价和最高卖出价，所以只需要记录当前最高的两个值，相比于方法二空间节省了很多，分配内存的时间也少了很多
//每天都在记忆买入最低价，同时后面的每一天都思考：如果今天卖出，利润能不能超过前面的记录，如果能够超出，那么就更新利润
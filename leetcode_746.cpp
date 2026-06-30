#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f = cost [0], g = cost [1];    //进行初始化
        int dp = 2;
        while(dp < n)
        {
            int temp = (g + cost [dp] < f + cost [dp])? g + cost [dp] : f + cost [dp];
            f = g;
            g = temp;
            // cout <<"台阶为："<< dp << " f = " << f << "g = " << g << endl;
            dp ++;      //完成一次迭代
        }
        return g > f? f : g;
    }
};

int main ()
{
    vector<int> cost;
    int n = 0;
    cin >> n;
    Solution a;
    for(int i = 0 ; i < n ; i ++) 
    {
        int num;
        cin >> num;
        cost.push_back(num);
    }
    cout << a.minCostClimbingStairs(cost);
    return 0;
}
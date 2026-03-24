#include<iostream>
#include<vector>
using namespace std ;

//方法一：暴力求解法（动态向量）
/*
int main ()
{
    int rowIndex ;
    cin >> rowIndex ;
    vector<vector<int>> arr(rowIndex + 1) ;
        for(int i = 0 ; i <= rowIndex ; i ++)
        {
            arr [i].resize(i + 1) ;
            arr [i][0] = 1 ;
            arr [i][i] = 1 ;
            for(int j = 1 ; j < i ; j ++)
                arr [i][j] = arr [i - 1][j] + arr [i - 1][j - 1] ;
        }
        for(int i = 0 ; i <= rowIndex ; i ++)
            cout << arr [rowIndex][i] << " "  ;
        return 0 ;
}
*/

//方法二：滚动数组

int main ()
{
    int rowIndex ;
    cin >> rowIndex ;
    vector<int> arr (rowIndex + 1) ;
    arr [0] = 1 ;
    for(int i = 1 ; i <= rowIndex ; i ++)
    {
        for(int j = i ; j > 0 ; j --)
        {
            arr [j] += arr [j - 1] ;
        }
    }
    for(int i = 0 ; i <= rowIndex ; i ++)
            cout << arr [i] << " "  ;
        return 0 ;
}

//思想：方法一中的动态向量中的数据没有完全利用，实际上只需要上一行的数据，考虑使用滚动数组降低空间复杂度
//下一行中的每一项等于上一行相同索引值的项和其前一项的和，所以可以从末尾开始逐个利用上一行的数据，前面的项的计算不会用到已经改变的项

//方法三：利用组合数公式，同一行的相邻项之间有确定的递推关系，而每一行的第一项都是1，可以用线性递推的方式
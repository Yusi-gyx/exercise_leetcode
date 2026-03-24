//方法一：双指针法
/*
class Solution {
public:
    #include<string>
    bool isSubsequence(string s, string t) {
        int n = t.length() , m = s.length() ;
        if(m == 0) return true ;
        if(n == 0) return false ;
        int j = 0 ;
        for(int i = 0 ; i < n ; i ++)
        {
            if(t [i] == s [j])
            {
                j ++ ;
            }
            if(j == m) return true ;
        }
        return false ;
    }
};
*/


//思考：这里使用i,j来表示字母在两个字符串中的位置，不论t中的字母是否匹配，i都需要向后移动一位直到完成匹配或者遍历完毕，每次匹配优先先找到的字母

//方法二：动态规划

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //先通过动态规划对s进行预处理
        int n = t.size() ;
        int ** record = new int* [n + 1] ;
        for(int i = 0 ; i <= n ; i ++)
        {
            record [i] = new int [26] ;
            if(i == n) 
            {
                for(int j = 0 ; j <= 25 ; j ++) record [i][j] = n ;
            }
        }
        for(int i = n - 1 ; i >= 0 ; i --)
        {
            for(int j = 0 ; j <= 25 ; j ++)
            {
                if(t [i] == 'a' + j) record [i][j] = i ;
                else record [i][j] = record [i + 1][j] ;
            }
        }

        //对输入字符串进行判断
        bool find = true ;
        int p = 0 ;
        for(int i = 0 ; i < s.size() ; i ++)
        {
            if(record [p][(int)s [i] - (int)('a')] == n)
            {
                find = false ;
                break ;
            }
            else p = record [p][(int)s [i] - (int)('a')] + 1 ;
        }


        for(int i = 0 ; i <= n ; i ++)
            delete [] record [i] ;
        delete [] record ;

        return find ;

    }
};
*/
//思考：这个题目的进阶模式需要利用动态规划的状态机进行实现，通过预处理记录在这一个字母之后下一个制定字母出现的位置


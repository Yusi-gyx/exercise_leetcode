#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//方案一：简单枚举+动态规划
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        //边界情况处理
        if(sequence.size() < word.size()) return 0;
        //首先建立dp数组，并单独处理size-1位置情况
        vector<int> f(sequence.size(), 0);
        f[word.size() - 1] = 1;
        for(int i = 0 ; i < word.size(); i++)
        {
            if(sequence[i] != word[i]) {f[word.size() - 1] = 0; break;}
        }
        //递推求得后面的情况
        int k = word.size();   //常数化
        for(int i = word.size(); i < sequence.size(); i++)
        {
            int v = 1;
            for(int j = 0; j < k; j++)
            {
                if(word [j] != sequence [(i - k + 1) + j]) {v = 0; break;}
            }
            f [i] = (v == 1)?  f[i - k] + v : 0;
        }
        //遍历向量找到对应的最大重复数
        int maximum = 0;
        for(auto& x: f) maximum = (x > maximum)? x:maximum;
        return maximum;
    }
};


//方案一：解答版
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        if (n < m) {
            return 0;
        }

        vector<int> f(n);          //默认初始化为0
        for (int i = m - 1; i < n; ++i) {         //word.size()-1位置的逻辑相同，可以一起处理
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                if (sequence[i - m + j + 1] != word[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                f[i] = (i == m - 1 ? 0 : f[i - m]) + 1;        //在这里判断是否为word.size() - 1，很优美的三元表达式
            }
        }
        
        return *max_element(f.begin(), f.end());
    }
};



//方案二：KMP算法+动态规划
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        if (n < m) {
            return 0;
        }

        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j != -1 && word[j + 1] != word[i]) {
                j = fail[j];
            }
            if (word[j + 1] == word[i]) {
                fail[i] = j + 1;
            }
        }

        vector<int> f(n);
        int j = -1;
        for (int i = 0; i < n; ++i) {
            while (j != -1 && word[j + 1] != sequence[i]) {
                j = fail[j];
            }
            if (word[j + 1] == sequence[i]) {
                ++j;
                if (j == m - 1) {
                    f[i] = (i >= m ? f[i - m] : 0) + 1;
                    j = fail[j];
                }
            }
        }

        return *max_element(f.begin(), f.end());
    }
};
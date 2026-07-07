#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//我的代码（一遍过！！！），递推时找到前面最近的不同子串（保证是最长的）
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<vector<int>> components(n);
        vector<int> f(n, 1);
        components[0].push_back(0);

        for(int k = 1; k < n; k++)
        {
            bool flag = false;
            int pre = 0;
            if(groups[k])
            {
                for(int i = k - 1; i >= 0; i--)      //check
                {
                    if(groups [i] == 0) {flag = true; pre = i; break;}
                }

                if(flag)    //前面有可添加的子串
                {
                    components [k] = components [pre];
                    components [k].push_back(k);
                    f[k] += f[pre];
                }
                else        //前面没有可添加的子串
                {
                    components [k].push_back(k);
                }
            }
            else
            {
                for(int i = k - 1; i >= 0; i--)      //check
                {
                    if(groups [i] == 1) {flag = true; pre = i; break;}
                }

                if(flag)    //前面有可添加的子串
                {
                    components [k] = components [pre];
                    components [k].push_back(k);
                    f[k] += f[pre];
                }
                else        //前面没有可添加的子串
                {
                    components [k].push_back(k);
                }
            }
        }
        int index = 0;
        for(int i = 1 ; i < n ; i ++)
        {
            if(f[i] > f[index]) index = i;
        }
        int m = f[index];
        vector<string> res(m);
        for(int i = 0; i < m ; i ++) res [i] = words[components[index][i]];
        return res;
    }
};

// 重构版本：算法不变（向前找最近的、组别不同的子串，DP 记录长度与路径），
// 合并原来 groups[k]==0/1 两个几乎相同的分支，简化结构。
class SolutionRefactored {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> f(n, 1);   // f[i]: 以 i 结尾的最长子序列长度
        vector<int> pre(n, -1);// pre[i]: 前驱下标，用于回溯               //此处的前驱下标非常好，值得学习，降低空间复杂度

        for (int k = 1; k < n; k++) {
            // 向前找最近的、组别不同的元素，接在其后即可保证最长
            for (int i = k - 1; i >= 0; i--) {
                if (groups[i] != groups[k]) {
                    f[k] = f[i] + 1;
                    pre[k] = i;
                    break;
                }
            }
        }

        // 找到最长子序列的结尾下标
        int end = 0;
        for (int i = 1; i < n; i++)
            if (f[i] > f[end]) end = i;

        // 沿 pre 回溯，逆序收集后再翻转
        vector<string> res;
        for (int i = end; i != -1; i = pre[i])               //回溯方法，将下一个下标指向当前下标的前驱
            res.push_back(words[i]);
        reverse(res.begin(), res.end());     //翻转向量得到正确答案
        return res;
    }
};


//方法二：贪心
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {           //贪心算法，一旦遇到与前面不相等的子串就加入其中
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};
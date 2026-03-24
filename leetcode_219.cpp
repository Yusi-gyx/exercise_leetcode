//方法一：哈希表法

/*
class Solution {
public:
    #include<vector>
    #include<unordered_map>
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numMap ;

        for(int i = 0 ; i < nums.size() ; i ++)
        {
            if(numMap.count(nums[i]) && i - numMap[nums[i]] <= k)
                return true ;
            numMap [nums [i]] = i ;
        }
        return false ;
    }   
};
*/

/*思考：利用哈希表建立映射关系，将第一次见到的数字加入哈希表，当再次遇到相同数字时，查询哈希表中记录的
索引，判断两个索引是否满足要求，若不满足要求，需要更新数字的索引为最近的一次（相当于记录每一个数字的最大下标）*/

//方法二：滑动窗口
class Solution {
public:
    #include<vector>
    #include<unordered_map>
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i ++)
        {
            if(i > k)
            {
                s.erase(nums [i - k - 1]) ;
            }
            if(s.count(nums [i]))
            {
                return true ;
            }
            s.emplace(nums [i]) ;
        }
        return false ;
    }
};
/*思考：有一个长度为k的滑动窗口，当窗口向右移动一个位置，将窗口最左侧的数字移除，然后判断窗口中是否有相同的数字
，再将这个数字加入哈希集合，遍历数组*/
//注意：移除操作和判断操作不能反，否则很有可能错误加入距离为k+1的数字
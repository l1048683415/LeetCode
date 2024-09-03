/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string p = "#";
        int maxn = 0;
        string tmp = "";
        for(int i = 0;i < s.size();i++){
            p = p + s[i] + '#';
        }
        for(int j = 1;j < p.size();j++){
            int index = 1;
            while(j + index < p.size() && j - index >= 0){
                if(p[j + index] == p[j - index]) index++;
                else break;
            }
            if(maxn < index) {
                maxn = index;
                tmp = "";
                tmp = string(p.begin() + j - index+1, p.begin() + j + index);
            }
        }
        string ans = "";
        for(int k = 0;k < tmp.size();k++){
            if(tmp[k] != '#') ans = ans + tmp[k];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */


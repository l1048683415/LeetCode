/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30204
 *
 * [2] 两数相加
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

 //Definition for singly-linked list.
//  struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while(l1 ||l2 ){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum  = n1 + n2 + carry;
            carry = sum / 10;
            if(head == nullptr){
                head = tail = new ListNode(sum % 10);
            }else{
                tail->next = new ListNode(sum % 10);//链表new到next节点
                tail = tail->next;
            }
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next; //链表后移前要判断null，操作完链表记得向后移
        }
        if(carry){
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */


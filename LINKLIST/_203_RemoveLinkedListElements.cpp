/**
 * 本代码来自 CSON 官方视频课程，由 @CSON 提供
 * 题目来源：http://leetcode.com
 * - CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
 * - 讲师：Edward Shi
 * - 官方网站：https://cspiration.com
 * - 版权归CSON所有，禁止转载
 */
// method1
class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = dummy;
    while (p->next != nullptr) {
      if (p->next->val == val) {
        p->next = p->next->next;
      } else {
        p = p->next;
      }
    }
    return dummy->next;
  }
};
// method2
class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) return head;
    ListNode *p = head;
    while (p->next != nullptr) {
      if (p->next->val == val) {
        p->next = p->next->next;
      } else {
        p = p->next;
      }
    }
    return head->val == val ? head->next : head;
  }
};
// method 3
class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
  }
};
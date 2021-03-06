/*61. Rotate List
Medium

1498

1048

Add to List

Share
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  public ListNode rotateRight(ListNode head, int k) {
    // base cases
    if (head == null) return null;
    if (head.next == null) return head;

    // close the linked list into the ring 关键处理技巧，串成环
    ListNode old_tail = head;
    int n;
    for(n = 1; old_tail.next != null; n++)
      old_tail = old_tail.next;
    old_tail.next = head;

    //记住k有可能大于n，得处理这种情况
    // and new head : (n - k % n)th node
    // find new tail : (n - k % n - 1)th node
    ListNode new_tail = head;
    for (int i = 0; i < n - k % n - 1; i++)//关键点 n - k % n - 1;
      new_tail = new_tail.next;//new tail : (n - k % n - 1)th node
    ListNode new_head = new_tail.next;//new head : (n - k % n)th node

    // break the ring
    new_tail.next = null;

    return new_head;
  }
}
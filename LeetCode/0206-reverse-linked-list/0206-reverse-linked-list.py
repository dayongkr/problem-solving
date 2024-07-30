# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rec(self, prev: Optional[ListNode], head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next == None:
            head.next = prev
            return head

        next_head = head.next
        head.next = prev

        return self.rec(head, next_head)
        
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head

        next_head = head.next
        head.next = None

        return self.rec(head, next_head)
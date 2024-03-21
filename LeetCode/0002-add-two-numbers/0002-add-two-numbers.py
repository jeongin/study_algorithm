# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyHead = ListNode(0)
        tail = dummyHead
        carry = 0
        
        while l1 is not None or l2 is not None or carry != 0:
            d1 = l1.val if l1 else 0
            d2 = l2.val if l2 else 0
            
            sum_d = d1 + d2 + carry
            
            digit = sum_d % 10
            carry = sum_d // 10
            
            new_node = ListNode(digit)
            tail.next = new_node
            tail = new_node
            
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        result = dummyHead.next
        dummyHead.next = None
        
        return result
            

        
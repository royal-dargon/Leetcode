import heapq


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    @staticmethod
    def mergeKLists(self, lists):
        if not lists:
            return None
        dummy = ListNode(-1)
        p = dummy
        pq = []
        for head in lists:
            while head:
                heapq.heappush(pq, head.val)
                head = head.next

        while pq:
            temp = ListNode(heapq.heappop(pq), None)
            p.next = temp
            p = p.next
        return dummy.next


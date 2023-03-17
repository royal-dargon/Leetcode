
    def partition(self, head, x):
        head1 = ListNode()
        head2 = ListNode()
        p1, p2 = head1, head2
        p = head
        while p is not None:
            if p.val >= x:
                p1.next = p
                p1 = p1.next
            else:
                p2.next = p
                p2 = p2.next
            temp = p.next
            p.next = None
            p = temp
        p2.next = head1.next
        return head2.next





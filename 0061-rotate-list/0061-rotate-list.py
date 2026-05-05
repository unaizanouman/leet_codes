class Solution:
    def rotateRight(self, head, k):
        if not head or not head.next or k==0:return head
        n=1
        cur=head
        while cur.next:
            cur=cur.next
            n+=1
        cur.next=head
        k%=n
        steps=n-k
        cur=head
        for _ in range(steps-1):
            cur=cur.next
        new_head=cur.next
        cur.next=None
        return new_head
#!/usr/bin/env python

# https://leetcode.com/problems/palindrome-linked-list/

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Given a singly linked list, determine if it is a palindrome.
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 1. Find list length O(n)
        count = 0
        p = head
        while p is not None:
            count += 1
            p = p.next

        # 2. Reverse first part of the list O(n/2)
        count_2 = count // 2
        head_to_left = head
        prev = None
        while count_2 > 0:
            count_2 -= 1
            tmp = head_to_left.next
            head_to_left.next = prev
            prev = head_to_left
            head_to_left = tmp
        head_to_right = head_to_left
        if count % 2 == 1:
            head_to_right = head_to_right.next
        head_to_left = prev

        # 3. Check that reversed part and second part are equal O(n/2)
        l = head_to_left
        r = head_to_right
        while l is not None:
            if l.val != r.val:
                return False
            l = l.next
            r = r.next
        return True

def test():
    s = Solution()
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    assert(s.isPalindrome(head) == False)

    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    assert(s.isPalindrome(head) == False)

    head = ListNode(1, ListNode(2, ListNode(3, ListNode(2, ListNode(1)))))
    assert(s.isPalindrome(head) == True)

    head = ListNode(1, ListNode(2, ListNode(2, ListNode(1))))
    assert(s.isPalindrome(head) == True)

    head = ListNode(1, ListNode(1))
    assert(s.isPalindrome(head) == True)

    head = ListNode(1)
    assert(s.isPalindrome(head) == True)

    head = None
    assert(s.isPalindrome(head) == True)


if __name__ == '__main__':
    test()
import sde_sheet.day_05.ListNode;

import java.util.*;

public class ListPalindrome {
    static class Solution {
        public boolean isPalindrome2(ListNode head) {
            ListNode temp = head;
            Stack<Integer> stack = new Stack <>();
            while(temp != null){
                stack.push(temp.val);
                temp = temp.next;
            }
            temp = head;
            while(temp != null){
                if(stack.pop() != temp.val)
                    return false;
                temp = temp.next;
            }
            return true;
        }
    }

    public boolean isPalindrome1(ListNode head) {
        ListNode temp = head;
        int len = 0, mid = 0;
        while(temp != null){
            len++;
            temp = temp.next;
        }
        mid = len/2;
        int [] stack = new int [mid];
        int t = 0;
        temp = head;
        for(int i = 0; i < mid; i++){
            stack[t++] = temp.val;
            temp = temp.next;
        }
        temp = (len%2 == 0) ? temp:temp.next;
        for(t-=1;t >= 0 && temp != null; t--){
            if(stack[t] != temp.val)
                return false;
            temp = temp.next;
        }
        return true;
    }

    public ListNode reverseList(ListNode head){
        if(head == null)
            return head;
        ListNode prev = head, curr = head.next;
        while(curr != null){
            ListNode front = curr.next;
            curr.next = prev;
            prev = curr;
            curr = front;
        }
        head.next = null;
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null)
            return true;
        ListNode slow = head, fast = head;
        while(fast.next != null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode reverse = reverseList(slow.next);
        ListNode temp = head;
        fast = reverse;
        while(fast != null){
            if(temp.val != fast.val){
                reverseList(reverse);
                return false;
            }
            temp = temp.next;
            fast = fast.next;
        }

        reverseList(reverse);
        return true;
    }
}

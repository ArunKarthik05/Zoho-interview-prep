import sde_sheet.day_05.ListNode;

import java.util.Scanner;

public class RemoveNthEnd {
    static class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            ListNode fast = head, slow = head;
            for(int i = 0; i < n; i++)
                fast = fast.next;
            if(fast == null){
                head = head.next;
                return head;
            }
            while(fast.next != null){
                slow = slow.next;
                fast = fast.next;
            }
            if(n == 1){
                slow.next = null;
                return head;
            }
            slow.next = slow.next.next;
            return head;
        }

        public ListNode removeNthFromEnd1(ListNode head, int n) {
            int len = 0;
            ListNode temp = head;
            while(temp != null){
                len++;
                temp = temp.next;
            }
            if(len == n){
                head = head.next;
                return head;
            }
            len = len-n;

            temp = head;
            while(len-- > 1){
                temp = temp.next;
            }
            if(n == 1){
                temp.next = null;
                return head;
            }
            temp.next = temp.next.next;
            return head;
        }
    }


    private static void printList(ListNode head) {
        if(head == null){
            System.out.println("List is empty.");
            return;
        }
        ListNode temp = head;
        while (temp != null){
            System.out.print(temp.val + " -> ");
            temp = temp.next;
        }
        System.out.println("null");

    }

    private void createLinkedList(int n) {
        Scanner input = new Scanner(System.in);
        ListNode curr  = head;
        for (int i = 0; i < n; i++) {
            int x = input.nextInt();
            ListNode temp = new ListNode(x, null);
            if(head == null){
                head = temp;
                curr = temp;
            }
            else {
                curr.next = temp;
                curr = temp;
            }
        }
        printList(head);

    }

    static ListNode head = null;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n  = input.nextInt();
        RemoveNthEnd obj = new RemoveNthEnd();
        obj.createLinkedList(n);
        int remove = input.nextInt();
        printList(new Solution().removeNthFromEnd(head,remove));
    }
}

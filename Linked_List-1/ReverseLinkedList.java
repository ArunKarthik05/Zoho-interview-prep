import sde_sheet.day_05.ListNode;

import java.util.Scanner;

public class ReverseLinkedList {
    static class Solution {

        // Using Extra Space
        public ListNode reverseList2(ListNode head) {
            if (head == null)
                return head;
            ListNode reverse = new ListNode(head.val, null);
            while (head.next != null) {
                head = head.next;
                reverse = new ListNode(head.val, reverse);
            }
            return reverse;
        }

        // Reverse In-Place
        public ListNode reverseList1(ListNode head) {
            if(head == null)
                return head;
            ListNode prev = head;
            ListNode curr = head.next;
            while(curr != null){
                ListNode temp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = temp;
            }
            head.next = null;
            return prev;
        }
        public ListNode reverseList(ListNode head) {
            if(head == null || head.next == null)
                return head;
            ListNode newHead = reverseList(head.next);
            ListNode front = head.next;
            front.next = head;
            head.next = null;
            printList(newHead);
            return newHead;
        }
    }

    static ListNode head = null;
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n  = input.nextInt();
        ReverseLinkedList obj = new  ReverseLinkedList();
        obj.createLinkedList(n);
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

        printList(new Solution().reverseList(head));

    }
}

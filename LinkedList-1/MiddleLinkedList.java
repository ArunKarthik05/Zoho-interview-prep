import sde_sheet.day_05.ListNode;

import java.util.Scanner;

public class MiddleLinkedList {
    static class Solution {

        /*
        fast and slow pointers
        Tortoise-Hare-Approach
         */

        public ListNode middleNode(ListNode head) {
            ListNode slow = head, fast = head;
            while(fast != null && fast.next != null){
                slow = slow.next;
                fast = fast.next.next;
            }

            return slow;
        }

        // Making traversal two times;
        public ListNode middleNode1(ListNode head) {
            ListNode temp = head;
            int n = 0;
            while(temp != null){
                temp = temp.next;
                n++;
            }
            int mid = n/2;
            n = 0;
            temp = head;
            while(n != mid){
                temp = temp.next;
                n++;
            }
            return temp;
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
        printList(new Solution().middleNode(head));

    }

    static ListNode head = null;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n  = input.nextInt();
        MiddleLinkedList obj = new MiddleLinkedList();
        obj.createLinkedList(n);
    }
}

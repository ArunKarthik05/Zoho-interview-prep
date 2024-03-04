
import sde_sheet.day_05.ListNode;

import java.util.Scanner;

public class AddTwoNumbers {
    static class Solution {
        public ListNode addTwoNumbers1(ListNode l1, ListNode l2) {
            long sum1 = l1.val, sum2 = l2.val, i;
            l1 = l1.next;
            l2 = l2.next;
            for(i = 10; l1 != null; i*=10){
                sum1 += i*l1.val;
                l1 = l1.next;
            }
            for(i = 10; l2 != null; i*=10){
                sum2 += i*l2.val;
                l2 = l2.next;
            }

            long ans = sum1 + sum2;
            if(ans == 0)
                return new ListNode(0);
            ListNode head = new ListNode(0,null);
            ListNode temp = head;
            temp.val = (int) (ans%10);
            ans = ans/10;
            while(ans != 0){
                ListNode next = new ListNode();
                temp.next = next;
                temp = temp.next;
                temp.val = (int)(ans%10);
                ans = ans/10;

            }
            temp.next = null;

            return head;

        }

        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode head = new ListNode();
            ListNode temp = head;
            int carry = 0, sum = 0;
            while(l1 != null || l2 != null || carry == 1){
                sum = carry;
                if(l1 != null){
                    sum += l1.val;
                    l1 = l1.next;
                }
                if(l2 != null){
                    sum += l2.val;
                    l2 = l2.next;
                }
                ListNode next = new ListNode(sum%10);
                carry = sum/10;
                temp.next = next;
                temp = temp.next;
            }
            temp = null;
            return head.next;
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

    private ListNode createLinkedList(int n) {
        Scanner input = new Scanner(System.in);
        ListNode head = null;
        ListNode curr  = new ListNode();
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
        return head;
    }

    static ListNode list1 = null, list2 = null;
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        AddTwoNumbers obj = new AddTwoNumbers();
        int n  = input.nextInt();
        list1 = obj.createLinkedList(n);
        int m  = input.nextInt();
        list2 = obj.createLinkedList(m);
        printList(new Solution().addTwoNumbers(list1,list2));

    }
}

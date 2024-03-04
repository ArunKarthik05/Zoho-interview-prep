import sde_sheet.day_05.ListNode;

import java.util.Scanner;

public class DeleteNode {
    static class Solution {
        public void deleteNode(ListNode node) {
            ListNode last = node;
            while(node.next != null){
                node.val = node.next.val;
                last = node;
                node = node.next;
            }
            last.next = null;
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
        DeleteNode obj = new DeleteNode();
        obj.createLinkedList(n);
        int remove = input.nextInt();
        ListNode temp = head;
        while(temp.val != remove){
            temp = temp.next;
        }
        new Solution().deleteNode(temp);
        printList(head);
    }
}

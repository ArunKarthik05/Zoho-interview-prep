import sde_sheet.day_05.ListNode;

import java.util.Scanner;

public class MergeSortedList {
    class Solution {

        // Creating new List
        public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
            if(list1 == null)
                return list2;
            if(list2 == null)
                return list1;
            ListNode head = null, track = null;
            ListNode temp1 = list1, temp2 = list2;
            if(temp1.val < temp2.val){
                head = temp1;
                temp1 = temp1.next;
            }
            else{
                head = temp2;
                temp2 = temp2.next;
            }
            track = head;
            while(temp1 != null && temp2 != null){
                if(temp1.val < temp2.val){
                    track.next = temp1;
                    track = temp1;
                    temp1 = temp1.next;
                }
                else{
                    track.next = temp2;
                    track = temp2;
                    temp2 = temp2.next;
                }
            }
            while(temp1 != null){
                track.next = temp1;
                track = temp1;
                temp1 = temp1.next;
            }
            while(temp2 != null){
                track.next = temp2;
                track = temp2;
                temp2 = temp2.next;
            }
            track.next = null;
            printList(head);
            return head;
        }

        // Sorting using inPlace
        public ListNode mergeTwoLists1(ListNode list1, ListNode list2) {
            if(list1 == null)
                return list2;
            if(list2 == null)
                return list1;
            ListNode head = list1, track = null;
            if(list1.val > list2.val){
                head = list2;
                list2 = list1;
                list1 = head;
            }
            while(list1 != null && list2 != null){
                while(list1 != null && list1.val <= list2.val){
                    track = list1;
                    list1 = list1.next;
                }
                track.next = list2;
                list2 = list1;
                list1 = track.next;
                track = list1;
            }

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

    private void merge(){
        printList(new Solution().mergeTwoLists1(list1,list2));
    }
    static ListNode list1 = null, list2 = null;
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        MergeSortedList obj = new MergeSortedList();
        int n  = input.nextInt();
        list1 = obj.createLinkedList(n);
        int m  = input.nextInt();
        list2 = obj.createLinkedList(m);
        obj.merge();

    }
}

import sde_sheet.day_05.ListNode;

public class ReverseKGroup {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode() {}
     *     ListNode(int val) { this.val = val; }
     *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    class Solution {
        public ListNode reverseList(ListNode head) {
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

        ListNode kthNode(ListNode start, int k){
            int len = 1;
            while(len < k && start != null){
                start = start.next;
                len++;
            }
            return start;
        }
        public ListNode reverseKGroup(ListNode head, int k) {
            if(head == null || head.next == null){
                return head;
            }
            ListNode temp = head, knode=head, pnode = temp,nnode;
            while(temp!=null){
                knode = kthNode(temp,k);
                if(knode == null){
                    pnode.next = temp;
                    break;
                }
                nnode = knode.next;
                knode.next = null;
                knode = reverseList(temp);
                if(temp == head)
                    head = knode;
                else
                    pnode.next = knode;
                pnode = temp;
                temp = nnode;
                knode = temp;
            }
            return head;
        }

    }
}

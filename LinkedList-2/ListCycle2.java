import sde_sheet.day_05.ListNode;

public class ListCycle2 {
    static class Solution {
        public ListNode detectCycle(ListNode head) {
            if(head == null || head.next == null)
                return null;
            ListNode slow = head.next, fast = head.next.next;
            while(slow != fast){
                if(fast == null || fast.next == null)
                    return null;
                fast = fast.next.next;
                slow = slow.next;
            }
            slow = head;
            while(fast != slow){
                slow = slow.next;
                fast = fast.next;
            }
            return slow;
        }
    }
}

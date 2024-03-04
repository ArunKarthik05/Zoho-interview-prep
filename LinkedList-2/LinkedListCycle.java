import sde_sheet.day_05.ListNode;

public class LinkedListCycle {
    static class Solution {
        public boolean hasCycle(ListNode head) {
            if(head == null || head.next == null){
                return false;
            }
            ListNode slow = head.next, fast = head.next.next;
            while(slow != fast){
                if(fast == null || fast.next == null)
                    return false;
                fast = fast.next.next;
                slow = slow.next;

            }
            return true;
        }
    }
}

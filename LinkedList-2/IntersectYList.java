import sde_sheet.day_05.ListNode;

import java.util.*;

public class IntersectYList {
    public class Solution {
        public ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
            HashSet<ListNode> nodes = new HashSet<>();
            ListNode temp = headA;
            while(temp != null){
                nodes.add(temp);
                temp = temp.next;
            }
            temp = headB;
            while(temp != null){
                if(!nodes.add(temp)){
                    return temp;
                }
                temp = temp.next;
            }
            return null;
        }

        public ListNode intersection(ListNode small, ListNode large, int diff){
            while(diff-- > 0){
                large = large.next;
            }
            while(small != null){
                if(small == large){
                    return small;
                }
                small = small.next;
                large = large.next;
            }
            return null;
        }
        public ListNode getIntersectionNode1(ListNode headA, ListNode headB) {
            int len1 = 0, len2 = 0;
            ListNode temp = headA;
            while(temp != null){
                len1++;
                temp = temp.next;
            }
            temp = headB;
            while(temp != null){
                len2++;
                temp = temp.next;
            }
            if(len1 < len2){
                return intersection(headA,headB,len2-len1);
            }
            return intersection(headB,headA,len1-len2);
        }

        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            ListNode l1 = headA, l2 = headB;
            while(l1 != l2) {
                l1 = l1.next;
                l2 = l2.next;
                if(l1 == l2) return l2;
                if(l1 == null) l1=headB;
                if(l2 == null) l2=headA;
            }

            return l1;
        }
    }
}

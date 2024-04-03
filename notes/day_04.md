# 1.Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.
### Example 1:
**Input:** head = [1,2,3,4,5]<br>
**Output:** [5,4,3,2,1]<br>
### Example 2:
**Input:** head = [1,2]<br>
**Output:** [2,1]<br>
### Example 3:
**Input:** head = []<br>
**Output:** []

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode prev = head;
        ListNode temp = head.next;
        while(temp != null){
            ListNode curr = temp.next;
            temp.next = prev;
            prev = temp;
            temp = curr;
        }
        head.next = null;
        return prev;
    }
}
```

# 
# 2.Middle of the Linked List
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
### Example 1:
**Input:** head = [1,2,3,4,5]<br>
**Output:** [3,4,5]<br>
**Explanation:** The middle node of the list is node 3.<br>
### Example 2:
**Input:** head = [1,2,3,4,5,6]<br>
**Output:** [4,5,6]<br>
**Explanation:** Since the list has two middle nodes with values 3 and 4, we return the second one.<br>
 
```java
class Solution {
    public ListNode middleNode(ListNode head) {
        if(head.next == null) return head;
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next != null){
            slow = slow.next;
            if(fast.next.next != null)
                fast = fast.next;
            fast = fast.next;
        }
        return slow;
    }
}
```

#
# 3.Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
### Example 1:
**Input:** list1 = [1,2,4], list2 = [1,3,4]<br>
**Output:** [1,1,2,3,4,4]<br>
### Example 2:
**Input:** list1 = [], list2 = []<br>
**Output:** []<br>
### Example 3:
**Input:** list1 = [], list2 = [0]<br>
**Output:** [0]<br>
```java
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
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
```
#
# 4. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.
### Example 1:
**Input:** head = [1,2,3,4,5], n = 2<br>
**Output:** [1,2,3,5]<br>
### Example 2:
**Input:** head = [1], n = 1<br>
**Output:** []<br>
### Example 3:
**Input:** head = [1,2], n = 1<br>
**Output:** [1]<br>

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null) return head;
        if(head.next == null) return null;
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
        slow.next = slow.next.next;
        return head;
    }
}
```

#
# 5.Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
### Example 1:
**Input:** l1 = [2,4,3], l2 = [5,6,4]<br>
**Output:** [7,0,8]<br>
**Explanation:** 342 + 465 = 807.
### Example 2:
**Input:** l1 = [0], l2 = [0]<br>
**Output:** [0]<br>
### Example 3:
**Input:** l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]<br>
**Output:** [8,9,9,9,0,0,0,1]<br>
```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        int sum = 0, carry = 0;
        ListNode temp = head;
        while(l1 != null || l2 != null || carry != 0){
            sum = carry;
            if(l1 != null){
                sum += l1.val;
                l1 = l1.next;
            }
            if(l2 != null){
                sum += l2.val;
                l2 = l2.next;
            }
            temp.next = new ListNode(sum%10);
            carry = sum/10;
            temp = temp.next;
        }
        return head.next;
    }
}
```

#
# 6.Delete Node in a Linked List
There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
- The value of the given node should not exist in the linked list.
- The number of nodes in the linked list should decrease by one.
- All the values before node should be in the same order.
- All the values after node should be in the same order.
### Custom testing:
- For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
- We will build the linked list and pass the node to your function.
- The output will be the entire list after calling your function.
 
### Example 1:
**Input:** head = [4,5,1,9], node = 5<br>
**Output:** [4,1,9]<br>
**Explanation:** You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
### Example 2:
**Input:** head = [4,5,1,9], node = 1<br>
**Output:** [4,5,9]<br>
**Explanation:** You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.


```java
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```
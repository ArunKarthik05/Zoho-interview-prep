#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
     ListNode* middleNode(ListNode* head) {
        int count =1;
        ListNode* temp = head;
        while(temp->next ){
            temp = temp->next;
            count++;
        }
        for( int i=1;i<count/2+1;i++ ){
            head = head->next;
        }
        return head;
    }
};

int main() {
    // Create a sample linked list for testing
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);

    // Create a Solution object
    Solution obj;

    // Test the middleNode function
    ListNode* middle = obj.middleNode(head);
    if (middle)
        cout << "Middle node value: " << middle->val << endl;
    else
        cout << "List is empty" << endl;

    ListNode *temp = middle;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    // Don't forget to free the memory allocated for the linked list
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    cout<<"ceil:"<<ceil(static_cast<double>(5)/2);
    return 0;
}

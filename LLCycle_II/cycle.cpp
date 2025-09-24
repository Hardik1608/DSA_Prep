#include<iostream>
using namespace std;


struct ListNode {
     int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL || head -> next -> next == NULL){
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

int main(){
    Solution sol;

    // Create nodes
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // Link nodes to form the list: 3 -> 2 -> 0 -> -4
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create a cycle: -4 -> 2
    node4->next = node2;

    ListNode *ans = sol.detectCycle(head);

    if (ans)
        cout << "Cycle starts at node with value: " << ans->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
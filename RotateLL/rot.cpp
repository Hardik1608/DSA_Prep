#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 1;
        int cnt = 0;
        
        if(head == NULL) return NULL;

        while(temp->next != NULL){
            temp = temp->next;
            n++;
        }
        // point the tail to the head
        temp->next = head;
        cnt = n - (k%n) - 1;

        temp = head;
        // traverse the Linked list
        while(cnt){
            temp = temp->next;
            cnt--;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};

int main() {
    // Create linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 97;
    Solution sol;
    ListNode* rotated = sol.rotateRight(head, k);

    // Print rotated list
    ListNode* curr = rotated;
    while (curr) {
        std::cout << curr->val;
        if (curr->next) std::cout << "->";
        curr = curr->next;
    }
    std::cout << std::endl;

    // Free memory
    curr = rotated;
    while (curr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
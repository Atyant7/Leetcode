/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* head1 = head;
        ListNode* slow = head, *fast = head -> next;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* head2 = slow -> next;
        slow -> next = nullptr;

        head1 = sortList(head1);
        head2 = sortList(head2);
        
        head = NULL;
        ListNode* tail = NULL;
        while(head1 != nullptr || head2 != nullptr){
            if(head1 && (head2 == nullptr || head1 -> val <= head2 -> val)){
                if(head == nullptr){
                    head = head1;
                    tail = head1;
                }else{
                    tail -> next = head1;
                    tail = tail -> next;
                }
                head1 = head1 -> next;
            }else{
                if(head == nullptr){
                    head = head2;
                    tail = head2;
                }else{
                    tail -> next = head2;
                    tail = tail -> next;
                }
                head2 = head2 -> next;
            }
        }

        return head;
    }
};
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> ok;
        for(int i = 1; i < int(v.size()) - 1; i++){
            if((v[i] > v[i-1] && v[i] > v[i+1] )|| (v[i] < v[i-1] && v[i] < v[i+1])){
                ok.push_back(i);
            }
        }
        if(int(ok.size()) < 2) return {-1,-1};
        sort(ok.begin() , ok.end());
        int mindis = INT_MAX;
        for(int i = 0; i < ok.size() - 1 ; i++){
            mindis = min(mindis , abs(ok[i] - ok[i+1]));
        }
        return {mindis, abs(ok[0] - ok[ok.size() - 1])};
    }
};
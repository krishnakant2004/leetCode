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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto const &val : nums) st.insert(val);
        return solve(st,head);
    }

    ListNode* solve(unordered_set<int> &st,ListNode* head){
        if(head == nullptr) return nullptr;

        if(st.find(head->val) != st.end()){
            return solve(st,head->next);
        }
        head->next = solve(st,head->next);
        return head;
    }

};
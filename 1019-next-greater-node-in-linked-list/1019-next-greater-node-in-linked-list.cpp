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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* it = head;
        
        // Convert the linked list to a vector
        while (it != nullptr) {
            arr.push_back(it->val);
            it = it->next;
        }
        
        int n = arr.size();
        vector<int> ans(n, 0); // Initialize the answer vector with the correct size
        stack<int> st;
        
        // Traverse the array from the end to the beginning
        for (int i = n - 1; i >= 0; --i) {
            // Maintain the stack such that the elements are always in decreasing order
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            
            // If stack is not empty, then the top of the stack is the next greater element
            if (!st.empty()) {
                ans[i] = st.top();
            }
            
            // Push the current element into the stack
            st.push(arr[i]);
        }
        
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to delete nodes from linked list present in array
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));

        // Handle head nodes to be deleted
        while (head != NULL && st.find(head->val) != st.end()) {
            head = head->next;  // skip unwanted head nodes
        }

        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (st.find(curr->next->val) != st.end()) {
                curr->next = curr->next->next;  // skip unwanted node
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
// Utility function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr);
    cout << "Original List: ";
    printList(head);

    head = modifiedList(nums, head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}

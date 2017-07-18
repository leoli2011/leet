/* First version, passed */
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return 1;
        }
    }

    return 0;
}

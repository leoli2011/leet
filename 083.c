struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }
    struct ListNode *tmp = head;
    while(tmp) {
        if (!tmp->next) {
            break;
        }

        if (tmp->val == tmp->next->val) {
            tmp->next = tmp->next->next;
        } else {
            tmp = tmp->next;
        }
    }
    return head;
}

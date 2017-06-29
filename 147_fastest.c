






struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* new_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_head->next = head;
    struct ListNode *prev = new_head;
    struct ListNode *curr = head;
    while (curr) {
        if (curr->next && curr->next->val < curr->val) {
            while (prev->next->val < curr->next->val)
                prev = prev->next;
            struct ListNode * temp = curr->next;
            curr->next = curr->next->next;
            temp->next = prev->next;
            prev->next = temp;
            prev = new_head;
        } else {
            curr = curr->next;
        }
    }
    head = new_head->next;
    return head;
}

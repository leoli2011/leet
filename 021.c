struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *start = new;
    new->next = NULL;
    while(p && q) {
        if (q->val <= p->val) {
            new->next = q;
            q = q->next;
            new->next->next = NULL;
        } else {
            new->next = p;
            p = p->next;
            new->next->next = NULL;
        }
        new = new->next;
    }

    if (p) {
        new->next = p;
    }

    if (q) {
        new->next = q;
    }

    return start->next;
}


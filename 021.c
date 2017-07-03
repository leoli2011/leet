/* my own 1, past in first round */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *start = new;
    new->next = NULL;
    while(l1 && l2) {
        if (l1->val <= l2->val) {
            new->next = l1;
            l1 = l1->next;
        } else {
            new->next = l2;
            l2 = l2->next;
        }
        new = new->next;
    }

    if (l1) {
        new->next = l1;
    }

    if (l2) {
        new->next = l2;
    }

    return start->next;
}

/* second version */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)   return l2;
    if (!l2)   return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

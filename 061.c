
/* my own first version, did not passed*/
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head) {
        return head;
    }

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    int i = 0;
    while(i < k && fast->next != NULL) {
        fast = fast->next;
        i++;
    }
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    if (i != 0) {
        dummy->next = slow->next;
        slow->next = fast->next;
        fast->next = head;
    }

    return dummy->next;
}


struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head) {
        return head;
    }

    struct ListNode *tail=head;
    struct ListNode *new=head;
    int len = 1;
    int i;
    while(tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    tail->next = head;

    if (k %= len) {
        for (i = 0; i < len-k; i++) {
            tail = tail->next;
        }
    }
    new = tail->next;
    tail->next = NULL;

    return new;
}


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len)
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};

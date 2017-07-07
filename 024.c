
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head) {
        return head;
    }
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *slow = head, *fast = head->next, *prev = dummy;
    while (fast) {
        slow->next = fast->next;
        fast->next = slow;
        prev->next = fast;
        prev = slow;
        slow = slow->next;
        if (slow) {
            fast = slow->next;
        } else  {
            break;
        }
    }

    return dummy->next;
}

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *node;
    struct ListNode **pp;

    node = head;
    pp = &head;
    while (node && node->next) {
        *pp = node->next;
        node->next = (*pp)->next;
        (*pp)->next = node;
        pp = &node->next;
        node = node->next;
    }
    return head;
}

    if(head == null)
        return head;

    ListNode dummy = new ListNode(12);
    dummy.next = head;
    ListNode slow = head, fast = head.next,  prev = dummy;

    while(fast != null) {
        slow.next = fast.next;
        fast.next = slow;
        prev.next = fast;
        prev =slow;
        slow = slow.next;
        if(slow != null)
            fast = slow.next;
        else
            break;
    }

    return dummy.next;



public ListNode swapPairs(ListNode head) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode current = dummy;
    while (current.next != null && current.next.next != null) {
        ListNode first = current.next;
        ListNode second = current.next.next;
        first.next = second.next;
        current.next = second;
        current.next.next = first;
        current = current.next.next;
    }
    return dummy.next;
}

/* my own 1 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int num = 0;
    int dpoint = 0;
    struct ListNode *cur = head;
    struct ListNode *pre;
    while (cur) {
        num++;
        cur = cur -> next;
    }
    dpoint = num - n + 1;
    if (dpoint <= 0) {
        return head;
    }

    num = 0;
    cur = head;
    pre = cur;
    while (cur) {
        num++;
        if (dpoint == 1) {
            head = head->next;
            break;
        }

        if (num == dpoint) {
            pre->next = cur->next;
            break;
        }
        pre = cur;
        cur = cur->next;
    }

    return head;
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i = 0;
    int dpoint = 0;
    struct ListNode *start = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *fast = start;
    struct ListNode *slow = start;
    start->next = head;

    while (i <= n) {
        fast = fast -> next;;
        i++;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return start->next;
}



public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode start = new ListNode(0);
    ListNode slow = start, fast = start;
    slow.next = head;

    //Move fast in front so that the gap between slow and fast becomes n
    for(int i=1; i<=n+1; i++)   {
        fast = fast.next;
    }
    //Move fast to the end, maintaining the gap
    while(fast != null) {
        slow = slow.next;
        fast = fast.next;
    }
    //Skip the desired node
    slow.next = slow.next.next;
    return start.next;
}

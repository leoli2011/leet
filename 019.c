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
    while (cur) {
        num++;
        if (num == dpoint) {
            pre->next = cur->next;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    return head;
}

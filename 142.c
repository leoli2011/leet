/**
 * first version , passed;
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *slow2;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            slow2 = head;
            while(slow != slow2) {
                slow = slow->next;
                slow2 = slow2->next;
            }
            return slow;
        }
    }

    return 0;
}


}

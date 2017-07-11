/* First version, didnot passed */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (!head) {
        return head;
    }
    if (n <= m) {
        return head;
    }
    int delta = n - m;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *pre = head;
    int i = 0;
    while(i < delta) {
        fast  = fast -> next;
        i++;
    }

    i = 0;
    while(i < m && fast->next) {
        pre = slow;
        fast = fast->next;
        slow = slow->next;
        i++;
    }

    while(slow != fast && slow->next) {
        slow->next = fast->next;
        fast->next = slow;
        slow = slow->next;
    }

    pre->next = slow;
    return head;
}

/* Second version, passed */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (!head) {
        return head;
    }
    int i;

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre = dummy;
    for (i = 0; i < m-1; i++) {
        pre = pre->next;
    }
    struct ListNode *cur = pre->next;
    struct ListNode *move = cur->next;

    for (i = 0; i < n-m; i++) {
        cur->next = move->next;
        move->next = pre->next;
        pre->next = move;
        move = cur->next;
    }

    return dummy->next;
}



public ListNode reverseBetween(ListNode head, int m, int n) {
    if(head == null) return null;
    ListNode dummy = new ListNode(0); // create a dummy node to mark the head of this list
    dummy.next = head;
    ListNode pre = dummy; // make a pointer pre as a marker for the node before reversing
    for(int i = 0; i<m-1; i++) pre = pre.next;

    ListNode start = pre.next; // a pointer to the beginning of a sub-list that will be reversed
    ListNode then = start.next; // a pointer to a node that will be reversed

    // 1 - 2 -3 - 4 - 5 ; m=2; n =4 ---> pre = 1, start = 2, then = 3
    // dummy-> 1 -> 2 -> 3 -> 4 -> 5

    for(int i=0; i<n-m; i++)
    {
        start.next = then.next;
        then.next = pre.next;
        pre.next = then;
        then = start.next;
    }

    // first reversing : dummy->1 - 3 - 2 - 4 - 5; pre = 1, start = 2, then = 4
    // second reversing: dummy->1 - 4 - 3 - 2 - 5; pre = 1, start = 2, then = 5 (finish)
    return dummy.next;
}



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        for (int i = 0; i < m - 1; i++)
            pre = pre -> next;
        ListNode* cur = pre -> next;
        for (int i = 0; i < n - m; i++) {
            ListNode* move = cur -> next; 
            cur -> next = move -> next;
            move -> next = pre -> next;
            pre -> next = move;
        }
        return new_head -> next;
    }
};


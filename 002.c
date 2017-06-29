struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num1;
    int num2;
    int carry = 0;
    struct ListNode *newhead = l1;
    struct ListNode *pre;
    while (l1 && l2) {
        pre = l1;
        num1 = l1->val;
        num2 = l2->val;
        l1->val = (num1 + num2 + carry)%10;
        carry = (num1 + num2 + carry)/10;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l2) {
        pre->next = l2;
    }
    while (l1) {
        pre = pre->next;
        num1 = l1->val;
        l1->val = (num1 + carry) % 10;
        carry  = (num1 + carry) / 10;
        l1 = l1->next;
    }
    while (l2) {
        pre = pre->next;
        num2 = l2->val;
        l2->val = (num2 + carry) % 10;
        carry  = (num2 + carry) / 10;
        l2 = l2->next;
    }

    if (carry) {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = NULL;
        pre ->next  = tmp;
    }

    return newhead;
}


public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode sentinel = new ListNode(0);
        ListNode d = sentinel;
        int sum = 0;
        while (c1 != null || c2 != null) {
            sum /= 10;
            if (c1 != null) {
                sum += c1.val;
                c1 = c1.next;
            }
            if (c2 != null) {
                sum += c2.val;
                c2 = c2.next;
            }
            d.next = new ListNode(sum % 10);
            d = d.next;
        }
        if (sum / 10 == 1)
            d.next = new ListNode(1);
        return sentinel.next;
    }
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1 = l1;
        struct ListNode* p2 = l2;
        struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
        ans->val = 0;
        struct ListNode* p = 0;
        int c = 0;
        while (p1 != 0 || p2 != 0 || c != 0) {
            if (p == 0) {
                p = ans;
            }
            else {
                p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                p->next->val = 0;
                p = p->next;
            }
            int a = p1 != 0 ? p1->val : 0;
            int b = p2 != 0 ? p2->val : 0;
            int s = (a + b + c) % 10;
            c = (a + b + c) / 10;
            p->val = s;
            p->next = 0;
            p1 = p1 == 0 ? 0 : p1->next;
            p2 = p2 == 0 ? 0 : p2->next;
        }
        return ans;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *newhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pre = newhead;
    int sum = 0;

    while (l1 || l2 ) {
        sum = sum / 10;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        pre->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        pre->next->next = NULL;
        pre->next->val = sum % 10;
        pre = pre->next;
    }

    if (sum / 10 == 1) {
        pre->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        pre->next->next = NULL;
        pre->next->val = sum / 10;
    }

    return newhead->next;
}

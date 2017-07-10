/* First version : did not passed */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *tmp = head;
    struct ListNode *pre = tmp;
    while(tmp) {
        if (!tmp->next) {
            break;
        }

        if (tmp->val == tmp->next->val) {
            tmp->next = tmp->next->next;
            if (tmp->next && tmp->val != tmp->next->val) {
                pre->next = tmp->next;
            }
        } else {
            pre = tmp;
            tmp = tmp->next;
        }
    }
    return head;
}


/* second version */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre = dummy;
    struct ListNode *cur = head;
    while(cur) {
        while (cur->next && cur->val == cur->next->val) {
            cur = cur->next;
        }

        if (pre->next == cur) {
            pre = pre->next;
        } else {
            pre->next = cur->next;
        }

        cur = cur->next;
    }
    return dummy->next;
}

public ListNode deleteDuplicates(ListNode head) {
        if(head==null) return null;
        ListNode FakeHead=new ListNode(0);
        FakeHead.next=head;
        ListNode pre=FakeHead;
        ListNode cur=head;
        while(cur!=null){
            while(cur.next!=null&&cur.val==cur.next.val){
                cur=cur.next;
            }
            if(pre.next==cur){
                pre=pre.next;
            }
            else{
                pre.next=cur.next;
            }
            cur=cur.next;
        }
        return FakeHead.next;
    }


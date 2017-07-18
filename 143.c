/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*  First version for report */
void reorderList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *middle = slow;
    struct ListNode *current = middle->next;
    struct ListNode *move;
    while(current->next) {
        move = current->next;
        current->next = move->next;
        move->next = middle->next;
        middle->next = move;
    }

    struct ListNode *p1 = head;
    struct ListNode *p2 = middle->next;
    while(p1 != middle) {
        middle->next = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = middle->next;
    }

    return head;
}


public void reorderList(ListNode head) {
            if(head==null||head.next==null) return;
            //Find the middle of the list
            ListNode p1=head;
            ListNode p2=head;
            while(p2.next!=null&&p2.next.next!=null){
                p1=p1.next;
                p2=p2.next.next;
            }
            //Reverse the half after middle  1->2->3->4->5->6 to 1->2->3->6->5->4
            ListNode preMiddle=p1;
            ListNode preCurrent=p1.next;
            while(preCurrent.next!=null){
                ListNode current=preCurrent.next;
                preCurrent.next=current.next;
                current.next=preMiddle.next;
                preMiddle.next=current;
            }
            //Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
            p1=head;
            p2=preMiddle.next;
            while(p1!=preMiddle){
                preMiddle.next=p2.next;
                p2.next=p1.next;
                p1.next=p2;
                p1=p2.next;
                p2=preMiddle.next;
            }
        }

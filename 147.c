/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <inttypes.h>
#include <sys/types.h>
typedef struct time_charge {
    char type;
    char date[8];
    char plugged;
    char warn_type;
}__attribute__((packed, aligned(1))) time_charge_t;

static time_charge_t g_time_charge;
int main()
{
    /*
    double i=0.000000;
    printf("i-1=%d\n", i-1 == 0 ? 1: 0);
    if (i == 0x0) {
        printf("=============\n");
    }
    */
    char pkg[10] = {0x9, 0x1, 0x02, 0x3, 0x4, 0x0, 0x5};
    char buf[20];
    int i;
    memset(buf, 0x0, sizeof(buf));
    snprintf(buf, sizeof(buf), "%s", pkg);
    //memcpy(buf, pkg, sizeof(pkg));
    for (i = 0; i < sizeof(buf); i++) {
        printf("%x:", buf[i]);
    }

    printf("\n");
    return 0;
}


struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head) {
        return head;
    }
    struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->next = NULL;
    struct ListNode *pre = new;
    struct ListNode *cur = head;
    struct ListNode *next = NULL;
    while(cur) {
        next = cur->next;
        while (pre->next != NULL && pre->next->val < cur->val) {
            pre = pre->next;
        }
        cur->next = pre->next;
        pre->next = cur;
        pre = new;
        cur = next;
    }

    return new->next;
}

struct ListNode* insertionSortList(struct ListNode* head) {

    if (!head || !head->next) {
        return head;
    }

    struct ListNode *unsorted = head->next;
    struct ListNode *sorted = NULL;
    struct ListNode *presorted = NULL;
    struct ListNode *next = NULL;

    head->next = NULL;
    while (unsorted) {
        sorted = head;
        presorted = head;
        next = unsorted->next;
        cnt = 0;
        while (sorted && sorted->value <= unsorted->value) {
            presorted = sorted;
            sorted = sorted->next;
            cnt++;
        }

        if (sorted) {
            if (cnt == 0) {
                head = unsorted;
            } else {
                presorted->next = unsorted;
            }
            unsorted->next = sorted;
        } else {
            unsorted->next = NULL
            presorted->next = unsorted;
        }

        unsorted = next;
    }

    return head;
}

public ListNode insertionSortList(ListNode head) {
        if( head == null ){
            return head;
        }
        ListNode helper = new ListNode(0); //new starter of the sorted list
        ListNode cur = head; //the node will be inserted
        ListNode pre = helper; //insert node between pre and pre.next
        ListNode next = null; //the next node will be inserted
        //not the end of input list
        while( cur != null ){
            next = cur.next;
            //find the right place to insert
            while( pre.next != null && pre.next.val < cur.val ){
                pre = pre.next;
            }
            //insert between pre and pre.next
            cur.next = pre.next;
            pre.next = cur;
            pre = helper;
            cur = next;
        }
        return helper.next;
    }

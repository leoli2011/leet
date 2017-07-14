/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
/*  First version passed */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *iter = head;
    struct RandomListNode *next;
    while(iter != NULL) {
        next = iter->next;
        struct RandomListNode *tmp = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        tmp->random = NULL;
        tmp->label = iter->label;
        tmp->next = next;
        iter->next = tmp;
        iter = next;
    }

    iter = head;
    while (iter != NULL) {
        if (iter->random != NULL) {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    struct RandomListNode *dummyhead = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
    dummyhead->next = NULL;
    struct RandomListNode *copyiter, *copy;
    iter = head;
    copyiter = dummyhead;
    while (iter) {
        next = iter->next->next;

        copy = iter->next;
        copyiter->next = copy;
        copyiter = copy;

        iter->next = next;
        iter = next;
    }

    return dummyhead->next;
}


public RandomListNode copyRandomList(RandomListNode head) {
    RandomListNode iter = head, next;

    // First round: make copy of each node,
    // and link them together side-by-side in a single list.
    while (iter != null) {
        next = iter.next;

        RandomListNode copy = new RandomListNode(iter.label);
        iter.next = copy;
        copy.next = next;

        iter = next;
    }

    // Second round: assign random pointers for the copy nodes.
    iter = head;
    while (iter != null) {
        if (iter.random != null) {
            iter.next.random = iter.random.next;
        }
        iter = iter.next.next;
    }

    // Third round: restore the original list, and extract the copy list.
    iter = head;
    RandomListNode pseudoHead = new RandomListNode(0);
    RandomListNode copy, copyIter = pseudoHead;

    while (iter != null) {
        next = iter.next.next;

        // extract the copy
        copy = iter.next;
        copyIter.next = copy;
        copyIter = copy;

        // restore the original list
        iter.next = next;

        iter = next;
    }

    return pseudoHead.next;
}

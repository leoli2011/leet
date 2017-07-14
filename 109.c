/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* First version of sortedtoBST */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) {
        return head;
    }

    struct TreeNode *dummy = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    dummy->val = head->val;
    dummy->left = NULL;
    dummy->right = NULL;
    Struct TreeNode *iter;
    iter = dummy->left;
    while(head && head->next) {
        head = head->next;
        struct TreeNode *tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        tmp->val = head->val;
        iter->left = tmp;
        iter = iter->left;
    }
    return dummy;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) {
        return head;
    }

    return toBST(head, NULL);
}

/* second version  passed */
struct TreeNode* toBST(struct ListNode *head, struct ListNode *tail) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    if (head == tail) {
        return NULL;
    }

    while (fast!=tail && fast->next != tail) {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct TreeNode *tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    tmp->val = slow->val;
    tmp->left = toBST(head, slow);
    tmp->right = toBST(slow->next, tail);
    return tmp;
}

public class Solution {
public TreeNode sortedListToBST(ListNode head) {
    if(head==null) return null;
    return toBST(head,null);
}
public TreeNode toBST(ListNode head, ListNode tail){
    ListNode slow = head;
    ListNode fast = head;
    if(head==tail) return null;

    while(fast!=tail&&fast.next!=tail){
        fast = fast.next.next;
        slow = slow.next;
    }
    TreeNode thead = new TreeNode(slow.val);
    thead.left = toBST(head,slow);
    thead.right = toBST(slow.next,tail);
    return thead;
}
}

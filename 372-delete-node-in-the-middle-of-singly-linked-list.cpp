// LintCode simple question

// Iterative method, which is not optimum.
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        ListNode* iter = node;
        while (iter->next->next) {
            iter->val = iter->next->val;
            iter = iter->next;
        }
        iter->val = iter->next->val;
        delete iter->next;
        iter->next = NULL;
    }
};

// Actually we only need to delete the node once.
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        if (!node->next)
            return;
        node->val = node->next->val;
        ListNode* temp = node->next->next;
        delete node->next;
        node->next = temp;
    }
};

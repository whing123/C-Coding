/* *题目：
 *  23
 *  Merge k Sorted Lists
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, 0, lists.size()-1);
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int low, int high) {
        if (low > high) {
            return NULL;
        }else if(low == high) {
            return lists[low];
        }

        int mid = low + (high - low) / 2;
        ListNode* left = mergeLists(lists, low, mid);
        ListNode* right = mergeLists(lists, mid+1, high);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode *p, *head = new ListNode(-1);
        p = head;

        while (left != NULL || right != NULL) {
            if (left == NULL) {
                p->next = right;
                break;
            }else if (right == NULL) {
                p->next = left;
                break;
            }

            if (left->val <= right->val) {
                p->next = left;
                left = left->next;
            }else {
                p->next = right;
                right = right->next;
            }
            
            p = p->next;
        }

        p = head->next;
        delete head;

        return p;
    }
};
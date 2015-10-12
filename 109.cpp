/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        ListNode *h = head;
        int cnt = 0;

        while (h != NULL)
        {
        	cnt++;
        	h = h->next;
        }

        return build_bst(head, cnt);
    }

private:
	TreeNode *build_bst(ListNode *head, int count)
	{
		if (head == NULL || count == 0)
			return NULL;
		if (count == 1)
			return new TreeNode(head->val);

		ListNode *h = head;
		int shift_time = count % 2 == 0 ? count / 2 - 1 : count / 2;
		for (int i = 0; i < shift_time; ++i)
			h = h->next;

		TreeNode *mid = new TreeNode(h->val);

		TreeNode *left, *right;
		left = build_bst(head, shift_time);
		right = build_bst(h->next, count / 2);
		mid->left = left;
		mid->right = right;

		return mid;
	}
};
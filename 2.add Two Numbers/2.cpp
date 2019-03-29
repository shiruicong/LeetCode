/*struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		ListNode *current = head;
		int flag = 0;
		int temp = 0;
		while ((l1 != NULL) || (l2 != NULL))
		{
			int num1 = 0, num2 = 0;
			if (l1 != NULL)
			{
				num1 = l1->val;
				l1 = l1->next;

			}
			if (l2 != NULL)
			{
				num2 = l2->val;
				l2 = l2->next;
			}
			temp = 0;
			if (flag == 0)
			{
				temp = num1 + num2;
			}
			if (flag == 1)
			{
				temp = num1 + num2 + 1;
				flag = 0;
			}
			if (temp>9)
			{
				flag = 1;
				temp = temp - 10;
			}
			current->next = new ListNode(temp);
			current = current->next;

		}
		if (flag == 1)
		{
			current->next = new ListNode(1);
			current = current->next;
		}

		return head->next;
	}
};
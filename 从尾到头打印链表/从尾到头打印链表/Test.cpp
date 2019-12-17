/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include<algorithm>
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> ArrayList;
		while (head != nullptr)
		{
			ArrayList.push_back(head->val);
			head = head->next;
		}
		reverse(ArrayList.begin(), ArrayList.end());
		return ArrayList;
	}
};
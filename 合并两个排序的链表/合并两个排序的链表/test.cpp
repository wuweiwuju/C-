#define _CRT_SECURE_NO_WARNINGS 1
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		ListNode* cur = nullptr;
		ListNode* prev = nullptr;
		ListNode* head = pHead1;
		if (pHead2->val < pHead1->val)
			head = pHead2;
		while (pHead1 && pHead2)
		{
			if (pHead1->val > pHead2->val)
			{
				cur->next = pHead2;
				prev = pHead2;
				pHead2 = pHead2->next;
				prev->next = pHead1;
				cur = prev;
			}
			else
			{
				cur = pHead1;
				pHead1 = pHead1->next;
			}
		}
		if (pHead2 == nullptr)
			return head;
		while (pHead2->val < cur->val && pHead2 != nullptr)
		{
			prev->next = pHead2;
			prev = pHead2;
			pHead2 = pHead2->next;
			prev->next = cur;
		}
		if (pHead2 != nullptr)
			cur->next = pHead2;
		return head;
	}
};*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		if (pHead1->val <= pHead2->val)
		{
			pHead1->next = Merge(pHead1->next, pHead2);
			return pHead1;
		}
		else
		{
			pHead2->next = Merge(pHead1, pHead2->next);
			return pHead2;
		}
	}
};
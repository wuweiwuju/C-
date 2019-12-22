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
	ListNode* ReverseList(ListNode* pHead) {
		/*if(pHead == nullptr)
			return pHead;
		ListNode* pre = pHead;
		ListNode* cur = pHead->next;
		ListNode* next = nullptr;
		while(cur)
		{
			next = cur->next;
			pre = cur->next;
			pre = cur;
			cur = next;
		}
		pHead->next = nullptr;
		pHead = pre;
		return pHead;*/
		if (pHead == nullptr)
			return nullptr;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		while (pHead != nullptr)
		{
			next = pHead->next;
			pHead->next = pre;
			pre = pHead;
			pHead = next;
		}
		return pre;
	}
};

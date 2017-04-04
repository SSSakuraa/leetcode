#include <iostream>
using namespace std;
// Number2
// You are given two linked lists representing two non-negative numbers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output : 7 -> 0 -> 8
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
{
	ListNode head(0);
	ListNode *tmp = &head;
	int inc = 0;
	while (l1&&l2) {
		int sum = l1->val + l2->val + inc;
		tmp->next = new ListNode(sum % 10);
		inc = sum / 10;
		l1 = l1->next;
		l2 = l2->next;
		tmp = tmp->next;
	}
	while (l1) {
		int sum = l1->val + inc;
		tmp->next = new ListNode(sum % 10);
		inc = sum / 10;
		l1 = l1->next;
		tmp = tmp->next;

	}
	while (l2) {
		int sum = l2->val + inc;
		tmp->next = new ListNode(sum % 10);
		inc = sum / 10;
		l2 = l2->next;
		tmp = tmp->next;
	}
	if (inc) {
		tmp->next = new ListNode(1);
	}
	return head.next;
}

int problem2() {
	
	ListNode *l1, x1(3), x2(7), x3(3);
	ListNode *l2, y1(9), y2(2), y3(7);
	l1 = &x1;
	x1.next = &x2;
	x2.next = &x3;
	l2 = &y1;
	y1.next = &y2;
	y2.next = &y3;
	ListNode *res = addTwoNumbers(l1, l2);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}
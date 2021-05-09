#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val): val(val), next(nullptr) {}
};

// Reverse the linked list and return the new head after reversing
ListNode* reverse_linked_list(ListNode* head) {
	// The basic concept behind this is we simply just reverse the orientation/pointer direction for every node in the list. This is trivial with a temp variables.
	ListNode *prev = nullptr, *curr = head, *next = nullptr;
	while(curr != nullptr) {
		next = curr->next; // This now points to next node in our list. Doesn't matter if it's nullptr or not, it works out!
		curr->next = prev; // Set the current node's next to prev.
		prev = curr; // Save the curr node and call it previous now.
		curr = next; // Set the current node to the next one.
	}
	// Lastly reverse the head reference and return it.
	head = prev;
	return head;
}

// check if the linked list contains the target
bool is_target_in_list(ListNode* head, int target) {
	ListNode* curr = head;
	while(curr != nullptr) {
		if(curr->val == target) {
			return true;
		}
		curr = curr->next;
	}
 	return false;
}

// find the largest value in the node
int find_max(ListNode* head) {
	ListNode* curr = head;
	int max = curr->val;
	while(curr != nullptr) {
		max = std::max(max, curr->val);
		curr = curr->next;
	}
	return max;
}

// These two are just helper functions to see how stuff works/executes correctly.
void append(ListNode* head, int data) {
	ListNode* curr = head;
	while(curr->next != nullptr) {
		curr = curr->next;
	}
	curr->next = new ListNode(data);
}

void printList(ListNode* head) {
	ListNode* curr = head;
	while(curr != nullptr) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	ListNode head(9);
	append(&head, 6);
	append(&head, 7);
	append(&head, 8);
	append(&head, 15);
	append(&head, 3);
	append(&head, 12);
	append(&head, 11);
	append(&head, 1);
	printList(&head);
	ListNode* reversed = reverse_linked_list(&head);
	printList(reversed);
	cout << (is_target_in_list(reversed, 5) ? "True" : "False") << endl;
	cout << find_max(reversed) << endl;
	return 0;
}

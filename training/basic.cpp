#ifndef __BASIC_CPP
#define __BASIC_CPP
#include "basic.h"
#include <algorithm>

#pragma region linked list
template <class T>
inline exercise::linked_node<T>::linked_node()
{
	this->value;
	this->next = nullptr;
}

template <class T>
exercise::linked_node<T>::~linked_node()
{
	delete next;
}

template <class T>
exercise::linked_list<T>::linked_list()
{
	linked_node<T>* head = new linked_node<T>();
	linked_node<T>* tail = new linked_node<T>();
}

template <class T>
exercise::linked_list<T>::~linked_list()
{
	delete head;
	delete tail;
}
template <class T>
void exercise::linked_list<T>::add_node(linked_node<T>* node)
{
	if (head == nullptr) {
		head = node;
		return;
	}

	tail->next = node;
	return;
}

template <class T>
void exercise::linked_list<T>::add_value(T node)
{
	linked_node<T>* new_node = new linked_node<T>();

	new_node->value = node;
	new_node->next = nullptr;
	if (head == nullptr) {
		head = new_node;
		return;
	}

	tail->next = new_node;
	return;
}
#pragma endregion

#pragma region stack
template <typename T>
exercise::stack<T>::stack()
{
	linked_list<T>* stacks = new linked_list<T>();
}
template <typename T>
exercise::stack<T>::~stack()
{
	delete stacks;
}

template <typename T>
T exercise::stack<T>::pop()
{
	linked_node<T>* top = stacks->head;
	T temp = top->value;
	stacks->head = stacks->head->next;
	return temp;

}

template <typename T>
T exercise::stack<T>::peek()
{

	if (stacks->head) {
		linked_node<T>* first_node = stacks->head;
		return first_node->value;
	}
}

template <typename T>
bool exercise::stack<T>::is_empty() {
	if (stacks == nullptr || stacks == new linked_list<T>()) {
		return true;
	}
	else if (stacks->head == nullptr){
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
void exercise::stack<T>::push(T val)
{	
	if (stacks) {
		linked_node<T>* first = stacks->head;
		linked_node<T>* new_first = new linked_node<T>();
		new_first->value = val;
		new_first->next = first;
		stacks->head = new_first;

	}
	else {
		linked_node<T>* new_node = new linked_node<T>();
		new_node->value = val;
		new_node->next = nullptr;
		stacks = new linked_list<T>();
		stacks->head = new_node;
		return;
	}
} 
#pragma endregion

#pragma region queue
template <class T>
exercise::queue<T>::queue()
{
	linked_list<T>* queues = new linked_list<T>();
}

template <class T>
exercise::queue<T>::~queue()
{
	delete queues;
}

template <class T>
T exercise::queue<T>::deque() //先进先出
{
	if (queues->head) {
		linked_node<T>* temp = queues->head;
		queues->head = queues->head->next;
		if (queues->head == nullptr) {
			queues = new queue<T>(); 
		}
		return temp->value;
	}

}

template <class T>
T exercise::queue<T>::peek()
{
	linked_node<T>* top = queues->head;
	return top->value;
}

template <class T>
void exercise::queue<T>::enque(T val)
{
	linked_node<T>* new_node = new linked_node<T>();
	new_node->value = val;
	new_node->next = nullptr;

	if (queues == nullptr || queues->head == nullptr) {
		queues = new linked_list<T>();
		queues->head = new_node;
		queues->tail = new_node;
		return;
	}

	linked_node<T>* rear = queues->head;
	while (rear->next != nullptr) {
		rear = rear->next;
	}

	rear->next = new_node;
	queues->tail = new_node;
	return;

}

template <class T>
bool exercise::queue<T>::is_empty() {
	if (queues == new linked_list<T>() || queues->head == nullptr) {
		return true;
	}
	else {
		return false;
	}

}
#pragma endregion

#pragma region tree_node
template <typename T>
exercise::tree_node<T>::tree_node()
{
	T value;
	int children_counts;
	
	std::vector<tree_node<T>*> children;
}

template <typename T>
exercise::tree_node<T>::tree_node(T val)
{	  
	this->value = val;
	this->children_counts = 0;
}

template <typename T>
exercise::tree_node<T>::~tree_node()
{
	for (size_t i = 0; i != children.size(); ++i) {
		delete children[i];
	}
	children.clear();
	//delete[] children;
}

template <typename T>
bool exercise::tree_node<T>::add_child(tree_node<T>* child)
{
	children.push_back(child);
	++children_counts;

	return true;
}

template <typename T>
int exercise::tree_node<T>::get_height()
{
	if (children_counts == 0)
		return 0;

	int height = 1;
	exercise::stack<std::pair <tree_node<T>*, int>>* stacks = new stack<std::pair <tree_node<T>*, int>>();
	for (auto &child : children) {
		stacks->push(std::pair <tree_node<T>*, int> (child, 1));
	}
	while (!(stacks->is_empty())) {
		std::pair <tree_node<T>*, int> cur = stacks->pop();
		tree_node<T>* root = cur.first;
		int cur_height = cur.second;
		if (root != nullptr) {
			height = height > cur_height ? height : cur_height;
			for (tree_node<T>* node : root->children) {
				stacks->push(std::pair <tree_node<T>*, int> (node, cur_height + 1));
			}
		}
	}
	return height;
}
#pragma endregion

#pragma region tree
template <typename T>
exercise::tree<T>::tree()
{
	tree_node<T>* root = nullptr;
}

template <typename T>
exercise::tree<T>::~tree()
{
	delete root;
}

template <typename T>
exercise::tree<T>::tree(tree_node<T>* node)
{
	tree_node<T>* root = node;
}
#pragma endregion


#pragma region binary_tree_node
template <typename T>
exercise::binary_tree_node<T>::binary_tree_node()
{
	std::vector<binary_tree_node<T>*> children;
	binary_tree_node<T>* left = nullptr;
	binary_tree_node<T>* right = nullptr;
	binary_tree_node<T>* parents = nullptr;
	int height;
	int bf;
}

template <typename T>
exercise::binary_tree_node<T>::~binary_tree_node()
{
	delete[]children;
	delete left;
	delete right;
	delete parents;
}

template <typename T>
exercise::binary_tree_node<T>* exercise::binary_tree_node<T>::get_left()
{
	return left;
}

template <typename T>
exercise::binary_tree_node<T>* exercise::binary_tree_node<T>::get_right()
{
	return right;
}

template <typename T>
int exercise::binary_tree_node<T>::get_height()
{
	if (left == nullptr && right == nullptr)
		return 0;

	int height = 1;
	exercise::stack<std::pair <binary_tree_node<T>*, int>>* stacks = new stack<std::pair <binary_tree_node<T>*, int>>();
	if (left) {
		stacks->push(std::pair<binary_tree_node<T>*, int>(left, 1));
	}
	if (right)
		stacks->push(std::pair<binary_tree_node<T>*, int>(right, 1));

	while (!(stacks->is_empty())) {
		std::pair <binary_tree_node<T>*, int> cur = stacks->pop();
		binary_tree_node<T>* root = cur.first;
		int cur_height = cur.second;
		
		if (root != nullptr) {
			height = height > cur_height ? height : cur_height;
			if (root->left)
				stacks->push(std::pair <binary_tree_node<T>*, int>(root->left, cur_height + 1));
			if (root->right)
				stacks->push(std::pair <binary_tree_node<T>*, int>(root->right, cur_height + 1));
			}
		}
	return height;
}

template <typename T>
bool exercise::binary_tree_node<T>::set_left(binary_tree_node<T>* left_child)
{
	left = left_child;
	return true;
}

template <typename T>
bool exercise::binary_tree_node<T>::set_right(binary_tree_node<T>* right_child)
{	
	right = right_child;
	return true;
}
#pragma endregion

#pragma region binary_search_tree
template <typename T>
exercise::binary_search_tree<T>::binary_search_tree()
{
	binary_tree_node<T>* roots;
}

template <typename T>
exercise::binary_search_tree<T>::~binary_search_tree()
{
	delete roots;
}

template<typename T>
template<class Compare>
bool exercise::binary_search_tree<T>::insert(T val, Compare& _cmp)
{
	if (roots == nullptr) {
		roots = new binary_tree_node<T>();
		roots->value = val;
		roots->left = nullptr;
		roots->right = nullptr;
		roots->bf = 0;
		roots->height = 0;
		roots->parents = nullptr;
		return true;
	}
	binary_tree_node<T>* parent = new binary_tree_node<T>();
	binary_tree_node<T>* cur = roots;
	while (cur!=nullptr) {
		
		if (_cmp(cur->value, val) < 0) {
			parent = cur;
			cur = cur->right;
		}
		else if (_cmp(cur->value, val) > 0){
			parent = cur;
			cur = cur->left;
		}
	}
	binary_tree_node<T>* new_node = new binary_tree_node<T>();
	new_node->parents = parent;
	new_node->value = val;
	// insert on the right or the left;
	if (_cmp(parent->value, val) < 0) {
		parent->right = new_node;
	}
	else {
		parent->left = new_node;
	}

	rebalance(new_node);
}

template<typename T>
void exercise::binary_search_tree<T>::rebalance(exercise::binary_tree_node<T>* cur) {
	while (cur != nullptr) {
		get_balance_factor(cur);
		if (cur->bf >= 2 || cur->bf <= -2) {
			rotate(cur);
		}
		cur = cur->parents;
	}
}

template<typename T>
int exercise::binary_search_tree<T>::get_balance_factor(exercise::binary_tree_node<T>* parent) {
	if (parent == nullptr) {
		return 0;
	}
	int left_height = 1;
	int right_height = 1;
	if (parent->left)
		left_height = parent->left->get_height() + 1;
	else
		left_height = 0;
	if (parent->right)
		right_height = parent->right->get_height() + 1;
	else
		right_height = 0;

	parent->bf = left_height - right_height;
	return parent->bf;
}

template<typename T>
template<class Compare>
bool exercise::binary_search_tree<T>::remove(T val, Compare& _cmp)
{
	if (roots == nullptr) {
		return false;
	}

	binary_tree_node<T>* parent = new binary_tree_node<T>();
	binary_tree_node<T>* cur = roots;
	while (cur) {
		if (_cmp(cur->value, val) > 0) {
			parent = cur;
			cur = cur->right;
		}
		else if (_cmp(cur->value, val) < 0) {
			parent = cur;
			cur = cur->left;
		}
		else {
			break;
		}
	}
	if (cur->left == nullptr && cur->right == nullptr) {
		if (parent == nullptr) {
			roots = nullptr;
		}
		else if (parent->left == cur) {
			parent->left = nullptr;
		}
		else
			parent->right = nullptr;
		delete cur;
		rebalance(parent);
	}
	else if (cur->right == nullptr) { // removing the node with only one left child
		if (parent == nullptr) {
			roots = cur->left;
			roots->parents = nullptr;
		}
		else if (parent->left == cur) {
			parent->left = cur->left;
			cur->left->parents = parent;
		}
		else {
			parent->right = cur->right;
			cur->right->parents = parent;
		}
		delete cur;
		rebalance(parent);
	}

	//removing the node with only one right child
	else if (cur->left == nullptr) {
		if (parent == nullptr) {
			roots = cur->right;
			roots->parents = nullptr;
		}
		else if (parent->left == cur) {
			parent->left = cur->left;
			cur->left->parents = parent;
		}
		else {
			parent->right = cur->right;
			cur->right->parents = parent;
		}
		delete cur;
		rebalance(parent);
	}
	else {
		binary_tree_node<T>* temp = cur->right;
	}
}

template<typename T>
void exercise::binary_search_tree<T>::rotate(exercise::binary_tree_node<T>* node) {
	binary_tree_node<T>* child = new binary_tree_node<T>();
	if (node->bf > 1) {
		child = node->left;

		get_balance_factor(child);
		if (child->bf == -1) {
			lrr_rotate(node, child, child->right);
		}
		else {
			llr_rotate(node, child, child->left);
		}
	}
	else {
		child = node->right;
		get_balance_factor(child);
		if (child->bf == 1) {
			rlr_rotate(node, child, child->left);
		}
		else {
			rrr_rotate(node, child, child->right);
		}
	}
}

template<typename T>
void exercise::binary_search_tree<T>::llr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child) {
	binary_tree_node<T>* grand_parent = parent->parents;
	node->parents = grand_parent;
	binary_tree_node<T>* sub_right = node->right;
	if (sub_right) {
		sub_right->parents = parent;
	}
	node->right = parent;
	parent->parents = node;
	parent->left = sub_right;
	if (grand_parent == nullptr)
		roots = node;
	else if (grand_parent->left == parent) {
		grand_parent->left = node;
	}
	else
		grand_parent->right = node;
}

template<typename T>
void exercise::binary_search_tree<T>::lrr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child) {
	rrr_rotate(node, child, child->right);
	llr_rotate(parent, child, node);
}

template<typename T>
void exercise::binary_search_tree<T>::rrr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child) {
	binary_tree_node<T>* grand_parent = parent->parents;
	node->parents = grand_parent;
	binary_tree_node<T>* sub_left = node->left;
	if (sub_left) {
		sub_left->parents = parent;
	}
	node->left = parent;
	parent->parents = node;
	parent->right = sub_left;
	if (grand_parent == nullptr)
		roots = node;
	else if (grand_parent->left == parent) {
		grand_parent->left = node;
	}
	else
		grand_parent->right = node;
}

template<typename T>
void exercise::binary_search_tree<T>::rlr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child) {
	llr_rotate(node, child, child->left);
	rrr_rotate(parent, child, node);
}

#pragma endregion

#endif
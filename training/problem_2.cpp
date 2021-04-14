#ifndef __PROBLEM_2_CPP
#define __PROBLEM_2_CPP
#include "problem_2.h"

template<typename T>
std::vector<exercise::binary_tree_node<T>*> exercise::inorder_traversal(
	exercise::binary_search_tree<T>* _tree)
{
	binary_tree_node<T>* trees = _tree->roots;
	std::vector<exercise::binary_tree_node<T>*> res;
	exercise::stack<binary_tree_node<T>*>* stacks = new stack<binary_tree_node<T>*>();
	while (trees != nullptr || !(stacks->is_empty())) {
		while (trees != nullptr) {
			stacks->push(trees);
			trees = trees->get_left();
		}
		trees = stacks->pop();
		
		res.push_back(trees);
		trees = trees->get_right();
	}
	return res;
}

template<typename T>
std::vector<exercise::binary_tree_node<T>*> exercise::preorder_traversal(exercise::binary_search_tree<T>* _tree)
{
	binary_tree_node<T>* tree = _tree->roots;
	std::vector<exercise::binary_tree_node<T>*> res;
	exercise::stack<binary_tree_node<T>*>* stacks = new stack<binary_tree_node<T>*>();
	
	while (!stacks->is_empty() || tree) {
		while (tree != nullptr) {
			res.push_back(tree);
			stacks->push(tree);
			tree = tree->get_left();
		}
		tree = stacks->pop();
		tree = tree->get_right();
	}
	return res;
}

template<typename T>
std::vector<exercise::binary_tree_node<T>*> exercise::postorder_traversal(exercise::binary_search_tree<T>* _tree)
{
	binary_tree_node<T>* tree = _tree->roots;
	std::vector<exercise::binary_tree_node<T>*> res;
	exercise::stack<binary_tree_node<T>*>* stacks = new stack<binary_tree_node<T>*>();
	binary_tree_node<T>* prev = new binary_tree_node<T>();

	while (!(stacks->is_empty()) || tree != nullptr) {
		while (tree != nullptr) {
			stacks->push(tree);
			tree = tree->get_left();
		}
		tree = stacks->pop();
		if (tree->get_right() == nullptr || tree->get_right() == prev) {
			res.push_back(tree);
			prev = tree;
			tree = nullptr;
		}
		else {
			stacks->push(tree);
			tree = tree->get_right();
		}
	}

	return res;

}
#endif
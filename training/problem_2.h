#pragma once
#ifndef __PROBLEM_2_H
#define __PROBLEM_2_H
#include "basic.h"
#include "basic.cpp"

namespace exercise {
	/// <summary>
	/// 下面三个方法返回三种遍历结果
	/// 直接把node指针按遍历顺序加入vector中，不要改变树本身
	/// </summary>
	template<typename T>
	std::vector<binary_tree_node<T>*> inorder_traversal(binary_search_tree<T>* _tree);

	template<typename T>
	std::vector<binary_tree_node<T>*> preorder_traversal(binary_search_tree<T>* _tree);

	template<typename T>
	std::vector<binary_tree_node<T>*> postorder_traversal(binary_search_tree<T>* _tree);
}
#endif
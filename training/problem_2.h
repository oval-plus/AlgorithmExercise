#pragma once
#ifndef __PROBLEM_2_H
#define __PROBLEM_2_H
#include "basic.h"
#include "basic.cpp"

namespace exercise {
	/// <summary>
	/// �������������������ֱ������
	/// ֱ�Ӱ�nodeָ�밴����˳�����vector�У���Ҫ�ı�������
	/// </summary>
	template<typename T>
	std::vector<binary_tree_node<T>*> inorder_traversal(binary_search_tree<T>* _tree);

	template<typename T>
	std::vector<binary_tree_node<T>*> preorder_traversal(binary_search_tree<T>* _tree);

	template<typename T>
	std::vector<binary_tree_node<T>*> postorder_traversal(binary_search_tree<T>* _tree);
}
#endif
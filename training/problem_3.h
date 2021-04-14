
#pragma once
#ifndef __PROBLEM_3_H
#define __PROBLEM_3_H
#include "basic.h"
#include "basic.cpp"

namespace exercise {
	/// <summary>
	/// ����BFS��ѯ��
	/// �����Ǿ仰����ֹ�ݹ飻���Ҫ�õ�queue����stack�����Լ�д��~
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_tree">����������ע�⣬��problem 2��ͬ��������ͨ�����������Ƕ�������</param>
	/// <param name="target">��ҪѰ�ҵĶ���</param>
	/// <returns>������ҵ������򷵻ض���·�������е�node; ������ܣ��򷵻ؿ�vector</returns>
	template <typename T>
	std::vector<tree_node<T>*> bfs_path(tree<T>* _tree, T target);

	/// <summary>
	/// ������������ҵ�����Ĺ������ڵ�
	///				1
	///			  /   \
	///			 2     3
	///			/ \   / \
	/// 	   4   5 6   7
	/// ���ϣ�����4,5 ���� 2
	///		���� 4,7 ����1
	///		���� 4,2 ����2
	///		���� 4,2,6 ����1
	///		���� 8 ���� null
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_tree">��</param>
	/// <param name="targets">���󼯺�</param>
	/// <returns>�������ڵ�</returns>
	template <typename T>
	tree_node<T>* find_lowest_common_parent(tree<T>* _tree, std::vector<T> targets);

	/// <summary>
	/// ��һ���б����ɶ�Ӧ����
	/// ���������
	/// [(1,2),(1,3),(2,4),(2,5),(3,6),(3,7)]
	/// ���ɣ�
	///				1
	///			  /   \
	///			 2     3
	///			/ \   / \
	/// 	   4   5 6   7
	/// ע������һ���Ƕ������������е�Ҳ��һ������
	/// ����������ڵ��Դ��룡������
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="Compare"></typeparam>
	/// <param name="_tree_list"></param>
	/// <param name="_cmp"></param>
	/// <returns></returns>
	/// 
	template <typename T>
	tree<T>* build_tree(std::vector<std::pair<T, T>> _tree_list);
}
#endif
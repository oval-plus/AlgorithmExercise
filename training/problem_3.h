
#pragma once
#ifndef __PROBLEM_3_H
#define __PROBLEM_3_H
#include "basic.h"
#include "basic.cpp"

namespace exercise {
	/// <summary>
	/// 利用BFS查询树
	/// 还是那句话，禁止递归；如果要用到queue或者stack，用自己写的~
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_tree">给出的树，注意，和problem 2不同，这里是通常的树，不是二叉树！</param>
	/// <param name="target">需要寻找的对象</param>
	/// <returns>如果能找到对象，则返回对象路径上所有的node; 如果不能，则返回空vector</returns>
	template <typename T>
	std::vector<tree_node<T>*> bfs_path(tree<T>* _tree, T target);

	/// <summary>
	/// 给出多个对象，找到最近的公共父节点
	///				1
	///			  /   \
	///			 2     3
	///			/ \   / \
	/// 	   4   5 6   7
	/// 如上，给出4,5 返回 2
	///		给出 4,7 返回1
	///		给出 4,2 返回2
	///		给出 4,2,6 返回1
	///		给出 8 返回 null
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="_tree">树</param>
	/// <param name="targets">对象集合</param>
	/// <returns>公共父节点</returns>
	template <typename T>
	tree_node<T>* find_lowest_common_parent(tree<T>* _tree, std::vector<T> targets);

	/// <summary>
	/// 给一个列表，生成对应的树
	/// 例如给出：
	/// [(1,2),(1,3),(2,4),(2,5),(3,6),(3,7)]
	/// 生成：
	///				1
	///			  /   \
	///			 2     3
	///			/ \   / \
	/// 	   4   5 6   7
	/// 注意树不一定是二叉树，给出列的也不一定排序。
	/// 这个方法用于调试代码！！！！
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
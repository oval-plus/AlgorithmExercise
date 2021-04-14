#pragma once
#ifndef __BASIC_H
#define __BASIC_H

#include <iostream>
#include<vector>

namespace exercise {
#pragma region Homework 1
	template <class T>
	class linked_node {
	public:
		linked_node();
		~linked_node();
		T value;
		linked_node* next;
	};

	template <class T>
	class linked_list {
	public:
		linked_list();
		~linked_list();
		linked_node<T>* head;
		linked_node<T>* tail;
		void add_value(T node);
		void add_node(linked_node<T>* node);
	};

	template <typename T>
	class stack : linked_list<T> {
	public:
		stack();
		~stack();
		T pop();
		T peek();
		void push(T val);
		bool is_empty();
		linked_list<T>* stacks;
	};

	template <class T>
	class queue : linked_list<T> {
	public:
		queue();
		~queue();
		T deque();
		T peek();
		void enque(T val);
		bool is_empty();
		linked_list<T>* queues;
	};

#pragma endregion

#pragma region Homework 2 & 3
	template <typename T>
	class tree_node {
	public:
		tree_node();
		tree_node(T val);
		~tree_node();
		T value;
		int children_counts;
		std::vector<tree_node<T>*> children; // tree_node<T>* array

		/// <summary>
		/// 增加child
		/// </summary>
		/// <param name="child">子节点</param>
		/// <returns></returns>
		bool add_child(tree_node<T>* child);

		/// <summary>
		/// 当前节点的高度
		/// </summary>
		/// <returns></returns>
		int get_height();
	};

	template <typename T>
	class tree {
	public:
		tree();
		~tree();
		tree(tree_node<T>* node);
		tree_node<T>* root;
	};

	template <typename T>
	class binary_tree_node : public tree_node<T> {
	public:
		binary_tree_node();
		~binary_tree_node();
		binary_tree_node<T>* get_left();  // get
		binary_tree_node<T>* get_right(); // get
		bool set_left(binary_tree_node<T>* left_child);  // set
		bool set_right(binary_tree_node<T>* right_child);  // set
		std::vector<binary_tree_node<T>*> children;
		binary_tree_node<T>* left;
		binary_tree_node<T>* right;
		binary_tree_node<T>* parents;
		int height;
		int bf;
		int get_height();

	};

	template <typename T>
	class binary_search_tree : tree<T> {
	public:
		binary_search_tree();
		~binary_search_tree();
		/// <summary>
		/// 往BST里塞入一个新的参数，注意平衡
		/// </summary>
		/// <typeparam name="Compare">T 类型比较器</typeparam>
		/// <param name="val">加入对象的参数</param>
		/// <param name="_cmp">比较器</param>
		/// <returns>是否加入参数成功</returns>
		template <class Compare>
		bool insert(T val, Compare& _cmp);
		/// <summary>
		/// 从BST里删除一个对应的参数，如果有多个只删除一个（任意），注意平衡
		/// </summary>
		/// <typeparam name="Compare"></typeparam>
		/// <param name="val">删除对象</param>
		/// <param name="_cmp">比较器</param>
		/// <returns>是否删除成功，比如没有这个参数的node就返回false</returns>
		template <class Compare>
		bool remove(T val, Compare& _cmp);
		binary_tree_node<T>* roots;

	private:
		void llr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child);
		void lrr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child);
		void rlr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child);
		void rrr_rotate(exercise::binary_tree_node<T>* parent, binary_tree_node<T>* node, binary_tree_node<T>* child);
		void rebalance(exercise::binary_tree_node<T>* cur);

		void rotate(exercise::binary_tree_node<T>* parent);
		int get_balance_factor(exercise::binary_tree_node<T>* parent);
	};
#pragma endregion

}
#endif
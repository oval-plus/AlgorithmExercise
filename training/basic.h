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
		/// ����child
		/// </summary>
		/// <param name="child">�ӽڵ�</param>
		/// <returns></returns>
		bool add_child(tree_node<T>* child);

		/// <summary>
		/// ��ǰ�ڵ�ĸ߶�
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
		/// ��BST������һ���µĲ�����ע��ƽ��
		/// </summary>
		/// <typeparam name="Compare">T ���ͱȽ���</typeparam>
		/// <param name="val">�������Ĳ���</param>
		/// <param name="_cmp">�Ƚ���</param>
		/// <returns>�Ƿ��������ɹ�</returns>
		template <class Compare>
		bool insert(T val, Compare& _cmp);
		/// <summary>
		/// ��BST��ɾ��һ����Ӧ�Ĳ���������ж��ֻɾ��һ�������⣩��ע��ƽ��
		/// </summary>
		/// <typeparam name="Compare"></typeparam>
		/// <param name="val">ɾ������</param>
		/// <param name="_cmp">�Ƚ���</param>
		/// <returns>�Ƿ�ɾ���ɹ�������û�����������node�ͷ���false</returns>
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
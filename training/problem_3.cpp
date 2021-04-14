#ifndef __PROBLEM_3_CPP
#define __PROBLEM_3_CPP
#include "problem_3.h"
#include <map>
#include <unordered_set>
#include <algorithm>
#include "limits.h"

template<typename T>
std::vector<exercise::tree_node<T>*> exercise::bfs_path(exercise::tree<T>* _tree, T target)
{
	exercise::queue<tree_node<T>*> queues;
	std::vector<exercise::tree_node<T>*> res;
	std::map<tree_node<T>*, tree_node<T>*> parent_map;
	std::map<T, tree_node<T>*> value_map;
	parent_map[_tree->root] = nullptr;
	queues.enque(_tree->root);
	while (!queues.is_empty()) {
		tree_node<T>* cur = queues.deque();
		int sz = cur->children_counts;
		value_map[cur->value] = cur;
		
		for (int i = 0; i < sz; ++i) {
			if (!cur->children.empty()) {
				parent_map[cur->children[i]] = cur;
				queues.enque(cur->children[i]);
			}
		}
	}
	if (value_map.find(target) == value_map.end()) {
		return res;
	} else{
		tree_node<T>* prev = value_map[target];
		res.push_back(prev);
		while (prev != _tree->root) {
			res.push_back(parent_map[prev]);
			prev = parent_map[prev];
		}
	}
	return res;
}

template<typename T>
exercise::tree_node<T>* exercise::find_lowest_common_parent(tree<T>* _tree, std::vector<T> targets)
{	
	std::map<tree_node<T>*, std::pair<int, int>> res_map;
	if (targets.size() == 1) {
		std::vector<tree_node<T>*> vec_node_1 = bfs_path(_tree, targets[0]);
		return vec_node_1[0];
	}
	std::vector<tree_node<T>*> vec_node_1 = bfs_path(_tree, targets[0]);
	std::vector<tree_node<T>*> vec_node_2 = bfs_path(_tree, targets[1]);
	for (int i = 0; i < vec_node_1.size(); ++i)
		for (int k = 0; k < vec_node_2.size(); ++k)
			if (vec_node_1[i] == vec_node_2[k]) {
				//res_temp.push_back(vec_node_1[i]);
				res_map[vec_node_1[i]] = std::pair<int, int> (1, vec_node_1[i]->get_height());
				}

	if (targets.size() > 2) {
		for (size_t i = 2; i != targets.size(); ++i) {
			std::vector<tree_node<T>*> node_res = bfs_path(_tree, targets[i]);
			for (size_t j = 0; j != node_res.size(); ++j) {
				//if (std::find(res_temp.begin(), res_temp.end(), node_res[j]) != res_temp.end()) {
				//	res.push_back(node_res[j]);
				//}
				if (res_map.find(node_res[j]) != res_map.end()) {
					int times = res_map[node_res[j]].first;
					int second = res_map[node_res[j]].second;
					res_map[node_res[j]] = std::pair<int, int>(times + 1, second);
				}
			}
		}
	}
	
	std::vector<std::pair <int, tree_node<T>*>> res_temp;
	for (auto iter = res_map.begin(); iter != res_map.end(); ++iter) {
		if (iter->second.first == (targets.size() - 1)) {
			res_temp.push_back(std::pair<int, tree_node<T>*>(iter->second.second, iter->first));
		}
	}

	exercise::tree_node<T>* res = new tree_node<T>();
	int min_height = INT_MAX;
	for (int i = 0; i != res_temp.size(); ++i) {
		if (min_height > res_temp[i].first) {
			min_height = res_temp[i].first;
			res = res_temp[i].second;
		}
	}
	return res;
}

template<typename T>
exercise::tree<T>* exercise::build_tree(std::vector<std::pair<T, T>> _tree_list)
{
	std::map<T, tree_node<T>*> adj_list;
	std::unordered_set<T> root_check_set;
	for (auto &_tree : _tree_list) {
		root_check_set.emplace(_tree.first);
		root_check_set.emplace(_tree.second);
	}
	for (auto &_tree : _tree_list) {
		if (adj_list[_tree.first] == nullptr) {
			adj_list[_tree.first] = new tree_node<T>(_tree.first);
		}
		if (adj_list[_tree.second] == nullptr) {
			adj_list[_tree.second] = new tree_node<T>(_tree.second);
		}
		adj_list[_tree.first]->add_child(adj_list[_tree.second]);
		root_check_set.erase(_tree.second);
	}
	
	if (root_check_set.size() != 1) {
		return nullptr;
	}

	int root_height = 0;
	tree<T>* roots = new tree<T>();
	for(auto &iter: adj_list) {
		int temp = iter.second->get_height();
		if (root_height < temp) {
			roots->root = iter.second;
			root_height = temp;
		}
	}
	return roots;
}
#endif
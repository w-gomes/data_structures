#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>

#include "fmt/format.h"

namespace tre {

template <auto N>
class Graph {
 public:
  Graph()
    : data_(N + 1) {}

  void add_data(int data, int link, int weight = 0) {
    this->data_[static_cast<std::size_t>(data)].push_back(
      std::make_pair(link, weight));
  }

  /*
  void print() const {
    for (const auto &[node, links] : this->data_) {
      std::cout << node << " -> [ ";
      for (const auto &link : links) { std::cout << link << " "; }
      std::cout << "]\n";
    }
  }
  */

  int dfs(int data, int target) {
    auto stk     = std::stack<int>{};
    auto visited = std::vector<bool>(this->data_.size() + 1, false);

    stk.push(data);

    std::cout << "walking the graph...\n";
    while (!stk.empty()) {
      data = stk.top();
      stk.pop();

      if (!visited[static_cast<std::size_t>(data)]) {
        visited[static_cast<std::size_t>(data)] = true;
      }

      if (data == target) {
        std::cout << "found: " << data << '\n';
        return data;
      }

      std::cout << "pushing on stack...\n";
      for (const auto &edge : this->data_[static_cast<std::size_t>(data)]) {
        if (!visited[static_cast<std::size_t>(edge.first)]) {
          stk.push(edge.first);
        }
        std::cout << edge.first << " ";
      }
      std::cout << '\n';
    }

    return data;
  }

  int bfs(int data, int target) {
    auto que     = std::queue<int>{};
    auto visited = std::vector<bool>(this->data_.size() + 1, false);

    que.push(data);

    while (!que.empty()) {
      data = que.front();
      que.pop();

      if (!visited[static_cast<std::size_t>(data)]) {
        std::cout << data << " ";
        visited[static_cast<std::size_t>(data)] = true;
      }

      if (data == target) {
        std::cout << "found: " << data << '\n';
        return data;
      }

      for (const auto &edge : this->data_[data]) {
        if (!visited[static_cast<std::size_t>(edge.first)]) {
          que.push(edge.first);
        }
      }
    }

    return data;
  }

  bool can_walk_to(int from, int to) {
    return std::ranges::any_of(
      this->data_[static_cast<std::size_t>(from)],
      [to](const auto &pair) { return pair.first == to; });
  }

 private:
  std::vector<std::vector<std::pair<int, int>>> data_;
};
}  // namespace tre

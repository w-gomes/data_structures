#include "fmt/format.h"

#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

template <auto N>
class Graph {
  // the key is the node and the vector is the list containing the edges
  std::unordered_map<int, std::vector<int>> list_;
 public:  
  Graph() : list_(N) {}

  void add_node(int vertex, int edge) {
    if (list_.size() == N) {
      fmt::print("graph max size reached!\n");
    } else {
      this->list_[vertex].push_back(edge);
    }
  }

  void print() const {
    for (const auto &[vertex, edges] : this->list_) {
      fmt::print("node: {} -> ", vertex);
      for (const auto &edge : edges) {
        fmt::print("{} ", edge);
      }
      fmt::print("\n");
    }
  }

  int dfs(int node, int target) {
    auto stk = std::stack<int>{};
    auto visited = std::vector<bool>(7, false);

    stk.push(node);

    while(!stk.empty()) {
      node = stk.top();
      stk.pop();

      if (node == target) {
        fmt::print("found target\n");
        return node;
      }

      if (!visited[node]) {
        fmt::print("{} ", node);
        visited[node] = true;
      }

      auto &edges = this->list_[node];
      for (const auto &edge : edges) {
        if(!visited[edge]) {
          stk.push(edge);
        }
      }
    }
    return node;
  }

  int bfs(int node, int target) {
    auto que = std::queue<int>{};
    auto visited = std::vector<bool>(7, false);

    que.push(node);

    while(!que.empty()) {
      node = que.front();
      que.pop();

      if (node == target) {
        fmt::print("found target\n");
        return node;
      }

      if (!visited[node]) {
        fmt::print("{} ", node);
        visited[node] = true;
      }

      auto &edges = this->list_[node];
      for (const auto &edge : edges) {
        if (!visited[edge]) {
          que.push(edge);
        }
      }
    }
    return node;
  }
};

int main()
{
  // node size 7.
  // 1 2 3 4 5 6 7
  auto g = Graph<7>();
  g.add_node(1, 2);
  g.add_node(1, 3);
  g.add_node(1, 5);
  g.add_node(2, 1);
  g.add_node(3, 1);
  g.add_node(3, 4);
  g.add_node(3, 6);
  g.add_node(3, 7);
  g.add_node(7, 3);
  g.add_node(7, 5);
  g.add_node(5, 4);
  g.add_node(5, 1);
  g.add_node(5, 7);
  g.add_node(4, 5);
  g.add_node(4, 3);
  g.add_node(6, 3);
  //g.add_node(8, 1);

  //g.print();

  auto result = g.dfs(1, 2);
  fmt::print("target: {}\n", result);

  auto result2 = g.bfs(1, 7);
  fmt::print("target: {}\n", result2);

}
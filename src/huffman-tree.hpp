#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

#pragma warning(push)
#pragma warning(disable : 4265)
#include "fmt/format.h"

struct node {
  char c{};
  unsigned frequency{};
  std::shared_ptr<node> right{nullptr};
  std::weak_ptr<node> left{nullptr};
};

// Helper to sort nodes by its frequencies...
struct compare {
  bool operator()(const std::unique_ptr<node> &lhs, const std::unique_ptr<node> &rhs) {
    return lhs->frequency > rhs->frequency;
  }
};

// Helper to print nodes...
std::ostream &operator<<(std::ostream &out, const node &n) {
  const std::string s = fmt::format("Character: {} - Frequency: {}\n", n.c, n.frequency);
  out << s;
  return out;
}

// Helper to print vector of nodes...
void print_node(const std::vector<node> vec) {
  for (const auto &n : vec) {
    std::cout << n;
  }
}

using heap =
  std::priority_queue<std::unique_ptr<node>, std::vector<std::unique_ptr<node>>, compare>;
void make_tree(std::vector<std::pair<char, unsigned>> data) {
  heap min_heap;
  for (const auto [c, f] : data) {
    min_heap.push(std::make_unique<node>(c, f));
  }

  node *top;
  node *left;
  node *right;
  while (min_heap.size() != 1) {
    // Extract the two nodes with minimum frequencies.
    left = min_heap.top().get();
    min_heap.pop();
    right = min_heap.top().get();
    min_heap.pop();

    // Create new internal with the sum of the frequencies.
    top        = new node('$', left->frequency + right->frequency);
    top->left  = std::move(left);
    top->right = std::move(right);
  }
}

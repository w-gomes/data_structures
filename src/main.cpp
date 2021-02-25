/*
 * Using Introduction to Algorithm book to learn some data structures.
 * */
#include <fmt/format.h>

#include <thread>

#include "double-linked.hpp"
#include "graph.hpp"
#include "stack.hpp"

template <typename T>
void empty(const tre::list<T>& list) {
  if (tre::is_empty(list)) {
    fmt::print("is empty\n");
  } else {
    fmt::print("is not empty\n");
  }
}

int main() {
  /*
  tre::stack<int, 20> s{};
  fmt::print("pushing...\n");
  fmt::print("len: {}\n", s.len());
  s.push(10);
  fmt::print("len: {}\n", s.len());
  s.push(27);
  fmt::print("len: {}\n", s.len());
  s.push(42);
  fmt::print("len: {}\n", s.len());

  fmt::print("\npopping...\n");
  fmt::print("len: {}\n", s.len());
  auto x = s.pop();
  fmt::print("len: {}\n", s.len());
  auto y = s.pop();
  fmt::print("len: {}\n", s.len());
  auto w = s.pop();
  fmt::print("len: {}\n", s.len());
  fmt::print("x {}, y {}, w {}\n", x, y, w);

  fmt::print("\nclearing...\n");
  s.clear();
  fmt::print("len: {}\n", s.len());
  tre::list l;
  */

  // double-linked
  /*
  auto my_list = tre::list<int>();
  empty(my_list);

  auto vec = std::vector<int>{1, 4, 16, 9, 25};

  for (const auto& num : vec) { tre::insert(my_list, num); }

  // auto node = tre::search(my_list, 16);
  // fmt::print("data is {}\n", node->data);
  tre::print(my_list);
  empty(my_list);
  auto x = tre::search(my_list, 25);
  if (x) {
    // fmt::print("x has {}\n", x->data);
  } else {
    fmt::print("x has nothing\n");
  }

  auto y = tre::search(my_list, 27);
  if (y) {
    // fmt::print("y has {}\n", y->data);
  } else {
    fmt::print("y has nothing\n");
  }

  fmt::print("size of list is {}\n", tre::size(my_list));
  */

  // graph
  auto g = tre::Graph<6>();
  g.add_data(1, 5, 0);
  g.add_data(1, 2, 0);
  g.add_data(2, 1, 0);
  g.add_data(2, 5, 0);
  g.add_data(2, 3, 0);
  g.add_data(3, 4, 0);
  g.add_data(3, 2, 0);
  g.add_data(4, 3, 0);
  g.add_data(4, 5, 0);
  g.add_data(4, 6, 0);
  g.add_data(4, 5, 0);
  g.add_data(5, 1, 0);
  g.add_data(5, 2, 0);
  g.add_data(5, 4, 0);
  g.add_data(6, 4, 0);

  fmt::print("has edge {}\n", g.can_walk_to(1, 2));
  fmt::print("has edge {}\n", g.can_walk_to(5, 3));
  fmt::print("has edge {}\n", g.can_walk_to(4, 1));
  fmt::print("has edge {}\n", g.can_walk_to(4, 2));

  // g.print();

  // std::cout << g.dfs(1, 6) << '\n';
  // std::cout << g.bfs(1, 6) << '\n';
  auto j = std::jthread{};
  return 0;
}

#pragma once
#include <fmt/format.h>

#include <algorithm>
#include <memory>
#include <vector>
/*
 * implementation of a double-linked tree with sentinel
 *
 *         node
 *  --------------------
 * | prev | data | next |
 *  --------------------
 *
 *        sentinel (nil)
 *  --------------------
 * | prev | data | next |
 *  --------------------
 *
 */

namespace tre {

template <typename T>
struct node {
  using value_type = T;

  node(value_type d, node *p, node *n)
    : data(d)
    , prev(p)
    , next(n) {}

  value_type data{};  // NOLINT
  node<T> *prev;      // NOLINT
  node<T> *next;      // NOLINT
};

template <typename T>
struct list {
  list()
    : nil(std::make_unique<node<T>>(0, nullptr, nullptr)) {}

  std::unique_ptr<node<T>> nil;                 // NOLINT
  std::vector<std::unique_ptr<node<T>>> nodes;  // NOLINT
};

// size of list
template <typename T>
auto size(const list<T> &l) {
  return l.nodes.size();
}

// print list
template <typename T>
void print(const list<T> &l) {
  for (const auto &node : l.nodes) {
    fmt::print("node: data = {}\n", node->data);
  }
}

// check if list is empty
template <typename T>
bool is_empty(const list<T> &l) {
  return l.nil->next == nullptr && l.nil->prev == nullptr;
}

// insert element
template <typename T>
void insert(list<T> &l, T data) {
  // pointer to nil node
  auto nil_pointer = l.nil.get();

  if (is_empty(l)) {
    // case 1: list is empty
    // we have to set both next and previous for nil pointer
    //
    // create new node to insert in the list
    auto new_node = std::make_unique<node<T>>(data, nil_pointer, nil_pointer);
    // set both next and prev
    nil_pointer->next = new_node.get();
    nil_pointer->prev = new_node.get();

    l.nodes.emplace_back(std::move(new_node));
  } else {
    // case 2: the list is not empty,
    // so we only have to set the next node.
    // nil pointing to next, the head of the list
    auto nil_next = nil_pointer->next;
    // create new node to insert in the list
    auto new_node     = std::make_unique<node<T>>(data, nil_pointer, nil_next);
    nil_pointer->next = new_node.get();

    l.nodes.emplace_back(std::move(new_node));
  }
}

// TODO: make this return a std::optional
// search element
template <typename T>
[[nodiscard]] auto search(const list<T> &l, const T data) {
  bool found{false};
  auto found_node = l.nil.get();

  for (const auto &node : l.nodes) {
    if (node->data == data) {
      found      = true;
      found_node = node.get();
      break;
    }
  }

  if (found) {
    fmt::print("{} element found\n", data);
  } else {
    fmt::print("{} element not found\n", data);
    found_node = nullptr;
  }

  return found_node;
}

}  // namespace tre

#include <iostream>
#include <stdexcept>
#include <utility>

namespace tre {
/*
 * LIFO: Last in First out.
 * */
template <typename Type, std::size_t Size>
class stack {
 public:
  stack() = default;

  void push(const Type &data) {
    this->data_[this->top_] = data;
    this->top_++;
  }

  [[nodiscard]] Type pop() {
    // this should throw an exception
    if (this->empty()) throw std::runtime_error("underflow");
    Type temp = this->data_[this->top_ - 1];
    this->top_--;
    return temp;
  }

  void clear() noexcept {
    for (std::size_t i = 0; i < Size; i++) {
      this->data_[i] = 0;
    }
    this->top_ = 0;
  }

  [[nodiscard]] std::size_t len() const { return this->top_; }
  [[nodiscard]] std::size_t stack_len() const { return this->len_; }
  [[nodiscard]] bool empty() const { return this->len_ == 0; }

 private:
  std::size_t len_ = Size;
  std::size_t top_{0};
  Type data_[Size];
};
}  // namespace tre

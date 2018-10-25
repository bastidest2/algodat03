#include <iostream>
#include <forward_list>

class Stack {
private:
  std::forward_list<char> stack {};

public:
  Stack() {}

  int size() const {
    return std::distance(stack.begin(), stack.end());
  }

  void push(char c) {
    stack.emplace_front(c);
  }

  char pop() {
    const char ret = stack.front();
    stack.pop_front();
    return ret;
  }
};

int check_parens(const std::string& input) {
  Stack stack{};

  for(const char c : input) {
    if(c == '(') {
      stack.push(c);
    } else if(c == ')') {
      if(stack.size() < 1 || stack.pop() != '(') {
        return -1;
      }
    }
  }

  if(stack.size() != 0) {
    return -2;
  }

  return 0;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "Usage: algo03 \"[<char>[<char> ...]]\"" << std::endl;
    return 2;
  }

  const std::string input {argv[1]};
  const int ret = check_parens(input);

  std::cout << ((ret == 0) ? "true" : "false") << std::endl;
  return ret;
}

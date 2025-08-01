#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  // Comparison to list
  std::cout << "--- std::list ---" << std::endl;
  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(17);
  std::cout << lst.back() << std::endl;
  lst.pop_back();
  std::cout << lst.size() << std::endl;
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);
  std::list<int>::iterator lit = lst.begin();
  std::list<int>::iterator lite = lst.end();
  ++lit;
  --lit;
  while (lit != lite) {
    std::cout << *lit << std::endl;
    ++lit;
  }

  // Corner case: empty MutantStack
  MutantStack<int> emptyStack;
  std::cout << "Empty stack iteration:" << std::endl;
  for (MutantStack<int>::iterator eit = emptyStack.begin();
       eit != emptyStack.end(); ++eit)
    std::cout << *eit << std::endl;

  // Corner case: copying and assignment
  MutantStack<int> copyStack = mstack;
  MutantStack<int> assignStack;
  assignStack = mstack;
  std::cout << "Copy stack iteration:" << std::endl;
  for (MutantStack<int>::iterator cit = copyStack.begin();
       cit != copyStack.end(); ++cit)
    std::cout << *cit << std::endl;
  std::cout << "Assign stack iteration:" << std::endl;
  for (MutantStack<int>::iterator ait = assignStack.begin();
       ait != assignStack.end(); ++ait)
    std::cout << *ait << std::endl;

  // Corner case: another type (std::string)
  MutantStack<std::string> strStack;
  strStack.push("hello");
  strStack.push("world");
  std::cout << "String stack iteration:" << std::endl;
  for (MutantStack<std::string>::iterator sit = strStack.begin();
       sit != strStack.end(); ++sit)
    std::cout << *sit << std::endl;
  return 0;
}
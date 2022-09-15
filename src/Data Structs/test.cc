

#include <assert.h>
#include <cstdio>

#include "list.hpp"

int main() {
  List<int> list;
  list.append(0);
  list.append(1);
  list.append(2);
  list.append(3);
  assert(list.size() == 4);
  assert(list.find(0)->data == 0);
  assert(list.find(1)->data == 1);
  assert(list.find(2)->data == 2);
  assert(list.find(3)->data == 3);

  list.erase(0);
  assert(list.size() == 3);
  assert(list.find(0)->data == 1);
  list.insert(2, 4);
  assert(list.find(2)->data == 4);
  assert(list.find(3)->data == 3);
  list.prepend(-1);
  assert(list.size() == 5);
  assert(list.find(0)->data == -1);

  list.erase(0);
  list.erase(0);
  list.erase(0);
  list.erase(0);
  list.erase(0);
  assert(list.size() == 0);
  puts("List test pass.");
}

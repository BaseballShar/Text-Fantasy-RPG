#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
  string data;
  Node *prev;
  Node *next;
};

struct List {
  Node *head = 0;
  Node *tail = 0;
  int len = 0;

  // Purpose: To add (str) to the back of the list
  void Append(string str);

  // Purpose: To add (str) to the front of the list
  void AppendFront(string str);

  // Purpose: Returns elements at the ith index positions
  string Extract(int index);

  // Purpose: To delete the element at index (index)
  void DeleteIndex(int index);

  // Purpose: To delete the element of value (value)
  void DeleteValue(string value);

  // Purpose: To erase all elements in the list
  void DeleteAll();

  // Purpose: To find and return the index of element of value (value)
  int Find(string value);

  // Purpose: To insert the element of value (value) at the index position
  void Insert(int index, string value);

};

#endif

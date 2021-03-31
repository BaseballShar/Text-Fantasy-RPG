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

  string first();

  string last();

  void AppendBack(string str);

  void AppendFront(string str);

  void PrintForward();

  void PrintBackward();

  // Purpose: Returns elements at the ith index positions
  string Extract(int index);

  void DeleteIndex(int index);

  void DeleteValue(string value);

};

void SortAsc(List &list);

void SortDsc(List &list);

#endif
#include <iostream>
#include "list.h"
using namespace std;


string List::first() {
  return head -> data;
}

string List::last() {
  return tail -> data;
}

void List::AppendBack(string str) {
  Node *p = new Node;
  p -> data = str;

  if (head != 0) {
    Node *current = head;

    p -> next = 0;
    p -> prev = tail;
    tail -> next = p;
    tail = p;
  }
  else {
    head = p;
    tail = p;
    head -> next = 0;
    head -> prev = 0;  
  }
  len += 1;
}

void List::AppendFront(string str) {
  Node *p = new Node;
  p -> data = str;

  if (head != 0) {
    Node *current = head;

    p -> next = head;
    p -> prev = 0;
    head -> prev = p;
    head = p;
  }
  else {
    head = p;
    tail = p;
    head -> next = 0;
    head -> prev = 0;
  }
  len += 1;
}

void List::PrintForward() {
  Node *current = head;
  while (current != 0) {
    cout << current -> data << " ";
    current = current -> next;
  }
  cout << endl;
}

void List::PrintBackward() {
  Node *current = head;
  while (current -> next != 0) {
    current = current -> next;
  }

  while (current != 0) {
    cout << current -> data << " ";
    current = current -> prev;
  }
  cout << endl;
}

  // Purpose: Returns elements at the ith index positions
string List::Extract(int index) {
  Node *current = head;

  if (index >= len) {
    cout << "Invalid index" << endl;
    return 0;
  }
  else {
    for (int i = 0; i < index; i++)
    current = current -> next;
    return current -> data;
  }
}

void List::DeleteIndex(int index) {
  if (index == 0 && len != 1) {
    Node *del = head;
    head = head -> next;
    head -> prev = 0;
    delete del;
  }
  else if (index == 0 && len == 1) {
    Node *del = head;
    head = 0;
    tail = 0;
    delete del;
  }
  else if (index == len - 1) {
    Node *del = tail;
    tail = tail -> prev;
    tail -> next = 0;
    delete del;
  }
  else {
    Node *current = head;
    for (int i = 0; i < index - 1; i++)
    current = current -> next;

    Node *left = current;
    Node *del = left -> next;
    Node *right = del -> next;

    left -> next = right;
    right -> prev = left;
    delete del;
  }
  len -= 1;
}

void List::DeleteValue(string value) {
  int index = 0;
  bool is_found = false;
  for(int i = 0; i < len; i++) {
    if (Extract(i) == value) {
    index = i;
    is_found = true;
    }
  }
  if (is_found) {
    DeleteIndex(index);
  }
  else {
    cout << "Invalid value" << endl;
  }
}



void SortAsc(List &list) {
  List sorted_list;
  int min_index;
  
  while (list.len > 0) {
    min_index = 0;
    for (int i = 0; i < list.len; i++) {
        if (list.Extract(i) < list.Extract(min_index))
          min_index = i;
    }

    sorted_list.AppendBack(list.Extract(min_index));
    list.DeleteIndex(min_index);
  }
  list.head = sorted_list.head;
  list.tail = sorted_list.tail;
}

void SortDsc(List &list) {
  List sorted_list;
  int max_index;
  
  while (list.len > 0) {
    max_index = 0;
    for (int i = 0; i < list.len; i++) {
        if (list.Extract(i) > list.Extract(max_index))
          max_index = i;
    }

    sorted_list.AppendBack(list.Extract(max_index));
    list.DeleteIndex(max_index);
  }
  list.head = sorted_list.head;
  list.tail = sorted_list.tail;
}

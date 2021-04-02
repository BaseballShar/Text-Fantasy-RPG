#include <iostream>
#include "list.h"
using namespace std;

// Purpose: To add (str) to the back of the list
void List::Append(string str) {
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

// Purpose: To add (str) to the front of the list
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

// Purpose: To delete the element at index (index)
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

// Purpose: To delete the element of value (value)
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

// Purpose: To erase all elements in the list
void List::DeleteAll() {
 while (len > 0) {
   DeleteIndex(0);
 }
}

// Purpose: To find and return the index of element of value (value)
int List::Find(string value) {
  int index = 0;
  for (int i = 0; i < len; i++) {
    if (Extract(i) == value)
      return i;
  }
  return -1;
}

// Purpose: To insert the element of value (value) at the index position
void List::Insert(int index, string value) {
  if (index == 0) {
    AppendFront(value);
  }
  else {
    Node *current = head;
    for (int i = 0; i < index; i++) {
      current = current -> next;
    }

    Node *right = current;
    Node *left = current -> prev;

    Node *p = new Node;
    p -> data = value;

    left -> next = p;
    p -> prev = left;
    right -> prev = p;
    p -> next = right;

    len += 1;
  }
  
}

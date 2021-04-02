#include "useful_function.h"

// Purpose: To check whether an input string is consisted of numbers only
bool IsNum(string value) {
  for (int i = 0; i < value.length(); i++) {
    if (!isnumber(value[i]))
      return false;
  }
  return true;
}
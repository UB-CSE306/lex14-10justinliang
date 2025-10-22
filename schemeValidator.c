#include "schemeValidator.h"

int schemeValidator(char scheme[]) {
  int result = -1;
  if (isAlpha(scheme[0])) {
    result = 0; 
    int i = 1;
    while (scheme[i] != '\0') {
      if (!isAlpha(scheme[i])) {
        if (!isDigit(scheme[i])) {
          if (!isSpecial(scheme[i])) {
            result = -1;
          }
        }
      }
      i++;
    }
  }
  if ('A' <= scheme[0] && scheme[0] <= 'Z') {
    result = 1;
  }
  return result;
}

bool isAlpha(char c) {
    if ('a' <= c && c <= 'z') {
        return true;
    }
    else if ('A' <= c && c <= 'Z') {
        return true;
    }
    else {
        return false;
    }
}

bool isSpecial(char c) {
  bool result = false;
  if (c == '+') result = true;
  else if (c == '-') result = true;
  else if (c == '.') result = true; 
  return result;
}

bool isDigit(char c) {
  return '0' < c && c < '9';
}
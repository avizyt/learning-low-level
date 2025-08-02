
// Helper function for infix to postfix convertion

// check if the char is an operator
#include <cctype>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// function to get the precedence of an opeartor
// higher number means higher precedence
int getPrecedence(char op) {
  if (op == '^')
    return 3;
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;

  return 0;
}

bool isLeftAssociative(char op) {
  return op == '+' || op == '-' || op == '*' ||
         op == '/'; // ^ is right-associative
}

// isfix to postfix
string infixToPostfix(const string &infix) {
  string postfix = "";
  stack<char> op_st;

  for (char c : infix) {
    if (isspace(c)) {
      continue;
    } else if (isalnum(c)) {
      postfix += c;
      postfix += ' ';
    } else if (c == '(') {
      op_st.push(c);
    } else if (c == ')') {
      while (!op_st.empty() && op_st.top() != '(') {
        postfix += op_st.top();
        postfix += ' ';
        op_st.pop();
      }
      if (!op_st.empty() && op_st.top() == '(') {
        op_st.pop();
      } else {
        return "Error: Mismatched parentheses";
      }
    } else if (isOperator(c)) {
      while (!op_st.empty() && op_st.top() != '(' &&
             (getPrecedence(c) < getPrecedence(op_st.top()) ||
              (getPrecedence(c) == getPrecedence(op_st.top()) &&
               isLeftAssociative(c)))) {
        postfix += op_st.top();
        postfix += ' ';
        op_st.pop();
      }
      op_st.push(c);
    } else {
      return "Error: Invalid char in expression";
    }
  }

  while (!op_st.empty()) {
    if (op_st.top() == '(') {
      return "Error: Mismatched parentheses";
    }
    postfix += op_st.top();
    postfix += ' ';
    op_st.pop();
  }

  if (!postfix.empty() && postfix.back() == ' ') {
    postfix.pop_back();
  }
  return postfix;
}
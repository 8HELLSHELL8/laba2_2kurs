//#include <iostream>
//#include "Stack.h"
//#include <string>
//#include "vector.h"
//
//using namespace std;
//
//bool isOperator(char token) {
//    return token == '+' || token == '-' || token == '*' || token == '/';
//}
//
//int precedence(char op) {
//    if (op == '*' || op == '/') return 3;
//    if (op == '+' || op == '-') return 2;
//    if (op == '(') return 1;
//    return 0;
//}
//
//Myvector<string> infixToPostfix(const string& infixexpr) {
//    Stack<char> opStack;
//    Myvector<string> postfixList;
//    string token;
//    bool lastWasOperand = false;
//
//    for (size_t i = 0; i < infixexpr.size(); ++i) {
//        char ch = infixexpr[i];
//
//        if (isspace(ch)) continue;
//
//        // Если символ - буква или число
//        if (isalnum(ch)) {
//            // Проверка, если предыдущий символ был операндом или закрывающей скобкой без оператора между ними
//            if (lastWasOperand) {
//                cerr << "Input error: missing operator between operands.\n";
//                return Myvector<string>();
//            }
//            token += ch;
//            lastWasOperand = true;
//        }
//        else {
//            if (!token.empty()) {
//                postfixList.MPUSH(token);
//                token.clear();
//            }
//
//            if (isOperator(ch)) {
//                while (!opStack.is_empty() && precedence(opStack.top()) >= precedence(ch)) {
//                    postfixList.MPUSH(string(1, opStack.top()));
//                    opStack.pop();
//                }
//                opStack.push(ch);
//                lastWasOperand = false;
//            }
//            else if (ch == '(') {
//                if (lastWasOperand) {
//                    cerr << "Input error: missing operator before '('.\n";
//                    return Myvector<string>();
//                }
//                opStack.push(ch);
//                lastWasOperand = false;
//            }
//            else if (ch == ')') {
//                while (!opStack.is_empty() && opStack.top() != '(') {
//                    postfixList.MPUSH(string(1, opStack.top()));
//                    opStack.pop();
//                }
//                if (!opStack.is_empty()) opStack.pop();
//                lastWasOperand = true;
//            }
//        }
//    }
//
//    if (!token.empty()) {
//        postfixList.MPUSH(token);
//    }
//
//    while (!opStack.is_empty()) {
//        postfixList.MPUSH(string(1, opStack.top()));
//        opStack.pop();
//    }
//
//    return postfixList;
//}
//
//int main() {
//    cout << "Enter the Infix expression:\n";
//    string input;
//    getline(cin, input);
//
//    int openBrackets = 0;
//    for (char ch : input) {
//        if (ch == '(') openBrackets++;
//        else if (ch == ')') openBrackets--;
//        if (openBrackets < 0) {
//            cerr << "Input error with parentheses: unmatched closing bracket.\n";
//            return 1;
//        }
//    }
//    if (openBrackets != 0) {
//        cerr << "Input error with parentheses: unmatched opening bracket.\n";
//        return 1;
//    }
//
//    Myvector<string> postfix = infixToPostfix(input);
//
//    if (postfix.size() == 0) {
//        return 1; // Ошибка уже выведена, завершаем программу
//    }
//
//    cout << "Postfix expression: ";
//    for (const auto& token : postfix) {
//        cout << token << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

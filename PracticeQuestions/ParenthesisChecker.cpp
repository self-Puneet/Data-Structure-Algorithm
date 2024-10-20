// Parenthesis Checker: Write a program that checks if a string of parentheses is well-formed, meaning every opening parenthesis has a corresponding closing parenthesis. Use a stack to validate the sequence, and return a message indicating whether the parentheses are balanced or not.

#include <iostream>
#include <string>
using namespace std;

class ParenthesisChecker {
    public:
        static void check (string str) {
            char parenthesis_char [3][2] = {{'{','}'},{'[',']'},{'(',')'}};
            char stack [str.length()];
            int top = -1;
            for (int i = 0; i < str.length(); i++) {
                if (ifIn (str[i], parenthesis_char)) {
                    addChar (str[i], stack, top, parenthesis_char);
                }
            }
            if (top == -1) {
                cout << "string is balanced" << endl;
            }
            else {
                cout << "string is not balanced" << endl;
            }
        }
    private:
        static bool ifIn (char c, char parenthesis_char[3][2]) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    if (c == parenthesis_char[i][j]) {
                        return true;
                    }
                }
                
            }
            return false;
        }
        static void addChar (char c, char stack[], int& top, char parenthsis_char[3][2]) {
            top++;
            stack[top] = c;
            for (int i = 0; i < 3; i++) {
                if (stack[top-1] == parenthsis_char[i][0] && stack[top] == parenthsis_char[i][1]) {
                    top -= 2;
                }
            }
        }
};

int main() {
    string str = "({[3+4]+2}-{6}+[7])";
    ParenthesisChecker::check(str);
    return 0;
}

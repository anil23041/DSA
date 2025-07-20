#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                if (st.empty()) s[i] = '0';
                st.push(ch);
            } else {
                st.pop();
                if (st.empty()) s[i] = '0';
            }
        }

        string ans;
        for (char ch : s) {
            if (ch != '0') ans.push_back(ch);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string input1 = "(()())(())";
    string input2 = "(()())(())(()(()))";
    string input3 = "()()";

    cout << "Input: " << input1 << "\nOutput: " << sol.removeOuterParentheses(input1) << "\n\n";
    cout << "Input: " << input2 << "\nOutput: " << sol.removeOuterParentheses(input2) << "\n\n";
    cout << "Input: " << input3 << "\nOutput: " << sol.removeOuterParentheses(input3) << "\n";

    return 0;
}

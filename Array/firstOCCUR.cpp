#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    cout << "Output 1: " << sol.strStr(haystack1, needle1) << endl;

    string haystack2 = "leetcode";
    string needle2 = "leeto";
    cout << "Output 2: " << sol.strStr(haystack2, needle2) << endl;

    return 0;
}

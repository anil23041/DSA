#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = 0;
        int current = 1;
        int i = 0;

        while (missing < k) {
            if (i < arr.size() && arr[i] == current) {
                i++;
            } else {
                missing++;
            }
            current++;
        }

        return current - 1;
    }
};

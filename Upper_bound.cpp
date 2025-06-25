#include <bits/stdc++.h>
using namespace std;

int lower_bound(int target, const vector<int> &temp) {
    int n = temp.size();
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (temp[mid] < target) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int upper_bound(int target, const vector<int> &temp) {
    int n = temp.size();
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (temp[mid] <= target) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    cout << "Binary search\n";
    vector<int> temp = {1, 2, 3, 4, 4, 4, 4, 5, 5, 5, 7, 7, 8, 9, 9, 10, 10, 151, 789};
    int target = 10;

    int lb = lower_bound(target, temp);
    int ub = upper_bound(target, temp);

    if (lb != -1 && temp[lb] == target)
        cout << "Lower Bound: " << lb << "\n";
    else
        cout << "Lower Bound: Not found\n";

    if (ub != -1)
        cout << "Upper Bound: " << ub << "\n";
    else
        cout << "Upper Bound: Not found\n";

    return 0;
}

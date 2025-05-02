#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string pushDominoes(string dominoes) {
    int n = dominoes.length();
    vector<int> force(n, 0);

    // Left to right pass for 'R'
    int f = 0;
    for (int i = 0; i < n; ++i) {
        if (dominoes[i] == 'R') f = n;
        else if (dominoes[i] == 'L') f = 0;
        else f = max(f - 1, 0);
        force[i] += f;
    }

    // Right to left pass for 'L'
    f = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (dominoes[i] == 'L') f = n;
        else if (dominoes[i] == 'R') f = 0;
        else f = max(f - 1, 0);
        force[i] -= f;
    }

    // Build result
    string result(n, '.');
    for (int i = 0; i < n; ++i) {
        if (force[i] > 0) result[i] = 'R';
        else if (force[i] < 0) result[i] = 'L';
    }

    return result;
}

int main() {
    string input = ".L.R...LR..L..";
    string output = pushDominoes(input);
    cout << "Result: " << output << endl;
    return 0;
}


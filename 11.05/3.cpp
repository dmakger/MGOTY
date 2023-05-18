#include <iostream>
#include <vector>

using namespace std;

int frogJump(int n, vector<vector<int>>& paths) {
    if (n <= 2) {
        return n;
    }

    int result = 0;
    for (int i = 1; i <= 3 && n - i >= 1; i++) {
        result += frogJump(n - i, paths);
        paths[n].push_back(n - i);
    }

    return result;
}

void printPaths(const vector<vector<int>>& paths) {
    for (int i = 0; i < paths.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < paths[i].size(); j++) {
            cout << paths[i][j] << " -> ";
        }
        cout << "end" << endl;
    }
}

int main() {
    int n = 10;
    vector<vector<int>> paths(n + 1);
    int result = frogJump(n, paths);

    cout << "f(10) = " << result << endl;
    cout << "Possible paths:" << endl;
    printPaths(paths);

    n = 40;
    paths.clear();
    paths.resize(n + 1);
    result = frogJump(n, paths);

    cout << "f(40) = " << result << endl;

    return 0;
}
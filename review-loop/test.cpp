#include <iostream>

using namespace std;

void reviewLoop() {
    string str;
    cin >> str;
    int n = str.size();

    int j = 0;
    while (j < n) {
        cout << str[j];
        j += 2;
    }
    cout << " ";
    j = 1;
    while (j < n) {
        cout << str[j];
        j += 2;
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        reviewLoop();
    }

    return 0;
}

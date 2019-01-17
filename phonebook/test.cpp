#include <map>
#include <iostream>

using namespace std;

int main() {
    string name;

    int n;
    cin >> n;

    std::map<string, long> phoneBook;

    while(n--) {
        cin >> name;
        cin >> phoneBook[name];
    }

    while(!cin.eof()) {
        cin >> name;

        auto it = phoneBook.find(name);

        if (it == phoneBook.end()) {
            cout << "Not found" << endl;
        }
        else {
            cout << it->first << "=" << it->second << endl;
        }
    }

    return 0;
}

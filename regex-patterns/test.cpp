#include <bits/stdc++.h>

using namespace std;

class Record {
private:
    string name, email;

public:
    Record(string name, string email) {
        this->name = name;
        this->email = email;
    }

    string getName() {
        return this->name;
    }

    bool isGmailUser() {
        regex re("@gmail\\.com");
        smatch matches;
        return regex_search(this->email, matches, re);
    }
};

struct NameRecordCompare {
    const bool operator() (Record* recA, Record* recB) const {
        return recA->getName() < recB->getName();
    }
};

Record* readRecord()
{
    string name, email;
    cin >> name >> email;
    return new Record(name, email);
}

int main()
{
    int n;
    cin >> n;

    vector<Record*> records;
    records.reserve(n);

    while (n-- > 0) {
        records.push_back(readRecord());
    }


    // filter
    auto filterFunc = [](Record* record) { return ! record->isGmailUser(); };

    records.erase(
        remove_if(records.begin(), records.end(), filterFunc),
        records.end()
    );


    // sort
    sort(records.begin(), records.end(), NameRecordCompare());

    for (auto x : records) {
        cout << x->getName() << endl;
    }   

    return 0;
}

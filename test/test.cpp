#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string x = "\"hi,AA, DD\",\"BB,CC\"";

    int start = x.find("\"");
    int end = x.find("\"", start + 1);

    if (start == -1 && end == -1) {
        // break;
    }

    string stringed_entry = x.substr(start, end);
    std::replace(stringed_entry.begin(), stringed_entry.end(), ',', ';');
    x.replace(start, end, stringed_entry);

    cout << x << endl;

    return 0;
}

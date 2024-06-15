#include "reader.h"

using namespace std;

// Constants for the number of rows and columns
const int NUM_ROWS = 19992;
const int NUM_COLS = 14;

void treat_csv() {
    fstream file;
    file.open("../data.csv", ios::in);
    if (!file.is_open()) {
        return;
    }

    int rows = 0;
    string row;
    while (getline(file, row)) // get every row
    {
        if (rows == 4) break;

        while (true) {
            int start = row.find("\"");
            int end = row.find("\"", start + 1);

            if (start == -1 && end == -1) {
                break;
            }

            string stringed_entry = row.substr(start, end + 1);
            std::replace(stringed_entry.begin(), stringed_entry.end(), ',', ';');
            row.replace(start, end, stringed_entry);
        }

        cout << "[" << rows << "] " << row << endl;
        cout << endl;

        rows++;
    }
}

void read_csv()
{
    fstream file;
    file.open("../data.csv", ios::in);
    if (!file.is_open()) {
        return;
    }

    int rows = 0;
    std::vector<std::vector<string>> columns;
    std::vector<string> column;
    string row;
    while (getline(file, row)) // get every row
    {
        size_t pos = 0;
        // Adapted from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c#14266139
        while (true) {
            pos = row.find(",");
            if (pos == string::npos) {
                // Empty check omitted as there are no empty row in this data set.
                column.push_back(row);
                break;
            }

            string value = row.substr(0, pos);
            column.push_back(value);
            row.erase(0, pos + 1); // this erases until the value and one more character which is the ","
                                   
            pos = row.find(",");
        }

        columns.push_back(column);
        rows++;
    }

    file.close();
}

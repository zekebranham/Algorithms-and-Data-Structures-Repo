#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip> // for setting decimal places
using namespace std;
//Lab 7 uses Hash Tables with Open Addressing-Linear Probing with Hash function: H(x) = (sum of ascii value of each character) % HASH SIZE


int uniqueWordCount = 0; // Global variable to track the number of unique words
struct KeyValuePair {
    string key;
    int value;
    bool occupied;
    KeyValuePair() : key(""), value(0), occupied(false) {}
};

class HashTable {
public:
    static const int tableSize = 4001;
    KeyValuePair table[tableSize];
    float updates[tableSize]; // Array to track updates
    float cost[tableSize]; // Array to track cost

    HashTable() {
        for (int i = 0; i < tableSize; i++) {
            updates[i] = static_cast<float>(updates[0]);
            cost[i] = static_cast<float>(cost[0]);
        }
    }

int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % tableSize;
    }

    void insert(const string& key, int value) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index].occupied) {
            if (table[index].key == key) {
                table[index].value = value;
                return;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex) {
                cerr << "Table is full." << endl;
                return;
            }
        }

        table[index].key = key;
        table[index].value = value;
        table[index].occupied = true;
    }

    int find(const string& key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index].occupied) {
            if (table[index].key == key) {
                return table[index].value;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex) {
                return -1;
            }
        }

        if (table[index].key == key) {
            updates[index] = 0; // Set update to 0 when the word is found
            cost[index] += 1;
            return table[index].value;
        } else {
            cost[index] += 2;
        }

        return -1;
    }

    int size() {
        int count = 0;
        for (int i = 0; i < tableSize; i++) {
            if (table[i].occupied) {
                count++;
            }
        }
        return count;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i].occupied) {
                cout << "Slot " << i << ": (" << table[i].key << ", " << table[i].value << ")" << endl;
            }
        }
    }

    void displayRatios() {
        for (int i = 0; i < tableSize; i++) {
            if (updates[i] > 0) {
                float ratio = static_cast<float>(cost[i]) / updates[i];
                cout << "i:" << i + 1 << " Ratio: " << fixed << setprecision(2) << ratio << endl;
            }
        }
    }

void update(HashTable& hashTable, const string& word) {
    int asciiValue = 0;
    for (char c : word) {
        asciiValue += static_cast<int>(c);
    }
    int originalAsciiValue = asciiValue; // Store the original ASCII value
    int index = hashTable.hashFunction(word);
    float probe = static_cast<float>(0);

    while (hashTable.table[index].occupied) {
        if (hashTable.table[index].key == word) {
            return; // Word already exists, no collision
        }
        index = (index + 1) % hashTable.tableSize; // Linear probing
        updates[index] = 1;     //update table = 1 when value is inserted
        probe++;
        if (index == hashTable.hashFunction(word)) {
            break;
        }
    }

    // If the loop ended, a collision occurred
    hashTable.insert(word, originalAsciiValue);
    uniqueWordCount++; // Increment uniqueWordCount for each collision
    cost[index]=probe;  //increment cost[]
}
};




int main() {
 HashTable hashTable;

 	string filePath = "C:\\Users\\14807\\Downloads\\RomeoAndJuliet.txt"; 
    ifstream inputFile(filePath);

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                hashTable.update(hashTable, word);
            }
        }
        inputFile.close();
    } else {
        cerr << "Error: Unable to open the input file." << endl;
        return 1;
    }

    hashTable.display();
    //hashTable.displayRatios();
    cout << "Number of unique words: " << uniqueWordCount << endl;


    return 0;
}

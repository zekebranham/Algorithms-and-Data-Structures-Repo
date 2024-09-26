#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

int uniqueWordCount = 0;
struct KeyValuePair {
    int key;
    string word;
};

class HashTable {
private:
    static const int tableSize = 4001;
    list<KeyValuePair> table[tableSize];

public:
    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key, string word) {
        int index = hashFunction(key);
        KeyValuePair pair;
        pair.key = key;
        pair.word = word;
        table[index].push_back(pair);
    }

    void update1(const string& word) {
        int asciiValue = 0;
        for (char c : word) {
            asciiValue += static_cast<int>(c);
        }
        insert(asciiValue, word);
    }
    void update(const string& line) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            int asciiValue = 0;
            for (char c : word) {
                asciiValue += static_cast<int>(c);
            }
            insert(asciiValue, word);
        }
    }

    int size() {
        int count = 0;
        for (int i = 0; i < tableSize; i++) {
            if (!table[i].empty()) {
                count++;
            }
        }
        return count;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            for (auto& pair : table[i]) {
                cout << "(" << pair.key << ", " << pair.word << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    int number = 0;

    string filePath = "C:\\Users\\14807\\Downloads\\RomeoAndJuliet.txt";
    ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        string word;
        while (inputFile >> word) {
            number++;
            //cout<<word<<" " ;
            hashTable.update(word);
        }
        inputFile.close();
        uniqueWordCount = hashTable.size();
    }
    else {
        cout << "Error: Unable to open the input file." << endl;
        return 1;
    }



    // Display the hash table
    hashTable.display();
    cout << "Number of words: " << number << endl;
    cout << "Number of unique words: " << uniqueWordCount << endl;

    return 0;
}


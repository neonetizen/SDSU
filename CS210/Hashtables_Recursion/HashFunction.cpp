#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Hash function class
class HashFunction {
private:
  int compressKey(string key) {
    // Compression: Convert the key into a 32-bit integer
    unsigned int hashcode = 0;
    int prime = 7;
    for (int c = 0; c < key.length(); c++) {
      if (isalpha(key[c])) {
        hashcode = tolower(key[c]);
      }
      hashcode = hashcode * prime + (int)key[c];
    }
    return hashcode;
  }

public:
  int hash(string key, const int tableSize) {
    int hashIndex = 0;

    // Call compression here.
    hashIndex = compressKey(std::move(key)) % tableSize;
    return hashIndex;
  };

  // Test function to demonstrate the hashing
  void testHashFunction() {
    // Example keys
    string keys[] = {"9242064424678123", "9NJGDHQQV8E", "ALTEBUERIO", "9242064424678123"};
    const int tableSize = 15;

    auto table = vector<int>(tableSize);

    cout << "Key\t\t\tHashed Index\n";
    cout << "---------------------------------\n";

    for (const auto& key : keys) {
      int hashed = hash(key, tableSize);
      while (table[hashed]) {
        hashed++;
      }
      table[hashed] = 1;

      cout << key << "\t\t" << hashed << '\n';
    }
  }

};
int main() {
    HashFunction hashFunction;
    hashFunction.testHashFunction();
    cout << "\n## The hash function deals with collisions with linear probing ##";
    return 0;
  }
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &str, int start, int end) {
  if (start >= end)
    return true;

  if (str[start] != str[end])
    return false;

  if (isPalindrome(str, start+1, end-1))
    return true;

  return false;
}

int main() {
  string input;

  // Input from the user
  cout << "Enter a string: ";
  getline(cin, input);
  // Write a function to ignore all the nonalphabetic characters in the string.
  string cleaned;
  for (const char& c : input) {
    if (isalnum(c) && !isspace(c)) {
      cleaned += tolower(c);
    }
  }
  // Call the recursive function and display the result
  if (isPalindrome(cleaned, 0, cleaned.length() - 1)) {
    cout << "\"" << input << "\" is a palindrome." << endl;
  } else {
    cout << "\"" << input << "\" is not a palindrome." << endl;
  }

  return 0;
}

// Recursive function to check if a string is a palindrome

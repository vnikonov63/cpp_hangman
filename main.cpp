#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Check the requirement to exit the program
void CheckIfExit(string input) {
  if (input == "Q") {
    exit(3);
  }
}

string pickRandomWord(vector<string> input) {
  srand(time(0));
  int randomNumber = (rand() % input.size());
  return input[randomNumber];
}

bool CheckAsteriksPresence(string input) {
  for (const char& c : input) {
    if (c == '*') {
      return false;
    }
  }
  return true;
}

string CheckGuess(string desiredWord, string partial, string choice) {
  int i = 0;
  for (const char& c : desiredWord) {
    if (c == choice[0]) {
      partial[i] = choice[0];
    }
    ++i;
  }
  return partial;
}

int main() {
  // initialise the possible languages for the programming languages
  vector<string> listOfWords;
  listOfWords.push_back("Python");
  listOfWords.push_back("Java Script");
  listOfWords.push_back("Java");
  listOfWords.push_back("Pascal");
  listOfWords.push_back("Basic");
  listOfWords.push_back("Fortran");
  listOfWords.push_back("Python");
  listOfWords.push_back("C");
  listOfWords.push_back("Assembly");
  listOfWords.push_back("Lisp");
  listOfWords.push_back("Ruby");
  listOfWords.push_back("PHP");
  listOfWords.push_back("Perl");
  listOfWords.push_back("Delphi");
  listOfWords.push_back("Go");
  listOfWords.push_back("Rust");
  listOfWords.push_back("C++");
  listOfWords.push_back("Cobol");
  listOfWords.push_back("Kotlin");
  listOfWords.push_back("Swift");

  string word = pickRandomWord(listOfWords);
  string userAnswer;
  userAnswer = string(word.size(), '*');
  /*cout << "Enter a letter in word ";
  cout << userAnswer;
  cout << " > "; */
  while (CheckAsteriksPresence(userAnswer) == false) {
    cout << "Enter a letter in word ";
    cout << userAnswer;
    cout << " > ";
    string choice;
    cin >> choice;
    string partial = CheckGuess(word, userAnswer, choice);
    userAnswer = partial;
    cout << endl;
  }
}

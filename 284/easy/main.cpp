#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> getDictionary() {
    unordered_set<string> dictionary;

    string word;
    ifstream fin("dictionary.txt");

    while(fin >> word) {
        dictionary.insert(word);
    }

    return dictionary;
}

void getWordsOfLengthGreaterThan(int length, string input, string current, const unordered_set<string> &dictionary, unordered_set<string> &answers) {

    if (current.size() + 1 >= length && dictionary.count(current + input[input.size() - 1]) > 0) {
        answers.insert(current + input[input.size() - 1]);
    }

    for (int i=0; i<input.size() - 1; ++i) {
        getWordsOfLengthGreaterThan(length, input.substr(i+1), current + input[i], dictionary, answers);
    }
}

unordered_set<string> getWordsOfLengthGreaterThan(int length, string input) {
    if (input.size() == 0) {
        return unordered_set<string>();
    }

    unordered_set<string> dictionary = getDictionary();

    unordered_set<string> toReturn;

    getWordsOfLengthGreaterThan(length, input.substr(1), input.substr(0,1), dictionary, toReturn);

    return toReturn;
}

int main() {
    string first = "qwertyuytresdftyuioknn";
    string second = "gijakjthoijerjidsdfnokg";

    unordered_set<string> words = getWordsOfLengthGreaterThan(5, first);

    for (string word : words) {
        cout << word << ' ';
    }

    cout << endl;

    return 0;
}


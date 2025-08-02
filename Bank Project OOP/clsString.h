#pragma once
#include <iostream>
#include <string>
#include<vector>

using namespace std;

class clsSrtring{
public:
  static int read_right_number(string massage) {
        int number = 0;
        cout << massage;
        cin >> number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid number, Enter anthor valid one : \n";
            cin >> number;
        }
        return number;
    }

  static string read_string() {
        string sentence;
        getline(cin, sentence);
        return sentence;
    }
  
  static void print_frist_letters(string sentence) {
        cout << "Frist letters of the string : \n";
        cout << sentence << endl;
        cout << sentence.at(0) << endl;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.at(i) == ' ') {
                cout << sentence.at(i + 1);
                cout << "\n";
            }
        }
    }
  
  static string make_it_capital(string sentence) {
        sentence.at(0) = toupper(sentence.at(0));
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.at(i) == ' ') {
                sentence.at(i + 1) = toupper(sentence.at(i + 1));
            }
        }
        return sentence;
    }
  
  static string make_it_lower(string sentence) {
        sentence.at(0) = tolower(sentence.at(0));
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.at(i) == ' ') {
                sentence.at(i + 1) = tolower(sentence.at(i + 1));
            }
        }
        return sentence;
    }
  
  static string make_it_allcapital(string sentence) {
        for (int i = 0; i < sentence.length(); i++) {
            sentence.at(i) = toupper(sentence.at(i));
        }
        return sentence;
    }
  
  static string make_it_Alllower(string sentence) {
        for (int i = 0; i < sentence.length(); i++) {
            sentence.at(i) = tolower(sentence.at(i));
        }
        return sentence;
    }
  
  static char invert_case(char letter) {
        if (letter >= 65 && letter <= 90) {
            letter = tolower(letter);
        }
        else if (letter >= 97 && letter <= 122) {
            letter = toupper(letter);
        }
        else {
            do {
                cout << "Please enter a valid letter\n";
                cin >> letter;
            } while (!(letter >= 65 && letter <= 90 || letter >= 97 && letter <= 122));
            letter = invert_case(letter);
        }
        return letter;
    }
  
  static char invert_case2(char letter) {
        char test;
        test = tolower(letter);
        if (test == letter) {
            letter = toupper(letter);
            return letter;
        }
        else {
            return test;
        }
    }

  static char invert_case3(char letter) {
        return isupper(letter) ? tolower(letter) : toupper(letter);
    }
  
  static string invert_all(string sentence) {
        for (int i = 0; i < sentence.length(); i++) {
            isupper(sentence.at(i)) ?
                sentence.at(i) = tolower(sentence.at(i)) : sentence.at(i) = toupper(sentence.at(i));
        }
        return sentence;
    }
  
  static int count_upper(string sentence) {
        int upper = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (isupper(sentence.at(i))) {
                upper++;
            }
        }
        return upper;

    }
  
  static int count_lower(string sentence) {
        int lower = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (islower(sentence.at(i))) {
                lower++;
            }
        }
        return lower;
    }
  
  static void print_letter_tallandsmall(string sentence) {
        cout << "String length : " << sentence.length() << endl;
        cout << "Capital letters count : " << count_upper(sentence) << endl;
        cout << "lower letters count : " << count_lower(sentence) << endl;

    }
  
  static int count_letter(string sentence, char letter) {
        int counter = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (letter == sentence[i]) {
                counter++;
            }
            else {
                if (invert_case3(sentence.at(i)) == letter) {
                    counter++;
                }
            }
        }
        return counter++;
    }
  
  static char read_char(string message) {
        char ch;
        while (true) {
            cout << message;
            cin >> ch;
            if (isalpha(ch))
                return ch;
            cout << "Invalid input. Please enter a letter only.\n";
            cin.ignore(1000, '\n');
        }
    }
  
  static bool is_vowel(char ch) {
        int length = 5;
        char arr[5] = { 'a','e','i','o','u' };
        for (int i = 0; i < 5; i++) {
            if (ch == arr[i] || invert_case2(ch) == arr[i]) {
                return true;
            }
        }
        return false;
    }
  
  static void print_vowel(char ch) {
        is_vowel(ch) ?
            cout << "Yes letter '" << ch << "' is vowel" : cout << "No letter '" << ch << "' is not vowel";
    }
  
  static int count_vowel(string sentence) {
        int counter = 0;
        for (int i = 0; i < sentence.length(); i++) {
            if (is_vowel(sentence.at(i))) {
                counter++;
            }
        }
        return counter;
    }
  
  static void print_number_of_vowel(string sentence) {
        cout << "Number of vowel in the sentence : " << count_vowel(sentence);
    }
  
  static void print_vowel_letters(string sentence) {
        cout << "Vowels in the string : ";
        for (int i = 0; i < sentence.length(); i++) {
            if (is_vowel(sentence.at(i))) {
                cout << sentence.at(i) << "\t";
            }
        }
    }
  
  static void print_in_lines(string sentence) {
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.at(i) == 32) {
                if (sentence.at(i) == sentence.at(i - 1)) {
                }
                else
                    cout << "\n";
            }
            else
                cout << sentence.at(i);
        }
    }
  
  static int count_words(string sentence) {
        int counter = 1;
        int i = 0;
        for (i = 0; i < sentence.length(); i++) {
            if (i >= 1) {
                if (sentence.at(i) == ' ' && sentence.at(i - 1) != ' ') {
                    counter++;
                }
            }
        }
        //In case user entered a ' ' after the end of sentence
        if (sentence.at(i - 1) == ' ') {
            counter--;
        }
        int x = 0;
        //In case user entered a ' ' all the sentence
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.at(i) == ' ') {
                x++;
            }
        }
        if (x / sentence.length() == 1) {
            return 0;

        }
        return counter;
    }
  
  static vector <string> split_sentence(string sentence) {
        vector <string> splitSentence;
        string splitWord;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.at(i) == 32) {
                if (sentence.at(i) == sentence.at(i - 1)) {
                }
                else {
                    splitSentence.push_back(splitWord);
                    splitWord.clear();
                }
            }
            else
                splitWord.push_back(sentence.at(i));
        }
        splitSentence.push_back(splitWord);
        splitWord.clear();
        return splitSentence;
    }
  
  static vector <string> split_sentence_extra(string sentence, string separator) {
        vector <string> words;
        string temb;
        short pos = 0;

        while ((pos = sentence.find(separator)) != string::npos) {

            temb = sentence.substr(0, pos);

            if (temb != "") {
                words.push_back(temb);
            }

            sentence.erase(0, pos + separator.length());
        }
        if (sentence != "") {
            words.push_back(sentence);
        }
        return words;
    }
  
  static void print_split(vector <string> sentence) {
        vector<string>::iterator iter;
        for (iter = sentence.begin(); iter != sentence.end(); iter++) {
            //it should be * before iter to know the location
            cout << *iter;
            //that if you dont want the new line in the last process
            if (iter != (sentence.end() - 1)) {
                cout << endl;
            }
        }
    }
  
  static void join_string(vector <string> sentence, string delim) {
        vector <string>::iterator iter;
        string after_join;
        for (iter = sentence.begin(); iter != sentence.end(); iter++) {
            cout << *iter << delim;
        }
    }
  
  static string reverse_words(string sentence) {
        vector<string> vString;
        string S2 = "";
        vString = split_sentence(sentence);
        // declare iterator
        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1); //remove last space.
        return S2;
    }
  
  static string replace_words_function(string sentence, string old_word, string new_word) {
        int pos = sentence.find(old_word);

        while (pos != string::npos) {
            sentence = sentence.replace(pos, old_word.length(), new_word);
            int pos = sentence.find(old_word);
        }
        return sentence;
    }
  
  static vector<string> turn_words_into_arry(string sentence) {
        vector<string> sent;
        string word = "";

        for (char ch : sentence) {
            if (ch != ' ') {
                word += ch;
            }
            else if (!word.empty()) {
                sent.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) {
            sent.push_back(word);  // Add the last word
        }

        return sent;
    }
  
  static string replace_words_No_matchcace(vector<string> sentence, string old_word, string new_word) {
        string new_sentence = "";

        for (size_t i = 0; i < sentence.size(); ++i) {
            if (make_it_Alllower(sentence[i]) == make_it_Alllower(old_word)) {
                new_sentence += new_word;
            }
            else {
                new_sentence += sentence[i];
            }
            if (i != sentence.size() - 1) {
                new_sentence += " ";
            }
        }

        return new_sentence;
    }
  
  static string replace_words(vector<string> sentence, string old_word, string new_word) {
        string new_sentence = "";

        for (size_t i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == old_word) {
                new_sentence += new_word;
            }
            else {
                new_sentence += sentence[i];
            }
            if (i != sentence.size() - 1) {
                new_sentence += " ";
            }
        }

        return new_sentence;
    }
  
  static string remove_punctuations(string sentence) {
        string new_sentence = "";
        for (int i = 0; i < sentence.length(); i++) {
            if (ispunct(sentence[i])) {
            }
            else {
                new_sentence += sentence[i];
            }
        }
        return new_sentence;
    }

};
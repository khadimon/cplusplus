/*

Name: <Khadichabonu Valieva>

NetID: <w10118633>

Program Description: < The runtime analysis of Linked List vs Trie data structure >

*/


#include <iostream>
#include "Tries.h"
#include "LinkedList.h"
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>


using namespace std;
using namespace std::chrono;

vector<string> getRandomWordsFromVocabulary(string vocabulary_file_name, int n) {
    vector<string> randwords;
    string temp_str;
    fstream vocabulary_file(vocabulary_file_name);

    long wc = 0;
    while (getline(vocabulary_file, temp_str)) {
        ++wc;
    }

    srand((unsigned) time(nullptr));
    for (int i = 0; i < n; i++) {
        vocabulary_file.clear();
        vocabulary_file.seekg(0);

        int sel = rand() % wc + 1;
        int j = 1;
        while (getline(vocabulary_file, temp_str)) {
            if (j == sel) break;
            j++;
        }

        randwords.push_back(temp_str);
    }

    vocabulary_file.close();
    return randwords;
}



int main(int argc, const char *argv[]) {
    

    
    LinkedList linkedList;
    Trie trie;


   int count = 100;
    string temp_str;

    fstream vocabulary_file("words_alpha.txt");
    fstream sample_words_file("sample_words.txt");

    cout << "Reading vocabulary file..." << endl;
    
    vector<string> sample_words;

    while (vocabulary_file >> temp_str) {
        linkedList.insert(temp_str);
        trie.insert(temp_str);

    }
    cout << "Completed." << endl;

    cout << "Reading sample file..." << endl;
   
    while (sample_words_file >> temp_str) {
        sample_words.push_back(temp_str);

    }

    cout << "Completed." << endl;
   
    for (int i = 0; i < sample_words.size(); ++i)
    {
        steady_clock::time_point start = steady_clock::now();
        linkedList.search(sample_words[i]);
        steady_clock::time_point end = steady_clock::now();
        milliseconds duration = duration_cast<milliseconds>(end - start);

        cout << "Time it took to search for " << sample_words[i] << " in the Linked List: " << duration.count() << " milliseconds."
             << endl;

        steady_clock::time_point start1 = steady_clock::now();
        trie.search(sample_words[i]);
        steady_clock::time_point end1 = steady_clock::now();
        nanoseconds duration1 = duration_cast<nanoseconds>(end1 - start1);

        cout << "Time it took to search for " << sample_words[i] << " in the Trie: " << duration1.count() << " nanoseconds."
             << endl << endl << endl;


    }

    vocabulary_file.close();
    sample_words_file.close();

    return 0;
}

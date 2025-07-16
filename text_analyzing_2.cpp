/*
Bu uygulama kullanıcıdan metinler alarak bu metinler üzerinde detaylı incelemeler yaparak aşağıdaki analizleri gerçekleştiriyor:

* Her kelimenin karakterlerini ardışık çiftler halinde yer değiştir. Uzunluk tekse son karakter sabit kalır.
* Yalnızca harf ve rakamları dikkate alarak en çok tekrar eden karakteri ve frekansını bulur.
* Her kelimenin tekrarsız karakter sayısını hesaplar ve en yüksek olanı belirler.
* Bir kelimenin tüm harflerinin birbirinden farklı olma durumunu (Isogram) kontrol eder ve isogram olanları listeler.
* Girilen metnin toplam uzunluğunu (boşluklar da dahil) hesaplar.

Program metindeki kelimelerin karakterlerini ardışık çiftler  halinde ayırır. Daha sonra bu karakter çiftlerinin içindeki karakterleri yer değiştirir ve daha sonnra tüm karakter çiftlerini tekrar  birleştirir. 
Uzunluk tekse son karakter sabit kalır. Frekans analizi yapılırken yalnızca harf ve rakamlar dikkate alır. İsogram kelime kontrolünde büyük küçük harf duyarlılığı yoktur.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

string swapPairs(const string& word) {
    string swapped = word;
    for (size_t i = 0; i + 1 < swapped.size(); i += 2) {
        swap(swapped[i], swapped[i + 1]);
    }
    return swapped;
}

pair<char, int> findMostFrequentChar(const string& text) {
    unordered_map<char, int> charFreq;
    for (char c : text) {
        if (isalnum(static_cast<unsigned char>(c)))
            charFreq[c]++;
    }

    char mostFreqChar = '\0';
    int highestFreq = 0;
    for (const auto& pair : charFreq) {
        if (pair.second > highestFreq) {
            mostFreqChar = pair.first;
            highestFreq = pair.second;
        }
    }
    return { mostFreqChar, highestFreq };
}

pair<string, size_t> findMaxUniqueCharWord(const vector<string>& words) {
    string maxUniqueWord;
    size_t maxUniqueCount = 0;

    for (const string& word : words) {
        unordered_set<char> uniqueChars(word.begin(), word.end());
        if (uniqueChars.size() > maxUniqueCount) {
            maxUniqueCount = uniqueChars.size();
            maxUniqueWord = word;
        }
    }
    return { maxUniqueWord, maxUniqueCount };
}

vector<string> findIsogramWords(const vector<string>& words) {
    vector<string> isogramWords;
    for (const string& word : words) {
        unordered_set<char> seen;
        bool isIsogram = true;
        for (char c : word) {
            char lower_c = tolower(static_cast<unsigned char>(c));
            if (seen.find(lower_c) != seen.end()) {
                isIsogram = false;
                break;
            }
            seen.insert(lower_c);
        }
        if (isIsogram) {
            isogramWords.push_back(word);
        }
    }
    return isogramWords;
}

size_t calculateTotalLen(const string& text) {
    return text.size();
}


int main() {
   
    cout << "Lütfen metni girin: ";
    string text;
    getline(cin, text);


    istringstream iss(text);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    vector<string> swappedWords;
    for (const string& w : words) {
        swappedWords.push_back(swapPairs(w));
    }

    pair<char, int> Result_1 = findMostFrequentChar(text);
    char mostFrequentChar = Result_1.first;
    int highestFreq = Result_1.second;

    pair<string, size_t> Result_2 = findMaxUniqueCharWord(words);
    string maxUniqueWord = Result_2.first;
    size_t maxUniqueCount = Result_2.second;

    vector<string> isogramWords = findIsogramWords(words);

    size_t total = calculateTotalLen(text);

    cout << "\n[{"; 

    for (size_t i = 0; i < words.size(); ++i) {
        cout << words[i] << " -> " << swappedWords[i];
        if (i < words.size() - 1) cout << ", ";
    }
    cout << "},";

    cout << "{" << mostFrequentChar << ", " << highestFreq << "},";

    cout << "{" << maxUniqueWord << ", " << maxUniqueCount << "},";

    cout << "{" << isogramWords.size() << ", ";
    for (size_t i = 0; i < isogramWords.size(); ++i) {
        cout << isogramWords[i];
        if (i < isogramWords.size() - 1) cout << ", ";
    }
    cout << "},";

    cout << "{" << total << "}]";

    return 0;
}

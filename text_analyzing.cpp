/*
Bu program, gelişmiş metin analizi yaparak aşağıdaki bilgileri çıkartır:

- Metindeki en uzun ve en kısa kelimeyi veya sayıyı bulur ve bunların uzunluklarını belirler.
- Palindrom kelimeleri tespit eder.
- En sık geçen harfi veya rakamı bulur ve frekansını belirler.
- Metnin toplam uzunluğunu hesaplar.

Bu program kelime tespit işlemlerinde sayıları(11, 256 ... ) ve özel karakterleri ('@' ve '!' gibi karakterler) bir string ifade olarak alır ve değerlendirir.
Fakat metinde en sık geçen harfi veya rakamı bulurken sadece sayı ve harfleri dikkate alır fakat özel karakterleri dikkate almaz. 
Bu kısıtlama oluşturmuş olduğum bu programda önemli bir detaydır. 

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Palindrom kontrolü
bool isPalindrome(const string& word) {
    string reversed = word;
    reverse(reversed.begin(), reversed.end());
    return word == reversed;
}

// Metin analiz fonksiyonu
void analyzeText(const string& text) {
    istringstream iss(text);
    vector<string> words;
    unordered_map<char, int> charFreq;
    string word, longestWord = "", shortestWord = "";
    vector<string> palindromes;
    int totalLength = text.length();

    while (iss >> word) {
        words.push_back(word);
        if (longestWord.empty() || word.length() > longestWord.length()) {
            longestWord = word;
        }
        if (shortestWord.empty() || word.length() < shortestWord.length()) {
            shortestWord = word;
        }
        if (isPalindrome(word)) {
            palindromes.push_back(word);
        }
        for (char c : word) {
            if (isalnum(c)) {
                charFreq[c]++;
            }
        }
    }

    char mostFrequentChar = '\0';
    int maxFrequency = 0;
    for (const auto& pair : charFreq) {
        char c = pair.first;
        int freq = pair.second;
        if (freq > maxFrequency) {
            mostFrequentChar = c;
            maxFrequency = freq;
        }
    }

    // Çıktı üretme
    cout << "[{" << longestWord << ", " << longestWord.length() << "}";
    cout << "{" << shortestWord << ", " << shortestWord.length() << "}";
    cout << "{";
    for (size_t i = 0; i < palindromes.size(); i++) {
        cout << palindromes[i];
        if (i < palindromes.size() - 1) cout << ", ";
    }
    cout << "}";
    cout << "{" << mostFrequentChar << ", " << maxFrequency << "}";
    cout << "{" << totalLength << "}]" << endl;
}


#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iomanip>

using namespace std;

// Filtrelenecek Kelimeler
unordered_set<string> stopwords = {
    "ve", "bir", "bu", "da", "de", "ile", "gibi", "veya", "ama", "her", "çok",
    "şimdi", "çünkü", "için", "fakat", "ancak", "ise", "ki", "mı", "mi", "mu",
    "mü", "ne", "o", "bu", "şu", "böyle", "şöyle", "orada", "burada", "biz",
    "siz", "ben", "sen", "onlar", "hep", "hiç", "artık", "yine", "hala"
};


unordered_map<string, int> get_word_frequency(const string& text, int& filtered_count) {
    unordered_map<string, int> word_freq;
    istringstream stream(text);
    string word;

    while (stream >> word) {
        
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (stopwords.find(word) == stopwords.end()) {
            word_freq[word]++;
        }
        else {
            filtered_count++;
        }
    }
    return word_freq;
}

double vector_magnitude(const unordered_map<string, int>& freq) {
    double sum = 0;

    for (auto it = freq.begin(); it != freq.end(); ++it) {

        sum += static_cast<long long>(it->second) * static_cast<long long>(it->second);
    }

    return sqrt(sum);
}

double cosine_similarity(const unordered_map<string, int>& freq1, const unordered_map<string, int>& freq2) {
    int dot_product = 0;

    for (auto it1 = freq1.begin(); it1 != freq1.end(); ++it1) {
        auto it2 = freq2.find(it1->first);
        if (it2 != freq2.end()) {
            dot_product += it1->second * it2->second;  
        }
    }

    double magnitude1 = vector_magnitude(freq1);
    double magnitude2 = vector_magnitude(freq2);

    if (magnitude1 == 0 || magnitude2 == 0) return 0.0; 

    return dot_product / (magnitude1 * magnitude2);
}

string evaluate_similarity(double similarity) {
    if (similarity >= 0.6) {
        return "Yüksek";
    }
    else if (similarity >= 0.3) {
        return "Orta";
    }
    else {
        return "Düşük";
    }
}

int main() {
    string text1, text2;

    cout << "Birinci metni girin: ";
    getline(cin, text1);

    cout << "İkinci metni girin: ";
    getline(cin, text2);

    if (text1.empty() || text2.empty()) {
        cout << "Boş metinden dolayı benzerlik hesaplanamaz." << endl;
        return 0;
    }

    int length1 = text1.length();
    int length2 = text2.length();

    int filtered_count1 = 0, filtered_count2 = 0;

    auto freq1 = get_word_frequency(text1, filtered_count1);
    auto freq2 = get_word_frequency(text2, filtered_count2);

    double similarity = cosine_similarity(freq1, freq2);

    string evaluation = evaluate_similarity(similarity);

    cout << "[{" << length1 << ", " << length2 << "}, {"
        << (filtered_count1 + filtered_count2) << "}, {"
        << similarity << "}, {" << evaluation << "}]" << endl;

    return 0;
}

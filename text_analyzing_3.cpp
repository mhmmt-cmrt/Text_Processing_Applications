/*
  Bu uygulama, kullanıcıdan aldığı metin üzerinde çeşitli işlemler yaparak aşağıdaki analizleri gerçekleştiriyor:

* Her kelimenin ilk harfini alarak, büyük harfleri hariç tutup bir kullanıcı adı oluşturur.
* Her kelimenin son harfini alarak bir şifre oluşturur ve şifrenin uzunluğunu kontrol eder.
* Şifre uzunluğu 4 karakterden az ise 'yetersiz' olarak sınıflandırır.
* Şifre uzunluğu 4 veya daha fazla ise, şifrede en az bir büyük harf, bir küçük harf ve bir özel karakter olup olmadığını kontrol ederek şifreyi 'güçlü', 'orta' veya 'basit' olarak sınıflandırır.
* En kısa kelime, en uzun kelime, toplam kelime sayısı ve toplam metin uzunluğunu analiz eder.	
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <utility>

using namespace std;

string createUsername(const vector<string>& words) {
    string username;
    for (unsigned int i = 0; i < words.size(); ++i) {
        unsigned char firstChar = static_cast<unsigned char>(words[i][0]);
        if (!isupper(firstChar)) {
            username += firstChar;
        }
    }
    return username;
}

pair<string, string> createPassword(const vector<string>& words) {
    string password;
    for (unsigned int i = 0; i < words.size(); ++i) {
        unsigned char lastChar = static_cast<unsigned char>(words[i][words[i].length() - 1]);
        password += lastChar;
    }

    if (password.length() < 4) {
        return make_pair(password, "yetersiz");
    }

    bool hasUpper = false, hasLower = false, hasSpecial = false;
    for (unsigned int i = 0; i < password.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(password[i]);
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (ispunct(c)) hasSpecial = true;
    }

    if (hasUpper && hasLower && hasSpecial) {
        return make_pair(password, "güçlü");
    }
    else if (hasUpper && hasLower) {
        return make_pair(password, "orta");
    }
    else {
        return make_pair(password, "basit");
    }
}

vector<string> splitText(const string& text) {
    vector<string> words;
    string word;
    for (unsigned int i = 0; i < text.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(text[i]);
        if (isspace(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

void processText(const string& inputText) {
    vector<string> words = splitText(inputText);

    string username = createUsername(words);
    pair<string, string> passwordResult = createPassword(words);
    string password = passwordResult.first;
    string passwordStrength = passwordResult.second;

    unsigned int minWordLength = 100;
    unsigned int maxWordLength = 0;
    for (unsigned int i = 0; i < words.size(); ++i) {
        if (words[i].length() < minWordLength) {
            minWordLength = words[i].length();
        }
        if (words[i].length() > maxWordLength) {
            maxWordLength = words[i].length();
        }
    }

    if (words.size() == 0) { minWordLength = 0; }

    cout << "[{"
        << username << ", " << username.length() << "}, {"
         << password << ", " << password.length() << ", " << passwordStrength << "}, {"
         << minWordLength << ", " << maxWordLength << ", "<< words.size() << ", "
         << inputText.length() << "}]" << endl;
}

int main() {
    string inputText;
    cout << "Lütfen bir metin girin: ";
    getline(cin, inputText);

    processText(inputText);

    return 0;
}

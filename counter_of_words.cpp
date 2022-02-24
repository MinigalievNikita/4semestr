#include<vector>
#include<string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Statistics{
    int count;
    std::string word;
};

void inesrtion_in_map(const std::string word,std::map<std::string, int> &box, std::map<std::string, int>::iterator &it){
    it = box.find(word);
    if (it == box.end()) {
        box.insert(make_pair(word, 1));
    } else {
        box[word]++;
    }
}

std::string prepare(std::string& s){
    std::string word = s;
    while (!isalpha(s.back())) {
        s.pop_back();
    }
    
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
    return std:: tolower(c);
    });
    return s;
}

bool comp(const struct Statistics s1, const struct Statistics s2){
    return s1.count > s2.count;
}

int main() {
    std::map<std::string, int> counter_of_words;
    std::map<std::string, int>::iterator it;
    std::string word;
    std::ifstream file("file.txt");
    if(file.is_open()) {
        std::cout<<"File was opened\n";
        while(!file.eof()) {
            file>>word;
            word = prepare(word);
            std::cout<<word<<"\n";
            inesrtion_in_map(word, counter_of_words, it);
                
        }
        counter_of_words[word]--; //баг повторения последнего слова
        std::vector<Statistics> s;
        struct Statistics temp;
        for (auto it = counter_of_words.begin(); it != counter_of_words.end(); ++it) {
            temp.word = it -> first;
            temp.count = it -> second;
            s.push_back(temp);
        }
        std::sort(s.begin(), s.end(), comp);
        std::cout<<s[0].count<<' '<<s[0].word<<"\n";
    } else {
        std::cout<<"File wasnt opened\n";
    }
    file.close();
    return 0;
}

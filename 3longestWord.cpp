#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


bool compare(const std::string& left, const std::string& right)
{
    return left.length() > right.length();
}

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<std::string> allWords;
    std::string tmpStr;
    std::string path = "C:/Users/egork/source/repos/Files/longestWord/onegin.txt";
    std::ifstream MyFile(path);

    while (MyFile >> tmpStr) {
        allWords.push_back(tmpStr);
    }
    MyFile.close();
    std::sort(begin(allWords), end(allWords), compare);

    for (int i(0); i < 3 && i < allWords.size(); i++) {
        std::cout << allWords[i] << " " << allWords[i].length() << "\n ";
    }
}

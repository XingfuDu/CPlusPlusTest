// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    //int len = s.length();
    //int i = 0;
    //int j = len - 1;
    //while (i < j) {
    //    while (i < len && !std::isalpha(s[i])) {
    //        i++;
    //    }
    //    while (j >=0 && !isalpha(s[j])) {
    //        j--;
    //    }
    //    if (std::tolower(s[i]) != std::tolower(s[j])) {
    //        return false;
    //    } 
    //    i++;
    //    j--;
    //}
    //return true;
    deque<char> dq;
    for (char ch : s) {
        if (isalpha(ch)) {
            dq.push_back(ch);
        }
    }
    while (dq.size() > 1) {
        char c1 = dq.front();
        char c2 = dq.back();
        if (tolower(c1) != tolower(c2)) return false;
        dq.pop_back();
        dq.pop_front();
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
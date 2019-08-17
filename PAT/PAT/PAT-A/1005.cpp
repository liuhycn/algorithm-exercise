#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

unordered_map<char, string> dict;
void init()
{
    dict['0'] = "zero";
    dict['1'] = "one";
    dict['2'] = "two";
    dict['3'] = "three";
    dict['4'] = "four";
    dict['5'] = "five";
    dict['6'] = "six";
    dict['7'] = "seven";
    dict['8'] = "eight";
    dict['9'] = "nine";
}

int main()
{
    string nums;
    init();
    cin >> nums;
    int sum = 0;
    for (auto digit : nums)
    {
        sum += digit - '0';
    }
    stringstream ss;
    ss << sum;
    nums = ss.str();
    int first = 0;
    for (auto digit : nums)
    {
        if (!first) 
        {
            first = 1;
            printf("%s", dict[digit].c_str());
        }
        else printf(" %s", dict[digit].c_str());
    }
    return 0;
}
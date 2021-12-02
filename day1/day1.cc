#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

vector<int> readFile()
{
    vector<int> numbers;
    string line;
    ifstream myfile("input.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            numbers.push_back(atoi(line.c_str()));
        }
    }
    myfile.close();

    return numbers;
}

pair<int, int> getCounts(const vector<int> numbers)
{
    auto count1 = 0;
    auto count2 = 0;

    for (int i = 1; i < numbers.size(); ++i)
    {
        if (numbers[i] > numbers[i - 1])
        {
            count1++;
        }
        if (i >= 3 && numbers[i] > numbers[i - 3])
        {
            count2++;
        }
    }

    return make_pair(count1, count2);
}

int main()
{
    const auto numbers = readFile();
    printf("Part 1: %d\nPart 2: %d\n", getCounts(numbers).first, getCounts(numbers).second);
    return 0;
}

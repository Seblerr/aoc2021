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

int part1(vector<int> numbers)
{
    int count = 0;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] > numbers[i - 1])
        {
            count++;
        }
    }

    return count;
}

int part2(vector<int> numbers)
{
    auto count = 0;
    auto sum = 0;
    auto prevSum = std::numeric_limits<int>::max();
    for (int i = 0; i < numbers.size(); ++i)
    {
        sum = numbers[i] + numbers[i + 1] + numbers[i + 2];
        if (sum > prevSum)
        {
            count++;
        }
        prevSum = sum;
    }
    return count;
}

int main()
{
    auto numbers = readFile();
    printf("Part1: %d\n", part1(numbers));
    printf("Part2: %d\n", part2(numbers));
    return 0;
}

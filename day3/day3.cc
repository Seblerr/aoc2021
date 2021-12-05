#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
#include <array>

using namespace std;

constexpr int bits = 12;

int partOne(const vector<bitset<bits>> inputs)
{
    vector<int> counter(bits);
    for (const auto &in : inputs)
    {
        for (auto i = 0; i < bits; i++)
        {
            if (in.test(i))
            {
                counter[i]++;
            }
        }
    }

    bitset<bits> gamma;
    for (auto i = 0; i < counter.size(); i++)
    {
        gamma[i] = counter[i] > inputs.size() / 2 ? 1 : 0;
    }
    const auto epsilon = bitset<bits>(gamma).flip();

    return gamma.to_ulong() * epsilon.to_ulong();
}

int partTwo(vector<bitset<bits>> inputs)
{
    vector<bitset<bits>> mostCommon(inputs);
    for (int i = bits - 1; i >= 0; i--)
    {
        array<vector<bitset<bits>>, 2> filtered;
        for (const auto &input : mostCommon)
        {
            filtered[input[i]].push_back(input);
        }
        mostCommon = filtered[1].size() >= filtered[0].size() ? filtered[1] : filtered[0];
    }

    auto oxygen = mostCommon[0];

    vector<bitset<bits>> leastCommon(inputs);
    for (int i = bits - 1; i >= 0; i--)
    {
        array<vector<bitset<bits>>, 2> filtered;
        for (const auto &input : leastCommon)
        {
            filtered[input[i]].push_back(input);
        }
        leastCommon = filtered[0].size() <= filtered[1].size() ? filtered[0] : filtered[1];
    }

    auto co2 = leastCommon[0];

    return oxygen.to_ulong() * co2.to_ulong();
}

int main()
{
    ifstream file("input.txt");
    string line;
    vector<bitset<bits>> inputs;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            inputs.push_back(bitset<bits>(line));
        }
    }
    file.close();

    cout << "Power consumption: " << partOne(inputs) << endl;
    cout << "Life support rating: " << partTwo(inputs) << endl;

    return 0;
}
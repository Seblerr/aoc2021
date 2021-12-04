#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

constexpr int bits = 12;

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

    vector<int> counter(bits);
    for (const auto &input : inputs)
    {
        for (auto i = 0; i < bits; i++)
        {
            if (input.test(i))
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
    auto epsilon = bitset<bits>(gamma).flip();

    cout << "Power consumption: " << gamma.to_ulong() * epsilon.to_ulong() << endl;

    return 0;
}
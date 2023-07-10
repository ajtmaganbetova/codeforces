#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;

    std::string str;
    std::string sub[t - 1];
    std::cin >> str;

    for (int i = 0; i < t - 1; i++)
    {
        sub[i] = str.substr(i, 2);
    }

    std::map<std::string, int> map;
    for (int i = 0; i < t - 1; i++)
    {
        map[sub[i]] = 1;
        for (int j = 0; j < t - 1; j++)
        {
            if (sub[i] == sub[j] && j != i)
            {
                map[sub[i]]++;
            }
        }
    }
    
    auto pr = std::max_element(map.begin(), map.end(), [](const auto &x, const auto &y)
                               { return x.second < y.second; });

    std::cout << pr->first << std::endl;

    return 0;
}
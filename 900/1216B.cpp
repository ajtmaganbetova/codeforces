#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    int dur;
    std::vector<int> vecs;
    std::vector<int> vec2;

    for (int i = 0; i < n; i++)
    {
        std::cin >> dur;

        vecs.push_back(dur);
        vec2.push_back(dur);
    }

    std::sort(vecs.begin(), vecs.end(), std::greater{});

    int minsum = 0;
    for (int i = 0; i < n; i++)
    {
        minsum += vecs[i] * i + 1;
    }

    std::cout << minsum << "\n";

    for (int i = 0; i < n; i++)
    {
        std::vector<int>::iterator it = std::find(vec2.begin(), vec2.end(), vecs[i]);
        std::cout << it - vec2.begin() + 1 << " ";
        
        vec2[it - vec2.begin()] = 0;
    }

    std::cout << "\n";

    return 0;
}
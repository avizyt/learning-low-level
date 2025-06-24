#include <bits/stdc++.h>

int main()
{
    std::vector<int> arr = {5, 3, 5, 2, 6};
    std::list<int> l = {1, 2, 3, 4, 5};

    l.push_back(6);
    l.push_front(0);
    for (auto item : l)
    {

        std::cout << item << std::endl;
    }

    std::cout << "front: " << l.front() << std::endl;
    std::cout << "back: " << l.back() << std::endl;
}

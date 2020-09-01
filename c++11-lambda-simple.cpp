//
// Created by kobi on 8/30/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
int main() {
    struct {
        void operator()(int x) const {
            std::cout << x << '\n';
        }
    } someInstance;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::for_each(v.begin(), v.end(), someInstance);
    std::for_each(v.begin(), v.end(), [] (int x) {
                    std::cout << x << '\n';
                  }
    );
    const auto f(    [] (int x) { std::cout << x << '\n';}    );
    std::for_each(v.begin(), v.end(), f);
}

//
// Created by kobi on 8/29/20.
//

#include <iostream>
#include <algorithm>
#include <vector>

struct PrintFunctor1 {
    void operator()(int x) const {
        std::cout << x << std::endl;
    }
};

template <typename Iter, typename Func>
Func my_for_each(Iter first, Iter last, Func func) {
    for (; first != last; ++first)
        func(*first);
    return func;
}

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // and we can also take the PrintFunctor and define it here"
    struct PrintFunctor2 {
        void operator()(int x) const {
            std::cout << x << std::endl;
        }
    };

    std::for_each(v.begin(), v.end(), PrintFunctor1());
    std::for_each(v.begin(), v.end(), PrintFunctor2());
    my_for_each(v.begin(), v.end(), PrintFunctor2());
}

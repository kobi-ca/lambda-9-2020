#include <type_traits>

// callable object
void f(){}
int g() { return 0;}

typedef int (*func_ptr) (int, char);
// or in modern C++
using func_ptr1 = int (*) (int, char);
// or even more
using func_ptr2 = std::add_pointer_t<int (int, char)>;
int my_func(int, char) { return 0; }

int main() {
    func_ptr2 funcPtr2 = my_func;
    auto ret = funcPtr2(3, 'a');
    func_ptr2 funcPtr3 = &my_func;
    ret = funcPtr3(7, 'b');
    return 0;
}

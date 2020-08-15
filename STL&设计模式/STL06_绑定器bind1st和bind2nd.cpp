/*
一元函数对象：对象重载了operator(),并且只含有一个形参变量；
二元函数对象：对象重载了operator(),含有两个形参变量；

在C++11前，STL中提供了两个绑定器，bind1st和bind2nd，分别用来绑定二元函数对象的第一个参数和第二个参数。
也就是说就是主要针对二元函数对象设计的，用来绑定参数，可以将二元函数转换成一个一元函数：

当二元函数中两个参数的第一个参数是一个确定的值时，我们可以使用bind1st；
当二元函数中两个参数的第一个参数是二个确定的值时，我们可以使用bind2nd.
*/

#include <iostream>
#include <vector>
#include <algorithm> //所有泛型算法
#include <functional>//所有函数对象
#include <ctime>

template <typename container>
void print_container(container& con)
{
    typename container::iterator it = con.begin();
    //编译器由上到下，由于container还没有被实例化，所以不知道container是个类型还是
    //作用域之类的，typename的作用就是告诉编译器container是个类型
    for (; it != con.end(); ++it)
    {
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec;
    srand(time(nullptr));//以系统时间为随机数种子
    for (int i = 0; i < 20; ++i)
    {
        vec.push_back(rand() % 100 + 1);
    }
    print_container(vec);
    std::sort(vec.begin(), vec.end()); //sort 默认是小到大排序
    print_container(vec);
    std::sort(vec.begin(),vec.end(),std::greater<int>());//从大到小，left>right
    print_container(vec);
    //std::sort(vec.begin(), vec.end(), std::less<int>());//从小到大,left<right
    //print_container(vec);

    //find_if每次从区间[behin(),end())中取一个值，然后和80作比较，但是less和greater都是二元函数对象，需要两个参数
    //并且我们的一个参数值每次确定为80
    //bind1st + greater bool opeartor()(80,const _Ty& _Right )绑定const _Ty& _Left  设置为确定的值
    //bind2nd + less bool opeartor()(const _Ty& _Left,80)绑定const _Ty& _Right  设置为确定的值
    auto it = std::find_if(vec.begin(),vec.end(),std::bind1st(std::greater<int>(),80));
    //auto it = std::find_if(vec.begin(), vec.end(), std::bind2nd(std::less<int>(), 80));
    if (it != vec.end())
    {
        vec.insert(it,80);
    }
    print_container(vec);
    /*
    bind 绑定器 + 二元函数对象 = 一元函数对象
    */
    return 0;
}

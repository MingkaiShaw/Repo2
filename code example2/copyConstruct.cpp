#include<iostream>
#include<string>

class Myclass
{
    public:
    Myclass(int *p);
    Myclass(const Myclass &rhs);
    ~Myclass();

    Myclass &operator=(const Myclass &rhs);
    void print();

    private:
    int *ptr;
};

Myclass::Myclass(int *p)
{
    std::cout << "进入主构造器。\n";
    ptr = p;
    std::cout <<"离开主构造器。\n";
}

Myclass:: Myclass(const Myclass &rhs)
{
    std::cout << "进入副本构造器。\n";
    *this = rhs;
    std::cout << "离开副本构造器。\n";
}

Myclass::~Myclass()
{
    std::cout << "进入析构器。\n";
    delete ptr;
    std::cout << "离开析构器。\n";
}

Myclass &Myclass::operator=(const Myclass &rhs)
{
   std::cout << "进入赋值语句重载。\n";
    if(this != &rhs)
    {
        delete ptr;
        ptr = new int;//未新对象指针分配新的地址，原对象指针地址不变
        *ptr = *rhs.ptr;
    }
    else
    {
        std::cout << "等号两边为同个对象，不做处理!\n";
    }
    std::cout << "离开赋值语句重载。\n";
    return *this;
}

void Myclass::print()
{
    std::cout << *ptr << std::endl;

}

int main()
{
    Myclass obj1(new int(1));
    Myclass obj2(new int(2));
    obj2 = obj1;
    obj1.print();
    obj2.print();
    std::cout << "--------------------------------------\n";

    Myclass obj3(new int(3));
    Myclass obj4 = obj3;
    obj3.print();
    obj4.print();
    std::cout << "--------------------------------------\n";

    Myclass obj5(new int(5));
    obj5 = obj5;
    obj5.print();

    return 0;
}



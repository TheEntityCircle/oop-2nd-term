// Был вот такой класс
class A 
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

// Наследуемся как public
class B : public A
{
    // x внутри B - public
    // y внутри B - protected
    // z недоступно для B
};

// Наследуемся как protected
class C : protected A
{
    // x внутри C - protected
    // y внутри C - protected
    // z недоступно для C
};

// Наследуемся как private
// (и это поведение по умолчанию)
class D : private A
{
    // x внутри D - private
    // y внутри D - private
    // z недоступно для D
};

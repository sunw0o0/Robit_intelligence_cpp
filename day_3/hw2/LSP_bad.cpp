#include <iostream>
#include <stdexcept>
#include <string>

class Bird
{
public:
    virtual void fly()
    {
        std::cout << "Bird is flying" << std::endl;
    }
    virtual ~Bird() {}
};

class Penguin : public Bird
{
public:
    void fly() override
    {
        throw std::runtime_error("Penguins cannot fly");
    }
};

int main()
{
    Bird bird;
    bird.fly();

    Bird* penguin = new Penguin();
    try
    {
        penguin->fly(); // 새는 fly하지만 자식인 펭귄은 fly못 함. 오류 뜸
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    delete penguin;
    return 0;
}

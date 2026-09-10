#include <iostream>

//인터페이스
class Switchable
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Switchable() {}
};

// 인터페이스를 구현하는 저수준 클래스
class Fan : public Switchable
{
public:
    void turnOn() override
    {
        std::cout << "Fan is spinning" << std::endl;
    }

    void turnOff() override
    {
        std::cout << "Fan is stopping" << std::endl;
    }
};

// 고수준 클래스
class Switch
{
private:
    Switchable* device;
public:
    Switch(Switchable* device)
        : device(device) {}

    void turnOn()
    {
        device->turnOn();
    }

    void turnOff()
    {
        device->turnOff();
    }
};

int main()
{
    Fan fan;
    Switch switchDevice(&fan);

    switchDevice.turnOn();
    switchDevice.turnOff();



    return 0;
}

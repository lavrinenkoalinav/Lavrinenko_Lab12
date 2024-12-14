#include <iostream>
#include <Windows.h>

using namespace std;

class Vehicle {
protected:
double fuel; 

public:
    Vehicle(double initialFuel) : fuel(initialFuel) {}

    void refuel(double amount) {
        if (amount > 0) {
            fuel += amount;
            std::cout << "Заправлено: " << amount << " одиниць. Поточне паливо: " << fuel << std::endl;
        }
        else {
            std::cout << "Неправильна кількість палива!" << std::endl;
        }
    }

    double getFuel() const {
        return fuel;
    }
};

class ElectricCar : public Vehicle {
private:
    double batteryCharge;

public:
    ElectricCar(double initialFuel, double initialCharge)
        : Vehicle(initialFuel), batteryCharge(initialCharge) {}

    void chargeBattery(double amount) {
        if (amount > 0) {
            batteryCharge += amount;
            std::cout << "Батарея заряджена: " << amount << " одиниць. Поточний заряд: " << batteryCharge << std::endl;
        }
        else {
            std::cout << "Неправильна сума списання!" << std::endl;
        }
    }

    double getBatteryCharge() const {
        return batteryCharge;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ElectricCar myElectricCar(10.0, 50.0);

    myElectricCar.refuel(15.0);
    myElectricCar.chargeBattery(25.0);

    std::cout << "Поточне паливо: " << myElectricCar.getFuel() << std::endl;
    std::cout << "Поточний заряд акумулятора: " << myElectricCar.getBatteryCharge() << std::endl;

    return 0;
}

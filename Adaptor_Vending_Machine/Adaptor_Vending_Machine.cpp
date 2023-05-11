#include <iostream>
#include <string>
// �������� ��������� ��� ��������� ��������
class DrinkMachine {
public:
    virtual void chooseDrink() = 0;
    virtual void addWater() = 0;
    virtual void addSugar() = 0;
    virtual void dispenseDrink() = 0;
};
// ����������� ��������� ��� ����������
class CoffeeMachine {
public:
    virtual void selectCoffee(const std::string& coffeeType) = 0;
    virtual void addWater() = 0;
    virtual void addSugar() = 0;
    virtual void pourCoffee() = 0;
};
// ������� ��� ���������� �� ���������� ��������� ��������
class CoffeeAdapter : public DrinkMachine {
private:
    CoffeeMachine* coffeeMachine_;
public:
    explicit CoffeeAdapter(CoffeeMachine* coffeeMachine) : coffeeMachine_(coffeeMachine) {}

    void chooseDrink() override {
        coffeeMachine_->selectCoffee("��������");
    }

    void addWater() override {
        coffeeMachine_->addWater();
    }

    void addSugar() override {
        coffeeMachine_->addSugar();
    }

    void dispenseDrink() override {
        coffeeMachine_->pourCoffee();
    }

};
class MyCoffeeMachine : public CoffeeMachine {
public:

    void selectCoffee(const std::string& coffeeType) override {
        std::cout << "������� " << coffeeType << " ����.\n";
    }

    void addWater() override {
        std::cout << "�������� ���� � ���������.\n";
    }

    void addSugar() override {
        std::cout << "� ��������� ������ �����.\n";
    }

    void pourCoffee() override {
        std::cout << "������� ���� � ����������.\n";
    }
};
class TeaMachine : public DrinkMachine  
{
public:
    void chooseDrink() override {
        std::cout << "������ ���\n";
    }

    void addWater() override {
        std::cout << "������ �� ��� ����.\n";
    }

    void addSugar() override {
        std::cout << "������ � ��� �����.\n";
    }

    void dispenseDrink() override {
        std::cout << "��� �������!\n"
            << "��������!\n";
    }
};
class CacaoMachine : public DrinkMachine {
public:
    void chooseDrink() override {
        std::cout << "������ �����\n";
    }

    void addWater() override {
        std::cout << "������ ���� �� �����.\n";
    }

    void addSugar() override {
        std::cout << "�� ����� ������ �����.\n";
    }

    void dispenseDrink() override {
        std::cout << "����� ������!\n"
            << "��������!\n";
    }

};
// ��� �볺���
int main() {
    setlocale(0, ".1251");
    DrinkMachine* machine = new TeaMachine();
    machine->chooseDrink();
    machine->addWater();
    machine->addSugar();
    machine->dispenseDrink();

    machine = new CoffeeAdapter(new MyCoffeeMachine());
    machine->chooseDrink();
    machine->addWater();
    machine->addSugar();
    machine->dispenseDrink();

    machine = new CacaoMachine();
    machine->chooseDrink();
    machine->addWater();
    machine->addSugar();
    machine->dispenseDrink();

    return 0;
}
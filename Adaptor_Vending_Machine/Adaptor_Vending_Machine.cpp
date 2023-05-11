#include <iostream>
#include <string>
// Основний інтерфейс для торгового автомата
class DrinkMachine {
public:
    virtual void chooseDrink() = 0;
    virtual void addWater() = 0;
    virtual void addSugar() = 0;
    virtual void dispenseDrink() = 0;
};
// Адаптований інтерфейс для кавомашини
class CoffeeMachine {
public:
    virtual void selectCoffee(const std::string& coffeeType) = 0;
    virtual void addWater() = 0;
    virtual void addSugar() = 0;
    virtual void pourCoffee() = 0;
};
// Адаптер для кавомашини до інтерфейсу торгового автомата
class CoffeeAdapter : public DrinkMachine {
private:
    CoffeeMachine* coffeeMachine_;
public:
    explicit CoffeeAdapter(CoffeeMachine* coffeeMachine) : coffeeMachine_(coffeeMachine) {}

    void chooseDrink() override {
        coffeeMachine_->selectCoffee("звичайна");
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
        std::cout << "Вибрана " << coffeeType << " кава.\n";
    }

    void addWater() override {
        std::cout << "Заливаємо воду в кавоварку.\n";
    }

    void addSugar() override {
        std::cout << "У кавоварку додаємо цукор.\n";
    }

    void pourCoffee() override {
        std::cout << "Наливаю каву з кавомашини.\n";
    }
};
class TeaMachine : public DrinkMachine  
{
public:
    void chooseDrink() override {
        std::cout << "Обрано чай\n";
    }

    void addWater() override {
        std::cout << "Долито до чаю воду.\n";
    }

    void addSugar() override {
        std::cout << "Додано в чай цукор.\n";
    }

    void dispenseDrink() override {
        std::cout << "Чай готовий!\n"
            << "Смачного!\n";
    }
};
class CacaoMachine : public DrinkMachine {
public:
    void chooseDrink() override {
        std::cout << "Обрано какао\n";
    }

    void addWater() override {
        std::cout << "Додано воду до какао.\n";
    }

    void addSugar() override {
        std::cout << "До какао додано цукор.\n";
    }

    void dispenseDrink() override {
        std::cout << "Какао готове!\n"
            << "Смачного!\n";
    }

};
// Код клієнта
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
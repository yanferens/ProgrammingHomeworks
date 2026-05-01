#include <iostream>
#include <vector>
#include <string>
#include <format>

// БАЗОВИЙ КЛАС
class SmartDevice {
protected:
    std::string name;
    bool isOn;

public:
    SmartDevice(std::string n) : name(n), isOn(false) {}

    SmartDevice();

    // Віртуальний деструктор
    virtual ~SmartDevice() {}
    virtual bool getStatus() const {return isOn;};
    // ЧИСТА ВІРТУАЛЬНА ФУНКЦІЯ
    virtual void status() const = 0;      // перевизначити в дочірніх класах    (якщо ввімкнено - [Назва пристрою] ввімкнено!! + (SmartLight) -> Яскравість лампочки = ... (brightness))
    // + (SmartAC)    -> Температура кондиціонера = ... (temperature)
    //     якщо вимкнено - [Назва пристрою] вимкнено!

    void toggle() { isOn = !isOn; }
};

class SmartLight : public SmartDevice {
private:
    int _brightness = 0;
public:

    SmartLight(int brightness, std::string n) : SmartDevice(n), _brightness(brightness){};

    void status() const {
        if (getStatus()) {
            std::cout << std::format("{} is on!! \n Brightness = {} \n", name, _brightness);
        }
        else {
            std::cout << std::format("{} is off!!\n", name);
        }
    }
};

class SmartAC : public SmartDevice {
private:
    int _temperature = 0;
public:

    SmartAC(int temperature, std::string n) : SmartDevice(n), _temperature(temperature){};

    void status() const {
        if (getStatus()) {
            std::cout << std::format("{} is on!! \n Temperature = {} \n", name, _temperature);
        }
        else {
            std::cout << std::format("{} is off!!\n", name);
        }
    }
};
// --- ВАШ КОД ТУТ ---
// 1. Створіть клас SmartLight (нащадок SmartDevice)     attributes: brightness  (int)
// 2. Створіть клас SmartAC : SmartDevice (нащадок SmartDevice)        attributes: temperature (int)
// ------------------

int main() {
    std::vector<SmartDevice*> home;
    SmartDevice* light1 = new SmartLight(5, "Light 1");
    SmartDevice* ac1 = new SmartAC(25, "AC 1");

    home.push_back(light1);
    home.push_back(ac1);
    for (auto device : home) {
        device->toggle();
        device->status();
    }
    // 3. Додайте у вектор одну лампу та один кондиціонер
    // 4. Увімкніть їх та виведіть статус через цикл

    for (auto device : home) {
        delete device;
    }
    return 0;
}





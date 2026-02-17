#include "basket.h"
#include <iostream>
#include <format>
#include <string>


Basket::Basket(string type) {
    this->fruitType = type;
}

void unloadBaskets(Basket *baskets, int n) {
    std::cout << "Unloading..." << std::endl;

    int countWatermelon = 0;
    int countMelon = 0;

    // ! ВАЖЛИВО: Масиви починаються з 0, тому i < n
    for (int i = 0; i < n; i++) {
        string currentContent = baskets[i].getContent();

        // Рахуємо фрукти
        if (currentContent == "Watermelon") {
            countWatermelon++;
        } else if (currentContent == "Melon") {
            countMelon++;
        }

        // Виводимо поточний кошик, використовуючи наш operator string()
        // (string)baskets[i] викликає наш метод перетворення
        std::cout << (i + 1) << ": " << (string)baskets[i] << std::endl;
    }

    // Фінальний вивід
    std::cout << "Unloaded " << countWatermelon << " Watermelons and "
              << countMelon << " Melons." << std::endl;
}




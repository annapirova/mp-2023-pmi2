#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <clocale>
#include <regex>
#include <fstream>

using namespace std;

// Enum для категорий продуктов
enum Category {
    VEGETABLES,
    DAIRY,
    FRUITS,
    MEAT,
    OTHER
};

// Словарь штрих-кодов
static map<string, int> barcodes;

class Product {
public:
    // Конструктор инициализации
    Product(const string& name, Category category, double price, double discount, int quantity)
        : name(name), category(category), price(price), discount(discount), quantity(quantity) {
        // Получение штрих-кода из словаря
        auto it = barcodes.find(name);
        if (it == barcodes.end()) {
            throw invalid_argument("Товар не найден в словаре штрих-кодов.");
        }
        barcode = it->second;
    }

    int getBarcode() const { return barcode; }
    string getName() const { return name; }
    Category getCategory() const { return category; }
    double getPrice() const { return price; }
    double getDiscount() const { return discount; }
    int getQuantity() const { return quantity; }

    // Метод для расчета общей стоимости продукта
    double calculateCost() const {
        return price * (1.0 - discount) * (double)quantity;
    }

    // Перегрузка оператора ==
    bool operator==(const Product& other) const {
        return barcode == other.barcode;
    }

    // Функция для получения строкового представления категории продукта
    string getCategoryName() const {
        switch (category) {
        case VEGETABLES:
            return "Овощи";
        case DAIRY:
            return "Молочные продукты";
        case FRUITS:
            return "Фрукты";
        case MEAT:
            return "Мясо";
        case OTHER:
            return "Прочее";
        default:
            return "Неизвестно";
        }
    }

    // Перегрузка оператора <
    bool operator<(const Product& other) const {
        return calculateCost() * quantity < other.calculateCost() * other.quantity;
    }

private:
    int barcode;
    string name;
    Category category;
    double price;
    double discount;
    int quantity;
};

class Store {
public:
    // Добавление товара в магазин
    void addProduct(const Product& product) {
        products.push_back(product);
    }
    // Публичный метод для получения продуктов
    const vector<Product>& getProducts() const {
        return products;
    }
    // Поиск товаров по имени и возвращение итератора на первый найденный продукт
    auto findProductByName(const string& name) const -> decltype(getProducts().begin()) {
        return find_if(getProducts().begin(), getProducts().end(), [&name](const Product& product){
            return equalsIgnoreCase(product.getName(), name);
            });
    }
    vector<Product> products;
private:
  
    // Статический метод для сравнения строк без учета регистра
    static bool equalsIgnoreCase(const string& str1, const string& str2) {
        if (str1.size() != str2.size()) {
            return false;
        }
        for (size_t i = 0; i < str1.size(); ++i) {
            if (tolower(str1[i]) != tolower(str2[i])) {
                return false;
            }
        }
        return true;
    }
};

class Receipt {
public:
    // Добавление товара в чек
    void addItem(const Product& product, int quantity) {
        items.push_back(make_pair(product, quantity));
    }

    // Подсчет суммы чека
    double calculateTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.first.calculateCost() * item.second;
        }
        return total;
    }

    // Сортировка чека по стоимости товаров
    void sortItems() {
        sort(items.begin(), items.end(), [](const pair<Product, int>& a, const pair<Product, int>& b){
            return a.first.calculateCost() * a.second < b.first.calculateCost() * b.second;
            });
    }

    // Печать чека
    void printReceipt() const {
        cout << "Чек:" << endl;
        for (const auto& item : items) {
            cout << "Товар: " << item.first.getName() << ", Количество: " << item.second << ", Стоимость: " << item.first.calculateCost() * item.second << endl;
        }
        cout << "Общая сумма: " << calculateTotal() << endl;
    }

private:
    vector<pair<Product, int>> items;
};

// Функция для нормализации названия продукта
string normalizeProductName(const string& name) {
    // Словарь для сопоставления вариантов написания с нормализованными названиями
    static map<string, string> normalizationMap = {
        {"bananas", "Banana"},
        {"banan", "Banana"},
        {"apples", "Apple"},
        // можно добавить различные вариации однокоренных названий
    };

    string lowerCaseName = name;
    transform(lowerCaseName.begin(), lowerCaseName.end(), lowerCaseName.begin(), ::tolower);

    auto it = normalizationMap.find(lowerCaseName);
    if (it != normalizationMap.end()) {
        return it->second;
    }
    return name; // Если нормализация не требуется, возвращаем исходное название
}

// Функция для обработки ввода пользователя и добавления товаров в чек
void processUserInput(const string& userInput, Store& store, Receipt& receipt) {
    regex productRegex("(\\d+)\\s*([a-zA-Z]+)");
    auto words_begin = sregex_iterator(userInput.begin(), userInput.end(), productRegex);
    auto words_end = sregex_iterator();

    map<string, int> productQuantities;

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string productName = normalizeProductName(match[2].str());
        int quantity = stoi(match[1].str());

        // Суммируем количество для одинаковых товаров
        productQuantities[productName] += quantity;
    }

    // Добавляем товары в чек с учетом суммированного количества
    for (const auto& pq : productQuantities) {
        string productName = pq.first;
        int totalQuantity = pq.second;

        auto it = store.findProductByName(productName);
        if (it != store.products.end()) {
            receipt.addItem(*it, totalQuantity);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Открытие файлов для ввода и вывода
    ifstream inputFile("SPISOK.txt");
    ofstream outputFile("output.txt");

    // Проверка успешного открытия файлов
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Ошибка при открытии файлов!" << endl;
        return 1;
    }
    // Инициализация словаря штрих-кодов
    barcodes = { {"Apple", 41}, {"Banana", 2}, {"Milk", 3}, {"Bread", 4}, {"Tomato", 5}, {"Cucumber", 6}, {"Potato", 7}, {"Cottage Cheese", 8}, {"Cheese", 9}, {"Sour Cream", 10}, {"Orange", 11}, {"Pear", 12}, {"Pineapple", 13}, {"Beef", 14}, {"Chicken", 15}, {"Pork", 16}, {"Soap", 17}, {"Shampoo", 18}, {"Pasta", 19} };

    // Создание экземпляра `Store`
    Store store;

    // Добавление товаров в магазин
    store.addProduct(Product("Apple", FRUITS, 2.5, 0.1, 10));
    store.addProduct(Product("Banana", FRUITS, 1.8, 0.05, 20));
    store.addProduct(Product("Milk", DAIRY, 1.2, 0.0, 15));
    store.addProduct(Product("Bread", OTHER, 1.0, 0.0, 30));
    store.addProduct(Product("Tomato", VEGETABLES, 3.0, 0.1, 8));
    store.addProduct(Product("Cucumber", VEGETABLES, 2.0, 0.0, 12));
    store.addProduct(Product("Potato", VEGETABLES, 1.5, 0.0, 10));
    store.addProduct(Product("Cottage Cheese", DAIRY, 2.0, 0.1, 10));
    store.addProduct(Product("Cheese", DAIRY, 5.0, 0.2, 8));
    store.addProduct(Product("Sour Cream", DAIRY, 2.5, 0.1, 10));
    store.addProduct(Product("Orange", FRUITS, 3.5, 0.0, 15));
    store.addProduct(Product("Pear", FRUITS, 4.0, 0.05, 10));
    store.addProduct(Product("Pineapple", FRUITS, 5.0, 0.1, 5));
    store.addProduct(Product("Beef", MEAT, 10.0, 0.15, 10));
    store.addProduct(Product("Chicken", MEAT, 7.0, 0.1, 15));
    store.addProduct(Product("Pork", MEAT, 8.0, 0.2, 10));
    store.addProduct(Product("Soap", OTHER, 2.5, 0.05, 20));
    store.addProduct(Product("Shampoo", OTHER, 4.5, 0.1, 15));
    store.addProduct(Product("Pasta", OTHER, 1.5, 0.0, 30));

    Receipt receipt;

    outputFile << "За покупками" << endl;
    string userInput;
    while (getline(inputFile, userInput)) {
        // Обработка ввода пользователя
        processUserInput(userInput, store, receipt);
    }

    // Печать чека в файл
    streambuf* stream_buffer_cout = cout.rdbuf();
    cout.rdbuf(outputFile.rdbuf());

    receipt.printReceipt();

    // Восстановление стандартного вывода
    cout.rdbuf(stream_buffer_cout);

    // Закрытие файлов
    inputFile.close();
    outputFile.close();

    return 0;
}

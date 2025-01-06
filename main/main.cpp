#include <iostream>
#include <cstring>

class String {
private:
    char* data;               
    size_t size;              
    static size_t objectCount;
public:
    String() {
        size = 80;
        data = new char[size + 1];
        data[0] = '\0';
        ++objectCount;
    }


    explicit String(size_t customSize) {
        size = customSize;
        data = new char[size + 1];
        data[0] = '\0'; 
        ++objectCount;
    }

    String(const char* input) {
        size = strlen(input);
        data = new char[size + 1];
        strcpy(data, input);
        ++objectCount;
    }

    ~String() {
        delete[] data;
        --objectCount;
    }

    void input() {
        std::cout << "Введіть рядок (до " << size << " символів): ";
        std::cin.getline(data, size + 1);
    }

    void output() const {
        std::cout << "Рядок: " << data << std::endl;
    }

    static size_t getObjectCount() {
        return objectCount;
    }
};

size_t String::objectCount = 0;

int main() {
    String str1;                      
    String str2(50);                 
    String str3("Привіт, світ!");   

    std::cout << "Кількість об'єктів: " << String::getObjectCount() << std::endl;

    str1.input();
    str1.output();

    str2.input();
    str2.output();

    str3.output();

    std::cout << "Кількість об'єктів: " << String::getObjectCount() << std::endl;

    return 0;
}

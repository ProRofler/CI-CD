#include <iostream>
#include <map>

class Matrix {
public:
    std::map<int, double> data;

    class ValueIterator {
    public:
        using MapIterator = std::map<int, double>::iterator;

        ValueIterator(MapIterator iter) : mapIter(iter) {}

        // Разыменование итератора возвращает значение
        double& operator*() const {
            return mapIter->second;
        }

        // Инкремент итератора
        ValueIterator& operator++() {
            ++mapIter;
            return *this;
        }

        // Сравнение итераторов на равенство
        bool operator!=(const ValueIterator& other) const {
            return mapIter != other.mapIter;
        }

    private:
        MapIterator mapIter;
    };

    // Методы для получения итераторов на начало и конец диапазона значений
    ValueIterator begin() {
        return ValueIterator(data.begin());
    }

    ValueIterator end() {
        return ValueIterator(data.end());
    }
};

int main() {
    Matrix matrix;
    for (auto a : matrix) {
        std::cout << a << std::endl;
    }

    return 0;
}

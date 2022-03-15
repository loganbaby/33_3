#include <iostream>
#include <map>

template<typename T1, typename T2>
class Register {
 private:
  std::multimap<T1, T2> _register{};
  T1 key;
  T2 value;

 public:
  inline void add() {
    std::cout << "Enter the key to add: ";
    std::cin >> key;

    std::cout << "Enter the value to add: ";
    std::cin >> value;

    _register.insert(std::make_pair(key, value));
  }

  inline void remove() {
    std::cout << "Enter the key to remove: ";
    std::cin >> key;

    _register.erase(key);
  }

  inline void print() const {
    for (auto it = _register.begin(); it != _register.end(); it++) {
      std::cout << it->first << " - " << it->second << std::endl;
    }
  }

  inline void find() {
    std::cout << "Enter the key to find: ";
    std::cin >> key;

    for (auto it = _register.begin(); it != _register.end(); it++) {
      if (it->first == key) {
        std::cout << it->first << " - " << it->second << std::endl;
      }
    }
  }
};

int main() {
  Register<int, int> reg;
  for (int i = 0; i < 2; i++) {    //чтобы посмотреть на 2 одинаковых ключа
    reg.add();
    reg.print();

    reg.remove();
    reg.print();

    reg.find();
  }

  Register<std::string, double> reg_2;
  reg_2.add();
  reg_2.print();

  reg_2.remove();
  reg_2.print();

  reg_2.find();
}
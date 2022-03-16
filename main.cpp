#include <iostream>
#include <map>

template<typename T1, typename T2>
class Register {
 private:
  std::multimap<T1, T2> _register{};

 public:

  inline void add(T1& key, T2& value) {
    std::cout << "Enter the key to add: ";
    std::cin >> key;

    std::cout << "Enter the value to add: ";
    std::cin >> value;

    _register.insert(std::make_pair(key, value));
  }

  inline void remove(T1& key) {
    std::cout << "Enter the key to remove: ";
    std::cin >> key;

    _register.erase(key);
  }

  inline void print() const {
    for (auto it = _register.begin(); it != _register.end(); it++) {
      std::cout << it->first << " - " << it->second << std::endl;
    }
  }

  inline void find(T1& key) {
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
    int key = 0;
    int value = 0;

    reg.add(key, value);
    reg.print();

    reg.remove(key);
    reg.print();

    reg.find(key);
  }

  Register<std::string, double> reg_2;
  std::string key = "";
  double value = 0;

  reg_2.add(key, value);
  reg_2.print();

  reg_2.remove(key);
  reg_2.print();

  reg_2.find(key);
}
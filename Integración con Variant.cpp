#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <variant>

class Environment {
public:
    Environment();
    void define(const std::string& symbol,const std::variant<int,double, std::string>& value);
    std::variant<int, std::string> lookup(const std::string& symbol) const;
    bool isDefined(const std::string& symbol) const;

private:
    std::map<std::string, std::variant<int, std::string>> symbolTable;
};

Environment::Environment() {}
void Environment::define(const std::string& symbol, const std::variant<int, double, std::string>& value) {
    symbolTable[symbol] = value;
}
std::variant<int,double,  std::string> Environment::lookup(const std::string& symbol) const {
    auto it = symbolTable.find(symbol);
    if (it == symbolTable.end()) {
        throw std::runtime_error("Undefined symbol: " + symbol);
    }
    return it->second;
}


bool Environment::isDefined(const std::string& symbol) const {
    return symbolTable.find(symbol) != symbolTable.end();
}


int main ()  {
    Environment env;
    env.define("x", 2,);
    env.define("y", 3);
    env.define("z", "Tarta de queso");

    try {
        auto    x = env.lookup("x");
        if (std::holds_alternative<int>(x)) {
            std::cout << "x = " << std::get<int>(x) << std::endl;
        }
         auto   y = env.lookup("y");
        if (std::holds_alternative<int>(y)) {
            std::cout << "y = " << std::get<int>(y) << std::endl;
        }
         auto   z = env.lookup("z");
        if (std::holds_alternative<int>(z)) {
            std::cout << "z = " << std::get<int>(z) << std::endl;
        }
        auto w = env.lookup("w");
        if (std::holds_alternative<int>(w)) {
            std::cout << "w no esta definis :( " << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
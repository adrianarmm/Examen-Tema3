#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <variant>

class Environment {
public:
    Environment();
    void define(const std::string& symbol, int value);
    std::variant<int, std::string> lookup(const std::string& symbol) const;
    bool isDefined(const std::string& symbol) const;

private:
    std::map<std::string, std::variant<int, std::string>> symbolTable;
};

Environment::Environment() {}
void Environment::define(const std::string& symbol, int value) {
    symbolTable[symbol] = value;
}
std::variant<int, std::string> Environment::lookup(const std::string& symbol) const {
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
    env.define("z", Tarta de queso);

    try {
        auto    x = env.lookup("x");
        auto    y = env.lookup("y");
        auto    z = env.lookup("z");
        std::cout << "x = " << std::get<int>(x) << std::endl;

    }


    return 0;
}
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <variant>

class Environment {
public:
    Environment();
    void define(const std::string& symbol, const std::variant<int, double, std::string>& value);
    std::variant<int, double, std::string> lookup(const std::string& symbol) const;
    bool isDefined(const std::string& symbol) const;
    void remove(const std::string& symbol);
    template<typename T>
    bool hasType(const std::string& symbol) const;

private:
    std::map<std::string, std::variant<int, double, std::string>> symbolTable;
};

Environment::Environment() {}

void Environment::define(const std::string& symbol, const std::variant<int, double, std::string>& value) {
    symbolTable[symbol] = value;
}

std::variant<int, double, std::string> Environment::lookup(const std::string& symbol) const {
    auto it = symbolTable.find(symbol);
    if (it == symbolTable.end()) {
        throw std::runtime_error("Undefined symbol: " + symbol);
    }
    return it->second;
}

bool Environment::isDefined(const std::string& symbol) const {
    return symbolTable.find(symbol) != symbolTable.end();
}

void Environment::remove(const std::string& symbol) {
    auto it = symbolTable.find(symbol);
    if (it != symbolTable.end()) {
        symbolTable.erase(it);
    }
}
template<typename T>
bool Environment::hasType(const std::string& symbol) const {
    if (isDefined(symbol)) {
        auto value = symbolTable.at(symbol);
        return std::holds_alternative<T>(value);
    }
    return false;
}
int main() {
    Environment env;
    env.define("x", 2);
    env.define("y", 3);
    env.define("z", std::string("Tarta de queso"));

    env.remove("y");
    std::cout << "x es de tipo int: " << std::boolalpha << env.hasType<int>("x") << std::endl;
    std::cout << "z es de tipo double: " << std::boolalpha << env.hasType<double>("z") << std::endl;
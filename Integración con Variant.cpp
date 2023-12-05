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
    env.define("x", 2);
    env.define("y", 3);
    env.define("z", 4);


    std::cout << "x = " << std::get<int>(env.lookup("x")) << std::endl;
    std::cout << "y = " << std::get<int>(env.lookup("y")) << std::endl;
    std::cout << "z = " << std::get<int>(env.lookup("z")) << std::endl;

    try {
        std::cout << "w = " << std::get<int>(env.lookup("w")) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
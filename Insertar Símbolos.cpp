#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
class Environment {
public:
    Environment();
    void define(const std::string& symbol, int value);
    int lookup(const std::string& symbol) const;
    bool isDefined(const std::string& symbol) const;

private:
    std::map<std::string, int> symbolTable;
};

Environment::Environment() {}
void Environment::define(const std::string& symbol, int value) {
    symbolTable[symbol] = value;
}

int Environment::lookup(const std::string& symbol) const {
    auto it = symbolTable.find(symbol);
    if (it == symbolTable.end()) {
        throw std::runtime_error("Undefined symbol: " + symbol);
    }
    return it->second;
}

bool Environment::isDefined(const std::string& symbol) const {
    return symbolTable.find(symbol) != symbolTable.end();
}
int main () {
    Environment env;
    env.define("x", 2);
    env.define("y", 3);
    env.define("z", 4);

    std::cout << "x = " << env.lookup("x") << std::endl;
    std::cout << "y = " << env.lookup("y") << std::endl;
    std::cout << "z = " << env.lookup("z") << std::endl;
    return 0;

    try     {
        std::cout << "x = " << env.lookup("x") << std::endl;
        std::cout << "y = " << env.lookup("y") << std::endl;
        std::cout << "z = " << env.lookup("z") << std::endl;
        std::cout << "w = " << env.lookup("w") << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
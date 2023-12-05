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
    void insert(const std::string& symbol, int value);

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
void Environment::insert(const std::string& symbol, int value) {
    auto it = symbolTable.find(symbol);
    if (it!= symbolTable.end()) {
throw std::runtime_error("Undefined symbol: " + symbol + " ya esta definido, ademas existe con otro valor")
    }
std::cout << "El simbolo " << symbol << " ha sido definido correctamente :)" << std::endl;


}
int main () {
    Environment env;
    env.insert("x", 2);
    env.insert("y", 3);
    env.insert("z", 4);

    std::cout << "x = " << env.lookup("x") << std::endl;
    std::cout << "y = " << env.lookup("y") << std::endl;
    std::cout << "z = " << env.lookup("z") << std::endl;

    try {
        std::cout << "w = " << env.lookup("w") << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;

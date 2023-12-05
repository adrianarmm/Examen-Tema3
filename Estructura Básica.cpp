#include <map>
#include <string>


class Environment {
public:
    Environment();
    void set(const std::string& symbol, int value);
    int get(const std::string& symbol) const;

private:
    std::map<std::string, int> symbolTable;
};
#include <stdexcept>
Environment::Environment() {}
void Environment::define(const std::string& symbol, int value) {
    symbolTable[symbol] = value;
}
int Environment::lookup(const std::string& symbol) const {
    auto it = symbolTable.find(symbol);
}
if (it == symbolTable.end()) {
    throw std::runtime_error("Undefined symbol: " + symbol);
         }
return it->second;
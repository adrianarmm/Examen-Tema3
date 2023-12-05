#include <map>
#include <string>
#include <stdexcept>

class Environment {
public:
    Environment();
    void set(const std::string& symbol, int value);
    int get(const std::string& symbol) const;

private:
    std::map<std::string, int> symbolTable;
};

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
}

bool Environment::isDefined(const std::string& symbol) const {
  return symbolTable.find(symbol) != symbolTable.end();
}
int main () {
  Environment env;
  env.define("x", 2);
  env.define("y", 3);
  env.define("z", 4);
  std::cout << env.lookup("x") << std::endl;
  std::cout << env.lookup("y") << std::endl;
  std::cout << env.lookup("z") << std::endl;
  std::cout << env.lookup("w") << std::endl;
  return 0;
}
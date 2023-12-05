#include <map>
#include <string>
Environment::Environment() {}
class Environment {
public:
    Environment();
    void set(const std::string& symbol, int value);
    int get(const std::string& symbol) const;

private:
    std::map<std::string, int> symbolTable;
};
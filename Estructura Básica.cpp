#include <map>
#include <string>

class Environment {
public:
    6    Environment();
    7    void set(const std::string& symbol, int value);
    8    int get(const std::string& symbol) const;
};
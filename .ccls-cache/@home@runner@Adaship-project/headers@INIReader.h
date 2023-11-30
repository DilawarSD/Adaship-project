#ifndef INIREADER_H
#define INIREADER_H

#include <string>
#include <unordered_map>

class INIReader {
public:
    INIReader(const std::string& filename);
    int ParseError() const;

    std::string Get(const std::string& section, const std::string& name, const std::string& default_value) const;
    int GetInteger(const std::string& section, const std::string& name, int default_value) const;

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> data;
    int parseError;
};

#endif // INIREADER_H
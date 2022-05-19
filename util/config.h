#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Config {
public:
    static const Config &getInstance();
    Config(const Config &other) = delete;
    void operator =(const Config &other) = delete;

    template<typename T>
    void getValue(const std::string &key, T &value) const { json_.at(key).get_to(value); }

    template<typename T>
    T getValue(const std::string &key) const { T value; json_.at(key).get_to(value); return value; }
private:
    static Config *instance_;
    explicit Config();
    nlohmann::json json_;
};

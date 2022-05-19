#include "config.h"

#include <fstream>

#include "rassert.h"

Config::Config()
{
    std::string config_path = "config.json";
    std::fstream config_file(config_path);
    rassert(config_file);

    config_file >> json_;
}

const Config &Config::getInstance()
{
    static Config config;
    return config;
}

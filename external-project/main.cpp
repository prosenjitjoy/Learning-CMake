#include <print>
#include <string>
#include "yaml-cpp/yaml.h"

int main()
{
    std::string name = "Guest";

    YAML::Node config = YAML::LoadFile("config.yaml");
    if (config["name"]) {
        name = config["name"].as<std::string>();
    }

    std::println("Welcome {}", name);
    return 0;
}

#pragma once
#include <string>
struct FileException {
    std::string msg;
    FileException(const std::string& msg) : msg(msg) {}
};

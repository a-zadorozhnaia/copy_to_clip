#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <iomanip>
#include <cassert>

#include "test.hpp"
#include "path_checker.hpp"

namespace fs = std::filesystem;

constexpr size_t print_filename_width = 75;
constexpr size_t print_status_width   = 20;

void PrintPathStatus(const PathChecker& path);
void PrintPathExist(const PathChecker& path);
void PrintDataType(const PathChecker& path);
void PrintPathType(const PathChecker& path);

void TestFileExist() {
    std::string path = "../test_files";
    std::vector<std::string> files = scanDirectory(path);
    files.push_back("~/Desktop/projects/copy_to_clip/test_files/cpp_file.cpp");
    files.push_back("usr/invalid_path_without_spaces");
    files.push_back("usr/invalid_path_with spaces");
    files.push_back("CMakeLists.txt");
    files.push_back("./CMakeLists.txt");
    files.push_back("../CMakeLists.txt");
    files.push_back("../../main.cpp");
    files.push_back("../../CMake Lists.txt");

    for (const auto& s : files) {
        PathChecker fm(s);
        std::cout << std::setw(print_filename_width) << std::setiosflags(std::ios::left) << s;
        PrintPathStatus(fm);
        PrintDataType(fm);
        PrintPathType(fm);
        std::cout << std::endl;
    }
}

void PrintPathStatus(const PathChecker& fm) {
    std::cout << std::setw(print_status_width);
    switch (fs::status(fm.absolutePath()).type())
    {
        case fs::file_type::none:
            std::cout << " has `not-evaluated-yet` type";
            break;
        case fs::file_type::not_found:
            std::cout << " does not exist";
            break;
        case fs::file_type::regular:
            std::cout << " is a regular file"; 
            break;
        case fs::file_type::directory:
            std::cout << " is a directory";
            break;
        case fs::file_type::symlink:
            std::cout << " is a symlink";
            break;
        case fs::file_type::block:
            std::cout << " is a block device";
            break;
        case fs::file_type::character:
            std::cout << " is a character device";
            break;
        case fs::file_type::fifo:
            std::cout << " is a named IPC pipe";
            break;
        case fs::file_type::socket:
            std::cout << " is a named IPC socket";
            break;
        case fs::file_type::unknown:
            std::cout << " has `unknown` type";
            break;
        default:
            std::cout << " has `implementation-defined` type";
            break;
    }
}

void PrintPathExist(const PathChecker& fm) {
    std::cout << std::setw(print_status_width);
    if (std::filesystem::exists(fm.absolutePath())) {
        std::cout << "exist";
    }
    else {
        std::cout << "not exist";
    }
}

void PrintDataType(const PathChecker& fm) {
    std::cout << std::setw(print_status_width);
    if (fm.isFile()) {
        std::cout << "is file";
    }   
    else {
        std::cout << "is text";
    }
}

void PrintPathType(const PathChecker& fm) {
    std::cout << std::setw(print_status_width);
    if (fs::path(fm.absolutePath()).is_relative()) {
        std::cout << "is rel";
    }   
    else {
        std::cout << "is abs";
    }
}

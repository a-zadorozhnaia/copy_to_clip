#include <iostream>
#include <string>
#include <filesystem>

#include "path_checker.hpp"
#include "clip.hpp"

int main(int argc, char* argv[]) {
    std::string str_args;
    if (argc < 2) {
        std::cout << "There are no arguments.\n"
                     "The program takes a single argument as input.\n"
                     "You can pass a string or a file path as an argument." << std::endl;
        return 0;
    }
    else if (argc > 2) {
        std::cout << "There are too many arguments.\n"
                     "The program takes a single argument as input.\n"
                     "You can pass a string or a file path as an argument." << std::endl;
        return 0;
    }
    else {
        str_args = argv[1];
    }

    PathChecker fm(str_args);
    if (fm.isFile()) {
        clip::set_file(fm.absolutePath());
        std::cout << "File is copied to clipboard" << std::endl;
    }
    else {
        clip::set_text(str_args);
        std::cout << "Text is copied to clipboard" << std::endl;
    }
    return 0;
}

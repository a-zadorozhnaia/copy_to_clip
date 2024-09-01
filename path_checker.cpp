#include <filesystem>
#include <vector>
#include <string>
#include <linux/limits.h>

#include "path_checker.hpp"

namespace fs = std::filesystem;

PathChecker::PathChecker(const std::string& path) {
    if (path.empty() || path.size() > PATH_MAX) {
        return;
    }

    // Check path like this "~/Desktop/projects/copy_to_clip"
    std::string converted_path = ConvertFromTildaPath(path);
    // Convert from relative path to absolute if exist
    ConvertToAbsolutePath(converted_path);
}

bool PathChecker::isFile() const {
    return is_file_;
}

std::string PathChecker::absolutePath() const {
    return absolute_path_;
}

std::string PathChecker::ConvertFromTildaPath(const std::string& path) {
    std::string converted_path{path};
    if (path[0] == '~') {
        const char* home = std::getenv("HOME");
        if (home) {
            converted_path = home;
            if (path.size() > 1) {
                converted_path += path.substr(1, path.size() - 1);
            }
        }
    }
    return converted_path;
}

void PathChecker::ConvertToAbsolutePath(const std::string& path) {
    try {
        if (fs::path(path).filename().string().size() > NAME_MAX) {
            return;
        }

        // Path exist and it's file
        if (fs::exists(path) && fs::status(path).type() == fs::file_type::regular) {
            is_file_ = true;
            if (fs::path(path).is_relative()) {
                absolute_path_ = std::filesystem::weakly_canonical(path);
            }
            else {
                absolute_path_ = path;
            }
        }
    } catch (...) {}
}

std::vector<std::string> scanDirectory(const std::string& path) {
    if (!fs::exists(path) || fs::status(path).type() != fs::file_type::directory) {
        return {};
    }

    std::vector<std::string> files;
    for (const auto & entry : fs::directory_iterator(path)) {
        files.push_back(entry.path());
    }
    return files;
}

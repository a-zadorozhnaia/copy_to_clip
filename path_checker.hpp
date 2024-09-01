#pragma once

#include <vector>
#include <string>

class PathChecker {
public:
    explicit PathChecker(const std::string& path);
    bool isFile() const;
    std::string absolutePath() const;

private:
    std::string ConvertFromTildaPath(const std::string& path);
    void ConvertToAbsolutePath(const std::string& path);

private:
    bool is_file_ {false};
    std::string absolute_path_;
};

std::vector<std::string> scanDirectory(const std::string& path);

#include <string>

namespace clip {

void set_text(const std::string& text) {
    const std::string command = "echo '" + text + "' | xclip -selection clipboard";
    system(command.c_str());
}

void set_file(const std::string& path) {
    const std::string command = "echo -e \"copy\nfile://" + path + "\\0\" | xclip -i -selection clipboard -t x-special/gnome-copied-files";
    system(command.c_str());
}

} // clip

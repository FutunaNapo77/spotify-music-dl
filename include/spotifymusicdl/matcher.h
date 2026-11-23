// matcher — part of spotify-music-dl.

#pragma once

#include <string>
#include <vector>

namespace spotifymusicdl {

class Matcher {
public:
    explicit Matcher(const std::string& config_path);

    void configure(const std::string& key, const std::string& value);
    bool run();
    bool verbose() const { return verbose_; }

private:
    std::string config_path_;
    bool verbose_ = false;
};

}  // namespace spotifymusicdl

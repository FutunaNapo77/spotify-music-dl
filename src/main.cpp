// main.cpp — entry point. Wires config and subsystems together.

#include "spotifymusicdl/settings.h"
#include "spotifymusicdl/matcher.h"
#include "spotifymusicdl/downloader.h"
#include "spotifymusicdl/tags.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    spotifymusicdl::Settings settings = spotifymusicdl::Settings::load_default();
    spotifymusicdl::Matcher matcher(settings.store_path);
    spotifymusicdl::Downloader downloader(settings.store_path);
    spotifymusicdl::Tags tags(settings.store_path);
    std::fprintf(stderr, "[spotify-music-dl] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}

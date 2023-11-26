#include "module1/Class.hpp"
#include "spdlog/spdlog.h"


int main()
{
    EASY_PROFILER_ENABLE;
    spdlog::info("Spdlog is activated!");
    spdlog::warn("Spdlog is warning you");
    spdlog::error("spdlog says this program should quit");

    EASY_BLOCK("Outer block", profiler::colors::Black);
    for (int i = 0; i < 10; ++i)
    {
        EASY_BLOCK("Inner block", profiler::colors::Amber);
        usleep(10000);
        EASY_END_BLOCK
    }
    EASY_END_BLOCK

    profiler::dumpBlocksToFile("../test_profile.prof");
    return 0;
}
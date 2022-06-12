#pragma once

namespace ANSI {
    const std::string FG_BLACK("\x1b[30m");
    const std::string FG_RED("\x1b[31m");
    const std::string FG_GREEN("\x1b[32m");
    const std::string FG_YELLOW("\x1b[33m");
    const std::string FG_BLUE("\x1b[34m");
    const std::string FG_MAGENTA("\x1b[35m");
    const std::string FG_CYAN("\x1b[36m");
    const std::string FG_WHITE("\x1b[37m");
    const std::string FG_DEFAULT("\x1b[39m");

    const std::string BG_BLACK("\x1b[40m");
    const std::string BG_RED("\x1b[41m");
    const std::string BG_GREEN("\x1b[42m");
    const std::string BG_YELLOW("\x1b[43m");
    const std::string BG_BLUE("\x1b[44m");
    const std::string BG_MAGENTA("\x1b[45m");
    const std::string BG_CYAN("\x1b[46m");
    const std::string BG_WHITE("\x1b[47m");
    const std::string BG_DEFAULT("\x1b[39m");


    const std::string ARROW_UP("\x1b\x5b\x41");
    const std::string ARROW_DOWN("\x1b\x5b\x42");
    const std::string ARROW_LEFT("\x1b\x5b\x43");
    const std::string ARROW_RIGHT("\x1b\x5b\x44");

    const std::string BOLD_ON("\x1b[1m");
    const std::string BOLD_OFF("\x1b[22m");

    const std::string UNDERLINE_ON("\x1b[4m");
    const std::string UNDERLINE_OFF("\x1b[24m");

    const std::string INVERSE_ON("\x1b[7m");
    const std::string INVERSE_OFF("\x1b[b27m");

    const std::string STRIKETHROUGH_ON("\x1b[9m");
    const std::string STRIKETHROUGH_OFF("\x1b[29m");

    const std::string ERASE_LINE("\x1b[2K");
    const std::string ERASE_SCREEN("\x1b[2J");
}
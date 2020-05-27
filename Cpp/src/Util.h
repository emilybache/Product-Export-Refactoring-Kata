#ifndef UTIL_H
#define UTIL_H

#include <ctime>
#include <iomanip>
#include <sstream>

static time_t from_iso_date(std::string datetime) {
    struct std::tm tm{};
    std::stringstream ss(datetime);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::time_t time = mktime(&tm);
    return time;
};
static std::string make_iso_date_str(time_t date) {
    std::tm * ptm = std::localtime(&date);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", ptm);
    return std::string(buffer);
};

#endif
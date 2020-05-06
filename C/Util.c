#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t from_iso_date(const char* datetime)
{
    struct tm t;
    int success = sscanf(datetime, "%d-%d-%dT%d:%dZ", /* */
                         &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min);
    if (success != 5) {
        return 0;
    }

    /* compensate expected ranges */
    t.tm_year = t.tm_year - 1900;
    t.tm_mon = t.tm_mon - 1;
    t.tm_sec = 0;
    t.tm_wday = 0;
    t.tm_yday = 0;
    t.tm_isdst = 0;

    time_t local_time = mktime(&t);
    time_t utc_time = local_time - timezone;
    return utc_time;
}

const char* make_iso_date_str(const time_t date)
{
    struct tm utc = *gmtime(&date);
    /* compensate expected ranges */
    utc.tm_year = utc.tm_year + 1900;
    utc.tm_mon = utc.tm_mon + 1;

    char* s = (char*)malloc(sizeof(char[17 + 1]));
    sprintf(s, "%04d-%02d-%02dT%02d:%02dZ", /* */
            utc.tm_year, utc.tm_mon, utc.tm_mday, utc.tm_hour, utc.tm_min);
    return s;
}

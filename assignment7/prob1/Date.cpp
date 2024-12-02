#include "Date.h"

Date::Date() = default;
Date::Date(int y, int m, int d): year(y), month(m), day(d) {}
Date::Date(string date_string) {
    int start = 0, end = 0;
    while (end < date_string.length() && date_string.at(end) != '/') end++;
    year = stoi(date_string.substr(start, end));

    end++, start = end;
    while (end < date_string.length() && date_string.at(end) != '/') end++;
    month = stoi(date_string.substr(start, end - start));

    start = end + 1;
    day = stoi(date_string.substr(start));
}
void Date::Dateadd(Date &rhs) {
    rhs.day++;
    if (rhs.month == 1 || rhs.month == 3 || rhs.month == 5 || rhs.month == 7 || rhs.month == 8 || rhs.month == 10 ||
        rhs.month == 12) {
        if (rhs.day == 32) {
            rhs.day = 1;
            rhs.month++;
        }
    } else if (rhs.month == 2) {
        if (rhs.day == 29) {
            rhs.day = 1;
            rhs.month++;
        }
    } else {
        if (rhs.day == 31) {
            rhs.day = 1;
            rhs.month++;
        }
    }
    if (rhs.month == 13) {
        rhs.month = 1;
        rhs.year++;
    }
}
bool Date::operator<(Date &rhs) {
    return year<rhs.year || (year==rhs.year && month<rhs.month) ||
           (year==rhs.year && month==rhs.month && day<rhs.day);
}

bool Date::operator>(Date &rhs) {
    return year>rhs.year || (year==rhs.year && month>rhs.month) ||
           (year==rhs.year && month==rhs.month && day>rhs.day);
}

bool Date::operator==(Date &rhs) {
    return year==rhs.year && month==rhs.month && day==rhs.day;
}

bool Date::operator!=(Date &rhs) {
    return !(*this == rhs);
}

bool Date::operator<=(Date &rhs) {
    return *this<rhs || *this==rhs;
}

bool Date::operator>=(Date &rhs) {
    return *this>rhs || *this==rhs;
}

void Date::print(ostream &out) {
    out << year << "/" << month << "/" << day;
}

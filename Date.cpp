//
// Created by Alex on 1/12/23.
//

#include "Date.h"

Date::Date(int year) : year(year) {
    month = 1;
    day = 1;
}

Date::Date(int year, int month) : year(year), month(month) { day = 1; }

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

Date &Date::addMonths(int n) {
    year += (month + n) / 12;
    month = (month + n) % 12;
    return *this;
}

Date &Date::addDays(int n) {
    int d = daysToDate() + n;
    int y = year, m = 1;
    while (d > daysInMonth(y, m)) {
        d -= daysInMonth(y, m);
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    day = d;
    month = m;
    year = y;

    return *this;
}

bool Date::isLeapYear(int y) {
    return !(y % 4 || (y % 100 == 0 && y % 400));
}

std::string Date::toString() const {
    std::stringstream out;
    const std::string monthName[] = {
            "Jan",
            "Feb",
            "Mar",
            "Apr",
            "May",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"
    };
    out << monthName[month - 1] << " " << day << ", " << year;
    return out.str();
}

int Date::daysToDate() const {
    int days_in_month[]{31, isLeapYear(year) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for (int m = 0; m < month - 1; m++) {
        days += days_in_month[m];
    }
    days += day;
    return days;
}

Date &Date::operator+(int n) {
    return addDays(n);
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    out << date.toString();
    return out;
}

int Date::daysInMonth(int y, int m) {
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[m - 1];
}

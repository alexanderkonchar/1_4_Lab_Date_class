//
// Created by Alex on 1/12/23.
//

#ifndef INC_1_4_LAB_DATE_CLASS_DATE_H
#define INC_1_4_LAB_DATE_CLASS_DATE_H


#include <sstream>

class Date {
public:
    explicit Date(int year);

    Date(int year, int month);

    Date(int year, int month, int day);

    Date &addMonths(int n);

    Date &addDays(int n);

    static bool isLeapYear(int y);

    std::string toString() const;

    int daysToDate() const;

    Date &operator+(int n);

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

private:
    int year, month, day;

    static int daysInMonth(int y, int m);
};


#endif //INC_1_4_LAB_DATE_CLASS_DATE_H

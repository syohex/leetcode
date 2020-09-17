#include <cassert>
#include <string>
#include <map>
#include <cstdio>

std::string reformatDate(const std::string &date) {
    std::map<std::string, std::string> day{
        {"1st", "01"},  {"2nd", "02"},  {"3rd", "03"},  {"4th", "04"},  {"5th", "05"},  {"6th", "06"},  {"7th", "07"},
        {"8th", "08"},  {"9th", "09"},  {"10th", "10"}, {"11th", "11"}, {"12th", "12"}, {"13th", "13"}, {"14th", "14"},
        {"15th", "15"}, {"16th", "16"}, {"17th", "17"}, {"18th", "18"}, {"19th", "19"}, {"20th", "20"}, {"21st", "21"},
        {"22nd", "22"}, {"23rd", "23"}, {"24th", "24"}, {"25th", "25"}, {"26th", "26"}, {"27th", "27"}, {"28th", "28"},
        {"29th", "29"}, {"30th", "30"}, {"31st", "31"},
    };

    std::map<std::string, std::string> month{
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
        {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"},
    };

    size_t day_end = 0;
    size_t month_end = 0;
    for (size_t i = 0; i < date.size(); ++i) {
        if (date[i] == ' ') {
            if (day_end == 0) {
                day_end = i;
            } else {
                month_end = i;
            }
        }
    }

    return date.substr(month_end + 1) + "-" + month[date.substr(day_end + 1, month_end - day_end - 1)] + "-" +
           day[date.substr(0, day_end)];
}

int main() {
    {
        assert(reformatDate("20th Oct 2052") == "2052-10-20");
        assert(reformatDate("6th Jun 1933") == "1933-06-06");
        assert(reformatDate("26th May 1960") == "1960-05-26");
    }
    return 0;
}

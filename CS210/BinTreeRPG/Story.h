#ifndef STORY_H
#define STORY_H

#include <string>
#include <utility>
using namespace std;

class Story {
public:
    string description;
    string leftOption;
    string rightOption;
    int eventNumber;
    int leftEventNumber;
    int rightEventNumber;

    Story(string desc, const int num, const int leftNum, const int rightNum, string lOpt, string rOpt)
            : description(std::move(desc)), leftOption(std::move(lOpt)), rightOption(std::move(rOpt)), eventNumber(num),
                leftEventNumber(leftNum), rightEventNumber(rightNum) {}
};

#endif // STORY_H

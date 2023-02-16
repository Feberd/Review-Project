#ifndef REVIEW_PROJECT_GRADEBOOK_H
#define REVIEW_PROJECT_GRADEBOOK_H

#include <string>
#include <vector>

class Gradebook{
private:
    int labs;
    int assign;
    int projects;
    int exam;

public:
    Gradebook(int labs, int assign, int projects, int exam);
    int IndividualGrade(std::string name);
    std::vector<int> CategoryGrade(std::string cat);
    void CourseGrade();
    void IndWriteFile(std::string output_file, std::string name, int grades);
    void WriteFile(std::string output_file, std::vector<int> *grades);
};

#endif //REVIEW_PROJECT_GRADEBOOK_H

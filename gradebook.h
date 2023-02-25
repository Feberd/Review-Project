#ifndef REVIEWPROJECT_GRADEBOOK_H
#define REVIEWPROJECT_GRADEBOOK_H

#include <string>
#include <vector>

class Gradebook{

private:
    std::vector<int> labGradesList;
    std::vector<int> assignmentGradesList;
    std::vector<int> projectGradesList;
    std::vector<int> examGradesList;

public:
    Gradebook(std::vector<int> labGradesList,std::vector<int> assignmentGradesList, std::vector<int> projectGradesList, std::vector<int> examGradesList);
    int IndividualGrade();
    int CategoryGrade(std::string categoryName);
    void IndividualWriteFile(std::string output_file, std::string name, std::string surName, int grades);
    void CategoryWriteFile(std::string output_file, std::string categoryName, int grades);
    void CourseWriteFile(std::string output_file, int grades);
};

#endif

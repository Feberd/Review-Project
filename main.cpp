#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int main(int argc, char*argv[]) {

    std::string name(argv[1]);          // name of the person
    std::string surName(argv[2]);       // surname of the person
    std::string input_file(argv[3]);    // file to read from
    std::string output_file(argv[4]);   // file to write to
    std::string output_type(argv[5]);   // type of choice for getting grade (individual, category, course)

    // string for category type
    std::string categoryName;

    // reads the file
    std::ifstream file(input_file);
    std::string line;

    // pushes the category names to a list
    std::vector<std::string> categoryList;
    std::string category;
    if (std::getline(file, line)) {
        std::istringstream ss(line);
        while (ss >> category) {
            categoryList.push_back(category);
        }
    }

    // lists to store the grades
    std::vector<int> labGradesList;
    std::vector<int> assignmentGradesList;
    std::vector<int> projectGradesList;
    std::vector<int> examGradesList;

    // single grades
    int labGrades;
    int assignmentGrades;
    int projectGrades;
    int examGrades;

    // pushes the specific grades to the specific list by line in order
    if (std::getline(file, line)) {
        std::istringstream ss(line);
        while (ss >> labGrades) {
            labGradesList.push_back(labGrades);
        }
    }
    if (std::getline(file, line)) {
        std::istringstream ss(line);
        while (ss >> assignmentGrades) {
            assignmentGradesList.push_back(assignmentGrades);
        }
    }
    if (std::getline(file, line)) {
        std::istringstream ss(line);
        while (ss >> projectGrades) {
            projectGradesList.push_back(projectGrades);
        }
    }
    if (std::getline(file, line)) {
        std::istringstream ss(line);
        while (ss >> examGrades) {
            examGradesList.push_back(examGrades);
        }
    }

    // calls the declare function
    Gradebook Mygradebook = Gradebook(labGradesList, assignmentGradesList, projectGradesList, examGradesList);

    // choice for the type of course output
    int choice;

    // asks user for input of the type of category
    if (output_type == "Category") {
        std::cout << "Select and type one category from (lab/assignment/project/exam) : ";
        std::cin >> categoryName;
        int grade = Mygradebook.CategoryGrade(categoryName);
        Mygradebook.CategoryWriteFile(output_file, categoryName, grade);
    }

    else if (output_type == "Individual") {
        int grades = Mygradebook.IndividualGrade();
        Mygradebook.IndividualWriteFile(output_file, name, surName, grades);
    }

    // asks user for what type of course grade output to have
    else if (output_type == "Course") {
        std::cout << "Enter 1 for all grades within categories and overall course grade" << "\n";
        std::cout << "Enter 2 for only category totals and overall course grade" << "\n";
        std::cout << "Enter 3 for only overall course grade" << "\n";
        std::cout << "Enter here :";
        std::cin >> choice;
        Mygradebook.CourseWriteFile(output_file, choice);

    }
    else {
        std::cout << "Please check your spelling for the 4th cla" << std::endl;
    }

    return 0;
}

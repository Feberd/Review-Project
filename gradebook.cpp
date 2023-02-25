#include "gradebook.h"
#include <iostream>
#include <vector>
#include <fstream>

Gradebook::Gradebook(std::vector<int> labGradesList,std::vector<int> assignmentGradesList, std::vector<int> projectGradesList, std::vector<int> examGradesList) {
    this->labGradesList = labGradesList;
    this->assignmentGradesList = assignmentGradesList;
    this->projectGradesList = projectGradesList;
    this->examGradesList = examGradesList;
}

// function to return the final course grade
int Gradebook::IndividualGrade(){

    // max number of points available
    int total = 1000;

    // adds all lab points
    double totalLab = 0;
    for (int i = 0; i < labGradesList.size(); i++) {
        totalLab += labGradesList[i];
    }

    // adds all assignment points
    double totalAssignment = 0;
    for (int i = 0; i < assignmentGradesList.size(); i++) {
        totalAssignment += assignmentGradesList[i];
    }

    // adds all project points
    double totalProject = 0;
    for (int i = 0; i < projectGradesList.size(); i++) {
        totalProject += projectGradesList[i];
    }

    // adds all exam points
    double totalExam = 0;
    for (int i = 0; i < examGradesList.size(); i++) {
        totalExam += examGradesList[i];
    }

    // adds all the grades
    double grade = totalLab + totalAssignment + totalProject + totalExam;

    // find final grade for course
    grade = grade / total * 100;

    return grade;
}

// function to return total category points
int Gradebook::CategoryGrade(std::string categoryName) {

    int grade = 0;

    // if statements to see what category the user chose
    if (categoryName == "lab") {
        for (int i = 0; i < labGradesList.size(); i++) {
            grade += labGradesList[i];
        }
    }
    else if (categoryName == "assignment") {
        for (int i = 0; i < assignmentGradesList.size(); i++) {
            grade += assignmentGradesList[i];
        }
    }
    else if (categoryName == "project") {
        for (int i = 0; i < projectGradesList.size(); i++) {
            grade += projectGradesList[i];
        }
    }
    else if(categoryName == "exam"){
        for (int i = 0; i < examGradesList.size(); i++) {
            grade += examGradesList[i];
        }
    }

    // depending on the category, the function returns that specific total points of that specific category
    return grade;
}


// write function for input individual
void Gradebook::IndividualWriteFile(std::string output_file, std::string name, std::string surName, int grades){

    // opens a new file and writes the information
    std::ofstream my_file(output_file);
    if (my_file.is_open()) {
        my_file << name << " ";
        my_file << surName << " ";
        my_file << grades;
        my_file.close();
    }
    else {
        std::cout << "Can not open the file" << std::endl;
    }
}

// write function for input category
void Gradebook::CategoryWriteFile(std::string output_file, std::string categoryName, int grades){

    // opens a new file and writes the information
    std::ofstream my_file(output_file);
    if (my_file.is_open()) {
        // if statements that decide what to write depending on the category name
        if (categoryName == "lab") {
            my_file << "Lab grades : ";
            for (int i = 0; i < labGradesList.size(); i++) {
                my_file << this->labGradesList[i] << " ";

            }
            my_file << "\n" << "Total lab score : " << grades << std::endl;
        }
        else if (categoryName == "assignment") {
            my_file << "Assignment grades : ";
            for (int i = 0; i < assignmentGradesList.size(); i++) {
                my_file << this->assignmentGradesList[i] << " ";

            }
            my_file << "\n" << "Total assignment score : " << grades;
        }
        else if (categoryName == "project") {
            my_file << "Project grades : ";
            for (int i = 0; i < projectGradesList.size(); i++) {
                my_file << this->projectGradesList[i] << " ";

            }
            my_file << "\n" << "Total project score : " << grades;
        }
        else if (categoryName == "exam") {
            my_file << "Exam grades : ";
            for (int i = 0; i < examGradesList.size(); i++) {
                my_file << this->examGradesList[i] << " ";

            }
            my_file << "\n" << "Total exam score : " << grades;
        }
    }
    else {
        std::cout << "Can not open the file" << std::endl;
    }
}

// write function for input course
void Gradebook::CourseWriteFile(std::string output_file, int choice){
    std::string lab;
    std::string assignment;
    std::string project;
    std::string exam;

    std::ofstream my_file (output_file);
    if (my_file.is_open()) {

        // depending on the choice, what to write on the file
        if (choice == 1) {
            my_file << "Lab grades : ";
            for (int i = 0; i < labGradesList.size(); i++) {
                my_file << this->labGradesList[i] << " ";
            }
            my_file << "\n";

            my_file << "Assignment grades : ";
            for (int i = 0; i < assignmentGradesList.size(); i++) {
                my_file << this->assignmentGradesList[i] << " ";
            }
            my_file << "\n";

            my_file << "Project grades : ";
            for (int i = 0; i < projectGradesList.size(); i++) {
                my_file << this->projectGradesList[i] << " ";
            }
            my_file << "\n";

            my_file << "Exam grades : ";
            for (int i = 0; i < examGradesList.size(); i++) {
                my_file << this->examGradesList[i] << " ";
            }
            my_file << "\n";

            int grade = IndividualGrade();
            my_file <<  "\n" << "Your course grade is : " << grade;
        }
        else if (choice == 2) {
            int labTotal = CategoryGrade("lab");
            int assignmentTotal = CategoryGrade("assignment");
            int projectTotal = CategoryGrade("project");
            int examTotal = CategoryGrade("exam");

            my_file << "Your total lab grade is : " << labTotal << std::endl;
            my_file << "Your total assignment grade is : " << assignmentTotal << std::endl;
            my_file << "Your total project grade is : " << projectTotal << std::endl;
            my_file << "Your total exam grade is : " << examTotal << std::endl;

            int grade = IndividualGrade();
            my_file <<  "\n" << "Your course grade is : " << grade;
        }
        else if (choice == 3) {
            int grade = IndividualGrade();
            my_file << "Your course grade is : " << grade;
        }
    }
    else {
        std::cout << "Can not open the file" << std::endl;
    }
}

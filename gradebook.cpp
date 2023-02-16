#include "gradebook.h"
#include <iostream>
#include <vector>
#include <fstream>

Gradebook::Gradebook(int labs, int assign, int projects, int exam){
    this->labs = labs;
    this->assign = assign;
    this->projects = projects;
    this->exam = exam;
}

int Gradebook::IndividualGrade(std::string name){
    //max number of points
    int total = 1000;
    //added all points
    double grade = labs + assign + projects + exam;

    //find final grade for course
    grade = grade / total * 100;

    return grade;
}

std::vector<int> Gradebook::CategoryGrade(std::string cat){
    //vector to hold all grades from the category and total grade of category
    std::vector<int> grade;

    //if statements to see what category the user chose
    if(cat == "labs"){
        std::cout << labs << std::endl;
    }
    else if(cat == "assign"){
        std::cout << assign << std::endl;
    }
    else if(cat == "projects"){
        std::cout << projects << std::endl;
    }
    else if(cat == "exam"){
        std::cout << exam << std::endl;
    }

    return grade;
}

//used for when individual grade is chosen by the user
void Gradebook::IndWriteFile(std::string output_file, std::string name, int grades){
    std::ofstream my_file (output_file);

    if(my_file.is_open()) {
        my_file << name << " ";
        my_file << grades;
        my_file.close();
    }
    else{
        std::cout << "can not open file" << std::endl;
    }
}

//used for when category or course is chosen by the user
void Gradebook::WriteFile(std::string output_file, std::vector<int> *grades){
    std::ofstream my_file (output_file);

    if(my_file.is_open()) {

        //loops through f_data and writes the values into the file
        for (int i = 0; i < grades->size(); i++) {
                my_file << (*grades)[i] << " ";
        }
        my_file.close();
    }
    else{
        std::cout << "can not open file" << std::endl;
    }
}
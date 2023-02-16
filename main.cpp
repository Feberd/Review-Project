#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int main(int argc, char*argv[]) {
    std::string name(argv[1]);          //name of person
    std::string input_file(argv[2]);    //file to read from
    std::string output_file(argv[3]);   //file to write to
    std::string output_type(argv[4]);   //what type of choice for getting grade (individual, category, course)

    //string for category type
    std::string cat;
    //choice for the type of course output
    int choice;

    //asks user for input of the type of category
    if(output_type == "Category") {
        std::cout << "Category: ";
        std::cin >> cat;
    }
    //asks user for what type of course grade output to have
    else if(output_type == "Course") {
        std::cout << "enter 1 for all grades within categories and overall course grade" << "\n";
        std::cout << "enter 2 for all grades within categories and overall course grade" << "\n";
        std::cout << "enter 3 for only overall course grade" << "\n";
        std::cin >> choice;

    }

    //the four categories
    int labs;
    int assign;
    int projects;
    int exam;

    //reads file
    std::ifstream file(input_file);

    std::string str;
    std::vector<int> temp;

    while (std::getline(file, str)) {


        std::istringstream ss(str);

        int token;

        while (ss >> token) {
            temp.push_back(token);
        }
    }

    /*for(int i = 0; i < temp.size(); i++) {
        std::cout << temp[i] << std::endl;
    }*/

    //puts grades in category variables
    labs = temp[0];
    assign = temp[1];
    projects = temp[2];
    exam = temp[3];
    /*std::cout << labs << std::endl;
    std::cout << assign << std::endl;
    std::cout << projects << std::endl;
    std::cout << exam << std::endl;*/

    //std::cout << cat << std::endl;

    Gradebook Mygradebook = Gradebook(labs, assign, projects, exam);

    if(output_type == "Individual"){
        int grades = Mygradebook.IndividualGrade(name);
        Mygradebook.IndWriteFile(output_file, name, grades);
    }
    else if(output_type == "Category"){
        std::vector<int> grades = Mygradebook.CategoryGrade(cat);

    }
    else if(output_type == "Course"){

    }
    //std::vector<int> vec = {30, 50, 70, 20};
    //Mygradebook.WriteFile(output_file, &vec);

    return 0;
}



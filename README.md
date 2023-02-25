# Review-Project
## Review project for CSC 212

### Summary of Project:

The user is able to use command line arguements (CLA) to decide what grades they would like to see for CSC 212. The variations include:

- Individual grade, where the user sees their name and overall course grade.
- Category grade, where the user can decide what category out of lab, assignment, project and exam they would like to see their grade in.
- Course grade, where the user can choose between three options
  1. Seeing all grades within categories and overall grade for the course.
  2. Seeing total grades from each category and overall grade for the course.
  3. Seeing only course grade.

Once one of these options are chosen, the file with the grades are read and the output is written back into a file to be viewed by the user.


### Pseudocode for choice of user in main.cpp:

  If "Individual" is part of the CLA, then
      go to the individual member function of the gradebook class to calculate the overall grade
      go to Individual write member function to write to specified output file
  else if "Category" is part of the CLA, then
      read in what category was typed by the user after the prompt and put it into the category name variable
      go to the Category member function of the gradebook class to calculate the grade of specified category
      go to Category write member function to write to specified output file
  else if "Course" is part of the CLA, then
      read in what choice was typed by the user after the prompt and put into the choice variable
      go to the Course write member function of the gradebook class where depending on the choice, different grades will be written to the file
      
      
### Detailed Instructions on Use of program:

  **CLA format:**   First_Name Last_Name input_file output_file output_type
        First_Name = the first name of the user
        Last_Name = the last name of the user
        input_file = file name that user wants the grades/categories to be read from
        output_file = file name that user wants the output to be written to
        output_type = users choice of "Individual", "Category" or "Course"
        
  **CLA example for Individual:**   John Smith grades.txt finalGrades.txt Individual
  
  **CLA example for Category:**     John Smith grades.txt finalGrades.txt Category    
  (A prompt is then sent to user, where they type "lab", "assignment", "project" or "exam", depending on what grades the user wants)
  
  **CLA example for Course:**       John Smith grades.txt finalGrades.txt Course      
  (A prompt is then sent to user explaining the choices, where the user types "1","2" or "3" depending on what grades the user wants)
  
  **_IMPORTANT_**: ***Fifth CLA and all choices in prompts are case and spelling sensitive***
  
              
          

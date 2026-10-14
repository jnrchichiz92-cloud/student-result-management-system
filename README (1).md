# Student Result Management System (C++)

A beginner-friendly console application demonstrating how arrays can store and process related student data.

## Features
- Add a student's full name and mark (0–100)
- Display all entered results and pass/fail status
- Calculate total marks and class average
- Identify highest and lowest marks
- Count passes and fails
- Search for a student's exact name
- Validate menu choices and marks

## Array concepts demonstrated
The program uses two parallel arrays:
- `studentNames[MAX_STUDENTS]` stores names.
- `studentMarks[MAX_STUDENTS]` stores marks.

The same index in both arrays refers to the same student. For example, `studentNames[0]` and `studentMarks[0]` belong to the first student. A loop processes all entries. The program supports up to 100 student records per run.

## Requirements
A C++ compiler that supports C++11 or later (for example, GCC, MinGW, or Clang).

## Compile and run

### Windows (MinGW)
Open Command Prompt in this folder and run:
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o student_results.exe
student_results.exe
```

### Linux / macOS
```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o student_results
./student_results
```

## Notes and limitations
- Records are kept in memory and are lost when the program closes.
- Names are searched by exact spelling and capitalization.
- The pass mark is set to 50. Change `PASS_MARK` in `main.cpp` if your course uses a different threshold.
- This is an educational console application, not a production student information system.

## Project structure
- `main.cpp` — application source code
- `README.md` — project description and instructions
- `Array_Data_Structures_Report.pdf` — assignment report

# 🎓 Student Marks Management System (C++)

## 📌 Overview
This project is a console-based Student Marks Management System developed using C++. It allows efficient management of student academic records with features like data storage, searching, sorting, and statistical analysis.

The system uses file handling to ensure persistent data storage and provides a structured menu-driven interface for user interaction.

---

## 🚀 Features

### 🔹 Student Record Management
- Add new student records
- Display all students with grades
- Search student by name
- Update existing student marks
- Delete student records

### 🔹 Data Processing
- Automatic grade calculation (A–F)
- Sort students by marks (highest first)

### 🔹 File Handling
- Save data to file (`students.txt`)
- Load data automatically on startup

### 🔹 Analytics & Reports
- Calculate:
  - Average marks
  - Highest marks
  - Lowest marks
- Export results to `report.txt`

---

## 🛠️ Tech Stack
- **Language:** C++
- **Concepts Used:**
  - Object-Oriented Programming (Structs)
  - File Handling (ifstream, ofstream)
  - STL (vector, algorithm)
  - Functions & Modular Design

---

## 🧠 Code Highlights

- Uses `vector<Student>` for dynamic data storage  
- Implements clean modular functions for each feature  
- Efficient searching and updating logic  
- Custom sorting using lambda function  
- Persistent storage using file handling  

---

## ▶️ How to Run

### 1. Compile the code
### 2. Run the program

---

## 📂 File Structure
student-marks-management-system-cpp
├── main.cpp
├── students.txt (auto-generated)
└── report.txt (exported results)

---

## 📷 Sample Functionalities

- Add student → Stores name & marks  
- Display → Shows grades automatically  
- Sort → Ranks students  
- Statistics → Shows avg, highest, lowest  
- Export → Generates report file  

---

## 🎯 Learning Outcomes

- Strong understanding of file handling in C++
- Practical use of STL (vector, sort)
- Implementation of real-world CRUD operations
- Improved problem-solving and logic building

---

## 🚀 Future Improvements

- Add GUI (using Qt or similar)
- Support multiple subjects per student
- Implement login/authentication system
- Store data using database instead of file

---

## 👨‍💻 Author
Developed as part of academic learning and self-practice to strengthen programming fundamentals.

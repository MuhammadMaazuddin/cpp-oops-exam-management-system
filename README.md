# 🎓 Exam Management System (OOP-Based Console Project)

A C++ console-based Exam Management System designed to demonstrate core **Object-Oriented Programming (OOP)** principles, such as **inheritance**, **encapsulation**, **modularity**, and **file I/O**, using a well-structured, class-driven architecture for managing exams, assignments, marks, and attendance for students and teachers.

## 👨‍💻 Author
**Muhammad Maazuddin Qureshi**  
BS Artificial Intelligence – FAST NUCES  
Roll No: 22i-1388

## 📌 Features

- Separate modes for **students** and **teachers**
- CSV-based **data storage and retrieval**
- Automated **assignment conduction** and **marking**
- Course-wise **attendance tracking**
- Dynamic **assignment generation** by instructors
- Secure **login** for both roles with password/email verification

---

## 🧠 OOP Concepts Used

| Concept           | Description |
|------------------|-------------|
| **Inheritance**  | All classes are structured in a hierarchical pattern, ensuring code reusability and clean architecture. |
| **Encapsulation**| Getter/setter methods are used for secure data access and manipulation. |
| **Abstraction**  | Complex logic for assignment conduction and file handling is encapsulated inside dedicated classes. |
| **Polymorphism** | Exam conduction supports different assignment types like MCQs, T/F, Descriptive, etc. |
| **Modularity**   | Classes are responsible for single tasks, promoting separation of concerns. |

---

## 🏗️ Class Architecture

```
                           +----------------------------+
                           |     Student (Base Class)   |
                           +----------------------------+
                                    |
                                    v
+------------------------+    +------------------------+
| Student_Registration   |    | Marks_and_Attendance   |
+------------------------+    +------------------------+
                                    |
                                    v
+------------------------+    +------------------------+
| Assignment_Conduction  |    | Assignment_In_Classes  |
+------------------------+    +------------------------+

Similarly for teachers:

                           +----------------------------+
                           |     Teacher (Base Class)   |
                           +----------------------------+
                                    |
                                    v
                      +-----------------------------+
                      | Teacher_Registration_Data   |
                      +-----------------------------+
```

---

## 🧑‍🏫 Teacher Mode

1. **Login with email & password**
2. Choose course and assignment type (MCQ, T/F, etc.)
3. Enter details: name, submission date, duration, question count
4. Assignment is created and saved to the course folder
5. A new entry is added to the respective CSV file (e.g., `PF.csv`)

---

## 🎓 Student Mode

1. **Login with email & password**
2. View registered courses
3. Choose to view marks or attempt assignment
4. Assignment conduction happens in real time
5. Marks & attendance are auto-uploaded to course CSV file

---

## 💾 Data Storage

- Each course has its own `.csv` file
- Assignments are stored as `.txt` files in course folders
- First few lines of files store metadata (date, duration, etc.)
- Student submissions and marks are recorded against their email

---

## 📁 Sample Files (Generated at Runtime)

```
/data/
 ├── PF.csv               # Stores marks & attendance for PF course
 ├── PF/
 │   ├── sample1.txt      # MCQ assignment uploaded by PF teacher
 │   └── sample2.txt      # Descriptive assignment
 └── AI.csv               # Stores data for AI course (if registered)
```

---

## ✅ Example Functionalities Demonstrated

- File handling (CSV/Plain Text)
- Dynamic assignment generation & evaluation
- MCQ, T/F, Descriptive question conduction
- Time-bound exams
- Late submission handling
- Student-specific views

---

## 🚀 How to Run

1. Clone the repo
2. Compile using your preferred C++ compiler
   ```bash
   g++ main.cpp -o exam_system
   ./exam_system
   ```
3. Follow the on-screen instructions for student/teacher login and interaction.

---

## 🏁 Conclusion

This project showcases a fully functional simulation of an **exam management system** through **clean OOP design**, demonstrating:
- Strong command over class hierarchies
- Effective use of file I/O and control structures
- Real-world implementation of inheritance and encapsulation


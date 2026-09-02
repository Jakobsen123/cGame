#include <iostream>
#include <string>
#include <vector>
#include <random>

struct courseStruct
{
    std::string name;
    std::string description;
    int maxStudents;
};

struct studentStruct
{
    std::string name;
    int age;
    int year;
    std::vector<courseStruct> Courses;
};

class Student
{
public:
    Student(studentStruct studentVar)
    {
        student = studentVar;
    };

    std::string getName() const {
        return student.name;
    }
    void enroll(Course course) {
        student.Courses.emplace_back(course);
    } 

private:
    studentStruct student;
};


class Course
{
public:
    Course(courseStruct courseVar) {
        course = courseVar;
    };

    bool checkStudentInCourse(const std::string& name) {
        for (const auto& student : entrolledStudents) {
            if (student.getName() == name) {
                return true;
            };
        }
        return false;
    }

    void EntrollStudent(Student student) {
        std::string name = student.getName();
        bool isInClass = checkStudentInCourse(name);
        if (isInClass) { std::cout << "Student " << name << " is already enrolled in the class." << std::endl; return; };
        addStudent(student);
        std::cout << "Student " << name << " has been added to course " << course.name << std::endl;
    }

private:
    courseStruct course;
    std::vector<Student> entrolledStudents;

    void addStudent(const Student& stud) {
        entrolledStudents.emplace_back(stud);
    }
};

int main()
{
    std::cin.get();
    return 0;
}
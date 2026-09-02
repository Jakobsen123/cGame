#include <iostream>
#include <string>
#include <vector>

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
};

class Course;

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
    void enroll(const Course& course) {
        Courses.emplace_back(course);
    } 

private:
    studentStruct student;
    std::vector<Course> Courses;
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

    void EnrollStudent(Student student) {
        std::string name = student.getName();
        bool isInClass = checkStudentInCourse(name);
        if (isInClass) { std::cout << "Student " << name << " is already enrolled in the class." << std::endl; return; };
        addStudent(student);
        std::cout << "Student " << name << " has been added to course " << course.name << std::endl;
    }

    std::string getName() {
        return course.name;
    }

private:
    courseStruct course;
    std::vector<Student> entrolledStudents;
    void addStudent(const Student& stud) {
        entrolledStudents.emplace_back(stud);
    }
};

    
class School 
{
    public:
        School(std::string nameVar) {
            name = nameVar;
        };

        void addStudent(const Student& student) {
            std::string name = student.getName();
            EnrolledStudents.emplace_back(student);
            std::cout << "Enrolled student " << name << " in " << name << std::endl;   
        };
        void addCourse(Course course) {
            std::string course_name = course.getName();
            Courses.emplace_back(course);
            std::cout << "Added course " << course_name << "." << std::endl;
        };
    private:
        std::string name;
        std::vector<Student> EnrolledStudents;
        std::vector<Course> Courses;
        
};

School Akademiet("Akademiet VGS");

int main()
{
    Student Matthias(studentStruct{
        .name = "Matthias",
        .age = 20,
        .year = 2
    });
    
    Student Eilert(studentStruct{
        .name = "Eilert",
        .age = 22,
        .year = 4
    });
    Student Sindre(studentStruct{
        .name = "Sindre",
        .age = 19,
        .year = 1
    });

    Course CS(courseStruct{
        .name = "Computer Science",
        .description = "How computers work",
        .maxStudents = 20
    });

    Course MP(courseStruct{
        .name = "Media Production",
        .description = "Produce media content",
        .maxStudents = 15
    });

    Akademiet.addCourse(CS);
    Akademiet.addCourse(MP);

    Akademiet.addStudent(Eilert);
    Akademiet.addStudent(Matthias);
    Akademiet.addStudent(Sindre);

    CS.EnrollStudent(Matthias);
    CS.EnrollStudent(Sindre);
    MP.EnrollStudent(Eilert);

    std::cin.get();
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

class Student;

class Course
{
public:
    Course(courseStruct courseVar) { course = courseVar; }

    bool checkStudentInCourse(const std::string &name)
    {
        return std::find(enrolledStudentNames.begin(), enrolledStudentNames.end(), name) != enrolledStudentNames.end();
    }

    std::string getName() const { return course.name; }

    std::vector<std::string> getEnrolledStudentNames() const { return enrolledStudentNames; }

    void EnrollStudent(Student &student);

private:
    courseStruct course;
    std::vector<std::string> enrolledStudentNames;
};

class Student
{
public:
    Student(studentStruct studentVar) { student = studentVar; }

    std::string getName() const { return student.name; }

    void enroll(const std::string &courseName) { studentCourseNames.push_back(courseName); }

    std::vector<std::string> getCourses() const { return studentCourseNames; }

private:
    studentStruct student;
    std::vector<std::string> studentCourseNames;
    void EnrollStudent(Student &student)
    {
        std::string name = student.getName();
        if (checkStudentInCourse(name))
        {
            std::cout << "Student " << name << " is already enrolled in the class." << std::endl;
            return;
        }
        enrolledStudentNames.push_back(name);
        student.enroll(course.name);
        std::cout << "Student " << name << " has been added to course " << course.name << std::endl;
    }
};

class School
{
public:
    School(std::string nameVar)
    {
        name = nameVar;
    };

    void addStudent(const Student &student)
    {
        std::string name = student.getName();
        EnrolledStudents.emplace_back(student);
        std::cout << "Enrolled student " << name << " in " << name << "\n";
    };
    void addCourse(Course course)
    {
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
        .year = 2});

    Student Eilert(studentStruct{
        .name = "Eilert",
        .age = 22,
        .year = 4});
    Student Sindre(studentStruct{
        .name = "Sindre",
        .age = 19,
        .year = 1});
    Student Erik(studentStruct{
        .name = "Erik",
        .age = 20,
        .year = 2});
    Student Petter(studentStruct{
        .name = "Petter",
        .age = 5,
        .year = 2});

    Course CS(courseStruct{
        .name = "Computer Science",
        .description = "How computers work",
        .maxStudents = 20});

    Course MP(courseStruct{
        .name = "Media Production",
        .description = "Produce media content",
        .maxStudents = 15});

    Akademiet.addCourse(CS);
    Akademiet.addCourse(MP);

    Akademiet.addStudent(Eilert);
    Akademiet.addStudent(Matthias);
    Akademiet.addStudent(Sindre);

    CS.EnrollStudent(Matthias);
    CS.EnrollStudent(Sindre);
    MP.EnrollStudent(Eilert);
    MP.EnrollStudent(Erik);
    MP.EnrollStudent(Petter);

    std::vector<std::string> ErikData = Erik.getCourses();
    for (const auto &courseName : ErikData)
    {
        std::cout << courseName << std::endl;
    }
    std::cin.get();
    return 0;
}
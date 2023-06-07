
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;
    int creditsCompleted;
    double cgpa;

public:
    Student(const std::string& name, int id, int creditsCompleted, double cgpa) {
        this->name = name;
        this->id = id;
        this->creditsCompleted = creditsCompleted;
        this->cgpa = cgpa;
    }

    std::string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    int getCreditsCompleted() const {
        return creditsCompleted;
    }

    double getCGPA() const {
        return cgpa;
    }
};

void rankStudents(Student* students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            // Compare credits completed
            if (students[j]->getCreditsCompleted() < students[j + 1]->getCreditsCompleted()) {
                // Swap students
                Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int MAX_STUDENTS = 5;
    Student* students[MAX_STUDENTS];

    std::string name;
    int id, creditsCompleted;
    double cgpa;

    // Input student information
    for (int i = 0; i < MAX_STUDENTS; i++) {
        std::cout << "Enter name of student " << i + 1 << ": ";
        std::cin >> name;

        std::cout << "Enter ID of student " << i + 1 << ": ";
        std::cin >> id;

        std::cout << "Enter credits completed by student " << i + 1 << ": ";
        std::cin >> creditsCompleted;

        std::cout << "Enter CGPA of student " << i + 1 << ": ";
        std::cin >> cgpa;

        students[i] = new Student(name, id, creditsCompleted, cgpa);
    }

    // Rank students
    rankStudents(students, MAX_STUDENTS);

    std::cout << "\nStudent Rankings:\n";
    std::cout << "-----------------\n";
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i]->getCreditsCompleted() >= 160) {
            std::cout << "Rank " << i + 1 << ":\n";
            std::cout << "Name: " << students[i]->getName() << "\n";
            std::cout << "ID: " << students[i]->getId() << "\n";
            std::cout << "Credits Completed: " << students[i]->getCreditsCompleted() << "\n";
            std::cout << "CGPA: " << students[i]->getCGPA() << "\n";
            std::cout << "-----------------\n";
        }
    }

    // Clean up memory
    for (int i = 0; i < MAX_STUDENTS; i++) {
        delete students[i];
    }

    return 0;
}

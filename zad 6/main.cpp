#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
	std::string imie;
	std::string nazwisko;
	int nr_albumu;
	int grupa;
	int rok;
	friend std::istream& operator>>(std::istream& is, Student& student) {
		is >> student.imie >> student.nazwisko >>
			student.nr_albumu >> student.grupa >> student.rok;
		return is;
	}

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.imie << " " << student.nazwisko
            << " " << student.nr_albumu << " " <<
            student.grupa << " " << student.rok;
        return os;
    }
};
int main() {

    std::vector<Student> students;

    std::ifstream inputFile("studenci.txt");
    if (inputFile.is_open()) {
        Student student;
        while (inputFile >> student) {
            students.push_back(student);
        }
        inputFile.close();
        std::cout << "Wczytano liste studentow z pliku." << std::endl;
    }
    else {
        std::cout << "Nie mo¿na otworzyc pliku do odczytu." << std::endl;
        return 1;
    }

    std::cout << "Pierwszy student na liscie: " << students[0] << std::endl;

    
    std::cout << "Lista studentow:" << std::endl;
    std::for_each(students.begin(), students.end(), [](const Student& student) {
        std::cout << student << std::endl;
        });

   
    int countThirdYear = std::count_if(students.begin(), students.end(), [](const Student& student) {
        return student.rok == 3;
        });
    std::cout << "Liczba studentow 3 roku: " << countThirdYear << std::endl;

    return 0;
}

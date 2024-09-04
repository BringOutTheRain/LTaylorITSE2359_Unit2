#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>


std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

using namespace std;

struct student {
    std::string name;
    int age;
    float gpa;
};

int main() {
    ifstream inputfile("studentdata.txt");
    if (!inputfile) {
        cerr << "No Input File" << endl;
        return -1;
    }


    map<string, student> studentMap;
    string line;


    while (getline(inputfile, line)) {
        istringstream iss(line);
        student Student;
        if (!(iss >> Student.name >> Student.age >> Student.gpa)) {
            cerr << "Error reading data from file" << endl;
            continue;
        }

        studentMap[toLower(Student.name)] = Student;
    }

    inputfile.close();


    cout << "All Student Data:" << endl;
    for (const auto& pair : studentMap) {
        const student& stu = pair.second;
        cout << "Name: " << stu.name << endl;
        cout << "Age: " << stu.age << endl;
        cout << "GPA: " << stu.gpa << endl;
        cout << "===============" << endl;
    }


    string searchName;
    cout << "Enter the name of the student to search for: ";
    getline(cin, searchName);


    string searchNameLower = toLower(searchName);


    auto it = studentMap.find(searchNameLower);
    if (it != studentMap.end()) {
        const student& foundStudent = it->second;
        cout << "Student found!" << endl;
        cout << "Name: " << foundStudent.name << endl;
        cout << "Age: " << foundStudent.age << endl;
        cout << "GPA: " << foundStudent.gpa << endl;
        cout << "===============" << endl;
    } else {
        cout << "Student with name " << searchName << " not found." << endl;
    }

    return 0;
}
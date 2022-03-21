#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Student {
    std::string name;
    std::string surname;
    int albumNumber;
    std::vector<float> grades;
public:
    Student(const std::string &name_, const std::string surname_, const int &albumNumber_, const std::vector <float> grades_ = {0.0}) {
        name = name_;
        surname = surname_;
        grades = grades_;
        if (albumNumber_ > 9999 && albumNumber_ < 1000000) {
            albumNumber = albumNumber_;
        }
        else cout<<"WRONG INPUT!"<<endl;
    }
    void setName(const std::string &name_) {
        name = name_;
    }
    void setSurname(const std::string &surname_) {
        surname = surname_;
    }
    void setAlbumNumber(const int &albumNumber_) {
        if (albumNumber_ > 9999 && albumNumber_<1000000) {
            albumNumber = albumNumber_;
        }
        else
            cout<<"WRONG INPUT!"<<endl;
    }
    void set_grades(const std::vector <float> grades_) {
        grades = grades_;
    }
    void printStudent() {
        std::cout << name << " " << surname << " " <<albumNumber;
        std::cout<<endl;
        for (auto grade : grades) {
            std::cout << grade << ", ";
        }
        std::cout<<std::endl << "MEAN GRADE = {" << mean_Grade() << "}" << std::endl;
        std::cout << std::endl;
    }
    bool add_grade(float grades_) {
        if (grades_ >= 2.0 && grades_ <= 5.0) {
            grades.push_back(grades_);
            return true;
        }
        else
            return false;
    }
    float mean_Grade() {
        float sum =  std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum/grades.size();

    }
    void pass_check() {
        int count = 0;
        for(auto grade :  grades)
            if (grade == 2.0) count++;
        if (mean_Grade() > 2.0 && count <= 1) {
            cout<<"YOU HAVE PASSED!" << endl;
        }
        else {
            cout<<"UNFORTUNATELY YOU HAVE FAILED!" << endl;
        }
    }
};

int main()
{
    string name;
    string surname;
    int albumNumber;
    vector<float> grades;
    float grade;

    cout<<"Enter student's first name"<< endl;
    cin>>name;
    cout<<"Enter student's surname"<< endl;
    cin>>surname;
    cout<<"Enter student's Album Number:" << endl;
    cin>>albumNumber;
    cout<<"Enter 5 grades:" << endl;
    for(int i = 1; i < 6; i++)
    {
        cout << i << " grade:" << endl;
        cin >> grade;
        grades.push_back(grade);
    }
    Student student(name, surname, albumNumber);
    student.set_grades(grades);
    student.printStudent();
    student.pass_check();
    return 0;
}

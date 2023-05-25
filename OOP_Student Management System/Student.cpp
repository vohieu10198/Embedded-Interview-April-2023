/*
* File Name: Student.cpp
* Author: Vo Minh Hieu
* Date: 25/05/2023
* Description: This program is used for student management purpose
*/

#include <stdio.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <stdint.h>

using namespace std;

typedef enum{
    Male,
    Female
}SexType;

typedef enum{
    Very_good,
    Good,
    Average_good,
    Below_average
}RankType;

/*
 * Function: Class Student
 * Description: The class represents the properties and methods of the student
 * Input:
 *    None
 * Output:
 *    None
*/

class Student{
    private:
    int _student_id;
    string _student_name;
    int _age;
    SexType _sex;
    float _math_mark;
    float _physics_mark;
    float _chemistry_mark;
    float _average_mark;
    RankType _academic_ranked;
    public:
    Student(string name, SexType sex, int age, float math, float physics, float chemistry);
    int getStudentID();
    void setStudentName(string name); //cần nhập vào tên
    string getStudentName();   // có thể lấy ra được
    void setStudentSex(SexType sex); //nhập giới tính
    SexType getStudentSex(); //lấy giới tính ra
    void setStudentAge(int age); //nhập tuổi
    int getStudentAge(); //lấy tuổi
    void setMathMark(float math); //nhập điểm toán
    float getMathMark(); //lấy điểm toán
    void setPhysicsMark(float physics); //nhập điểm toán lý
    float getPhysicsMark();  //lấy điểm lý
    void setChemistryMark(float chemistry); //nhập điểm toán hóa
    float getChemistryMark(); //lấy điểm hóa
    float getAverageMark();
    RankType getRankedAcademic();
};

/*
* Function: Constructor Student
* Description: import parameters to the object of the class HocSinh( name , gioiTinh, tuoi, diemtoan, diemly, diem hoa)
* Input:
*    name: string
*    sex: SexType
*    uint8_t: int
*    math: float
*    physic: float
*    chemistry: float
* Output:
*    None
*/

Student::Student(string name, SexType sex, int age, float math, float physics, float chemistry){
    static int id = 165;
    Student:: _student_id = id;
    id++;
    Student::_student_name = name;
    Student::_sex =sex;
    Student::_age = age;
    Student::_math_mark = math;
    Student::_physics_mark = physics;
    Student::_chemistry_mark = chemistry;
}

/*
 * Function: Student::getStudentID()
 * Description: get id for object
 * Input:
 *    _student_id: int
 * Output:
 *    none
*/

int Student::getStudentID(){
    return this->_student_id;
}

/*
 * Function: Student::setStudentName()
 * Description: set name for object
 * Input:
 *    name: string
 * Output:
 *    none
*/

void Student::setStudentName(string name){
    this->_student_name = name;
}

/*
 * Function: Student::getStudentName()
 * Description: use to get name
 * Input:
 *    none
 * Output:
 *    return student's name in type of string
*/

string Student::getStudentName(){
    return Student::_student_name;
}

/*
 * Function: Student::setStudentSex()
 * Description: set sex for object
 * Input:
 *    sex: SexType
 * Output:
 *    none
*/
void Student::setStudentSex(SexType sex){
    this->_sex = sex;
}

/*
 * Function: Student::getStudentSex()
 * Description: use to get sex
 * Input:
 *    none
 * Output:
 *    return sex in type of TypeGioiTinh
*/

SexType Student::getStudentSex(){
    return Student::_sex;
}

/*
 * Function: Student::setStudentAge()
 * Description: set age for object
 * Input:
 *    age: int
 * Output:
 *    none
*/

void Student::setStudentAge(int age){
    this->_age = age;
}

/*
 * Function: Student::getStudentAge()
 * Description: use to get age
 * Input:
 *    none
 * Output:
 *    return age in type of int
*/

int Student::getStudentAge(){
    return Student::_age;
}

/*
 * Function: Student::setMathMark()
 * Description: set math marks for object
 * Input:
 *   math : float
 * Output:
 *    none
*/
void Student::setMathMark(float math){
    this->_math_mark = math;
}

/*
 * Function: Student::setMathMark()
 * Description: use to get math scores
 * Input:
 *    none
 * Output:
 *    return math scores in type of float
*/
float Student::getMathMark(){
    return this->_math_mark;
}

/*
 * Function: Student::setMathMark()
 * Description: set math marks for object
 * Input:
 *   math : float
 * Output:
 *    none
*/
void Student::setPhysicsMark(float physics){
    this->_physics_mark = physics;
}

/*
 * Function: Student::setPhysicsMark()
 * Description: use to get math scores
 * Input:
 *    none
 * Output:
 *    return physics marks in type of float
*/
float Student::getPhysicsMark(){
    return this->_physics_mark;
}

/*
 * Function: Student::setMathMark()
 * Description: set chemistry marks for object
 * Input:
 *   chemistry : float
 * Output:
 *    none
*/
void Student::setChemistryMark(float chemistry){
    this->_chemistry_mark = chemistry;
}

/*
 * Function: Student::getChemistryMark()
 * Description: use to get chemistry scores
 * Input:
 *    none
 * Output:
 *    return chemistry marks in type of float
*/
float Student::getChemistryMark(){
    return this->_chemistry_mark;
}


/*
 * Function: Student::getAverageMark()
 * Description: use to get average scores of 3 subjects
 * Input:
 *    none
 * Output:
 *    return average mark of 3 subjects in type of float
*/

float Student::getAverageMark(){
    return ((_math_mark + _physics_mark + _chemistry_mark)/3);
}

RankType Student::getRankedAcademic(){
    if (getAverageMark() >= 8){
        return Very_good;
    }
    else if (getAverageMark() < 8 && getAverageMark() >= 6.5){
        return Good;
    }
    else if (getAverageMark() < 6.5 && getAverageMark() >= 5){
        return Average_good;
    }
    else{
        return Below_average;
    }
    
}

/*
 * Class Menu
 * Description: The class represents the properties and methods of the menu
 * Input:
 *    None
 * Output:
 *    None
*/

class Menu{
    private:
    vector<Student> Database;
    public:
    Menu();
    void addStudent(); //done
    void updateInfo();
    void deleteStudentById();
    void searchStudentName();
    void arrangeByGPA(); //done
    void arrangeByName(); //done
    void displayStudentList(); //done

};

Menu::Menu(){
    int user_selection = 0;
    cout << "Student Management System" << endl;
    cout << "1. Add new student" << endl;
    cout << "2. Update student's information" << endl;
    cout << "3. Delete student by their ID" << endl;
    cout << "4. Search student by their name" << endl;
    cout << "5. Arrange student list by their GPA" << endl;
    cout << "6. Arrange student list by their name" << endl;
    cout << "7. Student list" << endl;
    cout << "8. Exit" << endl;

    cout << "Enter your selection: " << endl;
    
    do{
        if (user_selection == 8) break;
        if (user_selection <=0 || user_selection > 7){
            cout << "Re-enter your selection!!!" << endl;
            user_selection = 0;
            cin >> user_selection;
        }
        switch (user_selection){
            case 1:
                Menu::addStudent();
                break;
            case 2:
                Menu::updateInfo();
                break;
            case 3:
                Menu::deleteStudentById();
                break;
            case 4:
                Menu::searchStudentName();
                break;
            case 5:
                Menu::arrangeByGPA();
                break;
            case 6:
                Menu::arrangeByName();
                break;
            case 7:
                Menu::displayStudentList();
                break;
            default:
            break;
        }

    }
    while(user_selection != 8);
    
}

/*
* Class: Menu
* Function: addStudent
* Description: This function use for adding student to database
* Input: none
* Output:
*   return: none
*/

void Menu::addStudent(){
    string name;
    string s_sex;
    SexType sex;
    RankType ranked;
    int age;
    float math;
    float physics;
    float chemistry;
    
    cout << "Enter student information" << endl;
    cout << "Name:..." << endl;
    cin >> name;
    cout << "Age:..." << endl;
    cin >> age;
    cout << "Sex(Male/Female):..." << endl; 
    cin >> s_sex;

    if (s_sex == "Male") sex = Male;
    else if(s_sex == "Female") sex = Female;

    cout << "Maths Mark: "; 
    cin >> math; 
    while (math < 0 || math > 10)
    {
        cout <<"Re-enter Math mark"<<endl << "Math Mark: "; 
        cin >> math;
    }

    cout << "Physics Mark: "; 
    cin >> math; 
    while (physics < 0 || physics > 10)
    {
        cout <<"Re-enter Physics mark"<<endl << "Physic Mark: "; 
        cin >> physics;
    }

    cout << "Chemistry Mark: "; 
    cin >> chemistry; 
    while (chemistry < 0 || chemistry > 10)
    {
        cout <<"Re-enter Chemistry mark"<<endl << "Chemistry Mark: "; 
        cin >> chemistry;
    }
    Student st(name, sex, age, math, physics, chemistry);
    Database.push_back(st);

}

/*
* Class: Menu
* Function: displayStudentList
* Description: This function use for displaying the list of student
* Input: none
* Output:
*   return: none
*/

void Menu::displayStudentList(){
    for (Student st : Database){
        string s_sex;
        string s_ranked;
        string name = st.getStudentName();
        if(st.getStudentSex() == Male) s_sex = "Male";
        else s_sex = "Female";

        if(st.getRankedAcademic() == Very_good) s_ranked = "Very Good";
        else if(st.getRankedAcademic() == Good) s_ranked ="Good";
        else if(st.getRankedAcademic() == Average_good) s_ranked = "Average Good";
        else s_ranked = "Below Average"; 


        cout << "ID: "<< st.getStudentID() << endl;
        cout << "Name: "<< st.getStudentName() << endl;
        cout << "Age: " << st.getStudentAge() << endl;
        cout << "Sex: " << st.getStudentSex() << endl;
        cout << "Math: " << st.getMathMark() << endl;
        cout << "Physics: " << st.getPhysicsMark() << endl;
        cout << "Chemistry: " << st.getChemistryMark() << endl;
        cout << "GPA: " << st.getAverageMark() << endl;
        cout << "Academic Ranked: " << st.getRankedAcademic() << endl;
        
    }
    
}

/*
* Class: Menu
* Function: arrangeByGPA
* Description: This function use for arranging student by their GPA
* Input: none
* Output:
*   return: none
*/

void Menu::arrangeByGPA(){
    int length = Database.size();
    for(int i = 0; i < length; i++){
        for (int j = i+1 ; j < length; j++){
            if (Database[i].getAverageMark() > Database[j].getAverageMark()){
                    Database.push_back(Database[i]);
                    Database[i] = Database[j];
                    Database[j] = Database[length];
                    Database.pop_back();
                    
            }
        }
    }
}

/*
* Class: Menu
* Function: arrangeByName
* Description: This function use for arranging student by their name
* Input: none
* Output:
*   return: none
*/


void Menu::arrangeByName(){
    int length = Database.size();
    for(int i = 0; i < length; i++){
        for (int j = i+1 ; j < length; j++){
            if (Database[i].getStudentName() > Database[j].getStudentName()){
                    Database.push_back(Database[i]);
                    Database[i] = Database[j];
                    Database[j] = Database[length];
                    Database.pop_back();
            }
        }
    }
}

void Menu::deleteStudentById(){
    int id;
    bool check = false;
    cout << "Enter Student ID that you want to delete" << endl;
    cin >> id;


}

void Menu::searchStudentName(){

}


void Menu::updateInfo(){

}
int main(int argc, char const *argv[])
{

    Menu ();
    return 0;
}



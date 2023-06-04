#include <iostream>
#include <variant>
#include <vector>

using namespace std;

struct Student {
    string name;
    int classNum;
    string classString;
    string want;
    string is;
};

vector<int> countStudents(vector<Student> students) {
    int wantTen = 0, wantT = 0, wantU = 0, isTen = 0, isT = 0, isU = 0;

    for (const auto& st : students) {
        if (st.want == "техникум")
            wantT++;
        if (st.want == "училище")
            wantU++;
        if (st.want == "10 класс")
            wantTen++;

        if (st.is == "техникум")
            isT++;
        if (st.is == "училище")
            isU++;
        if (st.is == "10 класс")
            isTen++;
    }

    vector<int> result = { wantTen, wantT, wantU, isTen, isT, isU };

    return result;
}

int countTenClass(vector<int> countStudents) {
    int count = 0, flag = 0, classSize = 10;
    int wantTen = countStudents[2];

    do {
        if (wantTen > classSize)
            wantTen -= 10;
        else
            wantTen -= wantTen;
        count++;
    } while (wantTen > classSize);


    return count;
}

int main()
{
    setlocale(LC_ALL, "ru");
    vector<Student> students = {
        {"Анастасия", 9, "A", "техникум", "училище"},
        {"Ира", 9, "Б", "10 класс", "техникум"},
        {"Максим", 9, "В", "училище", "10 класс"},
        {"Дмитрий", 9, "A", "училище", "техникум"},
        {"Вячеслав", 9, "Б", "10 класс", "10 класс"},
        {"Ксения", 9, "В", "техникум", "10 класс"},
        {"Марина", 9, "A", "10 класс", "училище"},
        {"Александр", 9, "Б", "училище", "техникум"},
        {"Светлана", 9, "A", "10 класс", "техникум"},
        {"Виктория", 9, "Б", "училище", "училище"},
        {"Дмитрий", 9, "A", "техникум", "10 класс"},
        {"Георгий", 9, "В", "училище", "техникум"},
        {"Евгений", 9, "A", "училище", "училище"},
        {"Екатерина", 9, "Б", "10 класс", "техникум"},
        {"Егор", 9, "A", "техникум", "техникум"},
        {"Майа", 9, "Б", "училище", "техникум"},
        {"Даниил", 9, "A", "техникум", "училище"},
        {"Данияр", 9, "Б", "10 класс", "10 класс"},
        {"Петр", 9, "A", "училище", "техникум"},
        {"Владимир", 9, "Б", "техникум", "техникум"},
        {"Люкан", 9, "A", "10 класс", "10 класс"},
        {"Лука", 9, "В", "техникум", "училище"},
        {"Энакен", 9, "В", "10 класс", "10 класс"},
        {"Николай", 9, "Б", "техникум", "10 класс"},
        {"Бен", 9, "В", "техникум", "техникум"},
        {"Тайлер", 9, "В", "училище", "техникум"} };

    vector<int> studentsCount = countStudents(students);
    int classCount = countTenClass(studentsCount);

    cout << "Хотели в 10 класс: " << studentsCount[0] << ". Поступили в 10 класс: " << studentsCount[3] << endl;
    cout << "Хотели в техникум: " << studentsCount[1] << ". Поступили в техникум: " << studentsCount[4] << endl;
    cout << "Хотели в училище: " << studentsCount[2] << ". Поступили в училище: " << studentsCount[5] << endl;
    cout << "Кол-во 10 классов: " << classCount << endl;

}

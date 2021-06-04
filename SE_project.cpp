#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Admin
{
private:
    bool admin = true;
    string name;
    string login;
    string password;
public:
    Admin(string nameTmp, string loginTmp, string passwordTmp)
    {
        name = nameTmp;
        login = loginTmp;
        password = passwordTmp;
    }
    string getLogin() { return login; }
    string getPassword() { return password; }
    void addSubject(ofstream &base) 
    {
        string tmp;
        cout << "Введiть назву предмету:" << endl;
        getline(cin, tmp);
        getline(cin, tmp);
        base << endl << tmp << endl;
        cout << "Введiть дату проведення пари в форматi число.мiсяць:" << endl;
        getline(cin, tmp);
        base << tmp << endl;
        cout << "Введiть прiзвище, iм'я, побатьковi викладача:" << endl;
        getline(cin, tmp);
        base << tmp << endl;
        cout << "Введiть аудеторiю:" << endl;
        getline(cin, tmp);
        base << tmp;
    }
};

class Subject
{
private:
    string name;
    string teacher;
    string auditor;
    string date;
public:
    string getName() { return name; }
    string getTeacher() { return teacher; }
    string getAuditor() { return auditor; }
    string getDate() { return date; }
    void setName(string nameT) { name = nameT; }
    void setTeacher(string teacherT) { teacher = teacherT; }
    void setAuditor(string auditorT) { auditor = auditorT; }
    void setDate(string dateT) { date = dateT; }
    void print()
    {
        cout << getName() << endl;
        cout << getTeacher() << endl;
        cout << getAuditor() << endl;
        cout << getDate() << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choise, counter = 0, n = 0;
    int ch = 1;
    char str[1024];
    Admin user("danil", "danil228", "11111111");
    string auditor, date, teacher, login, password, tmp;
    ifstream based("Table.txt");
    if (!based.is_open())
        cout << "Не найдена БД" << endl;
    while (getline(based, tmp))
    {
        counter++;
    }
    based.close();
    bool* count = new bool[counter / 4];
    bool* t = new bool[counter / 4];
    for (int i = 0; i < counter / 4; i++)
    {
        count[i] = true;
        t[i] = true;
    }

    while(ch == 1){
        counter = 0;
         based.open("Table.txt");
        if (!based.is_open())
            cout << "Не найдена БД" << endl;
        while (getline(based, tmp))
        {
            counter++;
        }
        based.close();
        Subject* subject = new Subject[counter / 4];
        ifstream base("Table.txt");
        for (int i = 0; i < counter / 4; i++)
        {
            getline(base, tmp);
            subject[i].setName(tmp);
            getline(base, tmp);
            subject[i].setDate(tmp);
            getline(base, tmp);
            subject[i].setTeacher(tmp);
            getline(base, tmp);
            subject[i].setAuditor(tmp);
        }
        base.close();
        system("cls");
        cout << "Оберiть що саме вам необхiдно:" << endl;
        cout << "1)Переглянути заняття в аудиторiї" << endl;
        cout << "2)Переглянути заняття у викладача" << endl;
        cout << "3)Переглянети всi заняття по датi" << endl;
        cout << "4)Авторизуватись як адмiнiстратор для додавання пари у росклад" << endl;
        choise = getchar();



        switch (choise)
        {
        case '1':
            cout << "Введiть назву аудиторiї:" << endl;
            cin >> auditor;
            cout << "Введiть дату(В форматi число.мiсяць):" << endl;
            cin >> date;
            system("cls");
            for (int i = 0; i < counter / 4; i++)
            {
                for (int j = 0; j < auditor.size() - 1 || j < (subject[i].getAuditor()).size() - 1; j++)
                {

                    if (auditor[j] != (subject[i].getAuditor())[j])
                    {
                        //cout << "Такой аудитории не найдено!" << (subject[i].getAuditor())[j] << auditor[j]  << endl;
                        count[i] = false;
                        break;
                    }
                }
            }
            for (int i = 0; i < counter / 4; i++)
            {
                if (count[i])
                {
                    for (int j = 0; j < date.size() - 1 || j < (subject[i].getDate()).size() - 1; j++)
                    {
                        if (date[j] != (subject[i].getDate())[j])
                        {
                            //cout << "Такой даты не найдено!" << subject[i].getDate()<< date << endl;
                            count[i] = false;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < counter / 4; i++)
            {
                if (count[i])
                {
                    subject[i].print();
                    cout << endl;
                }
                else
                    count[i] = true;
            }
            cout << "Якщо хочете продовжити натисныть 1, якщо хочете закiнчити 0" << endl;
            cin >> ch;

            break;
        case '2':
            cout << "Введiть прiзвище, iм'я та побатьковi викладача: " << endl;
            getline(cin, teacher);
            getline(cin, teacher);
            cout << "Введiть дату(В форматi число.мiсяць):" << endl;
            cin >> date;
            system("cls");
            for (int i = 0; i < counter / 4; i++)
            {
                for (int j = 0; j < teacher.size() - 1 || j < (subject[i].getTeacher()).size() - 1; j++)
                {

                    if (teacher[j] != (subject[i].getTeacher())[j])
                    {
                        //cout << "Такого викладача не найдено!" << teacher << subject[i].getTeacher() << endl;
                        count[i] = false;
                        break;
                    }
                }
            }
            for (int i = 0; i < counter / 4; i++)
            {
                if (count[i])
                {
                    for (int j = 0; j < date.size() - 1 || j < (subject[i].getDate()).size() - 1; j++)
                    {
                        if (date[j] != (subject[i].getDate())[j])
                        {
                            //cout << "Такой даты не найдено!" << endl;
                            count[i] = false;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < counter / 4; i++)
            {
                if (count[i])
                {
                    subject[i].print();
                    cout << endl;
                }
                else
                    count[i] = true;
            }
            cout << "Якщо хочете продовжити натисныть 1, якщо хочете закiнчити 0" << endl;
            cin >> ch;

            break;
        case '3':
            cout << "Введiть дату(В форматi число.мiсяць):" << endl;
            cin >> date;
            system("cls");
            for (int i = 0; i < counter / 4; i++)
            {
                for (int j = 0; j < date.size() - 1 || j < (subject[i].getDate()).size() - 1; j++)
                {

                    if (date[j] != (subject[i].getDate())[j])
                    {
                        //cout << "Такой дати не найдено!" << endl;
                        count[i] = false;
                        break;
                    }
                }
            }
            for (int i = 0; i < counter / 4; i++)
            {
                if (count[i])
                {
                    subject[i].print();
                    cout << endl;
                }
                else
                    count[i] = true;
            }
            cout << "Якщо хочете продовжити натисныть 1, якщо хочете закiнчити 0" << endl;
            cin >> ch;

            break;
        case '4':
            cout << "Введiть логiн:" << endl;
            cin >> login;
            cout << "Введiть пароль:" << endl;
            cin >> password;
            if (login == user.getLogin() && password == user.getPassword())
            {
                cout << "Авторизция пройшла успiшно" << endl;
                cout << "Додвання пари:" << endl;
                ofstream baze("Table.txt", ios::app);
                user.addSubject(baze);
                cout << "Пара додана!" << endl;
                cout << "Натиснiть будь яку клавiшу" << endl;
                getchar();
                baze.close();
            }
            else {
                cout << "Логин или пароль был введен неверно" << endl;
            }
            cout << "Якщо хочете продовжити натисныть 1, якщо хочете закiнчити 0" << endl;
            cin >> ch;

            break; 
        default:
                break;
        }
    }
        

    
}


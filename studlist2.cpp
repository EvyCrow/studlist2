#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
public:
    string namen;
    string datum;
    int noten[8];
    int kurse;
    int einheit;
};


int main()
{
    setlocale(LC_ALL, "rus");

    int chek = 1;
    while (chek == 1)
    {
        cout << "Введите 1 для запуска, 0 для выхода >";
        cin >> chek;
        switch (chek)
        {
        case(0):
            break;
        case(1):
        {
            int leng = 0;
            string s;
            ifstream fle("input.txt");
            while (getline(fle, s))
            {
                leng += 1; //подсчет строк в файле
            }
            Student* list = new Student[leng];
            int a = 0;

            fle.close();
            ifstream file("input.txt");

            string ss, buff;
            while (getline(file, s))
            {
                buff.assign(s);
                list[a].kurse = buff[0] - '0';
                buff.erase(0, 2);

                ss += buff[0];
                ss += buff[1];
                list[a].einheit = stoi(ss);
                ss.clear();
                buff.erase(0, 3);

                for (int i = 0; i < 10; i++)
                    list[a].datum += buff[i];
                buff.erase(0, 11);

                int kk = 0;
                for (int i = 0; i < 15; i++)
                {
                    if (buff[i] != ' ')
                    {
                        list[a].noten[kk] = buff[i] - '0';
                        kk += 1;
                    }
                }

                buff.erase(0, 16);
                list[a].namen.assign(buff);
                a += 1;
                buff.clear();
            }

            file.close();

            float max1 = 0, max2 = 0, max3 = 0, max4 = 0, max5 = 0;
            float min1 = 8888, min2 = 8888, min3 = 8888, min4 = 8888, min5 = 8888;
            int ma1 = 0, ma2 = 0, ma3 = 0, ma4 = 0, ma5 = 0;
            int mi1 = 0, mi2 = 0, mi3 = 0, mi4 = 0, mi5 = 0;
            float aver = 0;

            for (int i = 0; i < leng; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    aver += list[i].noten[j];
                }
                aver = aver / 8;

                switch (list[i].kurse)
                {
                case(1):
                {
                    if (aver > max1)
                    {
                        max1 = aver;
                        ma1 = i;
                        break;
                    }
                    if (aver < min1)
                    {
                        min1 = aver;
                        mi1 = i;
                        break;
                    }
                }
                case(2):
                {
                    if (aver > max2)
                    {
                        max2 = aver;
                        ma2 = i;
                        break;
                    }
                    if (aver < min2)
                    {
                        min2 = aver;
                        mi2 = i;
                        break;
                    }
                }
                case(3):
                {
                    if (aver > max3)
                    {
                        max3 = aver;
                        ma3 = i;
                        break;
                    }
                    if (aver < min3)
                    {
                        min3 = aver;
                        mi3 = i;
                        break;
                    }
                }
                case(4):
                {
                    if (aver > max4)
                    {
                        max4 = aver;
                        ma4 = i;
                        break;
                    }
                    if (aver < min4)
                    {
                        min4 = aver;
                        mi4 = i;
                        break;
                    }
                }
                case(5):
                {
                    if (aver > max5)
                    {
                        max5 = aver;
                        ma5 = i;
                        break;
                    }
                    if (aver < min5)
                    {
                        min5 = aver;
                        mi5 = i;
                        break;
                    }
                }
                }
                aver = 0;
            }

           cout << "Худший средний балл по курсам:" << endl;
            cout << "Первый курс >" << min1 << "  <<  " << list[mi1].namen << endl;
            cout << "Второй курс >" << min2 << "  <<  " << list[mi2].namen << endl;
            cout << "Третий курс >" << min3 << "  <<  " << list[mi3].namen << endl;
            cout << "Четвертый курс >" << min4 << "  <<  " << list[mi4].namen << endl;
            cout << "Пятый курс >" << min5 << "  <<  " << list[mi5].namen << endl;
            cout << "----------------------" << endl;
            cout << "Лучший средний балл по курсам:" << endl;
            cout << "Первый курс >" << max1 << "  <<  " << list[ma1].namen << endl;
            cout << "Второй курс >" << max2 << "  <<  " << list[ma2].namen << endl;
            cout << "Третий курс >" << max3 << "  <<  " << list[ma3].namen << endl;
            cout << "Четвертый курс >" << max4 << "  <<  " << list[ma4].namen << endl;
            cout << "Пятый курс >" << max5 << "  <<  " << list[ma5].namen << endl; 

            continue;
        }
        default:
        {
            cout << "Ошибка ввода" << endl;
            continue;
        }
        }
    }

}

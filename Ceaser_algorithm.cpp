

#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

//char charCpy(char arrFrom[], char arrTo[]) {
//    for (size_t i = 0; i < sizeof(arrFrom); i++)
//    {
//        arrTo[i] = arrFrom[i];
//    }
//    return arrTo;
//}
string ceasarFoo(string str, int lang, int k) {
    char arr[] = {'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю','Я'};
    char arreng[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','а','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char buf[100];
    strcpy_s(buf, str.c_str());
    for (int i = 0; i < strlen(buf); i++) {
        for (int j = 0; j < sizeof(arr); j++) {
            if (buf[i] == arr[j]) {
                if (j + k >= sizeof(arr)) {
                    int newPos = j + k - sizeof(arr);
                    buf[i] = arr[newPos];
                    break;
                }
                else {
                    buf[i] = arr[j + k];
                    break;
                }
            }
        }
    }
    string result;
    result = string(buf);
    return result;
}

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Russian_Russia.866");
    setlocale(LC_CTYPE, ".1251");
    int lang;
    cout << "Выберите язык шифра:" << "\n 1 - Русский" << "\n 2 - Английский" << endl;
    cin >> lang;
    int k = 0;
    cout << "Введите ключ ";
    cin >> k;
    string str, result;
    cout << "Введите данные для шифровки - ";
    for (int i = 0; i < 3; i++) {
        cin >> str;
        result += ceasarFoo(str, lang, k) + " ";
    }
    cout << "Result: " << result << endl;

    return 0;
}


#include "../include/martix.h"

using namespace std;

const int MENU_LEN {5};

void print_menu() {
    system("clear");
    cout << "Выберите опцию" << endl;
    cout << "1. Пересоздать матрицу" << endl;
    cout << "2. Вывести матрицу" << endl;
    cout << "3. Проверить, равны ли главная и побочная диагонали" << endl;
    cout << "4. Вывести минимальный элемент в чётных столбцах" << endl;
    cout << "5. Вывести минимальный элемент под главной диагональю" << endl;
    cout << "0. Выход" << endl << endl;
}


int get_value()
{
    int value{-1};
    while (not (cin >> value) or (value < 0) or (value > MENU_LEN))
    {
        cin.clear();
        cin.ignore();
        cout << "Вы ввели неверное значение!" << endl;
    }
    return value;
}

int main() {

    std::array<std::array<int, 17>, 17> arr{};
    Matrix matrix;
    int value{1};
    while (value) {

        print_menu();
        value = get_value();

        switch (value) {
            case 1:
                matrix.generate_array();
                break;
            case 2:
                matrix.print_array();
                break;
            case 3:
                cout << (matrix.are_main_and_secondary_diagonals_equal() ? "Совпадают": "Не совпадают") << endl;
                break;
            case 4:
                cout << matrix.get_max_elem_in_even_columns() << endl;
                break;
            case 5:
                cout << matrix.get_min_element_beneath_main_diagonal() << endl;
                break;
            default:
                break;
        }
        if (value) {
            system("read -rsp $'Press enter to continue...\\n'");
        }
    }
    return 0;
}

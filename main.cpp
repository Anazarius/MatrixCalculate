#include <iostream>
#include <vector>
using namespace std;

void soloMatrix() {
    int m,n=0;
    cout << "Введите размер матрицы (ex. 2 3)" << endl;
    cin >> m >> n;
    int matrix[m][n];
    char operation;
    cout << "Введите матрицу (ex. 1 2 3\n"
            "                     4 5 6)" << endl;
    for (int i =0; i <m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Введите операцию (ex. *,/)" << endl;
    cin >> operation;
    switch (operation) {
        case '*': {
            cout << "Введите число, на которое будут умножены элементы матрицы" << endl;
            int multi = 0;
            cin >> multi;
            cout << "Итоговая матрица" << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matrix[i][j] * multi << " ";
                }
                cout << endl;
            }
            break;
        }
        case '/': {
            cout << "Введите число, на которое будут разделены элементы матрицы" << endl;
            int division = 0;
            cin >> division;
            cout << "Итоговая матрица" << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matrix[i][j] / division << " ";
                }
                cout << endl;
            }
            break;
        }
        default:
            cout << "ERROR" << endl;
            break;
    }
}
void manyMatrix(int matrixCount) {
    vector<vector<vector<int>>> matrices;
    int m,n =0;
    for (int i = 1; i <= matrixCount; i++) {
        cout << "Введите размер " << i << " матрицы (ex. 2 3)" << endl;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));

        cout << "Введите матрицу (ex. 1 2 3\n"
                "                     4 5 6)" << endl;
        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        matrices.push_back(matrix);
    }

    cout << "Введите операцию (ex. +,-,*)" << endl;
    char operation;
    cin >> operation;
    switch (operation) {
        case '+': {
            bool valid = true;
            for (int i = 1; i < matrixCount; i++) {
                if (matrices[i].size() != matrices[0].size() || matrices[i][0].size() != matrices[0][0].size()) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                cout << "Все матрицы должны быть одного размера для выполнения сложения." << endl;
                return;
            }
            vector<vector<int>> resultMatrix(matrices[0].size(), vector<int>(matrices[0][0].size(), 0));
            for (int i = 0; i < matrixCount; i++) {
                for (int row = 0; row < matrices[i].size(); row++) {
                    for (int col = 0; col < matrices[i][row].size(); col++) {
                        resultMatrix[row][col] += matrices[i][row][col];
                    }
                }
            }
            cout << "Результат сложения матриц:" << endl;
            for (int row = 0; row < resultMatrix.size(); row++) {
                for (int col = 0; col < resultMatrix[row].size(); col++) {
                    cout << resultMatrix[row][col] << " ";
                }
                cout << endl;
            }
            break;
        }
        case '-': {
            bool valid = true;
            for (int i = 1; i < matrixCount; i++) {
                if (matrices[i].size() != matrices[0].size() || matrices[i][0].size() != matrices[0][0].size()) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                cout << "Все матрицы должны быть одного размера для выполнения вычитания." << endl;
                return;
            }
            vector<vector<int>> resultMatrix = matrices[0];
            for (int i = 1; i < matrixCount; i++) {
                for (int row = 0; row < matrices[i].size(); row++) {
                    for (int col = 0; col < matrices[i][row].size(); col++) {
                        resultMatrix[row][col] -= matrices[i][row][col];
                    }
                }
            }
            cout << "Результат вычитания матриц:" << endl;
            for (int row = 0; row < resultMatrix.size(); row++) {
                for (int col = 0; col < resultMatrix[row].size(); col++) {
                    cout << resultMatrix[row][col] << " ";
                }
                cout << endl;
            }

            break;
        }
        case '*': {
            bool valid = true;
            for (int i = 1; i < matrixCount; i++) {
                if (matrices[i].size() != matrices[0].size() || matrices[i][0].size() != matrices[0][0].size()) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                cout << "Все матрицы должны быть одного размера для выполнения умножения." << endl;
                return;
            }
            vector<vector<int>> resultMatrix = matrices[0];
            for (int i = 1; i < matrixCount; i++) {
                for (int row = 0; row < matrices[i].size(); row++) {
                    for (int col = 0; col < matrices[i][row].size(); col++) {
                        resultMatrix[row][col] *= matrices[i][row][col];
                    }
                }
            }
            cout << "Результат умножения матриц:" << endl;
            for (int row = 0; row < resultMatrix.size(); row++) {
                for (int col = 0; col < resultMatrix[row].size(); col++) {
                    cout << resultMatrix[row][col] << " ";
                }
                cout << endl;
            }

            break;
        }
        default:
            cout << "ERROR" << endl;
            break;
    }
}
int main() {
    setlocale(LC_ALL, "RU");
    cout << "Введите количество матриц (ex. 2)" << endl;
    int matrixCount = 0;
    cin >> matrixCount;
    if (matrixCount <= 0) {
        cout << "Нельзя производить операции с " << matrixCount << " количеством матриц" << endl;
        return 0;
    } else {
        switch (matrixCount) {
        case 1:
            soloMatrix();
            break;
        default:
            manyMatrix(matrixCount);
        }
    }
    return 0;
}
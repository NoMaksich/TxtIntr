#include <iostream>
#include <string>
#include <vector>

using namespace std;

double proizv(vector<double> operands) {
    double result = 1.0;
    for (double operand : operands) {
        result *= operand;
    }
    return result;
}

double delenie(vector<double> operands) {
    double result = operands[0];
    for (int i = 1; i < operands.size(); i++) {
        if (operands[i] == 0.0) {
            cout << "Нельзя делить на 0" << endl;
            return 0;
        }
        result /= operands[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 6) {
        cout<<"Недостаточно параметров"<<endl;
        return 1;
    }

    if (argc > 8) {
        cout<<"Много параметров"<<endl;
        return 1;
    }

    string operation = argv[2];
    vector<double> operands;

    for (int i = 3; i < argc; ++i) {
        double operand = stod(argv[i]);
        operands.push_back(operand);
    }

    double result;

    if (operation == "multiply") {
        result = proizv(operands);
    } else if (operation == "divide") {
        result = delenie(operands);
    } else {
        cout << "Неизвестная операция" << endl;
        return 1;
    }

    cout << "Результат: " << result << endl;
    return 0;
}
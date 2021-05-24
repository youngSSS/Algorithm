#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long calculate_numbers(vector<long long> numbers, vector<string> operators, vector<string> operator_priority) {
    int prio_idx = 0;

    while (numbers.size() != 1) {

        for (int i = 0; i < operators.size(); i++) {
            if (operators[i] == operator_priority[prio_idx]) {
                if (operators[i] == "+") numbers[i] = numbers[i] + numbers[i + 1];
                else if (operators[i] == "-") numbers[i] = numbers[i] - numbers[i + 1];
                else if (operators[i] == "*") numbers[i] = numbers[i] * numbers[i + 1];

                numbers.erase(numbers.begin() + (i + 1));
                operators.erase(operators.begin() + i);

                i -= 1;
            }
        }

        prio_idx += 1;
    }

    return numbers[0];
}

long long solution(string expression) {
    long long answer = 0;
    int start_idx = 0, end_idx = 0;

    vector<long long> numbers;
    vector<string> operators;

    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            string num, oper;

            num = expression.substr(start_idx, end_idx - start_idx);
            oper = expression[i];
            start_idx = i + 1;

            numbers.push_back(stoi(num));
            operators.push_back(oper);
        }

        end_idx += 1;
    }

    numbers.push_back(stoi(expression.substr(start_idx, end_idx - start_idx)));

    long long temp;

    temp = abs(calculate_numbers(numbers, operators, {"+", "-", "*"}));
    answer = answer < temp ? temp : answer;

    temp = abs(calculate_numbers(numbers, operators, {"+", "*", "-"}));
    answer = answer < temp ? temp : answer;

    temp = abs(calculate_numbers(numbers, operators, {"-", "+", "*"}));
    answer = answer < temp ? temp : answer;

    temp = abs(calculate_numbers(numbers, operators, {"-", "*", "+"}));
    answer = answer < temp ? temp : answer;

    temp = abs(calculate_numbers(numbers, operators, {"*", "+", "-"}));
    answer = answer < temp ? temp : answer;

    temp = abs(calculate_numbers(numbers, operators, {"*", "-", "+"}));
    answer = answer < temp ? temp : answer;

    return answer;
}

int main() {
    cout << solution("100-200*300-500+20");
}
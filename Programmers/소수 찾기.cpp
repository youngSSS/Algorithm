#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> Sieve;
int answer = 0;

void sieveOfEratosthenes() {
    int sieve[10000000];

    for (int i = 2; i < 10000000; i++)
        sieve[i] = i;

    for (int i = 2; i < 10000000; i++) {
        if (sieve[i] != 0) {
            for (int j = i * 2; j < 10000000; j+=i)
                sieve[j] = 0;
        }
    }

    for (int i = 2; i < 10000000; i++) {
        if (sieve[i] != 0) Sieve[sieve[i]] = 1;
    }
}

void combination(vector<int> num, vector<int> is_visit, int comp) {
    int temp_comp;
    for (int i = 0; i < num.size(); i++) {
        temp_comp = comp;
        if (is_visit[i] == 0) {
            temp_comp += num[i];

            if (Sieve.find(temp_comp) != Sieve.end()) {
                answer++;
                Sieve.erase(temp_comp);
            }

            is_visit[i] = 1;
            combination(num, is_visit, temp_comp * 10);
            is_visit[i] = 0;
        }
    }
}

int solution(string numbers) {
    vector<int> num;
    vector<int> is_visit(numbers.size(), 0);
    sieveOfEratosthenes();

    num.resize(numbers.size());
    for (int i = 0; i < numbers.size(); i++)
        num[i] = numbers[i] - '0';

    combination(num, is_visit, 0);

    return answer;
}
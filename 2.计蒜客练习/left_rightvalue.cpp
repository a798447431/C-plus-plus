#include <iostream>
#include <vector>

using namespace std;

vector<int> MakeVector(int start, int stop) {
    vector<int> numbers; //1次
    for (int i = start; i <= stop; i++) {
        numbers.push_back(i);
    }
    return numbers; //2次
}

class Sum {
private:
    vector<int> numbers;
public:
    explicit Sum(const vector<int>& theNumbers)
        :numbers{theNumbers} //3次 
    {
    }
    
    explicit Sum(vector<int>&& theNumbers)
        :numbers{forward<vector<int>>(theNumbers)}
    {

    }

    int Get() {
        int sum = 0;
        for (auto i : numbers)
        {
            sum += i;
        }
        return sum;
    }
};

int main() {
    Sum sum{ MakeVector(1, 10) };
    cout << sum.Get() << endl;
    return 0;
}


#include <iostream>
using namespace std;

class Reservoir
{
    char* name;
    int size_name;
    char* type;
    int size_type;
    int length;
    int width;
    int max_depth;

public:
    Reservoir(){}

    Reservoir(const char* name, int size_name, const char* type, int size_type, int length, int width, int max_depth) :
        name{ new char[size_name + 1] }, 
        type{ new char[size_type + 1] },  
        size_name { size_name }, 
        size_type { size_type },
        length{ length },
        width{ width },
        max_depth{ max_depth }
    {}

    explicit Reservoir(int max_depth) : max_depth{ max_depth }{}

    double calculateVolume() {
        double volume = 0;
        volume = width * length * max_depth;
        return volume;
    }

    bool equalReservoirs(Reservoir& object) {
        if (strlen(this->type) != strlen(object.type))
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (this->type[i] != object.type[i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Reservoir reservoir1{"Аральское море", 14, "Море", 4, 20, 30, 10 };
    Reservoir reservoir2{ "Каспийское море", 15, "Озеро", 5, 20, 30, 10 };

    cout << reservoir1.calculateVolume() << endl;
    cout << reservoir2.calculateVolume() << endl;

    cout << reservoir1.equalReservoirs(reservoir2) << endl;
}

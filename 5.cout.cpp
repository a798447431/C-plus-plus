/*************************************************************************
	> File Name: 5.cout.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 15时43分57秒
 ************************************************************************/

#include <iostream>
#include <string>

namespace haizei {
    class ostream {
    public :
        ostream &operator<<(int x) {
            printf("%d", x);
            return *this;
        }  
        ostream &operator<<(const std::string &str) {
            printf("%s", str.c_str());
            return *this;
        }
        ostream &operator<<(const char &ch) {
            printf("%c", ch);
            return *this;
        }        
        ostream &operator<<(const double &a) {
            char e_str[20];
            sprintf(e_str, "%-6g", a);
            for (int i = 0; e_str[i]; i++) {
                if (e_str[i] - ' ') continue;
                e_str[i] = 0;
                break;
            }
            printf("%s", e_str);
            /*
            return *this;
            int e_num, temp;
            sprintf(e_str, "%.5e", a);
            sscanf(e_str, "%d.%de%d", &temp, &temp, &e_num);
            printf("e_num : %d", e_num);
            if (e_num >= 6 || e_num <= -5) {
                printf(" %s", e_str);
            } else {
                temp = 5 - e_num;
                sprintf(e_str, "%%.%dlf", temp);
                printf(e_str, a);
            }
            return *this;
            */
        }        
    };
    char endl = '\n';
    ostream cout;
}

int main() {
    haizei::cout << "hello world" << haizei::endl;
    haizei::cout << 123 << haizei::endl;
    haizei::cout << 123.567 << haizei::endl; 
    haizei::cout << 123.567 << haizei::endl;
    haizei::cout << 123.56 << haizei::endl;
    haizei::cout << 123. << 123. << haizei::endl;
    std::cout << 123. << 123. << std::endl;
    haizei::cout << 123.78787878 << haizei::endl;
    haizei::cout << 3.78787878 << haizei::endl;
    double a = 3787878787878780;
    for (int i = 0; i < 20; i++) {
        a /= 10;
        haizei::cout << i << " " << a << haizei::endl;
        //printf(" %.5e\n", a);
    }
    printf("%lf\n", 123.567);
    printf("%lf\n", 123.56);
    printf("%lf\n", 123.);
    return 0;
}

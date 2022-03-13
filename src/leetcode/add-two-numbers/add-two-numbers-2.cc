#include <iostream>
#include <limits>

using namespace std;

int main()
{
    double a{std::numeric_limits<double>::min()};

    cout << a << "\n";
    a = a / 100000000000000;
    cout << a << " " << std::numeric_limits<double>::infinity() << "\n";
}

// q.1 2의보수 max에서 더했을떄 몇이되는지
// 2. double min /10의 결과
// 3.  변수 선언을 변수 이용하여 하기 (decltype)
//  4. 배열변수의 참조선언
//  5. 강제 형변환 축소변환 이해
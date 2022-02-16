# !sh
mkdir $1
echo "#include <iostream>
using namespace std;

//Problem site: https://www.acmicpc.net/problem/$1

int main() {
    freopen(\"input.txt\", \"r\", stdin);

    return 0;
}
" > $1/$1.cc

echo "" > $1/input.txt
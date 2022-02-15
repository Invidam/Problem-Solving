# !sh
mkdir $1
echo "#include <iostream>
using namespace std;

//Problem site: https://www.acmicpc.net/problem/$1

int main() {

    return 0;
}
" > $1/$1.cc

# !sh
mkdir $1
echo "#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/$1

int main() {

    return 0;
}
" > $1/$1.cc

# !sh
mkdir $1
echo "#include <iostream>
using namespace std;

//Problem site: https://algospot.com/judge/problem/read/$1

int main() {
    freopen(\"input.txt\", \"r\", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}
" > $1/$1.cc

echo "" > $1/input.txt
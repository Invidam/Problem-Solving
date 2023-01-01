#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;


class Card {
public:
    int month;
    char ch;

    Card() {}

    Card(int month, char ch) : month(month), ch(ch) {}

    Card(int num) : month(num / 4 + 1), ch('A' + (num % 4)) {}

    Card(const string &str) {
        month = stoi(str.substr(0, str.length() - 1));
        ch = str[str.length() - 1];
    }

    bool isEqual(Card &other) {
        return month == other.month && ch == other.ch;
    }


};
void dummyToDeck(unordered_map<int, vector<char>> &deck, stack<Card> &dummyList);

int case1(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {Card("1A"), Card("3A"), Card("8A"), Card("11A"), Card("12A")};
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    switch (cnt) {
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 15;
        default:
            return 0;
    }
}

int case2(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {
            Card("2A"), Card("4A"), Card("5A"),
            Card("6A"), Card("7A"), Card("8B"), Card("10A"), Card("12B")
    };
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    switch (cnt) {
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 4;
        default:
            return 0;
    }
}

int case3(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {
            Card("2A"), Card("4A"), Card("8B")
    };
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    switch (cnt) {
        case 3:
            return 5;
        default:
            return 0;
    }
}

int case4(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {
            Card("6B"), Card("9B"), Card("10B")
    };
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    switch (cnt) {
        case 3:
            return 3;
        default:
            return 0;
    }
}

int case5(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {
            Card("1B"), Card("2A"), Card("3B")
    };
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    switch (cnt) {
        case 3:
            return 3;
        default:
            return 0;
    }
}

int case6(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {
            Card("4B"), Card("5A"), Card("7B")
    };
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    switch (cnt) {
        case 3:
            return 3;
        default:
            return 0;
    }
}

int case7(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {
            Card("1B"), Card("2B"), Card("3B"),

            Card("4B"), Card("5B"), Card("6B"),

            Card("7B"), Card("9B"), Card("10B"),
            Card("12C")
    };
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    return cnt >= 5 ? cnt - 4 : 0;
}

int case8(vector<Card> &cards) {
    int cnt = 0;
    vector<Card> LIST = {
            Card("9A"), Card("11B"), Card("1C"),

            Card("2C"), Card("3C"), Card("4C"),

            Card("5C"), Card("6C"), Card("7C"),
            Card("8C"), Card("9C"), Card("10C"),
            Card("11C"), Card("1D"),

            Card("2D"), Card("3D"), Card("4D"),

            Card("5D"), Card("6D"), Card("7D"),
            Card("8D"), Card("9D"), Card("10D"),
            Card("11D"), Card("12D")
    };
    for (auto &card: cards) {
        for (auto &item: LIST) if (item.isEqual(card)) ++cnt;
    }
    return cnt >= 10 ? cnt - 9 : 0;
}

int getPoint(vector<Card> &cards) {
    int ret = 0;
    ret += case1(cards);
    ret += case2(cards);
    ret += case3(cards);
    ret += case4(cards);
    ret += case5(cards);
    ret += case6(cards);
    ret += case7(cards);
    ret += case8(cards);
    return ret;
}

void
pushCardToDeck(unordered_map<int, vector<char>> &deck, Card &card) { deck[card.month].push_back(card.ch); }

void userPlay2(vector<Card> &getList, unordered_map<int, vector<char>> &deck,
               stack<Card> &dummyList) {
    Card elem = dummyList.top();
    if (deck[elem.month].empty()) {
        dummyToDeck(deck, dummyList);
        return;
    }
    Card card = Card(elem.month, 'E');
    for (int j = 0; j < deck[elem.month].size(); ++j) {
        char ch = deck[elem.month][j];
        card.ch = min(card.ch, ch);
    }

    getList.push_back(elem);
    getList.push_back(card);
    deck[elem.month].erase(std::find(deck[elem.month].begin(), deck[elem.month].end(), card.ch));
    if (deck[elem.month].empty()) deck.erase(elem.month);


    dummyList.pop();
    return;

}
bool
userPlay1(vector<Card> &cardOrder, vector<Card> &compGet, unordered_map<int, vector<char>> &deck,
          stack<Card> &dummyList) {
    for (int i = 0; i < 10; ++i) {
        auto &elem = cardOrder[i];

        if (deck[elem.month].empty()) continue;
        Card card = Card(elem.month, 'E');
        for (int j = 0; j < deck[elem.month].size(); ++j) {
            char ch = deck[elem.month][j];
            card.ch = min(card.ch, ch);
        }

        compGet.push_back(elem);
        compGet.push_back(card);
        deck[elem.month].erase(std::find(deck[elem.month].begin(), deck[elem.month].end(), card.ch));
        if (deck[elem.month].empty()) deck.erase(elem.month);

        cardOrder.erase(cardOrder.begin() + i);
        return true;
    }
    return false;
}

void dummyToDeck(unordered_map<int, vector<char>> &deck, stack<Card> &dummyList) {
    pushCardToDeck(deck, dummyList.top());
    dummyList.pop();
}

bool isValid(vector<Card> &answer, vector<Card> &priority, vector<Card> &cardList) {
    vector<Card> compCardOrder, myOrder, compGet, myGet;
    myOrder = answer;
    for (auto &best: priority) {
        for (int i = 0; i < 10; ++i) {
            auto &elem = cardList[i];
            if (best.isEqual(elem)) compCardOrder.push_back(elem);
        }
    }
    unordered_map<int, vector<char>> deck;
    for (int i = 20; i < 28; ++i) {
        Card card = cardList[i];
        pushCardToDeck(deck, card);
    }

    stack<Card> dummyList;
    for (int i = 28; i < 48; ++i) {
        Card card = cardList[i];
        dummyList.push(card);
    }

    while (!dummyList.empty() && (!compCardOrder.empty() || myOrder.empty())) {

        if (!userPlay1(compCardOrder, compGet, deck, dummyList)) {
            pushCardToDeck(deck, compCardOrder.back());
            compCardOrder.pop_back();
        }
        userPlay2(compGet,deck,dummyList);

        userPlay1(myOrder, myGet, deck, dummyList);
//        if (!) {
//            pushCardToDeck(deck, compCardOrder.back());
//            compCardOrder.pop_back();
//        }
        userPlay2(myGet,deck,dummyList);
    }
    return getPoint(compGet) <  getPoint(myGet) ? true : false;
}


bool solve(vector<Card> &answer, vector<Card> &left, vector<Card> &priority, vector<Card> &cardList) {
    if (answer.size() == 10) return isValid(answer, priority, cardList);
    for (int i = 0; i < left.size(); ++i) {
        Card card = left[i];
        left.erase(left.begin() + i);
        answer.push_back(card);
        if(solve(answer, left, priority, cardList)) return true;
        answer.pop_back();
        left.insert(left.begin() + i, card);

    }
    return false;
}

bool play(vector<Card> &answer, vector<Card> &priority, vector<Card> &cardList) {
    vector<Card> left = vector<Card>(cardList.begin() + 10, cardList.begin() + 20);
    return solve(answer, left, priority, cardList);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        vector<Card> priorities(48);
        for (int j = 0; j < 48; ++j) {
            int priNum;
            cin >> priNum;
            priorities[priNum] = Card(j);
        }
        vector<Crd> cardList;
        for (int ard> cardList;
        for (int j = 0; j < 48; ++j) {
            string str;
            cin >> str;
            cardList.push_back(Card(str));
        }
        vector<Card> answer;
        bool ret = play(answer, priorities, cardList);
        if(ret) {
            for(auto& card : answer) cout << card.month << card.ch << ' ';
        }
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }
}


/*
ABC 123
DEF 456
GHI 789

 1
 6 ABC 6 ABD 7 ACD 8 AEF 12
//ATR MWX PKC



 *
 */

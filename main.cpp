#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios ;

#include <string>
using std::string ;

#include <stack>
using std::stack;

int main(int argc, char *argv[]) {

    string leite;

    stack<char> bananas , goiabas;

    leite=argv[1];

    for (int i = 0; i < leite.length() ; ++i) {
        bananas.push(leite[i]);
    }
    while(!bananas.empty()){
        goiabas.push(bananas.top());
        cout<<bananas.top();
        bananas.pop();

    }
    cout << endl;
    while(!goiabas.empty()){
        cout<<goiabas.top();
        goiabas.pop();

    }
    cout<<endl;


}

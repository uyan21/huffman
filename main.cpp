#include <iostream>
#include <ctime>
#include <queue>
#include "huffman.h"
#include <bitset>


#define SIZE 8
using namespace std;
int main() {

	time(NULL);
	Node P[SIZE];
	Book code[SIZE];
	huffman a=huffman(P, SIZE);
	Node result=a.tree();
	a.code_gen(&result,code,SIZE);
	for (int i = 0; i < SIZE; i++) {
		cout << code[i].ch << " code: " << code[i].line << " freq: "<< code[i].frequency<<endl;
	}

	a.print(&result);

}

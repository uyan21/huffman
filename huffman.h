#include <iostream>

using namespace std;

typedef struct Node{
	
	char code=NULL;
	double frequency=0;
	Node *left = NULL;
	Node *right = NULL;
}Node;

struct cmp {
	bool operator()(const Node a, const Node b) {
		return a.frequency > b.frequency;
	}
};
typedef struct Book{
	char ch=NULL;
	string line = "";
	double frequency = NULL;
}Book;
class huffman {
public:
	Node *ptr;
	huffman(Node P[],int size);
	Node tree();
	void print(Node * argNode);
	void code_gen(Node * argNode, Book * code, int size);
};





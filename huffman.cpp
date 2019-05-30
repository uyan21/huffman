#include <iostream>
#include <ctime>
#include <conio.h>
#include <bitset>
#include "huffman.h"
#include <queue>
#define BIT 100
priority_queue<Node, vector<Node>, cmp> q;
huffman::huffman(Node P[], int size) {
	
	double max = 0;
	for (int i = 0; i < size; i++) {
		time(NULL);
		P[i].code = i + 27;
		P[i].frequency =(1+i)*rand()%1000;
		max += P[i].frequency;
	}
	for (int i = 0; i < size; i++) {
		P[i].frequency = P[i].frequency / max;
	}
	for (int i = 0; i < size; i++) {
		q.push(P[i]);
	}
	double a=0;
	/*for (; !q.empty();) {
		
		a+=q.top().frequency;
		cout <<"["<< q.size() <<"]"<< q.top().frequency << endl;
		q.pop();
	}*/
	
}
Node huffman::tree() {
	Node *m=NULL,*M=NULL,*root;
	while (q.size() >= 2) {
		m = (Node*)malloc(sizeof(Node));
		M = (Node*)malloc(sizeof(Node));
		memcpy(m, (Node*)&(q.top()), sizeof(Node)); q.pop();
		memcpy(M, (Node*)&(q.top()), sizeof(Node)); q.pop();
		root = (Node*)malloc(sizeof(Node));
		root->left = m;
		root->right = M;
		root->frequency = m->frequency + M->frequency;
		q.push(*root);
		}
	cout << q.top().frequency<< endl;
	while (root->left == NULL) {
		root = root->left;
		cout << root->frequency << endl;
	}
	return q.top();
}
void huffman::print(Node *argNode) {
	Node *root;
	root = argNode;
	ptr = root;
	while (1) {
		int key = getch();
		if (key == 75) {
			if (ptr->right == NULL) {
				cout << "NULL" << endl;
			}
			else if (ptr->left != NULL) {
				ptr = ptr->left;
				cout <<"1 "<< ptr->frequency << "code : " << ptr->code << endl;
			}
		}
		else if (key == 77) {
			if (ptr->right == NULL) {
				cout << "NULL" << endl;
			}
			else if (ptr->right != NULL) {
				ptr = ptr->right;
				cout <<"0 "<< ptr->frequency << "code : " << ptr->code << endl;
			}
		}
		else if (key == 32) {
			ptr = root;
			cout << ptr->frequency << endl;
		}
		else if (key == 99)
			break;
	}

}
void huffman::code_gen(Node *argNode,Book *code,int size) {
	Node *ptr;
	char deter_ch = NULL;
	int i = 0;
	while(i<size) {
		ptr= argNode;
		int k = i;
		while (ptr->left != NULL | ptr->right != NULL) {
			if (bitset <BIT>(k)[1] == 1) {
				code->line += "1";
				ptr = ptr->left;
			}
			else {
				code->line += "0";
				ptr = ptr->right;
			}
			k = k >> 1;
			cout << bitset<10>(k) << " " << "k val" << endl;;
			
		}
		cout << code->line + " code " + ptr->code << endl;
		
				if (deter_ch != ptr->code) {
					
					deter_ch = ptr->code;
					code->frequency = ptr->frequency;
					code->ch = ptr->code;
					code++;
					
				}
				else {
					code->line = "";
				}
				cout << to_string(code->line.length())+" "+ "length" << endl;
				cout << bitset<10>(i) << endl;
				i++;
				

	}
	
}

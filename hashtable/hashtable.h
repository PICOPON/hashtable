#pragma once
#include <string>
#include <iostream>
class hashtable
{
	struct Node {
		std::string name;
		std::string info;
		Node* next;
	};
private:
	static const int size = 11;
	Node storage[size];
	int count;
protected:
	/* *hashFunc
	* -
	* params s corrspond to str
	*/
	int hashFunc(std::string s);
public:
	hashtable();
	~hashtable();

	void addItem(std::string name, std::string info);
	bool findItem(std::string name);

};


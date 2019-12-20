#include "hashtable.h"



hashtable::hashtable()
{
	this->count = 17;
	for (Node& i : storage) {
		i.name = "\0";
		i.info = "\0";
		i.next = nullptr;
	}
}
/* *addItem
* this function is used to add new item.
* @params
*/
void hashtable::addItem(std::string name,std::string info)
{
	Node* ptr_item = new Node;
	ptr_item->name = name;
	ptr_item->info = info;
	ptr_item->next = nullptr;
	int hashcode = hashtable::hashFunc(ptr_item->name);
	if (storage[hashcode].name == "\0") {
		storage[hashcode] = *ptr_item;
	}
	else {
		for (Node* ptr = &storage[hashcode]; ; ptr = ptr->next) {
			if (ptr->next == nullptr) {
				ptr->next = ptr_item;
				break;
			}
		}// 链地址法设置链地址的值
	}
}

bool hashtable::findItem(std::string name)
{
	int hashcode = hashtable::hashFunc(name);
	if (storage[hashcode].name == "\0") return false;
	if (storage[hashcode].name == name) {
		std::cout << hashcode << std::endl;
		std::cout << storage[hashcode].info << std::endl;
		return true;
	} else {
		for (Node* ptr = &storage[hashcode];; ptr = ptr->next) {
			if (ptr->name == name) {
				std::cout << hashcode << std::endl;
				std::cout << ptr->info;
				return true;
			}if (ptr->next == nullptr) {
				break;
			}
		}
		return false;
	}  //链地址法的查询
}


hashtable::~hashtable()
{

}

int hashtable::hashFunc(std::string s)
{
	int hashCode = 0;
	for (int i = 0; i < s.size(); i++) {
		hashCode = hashCode * count + int(s.at(i));
	}
	return hashCode % size;
}


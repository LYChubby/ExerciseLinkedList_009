#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int NIM;
	string Nama;    // Deklarasi Variabel
	Node* newNode = new Node();
	cout << "Masukkan RollNumber : ";
	cin >> NIM;     // Menyimpan Data Ke Dalam Variabel
	cout << "Masukkan Nama : ";
	cin >> Nama;
	newNode->rollNumber = NIM;   // Data rollNumber = NIM
	newNode->name = Nama;        // Data name = Nama

	if (LAST == NULL || NIM <= LAST->rollNumber) {
		if (LAST != NULL && NIM == LAST->rollNumber) {

			cout << "RollNumber Sudah Ada" << endl;
			return;
		}
		newNode->next = LAST->next;
		LAST->next = newNode;    // Membuat newNode berada di LAST->next
		return;
	}
	Node* previous = LAST;       // Membuat Data Sebelumnya Adalah LAST
	Node* current = newNode;     // Membuat Data Yang Sekarang Adalah newNode

	while ((current != NULL) && (NIM >= current->rollNumber)) {

		if (NIM == current->rollNumber) {
			cout << "RollNumber Sudah Ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	newNode->next = current;       // Membuat Data Sekarang Adalah newNode->next
	previous->next = newNode;      // Data Yang Sebelumnya Adalah newNode
}


bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	Node* previous = LAST;
	Node* current = LAST;
	LAST->next = current->next;

	previous = current;
	current = current->next;
	if (current == LAST)
		LAST = current->next;
	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				cout << "Data Berhasil Ditambahkan" << endl;
				system("pause");
				system("cls");
				break;
			}
			case '2': {
				obj.delNode();
				cout << "Data Berhasil Dihapus" << endl;
				system("pause");
				system("cls");
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
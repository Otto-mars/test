#include iostream
#include <string>

using namespace std;


struct Node {
	string veri; 
	Node* sonraki;

	Node(string v) {
		veri = v;
		sonraki = nullptr;
	}
};

void append(Node*& head, string kelime) {
    Node* yeni_node = new Node(kelime);

    if (head == nullptr) {
        head = yeni_node;
        return;
    }

    Node* gecici = head;
    while (gecici->sonraki != nullptr) {
        gecici = gecici->sonraki;
    }
    gecici->sonraki = yeni_node;
}

void undo(Node*& head) {
    if (head == nullptr) {
        cout << "Geri alınacak kelime yok!" << endl;
        return;
    }
    Node* gecici = head;
    Node* onceki = nullptr;
    while (gecici->sonraki != nullptr) {
        onceki = gecici;
        gecici = gecici->sonraki;
    }
    if (onceki != nullptr) {
        onceki->sonraki = nullptr;
    } else {
        head = nullptr; // Sadece bir kelime varsa
    }
    delete gecici; // Son kelimeyi sil
}

void display(Node* head) {
    Node* gecici = head;
    while (gecici != nullptr) {
        cout << "[" << gecici->veri << "]";
        if (gecici->sonraki != nullptr) cout << " -> ";
        gecici = gecici->sonraki;
    }
    cout << " -> NULL" << endl;
}

int main()
{
	Node* head = nullptr;


    string input;

    while (true) {
        cout << "Kelime gir: ";
        cin >> input;

        if (input == "EXIT") {
            break;
        }
        else if (input == "UNDO") {
            undo(head);
        }
        else {
            append(head, input);
        }

        display(head);
    }

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Định nghĩa cấu trúc cho mỗi thành viên trong gia phả
struct FamilyMember {
    string name;
    string relationship;
    FamilyMember* next;

    FamilyMember(string n, string r) : name(n), relationship(r), next(nullptr) {}
};

// 3.2. khởi tạo danh sách liên kết đơn
FamilyMember* createMember(string name, string relationship) {
    return new FamilyMember(name, relationship);
}

// 3.3. nhập dữ liệu
void addMember(FamilyMember*& head, string name, string relationship) {
    FamilyMember* newMember = createMember(name, relationship);
    newMember->next = head;
    head = newMember;
}

// 3.4. hiển thị danh sách
void displayList(FamilyMember* head) {
    FamilyMember* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name << ", Relationship: " << temp->relationship << endl;
        temp = temp->next;
    }
}

// 3.5. thêm vào đầu danh sách
void addMemberAtHead(FamilyMember*& head, string name, string relationship) {
    FamilyMember* newMember = createMember(name, relationship);
    newMember->next = head;
    head = newMember;
}

// 3.6. chèn vào cuối danh sách
void addMemberAtTail(FamilyMember*& head, string name, string relationship) {
    FamilyMember* newMember = createMember(name, relationship);
    if (!head) {
        head = newMember;
    } else {
        FamilyMember* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newMember;
    }
}

// 3.7. xóa thành viên theo tên
void deleteMemberByName(FamilyMember*& head, string name) {
    FamilyMember* temp = head;
    FamilyMember* prev = nullptr;

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

// 3.8. xóa thành viên theo quan hệ
void deleteMemberByRelationship(FamilyMember*& head, string relationship) {
    FamilyMember* temp = head;
    FamilyMember* prev = nullptr;

    while (temp != nullptr && temp->relationship != relationship) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

// 3.9. Đếm số lượng thành viên có quan hệ cụ thể
int countMembersByRelationship(FamilyMember* head, string relationship) {
    int count = 0;
    FamilyMember* temp = head;
    while (temp != nullptr) {
        if (temp->relationship == relationship) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// 3.10. Tìm kiếm thành viên theo tên
FamilyMember* searchMemberByName(FamilyMember* head, string name) {
    FamilyMember* temp = head;
    while (temp != nullptr) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// 3.11. Hiển thị danh sách thành viên theo một quan hệ cụ thể
void displayMembersByRelationship(FamilyMember* head, string relationship) {
    FamilyMember* temp = head;
    while (temp != nullptr) {
        if (temp->relationship == relationship) {
            cout << "Name: " << temp->name << ", Relationship: " << temp->relationship << endl;
        }
        temp = temp->next;
    }
}

// 3.12. Tìm kiếm thành viên theo quan hệ
FamilyMember* searchMemberByRelationship(FamilyMember* head, string relationship) {
    FamilyMember* temp = head;
    while (temp != nullptr) {
        if (temp->relationship == relationship) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// 3.13. Ghi danh sách thành viên vào tệp
void saveListToFile(FamilyMember* head, const string& filename) {
    ofstream file(filename);
    FamilyMember* temp = head;
    while (temp != nullptr) {
        file << temp->name << "," << temp->relationship << endl;
        temp = temp->next;
    }
    file.close();
}

// 3.14. Tính số lượng thành viên
int countMembers(FamilyMember* head) {
    int count = 0;
    FamilyMember* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 3.15. Sắp xếp danh sách tăng dần theo tên (Bubble Sort)
void bubbleSort(FamilyMember*& head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        FamilyMember* temp = head;
        while (temp->next != nullptr) {
            if (temp->name > temp->next->name) {
                swap(temp->name, temp->next->name);
                swap(temp->relationship, temp->next->relationship);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

// 3.16. Thoát khỏi chương trình
void exitProgram(FamilyMember*& head) {
    while (head != nullptr) {
        FamilyMember* temp = head;
        head = head->next;
        delete temp;
    }
}

// Menu chính của chương trình
void menu() {
    FamilyMember* head = nullptr;
    int choice;
    string name, relationship, filename;
    do {
        cout << "\n1. Khởi tạo danh sách liên kết đơn\n";
        cout << "2. Nhập dữ liệu\n";
        cout << "3. Hiển thị danh sách\n";
        cout << "4. Thêm vào đầu danh sách\n";
        cout << "5. Chèn vào cuối danh sách\n";
        cout << "6. Xóa thành viên theo tên\n";
        cout << "7. Xóa thành viên theo quan hệ\n";
        cout << "8. Đếm số lượng thành viên có quan hệ cụ thể\n";
        cout << "9. Tìm kiếm thành viên theo tên\n";
        cout << "10. Hiển thị danh sách thành viên theo quan hệ\n";
        cout << "11. Tìm kiếm thành viên theo quan hệ\n";
        cout << "12. Ghi danh sách thành viên vào tệp\n";
        cout << "13. Tính số lượng thành viên\n";
        cout << "14. Sắp xếp danh sách tăng dần theo tên\n";
        cout << "15. Thoát khỏi chương trình\n";
        cout << "Lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                head = nullptr;
                cout << "Danh sách liên kết đơn đã được khởi tạo.\n";
                break;
            case 2:
                cout << "Nhập tên: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhập quan hệ: ";
                getline(cin, relationship);
                addMember(head, name, relationship);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                cout << "Nhập tên: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhập quan hệ: ";
                getline(cin, relationship);
                addMemberAtHead(head, name, relationship);
                break;
            case 5:
                cout << "Nhập tên: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhập quan hệ: ";
                getline(cin, relationship);
                addMemberAtTail(head, name, relationship);
                break;
            case 6:
                cout << "Nhập tên thành viên cần xóa: ";
                cin.ignore();
                getline(cin, name);
                deleteMemberByName(head, name);
                break;
            case 7:
                cout << "Nhập quan hệ của thành viên cần xóa: ";
                cin.ignore();
                getline(cin, relationship);
                deleteMemberByRelationship(head, relationship);
                break;
            case 8:
                cout << "Nhập quan hệ: ";
                cin.ignore();
                getline(cin, relationship);
                cout << "Số lượng thành viên có quan hệ " << relationship << ": " << countMembersByRelationship(head, relationship) << endl;
                break;
            case 9:
                cout << "Nhập tên thành viên cần tìm: ";
                cin.ignore();
                getline(cin, name);
                if (searchMemberByName(head, name)) {
                    cout << "Thành viên " << name << " có trong gia phả.\n";
                } else {
                    cout << "Không tìm thấy thành viên " << name << ".\n";
                }
                break;
            case 10:
                cout << "Nhập quan hệ: ";
                cin.ignore();
                getline(cin, relationship);
                displayMembersByRelationship(head, relationship);
                break;
            case 11:
                cout << "Nhập quan hệ của thành viên cần tìm: ";
                cin.ignore();
                getline(cin, relationship);
                if (searchMemberByRelationship(head, relationship)) {
                    cout << "Có thành viên với quan hệ " << relationship << " trong gia phả.\n";
                } else {
                    cout << "Không tìm thấy thành viên với quan hệ " << relationship << ".\n";
                }
                break;
            case 12:
                cout << "Nhập tên tệp: ";
                cin.ignore();
                getline(cin, filename);
                saveListToFile(head, filename);
                break;
            case 13:
                cout << "Số lượng thành viên trong gia phả: " << countMembers(head) << endl;
                break;
            case 14:
                bubbleSort(head);
                cout << "Danh sách đã được sắp xếp tăng dần theo tên.\n";
                break;
            case 15:
                exitProgram(head);
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ!\n";
                break;
        }
    } while (choice != 15);
}

int main() {
    menu();
    return 0;
}

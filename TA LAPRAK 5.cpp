#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* left;
    Node* right;
    Node(int n): nilai(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int nilai) {
    if (!root) return new Node(nilai);
    if (nilai < root->nilai) root->left = insertNode(root->left, nilai);
    else if (nilai > root->nilai) root->right = insertNode(root->right, nilai);
    return root;
}

bool searchNode(Node* root, int nilai) {
    if (!root) return false;
    if (root->nilai == nilai) return true;
    if (nilai < root->nilai) return searchNode(root->left, nilai);
    return searchNode(root->right, nilai);
}

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->nilai;
}

int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->nilai;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih, x;

    do {
        cout << "\n=== SISTEM DATA NILAI MAHASISWA (BST) ===\n";
        cout << "1. Tambah Nilai Mahasiswa\n2. Cari Nilai Mahasiswa\n3. Tampilkan Nilai Terendah\n";
        cout << "4. Tampilkan Nilai Tertinggi\n5. Hitung Jumlah Data Nilai\n6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nilai mahasiswa: "; cin >> x;
            root = insertNode(root, x);
            cout << "Nilai berhasil disimpan!\n";
        } else if (pilih == 2) {
            cout << "Masukkan nilai yang ingin dicari: "; cin >> x;
            cout << (searchNode(root, x) ? "Nilai ditemukan di data.\n" : "Nilai tidak ditemukan.\n");
        } else if (pilih == 3) {
            cout << "Nilai terendah: " << findMin(root) << "\n";
        } else if (pilih == 4) {
            cout << "Nilai tertinggi: " << findMax(root) << "\n";
        } else if (pilih == 5) {
            cout << "Jumlah data nilai: " << countNodes(root) << "\n";
        }
    } while (pilih != 6);
     return 0;
}

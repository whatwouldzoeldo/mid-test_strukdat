/*
Nama        : Muhammad Zulfikar Ali
Kelas       : B
NPM         : 140810180064
Tanggal     : 24 April 2019
Deskripsi   : Menampilkan data pesanan di sebuah restoran
*/

#include <iostream>
#include <string.h>

using namespace std;

struct resto {
    int no;
    int harga;
    string menu;
    int jumlah;
    resto* next;
};
typedef resto* pointer;
typedef pointer List;

void createList (List& First) {
    First=NULL;
}

void createElemt(pointer& pBaru) {
    pBaru=new resto;
    cout<<"No\t : "; cin>>pBaru->no;
    cout<<"Menu\t : "; cin>>pBaru->menu;
    cout<<"Harga\t : "; cin>>pBaru->harga;
    cout<<endl;
    pBaru->jumlah=0;
    pBaru->next=NULL;
}

void insertLast(List& First, pointer pBaru) {
    pointer pBantu = First;
    if (First==NULL){
        First=pBaru;
    }
    else{
        while(pBantu->next!=NULL){
            pBantu = pBantu->next;
        }
        pBantu->next = pBaru;
    }
}

void traversal(List First) {
    pointer p=First;
    while(p!=NULL){
        cout<<p->no<<"\t"<<p->menu<<"\t"<<p->harga<<endl;
        p = p->next;
    }
}

void search(List& First, string kunci, int& ketemu, pointer& p) {
    p = First;
    while(p!=NULL&&ketemu==0){
        if (p->menu==kunci){
            ketemu= 1;
            break;
        }
        p = p->next;
    }
}

void update (List& First) {
    char input;
    do{
        pointer pHasil;
        int ketemu = 0;
        string kunci;
        cout<<"Masukan Menu :\n";cin>>kunci;
        search(First,kunci,ketemu,pHasil);
        if(ketemu){
            cout<<"Ketemu!";
            cout<<endl;
            cout<<pHasil->no<<" "<<pHasil->menu<<"=> jumlah pesanan = ";cin>>pHasil->jumlah;
        }
        else{
            cout<<"Data tidak ditemukan!!";
        }
        cout<<"\nInput lagi? (y/n): ";cin>>input;
    }while(input=='y'||input=='Y');
}

void tukar(pointer& a, pointer& b) {
    int temp = a->jumlah;
    string sem = a->menu;
    int x = a->no;
    a->jumlah = b->jumlah;
    a->menu = b->menu;
    a->no = b->no;
    b->jumlah = temp;
    b->menu = sem;
    b->no = x;
}

void sorting (List& First) {
    int swapped, i;
    pointer ptr1;
    pointer lptr = NULL;

    if (First == NULL)
        return;

    do{
        swapped = 0;
        ptr1 = First;

        while(ptr1->next!=lptr){
            if (ptr1->jumlah>ptr1->next->jumlah){
                tukar(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

int main()
{
    List c;
    pointer p;
    int n;
    createList(c);
    cout<<"Masukan banyak data: ";cin>>n;
    for (int i=0;i<n;i++){
        createElemt(p);
        insertLast(c,p);
    }
    cout<<"\nData awal:\n";
    traversal(c);
    update(c);
    cout<<"Sorted :\n";
    sorting(c);
    traversal(c);
    return 0;
}






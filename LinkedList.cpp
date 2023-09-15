#include <iostream>
using namespace std;

// Membuat node 
struct node{
    int info;
    int nextPointer;
};

// Variabel Global
int startInfoPoint, sumListAvail, startPointAvail, sumList, simpanPointAvail;
int lengthLinkedList, lengthInfoLink, lengthAvailLink;

//Mendefinisikan method-method.
void buatList(struct node LinkedList[]);
void CetakLinkedList(struct node LinkedList[]);
void HapusNode(struct node LinkedList[]);

// Main program
int main() {
    cout<<"Masukan panjang linked list: ";
    cin >> lengthLinkedList;
    cout << "Masukan panjang linked list informasi: ";
    cin >> lengthInfoLink; // Merepresentasikan panjang linked list informasi.
    lengthAvailLink = lengthLinkedList-lengthInfoLink; 
    //lengthAvailLink berfungsi untuk mereprensentasikan panjang list kosong
    cout << "Banyaknya list avail adalah: "<<lengthAvailLink<<endl<<endl;
    struct node LinkedList[lengthLinkedList];
    
    buatList(LinkedList);
    CetakLinkedList(LinkedList);
    
    int sign = 1;
    int sumDel = 0;
    while(sign!=0){
        cout<<"Apakah Anda ingin melakukan program penghapusan? (Tekan 1 jika ya, dan 0 jika tidak): ";
        cin >> sign;
        if(sign == 1){
            HapusNode(LinkedList);
            CetakLinkedList(LinkedList);
            if(lengthInfoLink==0){
                cout<<"Linked List telah terhapus semua."<<endl;;
                break;
            }
        }
    }
    cout << "Program telah selesai."<<endl;
    CetakLinkedList(LinkedList);
}

// Fungsi untuk membuat linkedList
void buatList(struct node LinkedList[]){
    for(int x = 0; x<lengthLinkedList; x++){
        if(x<lengthInfoLink){
            if(x == 0){
                cout <<"Masukan alamat pada pointer start: ";
                cin >> startInfoPoint;
            }
        cout<<"Masukan nilai dari informasi linked list: ";
        cin >> LinkedList[x].info;
            if(x != lengthInfoLink-1){
                cout << "Masukan nilai dari next pointer: ";
                cin >> LinkedList[x].nextPointer;
                }
            else{
                LinkedList[x].nextPointer = 0;
            }
        
        }
        else{
            if(sumListAvail == 0){
                cout<<"Masukkan pointer awal Linked List Avail: ";
                cin >> startPointAvail;
            }
            LinkedList[x].info = 0;
            if(sumListAvail != lengthAvailLink-1 ){
            cout << "Masukan nilai dari next pointer Linked List Avail: ";
                cin >> LinkedList[x].nextPointer;
            }
            else{
                LinkedList[x].nextPointer = 0;
            }
            sumListAvail++;
        }
        cout <<"Node: " <<endl << "|" << LinkedList[x].info << "|" << LinkedList[x].nextPointer<<"|";
        cout<<endl<<endl;
    }
}

// Fungsi untuk menghapus node.
void HapusNode(struct node LinkedList[]){    
    int hapus;
    cout<<"Masukan nilai yang ingin dihapus: ";
            cin >> hapus;
            for(int x = 0; x<lengthLinkedList; x++){
                if( LinkedList[x].info == hapus && LinkedList[x].info!= 0){
                    LinkedList[x].info = 0;
                    if(x < lengthInfoLink && x > 0){
                        simpanPointAvail = LinkedList[x-1].nextPointer;
                        LinkedList[x-1].nextPointer = LinkedList[x].nextPointer;
                        LinkedList[x].nextPointer = startPointAvail;
                        startPointAvail =  simpanPointAvail;
                    }
                    else if(x == lengthInfoLink-1  && x!= 0){
                        simpanPointAvail = LinkedList[x-1].nextPointer;
                        LinkedList[x-1].nextPointer = 0;
                        startPointAvail =  simpanPointAvail;
                    }
                    else{
                        int simpanSementara = LinkedList[x].nextPointer;
                        LinkedList[x].nextPointer = startPointAvail;
                        startPointAvail = startInfoPoint;
                        startInfoPoint = simpanSementara;
                    } 
                    
                    for(int y = x; y<lengthLinkedList-1; y++){
                    if(LinkedList[y+1].info == 0){
                        break;
                    }
                    int NilaiSementara = LinkedList[y+1].info;
                    int PointSementara = LinkedList[y+1].nextPointer;
                    LinkedList[y+1].info = LinkedList[y].info;
                    LinkedList[y].info = NilaiSementara;
                    LinkedList[y+1].nextPointer = LinkedList[y].nextPointer;
                    LinkedList[y].nextPointer = PointSementara;
                }
               lengthAvailLink++;
               lengthInfoLink--;
                    break;
                    }
                else if(x >= lengthInfoLink && (LinkedList[x].info != hapus || LinkedList[x].info == 0 )){
                    cout << "Angka tidak ditemukan!";
                    cout<<endl;
                    break;
                }
                }
               
    
        }
        
// Fungsi untuk mencetak LinkedList
void CetakLinkedList(struct node LinkedList[]){
    
    cout<<"------------------------------------------------------------------------"<<endl;
    cout << "Hasil dari linked list adalah: "<<endl;
    cout<<"Start Pointer Linked List: "<< startInfoPoint<<endl;
    cout<<"Linked list: ";
    sumList = 0;
    for(int x = 0; x<lengthLinkedList; x++){
        if(LinkedList[x].info!=0){
        cout << "|" << LinkedList[x].info << "|" << LinkedList[x].nextPointer<<"|";
        sumList++;
        if(sumList==lengthInfoLink){
            sumList = 0;
            break;
        }
        cout << "-->";
        }
    }
     if(lengthInfoLink== 0){
        cout<<"Kosong.";
    }
    cout <<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    
    cout << "Hasil dari linked list Avail adalah: "<<endl;
    cout<<"Start Pointer Linked List Avail: "<< startPointAvail<<endl;
    cout<<"Linked list avail: ";
    sumListAvail = 0;
    for(int x = 0; x<lengthLinkedList; x++){
        if(LinkedList[x].info==0){
        cout << "|" << LinkedList[x].info << "|" << LinkedList[x].nextPointer<<"|";
        sumListAvail++;
        if(sumListAvail==lengthAvailLink){
            sumListAvail = 0;
            break;
        }
        cout << "-->";
    }
    }
    cout<<endl<<"------------------------------------------------------------------------"<<endl;
    
    cout<<endl;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct customer{
	vector<string> barang;
	vector<int> harga;
	vector<int> jumlah;
};

void Save(vector<string> nama,customer milik[]){
	ofstream f("file.txt");
	if(f.is_open()){
		for(int i=0;i<nama.size();i++){
			f<<nama[i]<<endl;
			f<<milik[i].barang.size()<<endl;
			for(int j=0;j<milik[i].barang.size();j++){
				f<<milik[i].barang[j]<<endl;
				f<<milik[i].jumlah[j]<<endl;
				f<<milik[i].harga[j]<<endl;
			}
		}
	}
	f.close();
}

void Load(vector<string> &nama,customer milik[]){
	nama.clear();
	ifstream f("file.txt");
	if(f.is_open()){
		while(!f.eof()){
			string tempnama,tempbarang,stempj,stemph;
			int tempharga,tempjumlah,ctr=0,totalb;
			getline(f,tempnama);
			if(tempnama!=""){
				f>>totalb;
				for(int i=0;i<totalb;i++){
					getline(f,tempbarang);
					getline(f,stempj);
					getline(f,stemph);
					stringstream(stempj)>>tempjumlah;
					stringstream(stemph)>>tempharga;
					nama.push_back(tempnama);
					milik[ctr].barang.push_back(tempbarang);
					milik[ctr].jumlah.push_back(tempjumlah);
					milik[ctr].harga.push_back(tempharga);
				}
				ctr++;
			}
		}
	}
	f.close();
}

int main()
{
	int menu,ctr=0;
	customer milik[10];
	vector<string> nama;
	Load(nama,milik);
	do{
		system("cls");
		cout<<"itp mart"<<endl;
		cout<<"--------"<<endl;
		cout<<"1. create transaction"<<endl;
		cout<<"2. view transaction"<<endl;
		cout<<"3. save & exit"<<endl;
		cout<<">>> "; cin>>menu;
		if(menu==1){
			string tempnama,tempbarang;
			int tempharga,tempjumlah,counter=1;
			cout<<"customer name: "; cin.ignore(); getline(cin,tempnama);
			do{
				if(counter==1){
					cout<<"barang #"<<counter<<": "; getline(cin,tempbarang);
				} else{
					cout<<"barang #"<<counter<<": "; cin.ignore(); getline(cin,tempbarang);
				}
				if(tempbarang!="-"){
					do{
						cout<<"harga: "; cin>>tempharga;
						if(tempharga<0) cout<<"harga tidak valid!"<<endl;
					}while(tempharga<0);
					do{
						cout<<"jumlah: "; cin>>tempjumlah;
						if(tempjumlah<1) cout<<"jumlah tidak valid!"<<endl;
					}while(tempjumlah<1);
					milik[ctr].barang.push_back(tempbarang);
					milik[ctr].harga.push_back(tempharga);
					milik[ctr].jumlah.push_back(tempjumlah);
					counter++;
				} else{
					cout<<"bye :)"<<endl;
					system("pause");
				}
			}while(tempbarang!="-");
			nama.push_back(tempnama);
			ctr++;
		} else if(menu==2){
			for(int i=0;i<nama.size();i++){
				int total=0;
				cout<<nama[i]<<endl;
				cout<<"===================="<<endl;
				for(int j=0;j<milik[i].barang.size();j++){
					cout<<milik[i].barang[j]<<" - "<<milik[i].jumlah[j]<<" - "<<milik[i].harga[j]<<endl;
					total+=milik[i].jumlah[j]*milik[i].harga[j];
				}
				cout<<"--------------------"<<endl;
				cout<<"Total : "<<total<<endl<<endl;
			}
			system("pause");
		} else if(menu==3){
			Save(nama,milik);
			cout<<"transaksi berhasil tersimpan!";
		}
	}while(menu!=3);
	
    return 0;
}

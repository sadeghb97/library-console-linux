#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<vector>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
using namespace std;
int choice(int,int);
bool checknum(char[]);
int enternum();
//void save_txt();
class date{
	//public;
	public:
	int year;
	int month;
	int day;
	public:
	date(){
		year=0;
		month=0;
		day=0;
	}
	void input(){
		cout<<"Sal, mah va sepas ruz ra vared konid."<<endl;
		year=enternum();
		month=enternum();
		day=enternum();
	}
	void print(){
		cout<<endl<<"Year: "<<year<<" | Month: "<<month<<" | Day: "<<day;
	}
	int operator[](const char inp[30]){
		if(!strcmp(inp,"year")) return year;
		else if(!strcmp(inp,"month")) return month;
		else if(!strcmp(inp,"day")) return day;
		else return 0;
	}
};
class PersonArray;
class ThingArray;
class lend;
class person{
	protected:
	public:
	char fname[30];
	char lname[30];
	char mellic[15];
	date born;
	char born_place[30];
	char father_name[30];
	char mother_name[30];
	bool jensiat;
	char adress[200];
	char mobile_num[20];
	char telephone[20];
	char tahsilat[60];
	int type;
	public:
	person(){}
	virtual void pointspp(){};
	virtual int sendpass(){return -1;}
	int sendtype(){return type;}
	//void edit_type(int t){type=t;}
	char* sendmellic(){return mellic;}
	virtual person* clone()=0;
	virtual void save_txt(ostream&)=0; 
	virtual void load_txt(istream&)=0;
	virtual void input(PersonArray)=0;
	virtual void print()=0; 
	virtual void edit(PersonArray)=0;
	friend class PersonArray;
};
class member:public person{
	int points;
	date start;
	public:
	member(){
		strcpy(mellic,"null");
		points=0;
		type=1;
	}
	member(member &m1){
		type=m1.type;
		strcpy(fname,m1.fname);
		strcpy(lname,m1.lname);
		strcpy(mellic,m1.mellic);
		born=m1.born;
		strcpy(born_place,m1.born_place);
		strcpy(father_name,m1.father_name);
		strcpy(mother_name,m1.mother_name);
		jensiat=m1.jensiat;
		strcpy(adress,m1.adress);
		strcpy(mobile_num,m1.mobile_num);
		strcpy(telephone,m1.telephone);
		strcpy(tahsilat,m1.tahsilat);
		points=m1.points;
		start=m1.start;
	}
	person* clone(){return new member(*this);}
	void save_txt(ostream &f1){
		f1<<type<<endl;
		f1<<fname<<endl;
		f1<<lname<<endl;
		f1<<mellic<<endl;
		f1<<born.year<<endl;
		f1<<born.month<<endl;
		f1<<born.day<<endl;
		f1<<born_place<<endl;
		f1<<father_name<<endl;
		f1<<mother_name<<endl;
		f1<<jensiat<<endl;
		f1<<adress<<endl;
		f1<<mobile_num<<endl;
		f1<<telephone<<endl;
		f1<<tahsilat<<endl;
		f1<<points<<endl;
		f1<<start.year<<endl;
		f1<<start.month<<endl;
		f1<<start.day<<endl;
	}
	void load_txt(istream &f1){
		f1.getline(fname,30);
		f1.getline(lname,30);
		f1.getline(mellic,15);
		f1>>born.year;
		f1.ignore();
		f1>>born.month;
		f1.ignore();
		f1>>born.day;
		f1.ignore();
		f1.getline(born_place,30);
		f1.getline(father_name,30);
		f1.getline(mother_name,30);
		f1>>jensiat;
		f1.ignore();
		f1.getline(adress,200);
		f1.getline(mobile_num,20);
		f1.getline(telephone,20);
		f1.getline(tahsilat,60);
		f1>>points;
		f1.ignore();
		f1>>start.year;
		f1.ignore();
		f1>>start.month;
		f1.ignore();
		f1>>start.day;
		f1.ignore();
	}
	void input(PersonArray);
	void print(){
		cout<<endl<<"Moshakhasate Ozv: "<<endl;
		cout<<"First Name: ";
		cout<<fname<<endl;
		cout<<"Last Name: ";
		cout<<lname<<endl;
		cout<<"Melli Code: ";
		cout<<mellic<<endl;
		cout<<"Born Date: ";
		born.print(); cout<<endl;
		cout<<"Born Place: ";
		cout<<born_place<<endl;
		cout<<"Father Name: ";
		cout<<father_name<<endl;
		cout<<"Mother Name: ";
		cout<<mother_name<<endl;
		cout<<"Jensiat: ";
		if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
		cout<<"Adress: ";
		cout<<endl<<adress<<endl;
		cout<<"Mobile Number: ";
		cout<<mobile_num<<endl;
		cout<<"Telephone: ";
		cout<<telephone<<endl;
		cout<<"Tahsilat: ";
		cout<<endl<<tahsilat<<endl;
		cout<<"Points: ";
		cout<<points<<endl;
		cout<<"Tarikhe Ozviat: ";
		start.print(); cout<<endl;
	}
	void edit(PersonArray);
	void pointspp(){points++;}
};
class librarian:public person{
	char hoghugh[70];
	char saate_kar[120];
	bool bimeh;
	int tedad;
	int pass;
	date start;
	public:
	librarian(){
		strcpy(mellic,"null");
		tedad=0;
		type=2;
	}
	librarian(librarian &l1){
		type=l1.type;
		strcpy(fname,l1.fname);
		strcpy(lname,l1.lname);
		strcpy(mellic,l1.mellic);
		born=l1.born;
		strcpy(born_place,l1.born_place);
		strcpy(father_name,l1.father_name);
		strcpy(mother_name,l1.mother_name);
		jensiat=l1.jensiat;
		strcpy(adress,l1.adress);
		strcpy(mobile_num,l1.mobile_num);
		strcpy(telephone,l1.telephone);
		strcpy(tahsilat,l1.tahsilat);
		tedad=l1.tedad;
		start=l1.start;
		pass=l1.pass;
		strcpy(hoghugh,l1.hoghugh);
		strcpy(saate_kar,l1.saate_kar);
		bimeh=l1.bimeh;
	}
	person* clone(){return new librarian(*this);}
	void input(PersonArray);
	void save_txt(ostream &f1){
		f1<<type<<endl;
		f1<<fname<<endl;
		f1<<lname<<endl;
		f1<<mellic<<endl;
		f1<<born.year<<endl;
		f1<<born.month<<endl;
		f1<<born.day<<endl;
		f1<<born_place<<endl;
		f1<<father_name<<endl;
		f1<<mother_name<<endl;
		f1<<jensiat<<endl;
		f1<<adress<<endl;
		f1<<mobile_num<<endl;
		f1<<telephone<<endl;
		f1<<tahsilat<<endl;
		f1<<tedad<<endl;
		f1<<start.year<<endl;
		f1<<start.month<<endl;
		f1<<start.day<<endl;
		f1<<pass<<endl;
		f1<<hoghugh<<endl;
		f1<<saate_kar<<endl;
		f1<<bimeh<<endl;
	}
	void load_txt(istream &f1){
		f1.getline(fname,30);
		f1.getline(lname,30);
		f1.getline(mellic,15);
		f1>>born.year;
		f1.ignore();
		f1>>born.month;
		f1.ignore();
		f1>>born.day;
		f1.ignore();
		f1.getline(born_place,30);
		f1.getline(father_name,30);
		f1.getline(mother_name,30);
		f1>>jensiat;
		f1.ignore();
		f1.getline(adress,200);
		f1.getline(mobile_num,20);
		f1.getline(telephone,20);
		f1.getline(tahsilat,60);
		f1>>tedad;
		f1.ignore();
		f1>>start.year;
		f1.ignore();
		f1>>start.month;
		f1.ignore();
		f1>>start.day;
		f1.ignore();
		f1>>pass;
		f1.ignore();
		f1.getline(hoghugh,70);
		f1.getline(saate_kar,120);
		f1>>bimeh;
		f1.ignore();
	}
	void print(){
		cout<<endl<<"Moshakhasate Ketabdar: "<<endl;
		cout<<"First Name: ";
		cout<<fname<<endl;
		cout<<"Last Name: ";
		cout<<lname<<endl;
		cout<<"Melli Code: ";
		cout<<mellic<<endl;
		cout<<"Born Date: ";
		born.print(); cout<<endl;
		cout<<"Born Place: ";
		cout<<born_place<<endl;
		cout<<"Father Name: ";
		cout<<father_name<<endl;
		cout<<"Mother Name: ";
		cout<<mother_name<<endl;
		cout<<"Jensiat: ";
		if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
		cout<<"Adress: ";
		cout<<endl<<adress<<endl;
		cout<<"Mobile Number: ";
		cout<<mobile_num<<endl;
		cout<<"Telephone: ";
		cout<<telephone<<endl;
		cout<<"Tahsilat: ";
		cout<<endl<<tahsilat<<endl;
		cout<<"Tarikhe Estekhdam: ";
		start.print(); cout<<endl;
		cout<<"Hoghugh: ";
		cout<<hoghugh<<endl;
		cout<<"Saate Kar: ";
		cout<<saate_kar<<endl;
		cout<<"Points: ";
		cout<<tedad<<endl;
		cout<<"Bimeh: ";
		if(bimeh) cout<<"Darad"<<endl; else cout<<"Nadarad"<<endl;
	}
	void pointspp(){tedad++;}
	int sendpass(){return pass;}
	void edit(PersonArray);
};
class servant:public person{
	char hoghugh[50];
	char saate_kar[50];
	bool bimeh;
	date start;
	public:
	servant(){strcpy(mellic,"null"); type=3;}
	servant(servant &s1){
		type=s1.type;
		strcpy(fname,s1.fname);
		strcpy(lname,s1.lname);
		strcpy(mellic,s1.mellic);
		born=s1.born;
		strcpy(born_place,s1.born_place);
		strcpy(father_name,s1.father_name);
		strcpy(mother_name,s1.mother_name);
		jensiat=s1.jensiat;
		strcpy(adress,s1.adress);
		strcpy(mobile_num,s1.mobile_num);
		strcpy(telephone,s1.telephone);
		strcpy(tahsilat,s1.tahsilat);
		start=s1.start;
		strcpy(hoghugh,s1.hoghugh);
		strcpy(saate_kar,s1.saate_kar);
		bimeh=s1.bimeh;
	}
	person* clone(){return new servant(*this);}
	void input(PersonArray);
	void save_txt(ostream &f1){
		f1<<type<<endl;
		f1<<fname<<endl;
		f1<<lname<<endl;
		f1<<mellic<<endl;
		f1<<born.year<<endl;
		f1<<born.month<<endl;
		f1<<born.day<<endl;
		f1<<born_place<<endl;
		f1<<father_name<<endl;
		f1<<mother_name<<endl;
		f1<<jensiat<<endl;
		f1<<adress<<endl;
		f1<<mobile_num<<endl;
		f1<<telephone<<endl;
		f1<<tahsilat<<endl;
		f1<<start.year<<endl;
		f1<<start.month<<endl;
		f1<<start.day<<endl;
		f1<<hoghugh<<endl;
		f1<<saate_kar<<endl;
		f1<<bimeh<<endl;
	}
	void load_txt(istream &f1){
		f1.getline(fname,30);
		f1.getline(lname,30);
		f1.getline(mellic,15);
		f1>>born.year;
		f1.ignore();
		f1>>born.month;
		f1.ignore();
		f1>>born.day;
		f1.ignore();
		f1.getline(born_place,30);
		f1.getline(father_name,30);
		f1.getline(mother_name,30);
		f1>>jensiat;
		f1.ignore();
		f1.getline(adress,200);
		f1.getline(mobile_num,20);
		f1.getline(telephone,20);
		f1.getline(tahsilat,60);
		f1>>start.year;
		f1.ignore();
		f1>>start.month;
		f1.ignore();
		f1>>start.day;
		f1.ignore();
		f1.getline(hoghugh,70);
		f1.getline(saate_kar,120);
		f1>>bimeh;
		f1.ignore();
	}
	void print(){
		cout<<endl<<"Moshakhasate Mostakhdem: "<<endl;
		cout<<"First Name: ";
		cout<<fname<<endl;
		cout<<"Last Name: ";
		cout<<lname<<endl;
		cout<<"Melli Code: ";
		cout<<mellic<<endl;
		cout<<"Born Date: ";
		born.print(); cout<<endl;
		cout<<"Born Place: ";
		cout<<born_place<<endl;
		cout<<"Father Name: ";
		cout<<father_name<<endl;
		cout<<"Mother Name: ";
		cout<<mother_name<<endl;
		cout<<"Jensiat: ";
		if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
		cout<<"Adress: ";
		cout<<endl<<adress<<endl;
		cout<<"Mobile Number: ";
		cout<<mobile_num<<endl;
		cout<<"Telephone: ";
		cout<<telephone<<endl;
		cout<<"Tahsilat: ";
		cout<<endl<<tahsilat<<endl;
		cout<<"Tarikhe Estekhdam: ";
		start.print(); cout<<endl;
		cout<<"Hoghugh: ";
		cout<<hoghugh<<endl;
		cout<<"Saate Kar: ";
		cout<<saate_kar<<endl;
		cout<<"Bimeh: ";
		if(bimeh) cout<<"Darad"<<endl; else cout<<"Nadarad"<<endl;
	}
	void edit(PersonArray);	
};
class thing{
	protected:
	char name[120];
	int npages;
	char subject[50];
	int cost;
	int code;
	int type;
	bool available;
	int tedad;
	public:
	thing(){}
	int sendtype(){return type;}
	int sendcode(){return code;}
	void borrow(){available=0; tedad++;}
	void give_back(){available=1;}
	virtual void save_txt(ostream&)=0; 
	virtual void load_txt(istream&)=0;
	virtual thing* clone()=0;
	virtual void edit(ThingArray)=0;
	virtual void input(ThingArray)=0;
	virtual void print()=0;
	friend class ThingArray;
	friend class lend;
};
class book:public thing{
	char writer[60];
	char nasher[60];
	int chap_sal;
	int number;
	public:
	book(){code=0; type=1; available=1; tedad=0;}
	book(book &b1){
		tedad=b1.tedad;
		type=b1.type;
		strcpy(name,b1.name);
		npages=b1.npages;
		strcpy(subject,b1.subject);
		cost=b1.cost;
		code=b1.code;
		strcpy(writer,b1.writer);
		strcpy(nasher,b1.nasher);
		chap_sal=b1.chap_sal;
		number=b1.number;
		available=b1.available;
	}
	thing* clone(){return new book(*this);}
	void save_txt(ostream &f1){
		f1<<type<<endl;
		f1<<tedad<<endl;
		f1<<available<<endl;
		f1<<name<<endl;
		f1<<npages<<endl;
		f1<<subject<<endl;
		f1<<cost<<endl;
		f1<<code<<endl;
		f1<<writer<<endl;
		f1<<nasher<<endl;
		f1<<chap_sal<<endl;
		f1<<number<<endl;
	}
	void load_txt(istream &f1){
		f1>>tedad;
		f1.ignore();
		f1>>available;
		f1.ignore();
		f1.getline(name,120);
		f1>>npages;
		f1.ignore();
		f1.getline(subject,50);
		f1>>cost;
		f1.ignore();
		f1>>code;
		f1.ignore();
		f1.getline(writer,60);
		f1.getline(nasher,60);
		f1>>chap_sal;
		f1.ignore();
		f1>>number;
		f1.ignore();
	}
	void edit(ThingArray);
	void input(ThingArray);
	void print(){
		cout<<endl<<"Moshakhasate Ketab: "<<endl;
		cout<<"Name Ketab: ";
		cout<<name<<endl;
		cout<<"Mojudi: ";
		if(available) cout<<"Darad"<<endl; else cout<<"Nadarad"<<endl;
		cout<<"Tedade Safahat: ";
		cout<<npages<<endl;
		cout<<"Mowzue Ketab: ";
		cout<<subject<<endl;
		cout<<"Gheimat: ";
		cout<<cost<<" Rials"<<endl;
		cout<<"Kode Shenasaeiye Mahsul: ";
		cout<<code<<endl;
		cout<<"Name Nevisandeh: ";
		cout<<writer<<endl;
		cout<<"Nashere Ketab: ";
		cout<<nasher<<endl;
		cout<<"Sale Chap: ";
		cout<<chap_sal<<endl;
		cout<<"Shomare Ketab: ";
		cout<<number<<endl;
		cout<<"Tedade Amanat: ";
		cout<<tedad<<endl;
	}
	friend class lend;
};
class mag:public thing{
	char sardabir[60];
	char dowreh[60];
	date tenteshar;
	int number;
	public:
	mag(){code=0; type=2; available=1; tedad=0;}
	mag(mag &m1){
		type=m1.type;
		strcpy(name,m1.name);
		npages=m1.npages;
		strcpy(subject,m1.subject);
		cost=m1.cost;
		code=m1.code;
		strcpy(sardabir,m1.sardabir);
		strcpy(dowreh,m1.dowreh);
		tenteshar=m1.tenteshar;
		number=m1.number;
		available=m1.available;
		tedad=m1.tedad;
	}
	thing* clone(){return new mag(*this);}
	void save_txt(ostream &f1){
		f1<<type<<endl;
		f1<<tedad<<endl;
		f1<<available<<endl;
		f1<<name<<endl;
		f1<<npages<<endl;
		f1<<subject<<endl;
		f1<<cost<<endl;
		f1<<code<<endl;
		f1<<sardabir<<endl;
		f1<<dowreh<<endl;
		f1<<tenteshar.year<<endl;
		f1<<tenteshar.month<<endl;
		f1<<tenteshar.day<<endl;
		f1<<number<<endl;
	}
	void load_txt(istream &f1){
		f1>>tedad;
		f1.ignore();
		f1>>available;
		f1.ignore();
		f1.getline(name,120);
		f1>>npages;
		f1.ignore();
		f1.getline(subject,50);
		f1>>cost;
		f1.ignore();
		f1>>code;
		f1.ignore();
		f1.getline(sardabir,60);
		f1.getline(dowreh,60);
		f1>>tenteshar.year;
		f1.ignore();
		f1>>tenteshar.month;
		f1.ignore();
		f1>>tenteshar.day;
		f1.ignore();
		f1>>number;
		f1.ignore();
	}
	void edit(ThingArray);
	void input(ThingArray);
	void print(){
		cout<<endl<<"Moshakhasate Nashriyeh: "<<endl;
		cout<<"Name Nashriyeh: ";
		cout<<name<<endl;
		cout<<"Mojudi: ";
		if(available) cout<<"Darad"<<endl; else cout<<"Nadarad"<<endl;
		cout<<"Tedade Safahat: ";
		cout<<npages<<endl;
		cout<<"Mowzue Nashriyeh: ";
		cout<<subject<<endl;
		cout<<"Gheimat(Rial): ";
		cout<<cost<<endl;
		cout<<"Kode Shenasaeiye Mahsul: ";
		cout<<code<<endl;
		cout<<"Name Sardabir: ";
		cout<<sardabir<<endl;
		cout<<"Tarikhe Enteshar: ";
		tenteshar.print(); cout<<endl;
		cout<<"Dowreye Enteshar: ";
		cout<<dowreh<<endl;
		cout<<"Shomareh: ";
		cout<<number<<endl;
		cout<<"Tedade Amanat: ";
		cout<<tedad<<endl;
	}	
	friend class lend;
};
class PersonArray{
	//public;
	public:
	vector<person *> data;
	public:
	PersonArray(int number=1){
		if(number>0){
			data.resize(number);
			for(int i=0; data.size()>(unsigned)i; i++) data[i]=0;
		}
		else cout<<"Error in number of array fields"<<endl;	
	}
	PersonArray(PersonArray &pa){
		data.clear();
		data.resize(pa.data.size());
		for(int i=0; pa.data.size()>(unsigned)i && pa.data.at(i)!=0; i++) data.at(i)=pa.data.at(i)->clone();
	}
	void append(const char* t){
		int possible, nxtindex;
		unsigned int oldt,newt;
		possible=0;
		for(nxtindex=0; data.size()>(unsigned)nxtindex; nxtindex++) if(data.at(nxtindex)==0){ possible=1; break;}
		if(possible==0){
			oldt=data.size();
			newt=2*oldt;
			data.resize(newt);
			for(; data.size()>(unsigned)nxtindex; nxtindex++) data.at(nxtindex)=0;
			//cout<<endl<<data.size()<<endl;
			possible=1;
			nxtindex=oldt;
		}
		if(strcmp(t,"member") && strcmp(t,"librarian") && strcmp(t,"servant")) possible=0;
		if(possible==1){
			cout<<endl<<nxtindex<<endl;
			if(!strcmp(t,"member")){ data.at(nxtindex)=new member; data.at(nxtindex)->input(*this);}
			if(!strcmp(t,"librarian")){ data.at(nxtindex)=new librarian; data.at(nxtindex)->input(*this);}
			if(!strcmp(t,"servant")){ data.at(nxtindex)=new servant; data.at(nxtindex)->input(*this);}
		}
		else cout<<endl<<"Error in type"<<endl;
	}
	int checkmellic(char* mellic_index){
		for(int i=0; data.size()>(unsigned)i && data.at(i)!=0; i++) if(!strcmp(data.at(i)->sendmellic(),mellic_index)) return i;
		return -1;
	}
	void delete_element(int index){
		data.erase(data.begin()+index);
	}
	void edit_element(int index){
		data.at(index)->edit(*this);
	}
	void save_txt(){
		int tedad;
		//cout<<endl<<data.size()<<endl;
		//for(int i=0; data.size()>(unsigned)i; i++) cout<<endl<<data.at(i)<<endl;
		for(tedad=0; data.size()>(unsigned)tedad && data.at(tedad)!=0; tedad++);
		fstream f1("people.txt" , ios::out);
		//cout<<endl<<tedad<<endl;
		f1<<tedad<<endl;
		for(int i=0; tedad>i; i++) data.at(i)->save_txt(f1);
		f1.close();
	}
	void load_txt(){
		if(!ifstream("people.txt")) return;
		int tedad;
		int tp;
		data.clear();
		fstream f1("people.txt",ios::in);
		f1>>tedad;
		f1.ignore();
		data.resize(tedad);
		for(int i=0; tedad>i; i++){
			f1>>tp;
			f1.ignore();
			if(tp==1){ data.at(i)=new member; data.at(i)->load_txt(f1);}
			if(tp==2){ data.at(i)=new librarian; data.at(i)->load_txt(f1);}
			if(tp==3){ data.at(i)=new servant; data.at(i)->load_txt(f1);}
		}
		f1.close();
	}	
	person* operator[](char* mellic_index){
		for(int i=0; data.size()>(unsigned)i && data.at(i)!=0; i++) if(!strcmp(mellic_index,data.at(i)->sendmellic())) return data.at(i);
		throw "User Not Found.";
	}
	friend void person_manage(PersonArray &);
	friend class lend;
};
class ThingArray{
	vector <thing *> data;
	public:
	ThingArray(int number=1){
		if(number>0){
			data.resize(number);
			for(int i=0; data.size()>(unsigned)i; i++) data[i]=0;
		}
		else cout<<"Error in number of array fields"<<endl;	
	}
	ThingArray(ThingArray &ta){
		data.clear();
		data.resize(ta.data.size());
		for(unsigned int i=0; ta.data.size()>i && ta.data.at(i)!=0; i++) data.at(i)=ta.data.at(i)->clone();
			/*if(ta.data.at(i)->type==1){ data.at(i)=new book; *(data.at(i))=*(ta.data.at(i));}
			if(ta.data.at(i)->type==2){ data.at(i)=new mag; *(data.at(i))=*(ta.data.at(i));}*/
	}
	void append(const char* t){
		int possible, nxtindex;
		unsigned int oldt,newt;
		possible=0;
		for(nxtindex=0; data.size()>(unsigned)nxtindex; nxtindex++) if(data.at(nxtindex)==0){ possible=1; break;}
		if(possible==0){
			oldt=data.size();
			newt=2*oldt;
			data.resize(newt);
			for(; data.size()>(unsigned)nxtindex; nxtindex++) data.at(nxtindex)=0;
			possible=1;
			nxtindex=oldt;
		}
		if(strcmp(t,"book") && strcmp(t,"mag")) possible=0;
		if(possible==1){
			if(!strcmp(t,"book")){ data.at(nxtindex)=new book; data.at(nxtindex)->input(*this);}
			if(!strcmp(t,"mag")){ data.at(nxtindex)=new mag; data.at(nxtindex)->input(*this);}
		}
		else cout<<endl<<"Error in type"<<endl;
	}
	int checkcode(int code_index){
		for(int i=0; data.size()>(unsigned)i && data.at(i)!=0; i++) if(code_index==data.at(i)->sendcode()) return i;
		return -1;
	}
	void delete_element(int index){
		data.erase(data.begin()+index);
	}
	void edit_element(int index){
		data.at(index)->edit(*this);
	}
	void save_txt(){
		int tedad;
		//cout<<endl<<data.size()<<endl;
		//for(int i=0; data.size()>(unsigned)i; i++) cout<<endl<<data.at(i)<<endl;
		for(tedad=0; data.size()>(unsigned)tedad && data.at(tedad)!=0; tedad++);
		fstream f1("things.txt" , ios::out);
		//cout<<endl<<tedad<<endl;
		f1<<tedad<<endl;
		for(int i=0; tedad>i; i++) data.at(i)->save_txt(f1);
		f1.close();
		
	}
	void load_txt(){
		if(!ifstream("things.txt")) return;
		int tedad;
		int tp;
		data.clear();
		fstream f1("things.txt",ios::in);
		f1>>tedad;
		f1.ignore();
		data.resize(tedad);
		for(int i=0; tedad>i; i++){
			f1>>tp;
			f1.ignore();
			if(tp==1){ data.at(i)=new book; data.at(i)->load_txt(f1);}
			if(tp==2){ data.at(i)=new mag; data.at(i)->load_txt(f1);}
		}
		f1.close();
	}
	thing* operator[](int code_index){
		for(int i=0; data.size()>(unsigned)i && data.at(i)!=0; i++) if(code_index==data.at(i)->sendcode()) return data.at(i);
		throw "User Not Found.";
	}
	friend void things_manage(ThingArray &);
	friend class lend;
};
/*class lend{
	//librarian lib2;
	person* lib;
	person* lib_back;
	person* mem;
	thing *tng;
	bool empty;
	bool close;
	public:
	lend(){empty=true; lib_back=0; close=false;}
	void input(PersonArray pa,ThingArray ta,LendArray la){
		char lib_mellic[15],mem_mellic[15];
		int lib_pass,tng_code;
		int c;
		cout<<"Kode Melli Va Passworde Ketabdar:"<<endl;
		cout<<"Kode Melli: ";
		cin>>lib_mellic;
		cin.ignore();
		cout<<"Password: ";
		lib_pass=enternum();
		if(pa.checkmellic(lib_mellic)==-1){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
		if(pa[lib_mellic]->sendtype()!=2){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
		if(lib_pass!=pa[lib_mellic]->sendpass()){ cout<<endl<<"Kode Melli Va Password Motabeghat Nadarad"; return;}
		cout<<endl<<"Kode Mellie Ozv Ra Vared Konid: ";
		cin>>mem_mellic;
		cin.ignore();
		while(pa.checkmellic(mem_mellic)==-1 || pa[mem_mellic]->sendtype()!=1){
			cout<<"In Ozv Vojud Nadarad"<<endl;
			cout<<"Edame midahid?(1:Yes | 2:No): ";
			c=choice(1,2);
			if(c==1){
				cout<<endl<<"Kode Mellie Ozv Ra Vared Konid: ";
				cin>>mem_mellic;
				cin.ignore();
			}
			if(c==2) break;
		}
		if(c==2) return;
		cout<<"Kode Mahsul Ra Vared Konid: ";
		tng_code=enternum();
		while(ta.checkcode(tng_code)==-1 || la.check_code(tng_code)!=-1){
			if(ta.checkcode(tng_code)==-1) cout<<"In Mahsul Vojud Nadarad"<<endl;
			if(la.check_code(tng_code)!=-1) cout<<"In Mahsul dar Dastras Nist"<<endl;
			cout<<"Edame midahid?(1:Yes | 2:No): ";
			c=choice(1,2);
			if(c==1){
				cout<<endl<<"Kode Mahsul Ra Vared Konid: ";
				tng_code=enternum();
			}
			if(c==2) break;
		}
		if(c==2) return;
		lib=new librarian;
		mem=new member;
		//lib2=*(pa[lib_mellic]);
		*lib= *(pa[lib_mellic]);
		pa[lib_mellic]->pointspp();
		*mem= *(pa[mem_mellic]);
		pa[mem_mellic]->pointspp();
		if(ta[tng_code]->sendtype()==1){tng=new book; *tng=*(ta[tng_code]);}
		if(ta[tng_code]->sendtype()==2){tng=new mag; *tng=*(ta[tng_code]);}
		tng->borrow();
		empty=false;
	}
	void close(LendArray &la){
		char lib_mellic[15];
		int tng_code,lib_pass;
		int c;
		cout<<"Kode Melli Va Passworde Ketabdar:"<<endl;
		cout<<"Kode Melli: ";
		cin>>lib_mellic;
		cin.ignore();
		cout<<"Password: ";
		lib_pass=enternum();
		if(pa.checkmellic(lib_mellic)==-1){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
		if(pa[lib_mellic]->sendtype()!=2){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
		if(lib_pass!=pa[lib_mellic]->sendpass()){ cout<<endl<<"Kode Melli Va Password Motabeghat Nadarad"; return;}
		cout<<"Kode Ketabe Gharz Gerefte Shode Ra Vared Konid: ";
		tng_code=enternum();
		while(la.check_code(tng_code==-1){
			
	friend class LendArray;
};*/
int open_lend(vector<lend>,int);
class lend{
	person* lib;
	person* lib_back;
	person* mem;
	thing *tng;
	bool empty;
	bool close;
	public:
	lend(){empty=true; lib_back=0; close=false;}
	bool sendempty(){return empty;}
	bool sendclose(){return close;}
	void input(PersonArray &pa, ThingArray &ta,vector<lend> &lends){
		char lib_mellic[15],mem_mellic[15];
		int lib_pass,tng_code;
		int c;
		cout<<"Kode Melli Va Passworde Ketabdar:"<<endl;
		cout<<"Kode Melli: ";
		cin>>lib_mellic;
		cin.ignore();
		cout<<"Password: ";
		lib_pass=enternum();
		if(pa.checkmellic(lib_mellic)==-1){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
		if(pa[lib_mellic]->sendtype()!=2){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
		if(lib_pass!=pa[lib_mellic]->sendpass()){ cout<<endl<<"Kode Melli Va Password Motabeghat Nadarad"; return;}
		cout<<endl<<"Kode Mellie Ozv Ra Vared Konid: ";
		cin>>mem_mellic;
		cin.ignore();
		while(pa.checkmellic(mem_mellic)==-1 || pa[mem_mellic]->sendtype()!=1){
			cout<<"In Ozv Vojud Nadarad"<<endl;
			cout<<"Edame midahid?(1:Yes | 2:No): ";
			c=choice(1,2);
			if(c==1){
				cout<<endl<<"Kode Mellie Ozv Ra Vared Konid: ";
				cin>>mem_mellic;
				cin.ignore();
			}
			if(c==2) break;
		}
		if(c==2) return;
		cout<<"Kode Mahsul Ra Vared Konid: ";
		tng_code=enternum();
		while(ta.checkcode(tng_code)==-1 || open_lend(lends,tng_code)!=-1){
			if(ta.checkcode(tng_code)==-1) cout<<"In Mahsul Vojud Nadarad"<<endl;
			else if(open_lend(lends,tng_code)!=-1) cout<<"In Mahsul dar Dastras Nist"<<endl;
			cout<<"Edame midahid?(1:Yes | 2:No): ";
			c=choice(1,2);
			if(c==1){
				cout<<endl<<"Kode Mahsul Ra Vared Konid: ";
				tng_code=enternum();
			}
			if(c==2) break;
		}
		if(c==2) return;
		//lib2=*(pa[lib_mellic]);
		lib= pa[lib_mellic]->clone();;
		pa[lib_mellic]->pointspp();
		mem= pa[mem_mellic]->clone();
		pa[mem_mellic]->pointspp();
		tng=ta[tng_code]->clone();
		ta[tng_code]->borrow();
		empty=false;
	}
	void closing(PersonArray pa,ThingArray &ta,char lib_mellic[15]){
		lib_back= pa[lib_mellic]->clone();
		ta[tng->sendcode()]->give_back();
		close=true;
	}
	void print(){
		cout<<endl<<"Sabt Konandeh: "<<lib->fname<<" "<<lib->lname<<" | "<<lib->sendmellic();
		cout<<endl<<"Gharz Girandeh: "<<mem->fname<<" "<<mem->lname<<" | "<<mem->sendmellic();
		cout<<endl<<"Name Mahsul: "<<tng->name<<" | "<<tng->sendcode();
		if(close==true){
			cout<<endl<<"Returned"<<endl;
			cout<<"Sabt Konandehe Bargasht: "<<lib_back->fname<<" "<<lib_back->lname<<" | "<<lib_back->sendmellic()<<endl;
		}
		else cout<<endl<<"Unreturned"<<endl;
	}
	void save_txt(ostream &f1){
		f1<<empty<<endl;
		if(empty==false){
			lib->save_txt(f1);
			mem->save_txt(f1);
			tng->save_txt(f1);
			f1<<close<<endl;
			if(close==true) lib_back->save_txt(f1);
		}
	}
	void load_txt(istream &f1){
		int type;
		f1>>empty;
		f1.ignore();
		if(empty==false){
			f1>>type; f1.ignore(); lib=new librarian; lib->load_txt(f1);
			f1>>type; f1.ignore(); mem=new member; mem->load_txt(f1);
			f1>>type; f1.ignore();
			if(type==1) tng=new book;
			else if(type==2) tng=new mag;
			tng->load_txt(f1);
			f1>>close;
			f1.ignore();
			if(close==true){ f1>>type; f1.ignore(); lib_back=new librarian; lib_back->load_txt(f1);}
		}
		//cout<<endl<<f1.tellg()<<endl;
	}
	friend int open_lend(vector<lend>,int);
	friend void show_livery(ThingArray,vector<lend>);
	friend void liveries_load_txt(vector<lend> &);
};
/*class LendArray{
	PersonArray pa;
	ThingArray ta;
	public:
	vector <lend> borrows;
	public:
	LendArray(PersonArray p, ThingArray t, int n){
		pa=p;
		ta=t;
		if(n>0) borrows.resize(n);
		else borrows.resize(1);
	}
	int check_code(int tng_code){
		for(unsigned int i=0; borrows.size()>i; i++){
			if(borrows.at(i).tng->sendcode()==tng_code) if(borrows.at(i).close==false) return i;
		}
		return -1;
	}
	lend operator[](int tng_code){
		for(unsigned int i=0; borrows.size()>i; i++){
			if(borrows.at(i).tng->sendcode()==tng_code) if(borrows.at(i).close==false) return borrows.at(i);
		}
		throw "The Lend Data Not Found.";
	}
	void input(){
		char lib_mellic[15],mem_mellic[15];
		int lib_pass,tng_code;
		int c,possible;
		unsigned int oldt,newt,nxt;
		cout<<"Kode Melli Va Passworde Ketabdar:"<<endl;
		cout<<"Kode Melli: ";
		cin>>lib_mellic;
		cin.ignore();
		cout<<"Password: ";
		lib_pass=enternum();
		if(pa.checkmellic(lib_mellic)==-1){cout<<endl<<pa.data.size()<<endl<<pa.data.at(0)->mellic; cout<<endl<<"Kode Melli Motabar Nist."; return;}
		if(pa[lib_mellic]->sendtype()!=2){ cout<<endl<<"Kode Melli Motabar2 Nist."; return;}
		if(lib_pass!=pa[lib_mellic]->sendpass()){ cout<<endl<<"Kode Melli Va Password Motabeghat Nadarad"; return;}
		cout<<endl<<"Kode Mellie Ozv Ra Vared Konid: ";
		cin>>mem_mellic;
		cin.ignore();
		while(pa.checkmellic(mem_mellic)==-1 || pa[mem_mellic]->sendtype()!=1){
			cout<<"In Ozv Vojud Nadarad"<<endl;
			cout<<"Edame midahid?(1:Yes | 2:No): ";
			c=choice(1,2);
			if(c==1){
				cout<<endl<<"Kode Mellie Ozv Ra Vared Konid: ";
				cin>>mem_mellic;
				cin.ignore();
			}
			if(c==2) break;
		}
		if(c==2) return;
		cout<<"Kode Mahsul Ra Vared Konid: ";
		tng_code=enternum();
		while(ta.checkcode(tng_code)==-1 || check_code(tng_code)!=-1){
			if(ta.checkcode(tng_code)==-1) cout<<"In Mahsul Vojud Nadarad"<<endl;
			if(check_code(tng_code)!=-1) cout<<"In Mahsul dar Dastras Nist"<<endl;
			cout<<"Edame midahid?(1:Yes | 2:No): ";
			c=choice(1,2);
			if(c==1){
				cout<<endl<<"Kode Mahsul Ra Vared Konid: ";
				tng_code=enternum();
			}
			if(c==2) break;
		}
		if(c==2) return;
		possible=0;
		for(nxt=0; borrows.size()>nxt && borrows[nxt].empty==true; nxt++){ possible=1; break;}
		if(possible==0){
			oldt=borrows.size();
			newt=2*oldt;
			borrows.resize(newt);
			for(; borrows.size()>nxt; nxt++) borrows[nxt].empty=true;
			possible=1;
			nxt=oldt;
		}
		borrows[nxt].lib=new librarian;
		borrows[nxt].mem=new member;
		//lib2=*(pa[lib_mellic]);
		*(borrows[nxt].lib)= *(pa[lib_mellic]);
		pa[lib_mellic]->pointspp();
		*(borrows[nxt].mem)= *(pa[mem_mellic]);
		pa[mem_mellic]->pointspp();
		if(ta[tng_code]->sendtype()==1){borrows[nxt].tng=new book; *(borrows[nxt].tng)=*(ta[tng_code]);}
		if(ta[tng_code]->sendtype()==2){borrows[nxt].tng=new mag; *(borrows[nxt].tng)=*(ta[tng_code]);}
		borrows[nxt].tng->borrow();
		borrows[nxt].empty=false;
	}
};*/
void person_manage(PersonArray&);
void add_person(PersonArray&);
void delete_person(PersonArray&);
void edit_person(PersonArray&);
void show_person(PersonArray&);
void things_manage(ThingArray&);
void add_thing(ThingArray&);
void delete_thing(ThingArray&);
void edit_thing(ThingArray&);
void show_thing(ThingArray&);
void lend_manage(PersonArray &, ThingArray &,vector<lend> &);
void add_livery(PersonArray &, ThingArray &,vector<lend> &);
void closing_livery(PersonArray, ThingArray &,vector<lend> &);
void show_livery(ThingArray,vector<lend>);
void liveries_save_txt(vector<lend> &);
void liveries_load_txt(vector<lend> &);
void save(PersonArray ,ThingArray ,vector<lend> );
void load(PersonArray &,ThingArray &,vector<lend> &);

int main(){
	int c;
	ThingArray things(5);
	PersonArray people(5);
	//people.load_txt(); things.load_txt();
	vector <lend> lends(5);
	//lends[0].input(people,things,lends);
	//lends[1].input(people,things,lends);
	//lends[0].print();
	//char lib[15];
	//cin>>lib;
	//cin.ignore();
	//lends[0].closing(people,things,lib);
	//lends[0].print();
	//LendArray lends(people,things,5);
	//people.load_txt();
	//for(int i=0; 4>i; i++) people.append("librarian");
	while(1){
		//people.append("member");
		cout<<endl<<BOLDRED<<"Main Section: "<<RESET<<endl;
		cout<<"1: People Section\n2: Stuff Section\n3: Liveries Section\n4: Save\n5: Load\n6: Exit\n";
		c=choice(1,6);
		switch(c){
			case 1: person_manage(people); break;
			case 2: things_manage(things); break;
			case 3:	lend_manage(people,things,lends); break;
			case 4:	save(people,things,lends); break;
			case 5:	load(people,things,lends); break;
			case 6: break;
		}
		if(c==6) break;
	}
	//people.save_txt();
}
int choice(int min,int max){
	char choice_char[35];
	int zarb,error,choice,t,r;
	input:
	error=0;
	cout<<endl<<"Enter Your Choice Between "<<min<<" and "<<max<<": ";
	cin>>choice_char;
	cin.ignore();
	while(choice_char[0]==0 || !checknum(choice_char)){ cout<<endl<<"You must enter a number. Enter Your Choice Between "<<min<<" and "<<max<<": "<<endl; cin>>choice_char; cin.ignore();}
	for(int i=0; choice_char[i]; i++) if(choice_char[i]>57 || choice_char[i]<48) error=1;
	while(error==1){
		cout<<endl<<"You must enter a number. Enter Your Choice Between "<<min<<" and "<<max<<": "<<endl;
		cin>>choice_char;
		cin.ignore();
		error=0;
		for(int i=0; choice_char[i]; i++) if(choice_char[i]>57 || choice_char[i]<48) error=1;
	}
	choice=0; zarb=1;
	for(t=1; choice_char[t]; t++) zarb=zarb*10;
	for(int i=0; t>i; i++){
		r= choice_char[i]-48;
		choice=choice+r*zarb;
		zarb=zarb/10;
	}
	if(!(choice>=min && choice<=max)){
		cout<<endl<<"Error!. ";
		goto input;
	}
	return choice;
}
int enternum(){
	//cout<<endl<<"Farakhani Shod"<<endl;
	int out,zarb,t,r,dowhile_index;
	char number[25];
	enter:
	dowhile_index=0;
	do{
		if(dowhile_index) cout<<"Error. Adade Vorudi Hade aksar 9 ragham mitavanad bashad. Try Again"<<endl;
		cin>>number;
		cin.ignore();
		for(t=1; number[t]; t++);
		dowhile_index=1;
	}
	while(t>9);
	for(int i=0; number[i]; i++) if(!isdigit(number[i])){ cout<<"Error! Lotfan Adade sahih vared konid. Try Again: "; goto enter; break;}
	out=0; zarb=1;
	for(t=1; number[t]; t++) zarb=zarb*10;
	for(int i=0; t>i; i++){
		r= number[i]-48;
		out=out+r*zarb;
		zarb=zarb/10;
	}
	return out;
}
bool checknum(char num[]){
	int tul;
	for(tul=0; num[tul]; tul++);
	if(tul>15) return false;
	for(int i=0; num[i]; i++) if(num[i]>57 || num[i]<48) return false;
	return true;
}
void member::input(PersonArray ppl){
	char temp_mellic[15];
	int c;
	input:
	cout<<endl<<"Entering New Member: "<<endl;
	cout<<"First Name: ";
	//cin.ignore(0,'\n');
	cin.getline(fname,30);
	cout<<"Last Name: ";
	cin.getline(lname,30);
	cout<<"Melli Code: ";
	cin>>temp_mellic;
	cin.ignore();
	while(ppl.checkmellic(temp_mellic)!=-1){
		//cout<<endl<<ppl.checkmellic(mellic)<<endl;
		cout<<"Kode Melli Tekrari Ast. Try Again."<<endl;
		cin>>temp_mellic;
		cin.ignore();
	}
	strcpy(mellic,temp_mellic);
	cout<<"Born Date: "<<endl;
	born.input();
	cout<<"Born Place: ";
	//cin.ignore(0,'\n');
	cin.getline(born_place,30);
	cout<<"Father Name: ";
	cin.getline(father_name,30);
	cout<<"Mother Name: ";
	cin.getline(mother_name,30);
	cout<<"Jensiat (0:Zan | 1:Mard): ";
	jensiat=choice(0,1);
	cout<<"Adress: ";
	//cin.ignore(0,'\n');
	cin.getline(adress,200);
	cout<<"Mobile Number: ";
	cin>>mobile_num;
	cin.ignore();
	cout<<"Telephone: ";
	cin>>telephone;
	cin.ignore();
	cout<<"Tahsilat: ";
	//cin.ignore(0,'\n');
	cin.getline(tahsilat,60);
	cout<<"Tarikhe Ozviat: "<<endl;
	start.input();
		
	cout<<endl<<endl<<"First Name: ";
	cout<<fname<<endl;
	cout<<"Last Name: ";
	cout<<lname<<endl;
	cout<<"Melli Code: ";
	cout<<mellic<<endl;
	cout<<"Born Date: ";
	born.print(); cout<<endl;
	cout<<"Born Place: ";
	cout<<born_place<<endl;
	cout<<"Father Name: ";
	cout<<father_name<<endl;
	cout<<"Mother Name: ";
	cout<<mother_name<<endl;
	cout<<"Jensiat: ";
	if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
	cout<<"Adress: ";
	cout<<endl<<adress<<endl;
	cout<<"Mobile Number: ";
	cout<<mobile_num<<endl;
	cout<<"Telephone: ";
	cout<<telephone<<endl;
	cout<<"Tahsilat: ";
	cout<<endl<<tahsilat<<endl;
	cout<<"Tarikhe Ozviat: ";
	start.print(); cout<<endl;
	if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)) cout<<endl<<RED<<"Error dar vared kardane sahihe adad."<<RESET<<endl;
	cout<<endl<<"Do You Want To Edit? (1:No | 2:Yes): ";
	c=choice(1,2);
	if(c==2) goto input;
	if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)){
		cout<<endl<<RED<<"Error dar vared kardane sahihe adad. Az ebteda etelalat ra vared konid."<<RESET<<endl;
		goto input;
	}
}
void member::edit(PersonArray ppl){
	int c;
	char temp_mellic[15];
	edit:
	cout<<endl<<"Ajabz"<<endl;
	while(1){
		cout<<endl<<"Editing Member: "<<endl;
		cout<<"Kodam Ghesmat ra Virayesh Mikonid?"<<endl;
		cout<<"1: Hame ra az Ebteda\n2: Name\n3: Melli Code\n4: Born\n5: Parents\n6: Jensiat\n7: Adres va Shomare Tamas\n8: Tahsilat\n9: Tarikhe Ozviat\n10: Enseraf"<<endl;
		c=choice(1,10);
		cout<<endl;
		switch(c){
			case 1: input(ppl); break;
			case 2:
				cout<<"First Name: ";
				//cin.ignore(0,'\n');
				cin.getline(fname,30);
				cout<<"Last Name: ";
				cin.getline(lname,30);
				break;
			case 3:
				cout<<"Melli Code: ";
				cin>>temp_mellic;
				cin.ignore();
				while(ppl.checkmellic(temp_mellic)!=-1){
					//cout<<endl<<ppl.checkmellic(mellic)<<endl;
					cout<<"Kode Melli Tekrari Ast. Try Again."<<endl;
					cin>>temp_mellic;
					cin.ignore();
				}
				break;
			case 4:
				cout<<"Born Date: "<<endl;
				born.input();
				cout<<"Born Place: ";
				//cin.ignore(0,'\n');
				break;
			case 5:
				cout<<"Father Name: ";
				//cin.ignore(0,'\n');
				cin.getline(father_name,30);
				cout<<"Mother Name: ";
				cin.getline(mother_name,30);
				break;
			case 6:
				cout<<"Jensiat (0:Zan | 1:Mard): ";
				jensiat=choice(0,1);
				break;
			case 7:
				cout<<"Adress: ";
				//cin.ignore(0,'\n');
				cin.getline(adress,200);
				cout<<"Mobile Number: ";
				cin>>mobile_num;
				cin.ignore();
				cout<<"Telephone: ";
				cin>>telephone;
				cin.ignore();
				break;
			case 8:
				cout<<"Tahsilat: ";
				//cin.ignore(0,'\n');
				cin.getline(tahsilat,60);
				break;		
			case 9:
				cout<<"Tarikhe Ozviat: "<<endl;
				start.input();
				break;
			case 10: break;
		}
		if(c==10) break;
		cout<<endl<<endl<<"First Name: ";
		cout<<fname<<endl;
		cout<<"Last Name: ";
		cout<<lname<<endl;
		cout<<"Melli Code: ";
		cout<<mellic<<endl;
		cout<<"Born Date: ";
		born.print(); cout<<endl;
		cout<<"Born Place: ";
		cout<<born_place<<endl;
		cout<<"Father Name: ";
		cout<<father_name<<endl;
		cout<<"Mother Name: ";
		cout<<mother_name<<endl;
		cout<<"Jensiat: ";
		if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
		cout<<"Adress: ";
		cout<<endl<<adress<<endl;
		cout<<"Mobile Number: ";
		cout<<mobile_num<<endl;
		cout<<"Telephone: ";
		cout<<telephone<<endl;
		cout<<"Tahsilat: ";
		cout<<endl<<tahsilat<<endl;
		cout<<"Tarikhe Ozviat: ";
		start.print(); cout<<endl;
		if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)){
			cout<<endl<<RED<<"Error dar vared kardane sahihe adad. Az ebteda etelalat ra vared konid."<<RESET<<endl;
			goto edit;
		}
	}
}
void librarian::input(PersonArray ppl){
	int c;
	char temp_mellic[15];
	input:
	cout<<endl<<"Entering New Librarian: "<<endl;
	cout<<"First Name: ";
	//cin.ignore(0,'\n');
	cin.getline(fname,30);
	cout<<"Last Name: ";
	cin.getline(lname,30);
	cout<<"Melli Code: ";
	cin>>temp_mellic;
	cin.ignore();
	while(ppl.checkmellic(temp_mellic)!=-1){
		//cout<<endl<<ppl.checkmellic(mellic)<<endl;
		cout<<"Kode Melli Tekrari Ast. Try Again."<<endl;
		cin>>temp_mellic;
		cin.ignore();
	}
	cout<<"Born Date: "<<endl;
	born.input();
	cout<<"Born Place: ";
	//cin.ignore(0,'\n');
	cin.getline(born_place,30);
	cout<<"Father Name: ";
	cin.getline(father_name,30);
	cout<<"Mother Name: ";
	cin.getline(mother_name,30);
	cout<<"Jensiat (0:Zan | 1:Mard): ";
	jensiat=choice(0,1);
	cout<<"Adress: ";
	//cin.ignore(0,'\n');
	cin.getline(adress,200);
	cout<<"Mobile Number: ";
	cin>>mobile_num;
	cin.ignore();
	cout<<"Telephone: ";
	cin>>telephone;
	cin.ignore();
	cout<<"Tahsilat: ";
	//cin.ignore(0,'\n');
	cin.getline(tahsilat,60);
	cout<<"Tarikhe Estekhdam: "<<endl;
	start.input();
	cout<<"Hoghugh: ";
	//cin.ignore(0,'\n');
	cin.getline(hoghugh,70);
	cout<<"Saate Kar: ";
	cin.getline(saate_kar,120);
	cout<<"Bimeh (0:Na | 1:Baleh): ";
	bimeh=choice(0,1);
	cout<<"Password(Hade Aksar 9 Ragham): ";
	pass=enternum();
		
	cout<<endl<<endl<<"First Name: ";
	cout<<fname<<endl;
	cout<<"Last Name: ";
	cout<<lname<<endl;
	cout<<"Melli Code: ";
	cout<<mellic<<endl;
	cout<<"Born Date: ";
	born.print(); cout<<endl;
	cout<<"Born Place: ";
	cout<<born_place<<endl;
	cout<<"Father Name: ";
	cout<<father_name<<endl;
	cout<<"Mother Name: ";
	cout<<mother_name<<endl;
	cout<<"Jensiat: ";
	if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
	cout<<"Adress: ";
	cout<<endl<<adress<<endl;
	cout<<"Mobile Number: ";
	cout<<mobile_num<<endl;
	cout<<"Telephone: ";
	cout<<telephone<<endl;
	cout<<"Tahsilat: ";
	cout<<endl<<tahsilat<<endl;
	cout<<"Tarikhe Estekhdam: ";
	start.print(); cout<<endl;
	cout<<"Hoghugh: ";
	cout<<hoghugh<<endl;
	cout<<"Saate Kar: ";
	cout<<saate_kar<<endl;
	cout<<"Bimeh: ";
	if(bimeh) cout<<"Darad"<<endl; else cout<<"Nadarad"<<endl;
	if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)) cout<<endl<<RED<<"Error dar vared kardane sahihe adad."<<RESET<<endl;
	cout<<endl<<"Do You Want To Edit? (1:No | 2:Yes): ";
	c=choice(1,2);
	if(c==2) goto input;
	if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)){
		cout<<endl<<RED<<"Error dar vared kardane sahihe adad. Az ebteda etelalat ra vared konid."<<RESET<<endl;
		goto input;
	}
}
void librarian::edit(PersonArray ppl){
	int c,oldpass;
	char temp_mellic[15];
	edit:
	while(1){
		cout<<endl<<"Editing Librarian: "<<endl;
		cout<<"Kodam Ghesmat ra Virayesh Mikonid?"<<endl;
		cout<<"1: Hame ra az Ebteda\n2: Name\n3: Melli Code\n4: Born\n5: Parents\n6: Jensiat\n7: Adres va Shomare Tamas\n8: Tahsilat\n9: Tarikhe Estekhdam\n10: Hoghugh\n"
		"11: Saate Kar\n12: Bimeh\n13: Password\n14: Enseraf"<<endl;
		c=choice(1,14);
		cout<<endl;
		switch(c){
			case 1: input(ppl); break;
			case 2:
				cout<<"First Name: ";
				//cin.ignore(0,'\n');
				cin.getline(fname,30);
				cout<<"Last Name: ";
				cin.getline(lname,30);
				break;
			case 3:
				cout<<"Melli Code: ";
				cin>>temp_mellic;
				cin.ignore();
				while(ppl.checkmellic(temp_mellic)!=-1){
					//cout<<endl<<ppl.checkmellic(mellic)<<endl;
					cout<<"Kode Melli Tekrari Ast. Try Again."<<endl;
					cin>>temp_mellic;
					cin.ignore();
				}
				break;
			case 4:
				cout<<"Born Date: "<<endl;
				born.input();
				cout<<"Born Place: ";
				//cin.ignore(0,'\n');
				break;
			case 5:
				cout<<"Father Name: ";
				//cin.ignore(0,'\n');
				cin.getline(father_name,30);
				cout<<"Mother Name: ";
				cin.getline(mother_name,30);
				break;
			case 6:
				cout<<"Jensiat (0:Zan | 1:Mard): ";
				jensiat=choice(0,1);
				break;
			case 7:
				cout<<"Adress: ";
				//cin.ignore(0,'\n');
				cin.getline(adress,200);
				cout<<"Mobile Number: ";
				cin>>mobile_num;
				cin.ignore();
				cout<<"Telephone: ";
				cin>>telephone;
				cin.ignore();
				break;
			case 8:
				cout<<"Tahsilat: ";
				//cin.ignore(0,'\n');
				cin.getline(tahsilat,60);
				break;		
			case 9:
				cout<<"Tarikhe Ozviat: "<<endl;
				start.input();
				break;
			case 10:
				start.print(); cout<<endl;
				cout<<"Hoghugh: ";
				break;
			case 11:
				cout<<"Saate Kar: ";
				cin.getline(saate_kar,120);
				break;
			case 12:
				cout<<"Hoghugh: ";
				//cin.ignore(0,'\n');
				cin.getline(hoghugh,70);
				break;
			case 13:
			
				cout<<"Enter Recent Password: ";
				cin>>oldpass;
				cin.ignore();
				if(oldpass==pass){
					cout<<"Enter New Password: ";
					pass=enternum();
				}
				else cout<<"Wrong Password"<<endl;
				break;
			case 14: break;
		}
		if(c==14) break;
		cout<<endl<<endl<<"First Name: ";
		cout<<fname<<endl;
		cout<<"Last Name: ";
		cout<<lname<<endl;
		cout<<"Melli Code: ";
		cout<<mellic<<endl;
		cout<<"Born Date: ";
		born.print(); cout<<endl;
		cout<<"Born Place: ";
		cout<<born_place<<endl;
		cout<<"Father Name: ";
		cout<<father_name<<endl;
		cout<<"Mother Name: ";
		cout<<mother_name<<endl;
		cout<<"Jensiat: ";
		if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
		cout<<"Adress: ";
		cout<<endl<<adress<<endl;
		cout<<"Mobile Number: ";
		cout<<mobile_num<<endl;
		cout<<"Telephone: ";
		cout<<telephone<<endl;
		cout<<"Tahsilat: ";
		cout<<endl<<tahsilat<<endl;
		cout<<"Tarikhe Ozviat: ";
		start.print(); cout<<endl;
		if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)){
			cout<<endl<<RED<<"Error dar vared kardane sahihe adad. Az ebteda etelalat ra vared konid."<<RESET<<endl;
			goto edit;
		}
	}
}		
void servant::input(PersonArray ppl){
	int c;
	char temp_mellic[15];
	input:
	cout<<endl<<"Entering New Servant: "<<endl;
	cout<<"First Name: ";
	//cin.ignore(0,'\n');
	cin.getline(fname,30);
	cout<<"Last Name: ";
	cin.getline(lname,30);
	cout<<"Melli Code: ";
	cin>>temp_mellic;
	cin.ignore();
	while(ppl.checkmellic(temp_mellic)!=-1){
		//cout<<endl<<ppl.checkmellic(mellic)<<endl;
		cout<<"Kode Melli Tekrari Ast. Try Again."<<endl;
		cin>>temp_mellic;
		cin.ignore();
	}
	cout<<"Born Date: "<<endl;
	born.input();
	cout<<"Born Place: ";
	//cin.ignore(0,'\n');
	cin.getline(born_place,30);
	cout<<"Father Name: ";
	cin.getline(father_name,30);
	cout<<"Mother Name: ";
	cin.getline(mother_name,30);
	cout<<"Jensiat (0:Zan | 1:Mard): ";
	jensiat=choice(0,1);
	cout<<"Adress: ";
	//cin.ignore(0,'\n');
	cin.getline(adress,200);
	cout<<"Mobile Number: ";
	cin>>mobile_num;
	cin.ignore();
	cout<<"Telephone: ";
	cin>>telephone;
	cin.ignore();
	cout<<"Tahsilat: ";
	//cin.ignore(0,'\n');
	cin.getline(tahsilat,60);
	cout<<"Tarikhe Estekhdam: "<<endl;
	start.input();
	cout<<"Hoghugh: ";
	//cin.ignore(0,'\n');
	cin.getline(hoghugh,70);
	cout<<"Saate Kar: ";
	cin.getline(saate_kar,120);
	cout<<"Bimeh (0:Na | 1:Baleh): ";
	bimeh=choice(0,1);
		
	cout<<endl<<endl<<"First Name: ";
	cout<<fname<<endl;
	cout<<"Last Name: ";
	cout<<lname<<endl;
	cout<<"Melli Code: ";
	cout<<mellic<<endl;
	cout<<"Born Date: ";
	born.print(); cout<<endl;
	cout<<"Born Place: ";
	cout<<born_place<<endl;
	cout<<"Father Name: ";
	cout<<father_name<<endl;
	cout<<"Mother Name: ";
	cout<<mother_name<<endl;
	cout<<"Jensiat: ";
	if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
	cout<<"Adress: ";
	cout<<endl<<adress<<endl;
	cout<<"Mobile Number: ";
	cout<<mobile_num<<endl;
	cout<<"Telephone: ";
	cout<<telephone<<endl;
	cout<<"Tahsilat: ";
	cout<<endl<<tahsilat<<endl;
	cout<<"Tarikhe Estekhdam: ";
	start.print(); cout<<endl;
	cout<<"Hoghugh: ";
	cout<<hoghugh<<endl;
	cout<<"Saate Kar: ";
	cout<<saate_kar<<endl;
	cout<<"Bimeh: ";
	if(bimeh) cout<<"Darad"<<endl; else cout<<"Nadarad"<<endl;
	if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)) cout<<endl<<RED<<"Error dar vared kardane sahihe adad."<<RESET<<endl;
	cout<<endl<<"Do You Want To Edit? (1:No | 2:Yes): ";
	c=choice(1,2);
	if(c==2) goto input;
	if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)){
		cout<<endl<<RED<<"Error dar vared kardane sahihe adad. Az ebteda etelalat ra vared konid."<<RESET<<endl;
		goto input;
	}
}
void servant::edit(PersonArray ppl){
	int c;
	char temp_mellic[15];
	edit:
	while(1){
		cout<<endl<<"Editing Servant: "<<endl;
		cout<<"Kodam Ghesmat ra Virayesh Mikonid?"<<endl;
		cout<<"1: Hame ra az Ebteda\n2: Name\n3: Melli Code\n4: Born\n5: Parents\n6: Jensiat\n7: Adres va Shomare Tamas\n8: Tahsilat\n9: Tarikhe Estekhdam\n10: Hoghugh\n"
		"11: Saate Kar\n12: Bimeh\n13: Enseraf"<<endl;
		c=choice(1,13);
		cout<<endl;
		switch(c){
			case 1: input(ppl); break;
			case 2:
				cout<<"First Name: ";
				//cin.ignore(0,'\n');
				cin.getline(fname,30);
				cout<<"Last Name: ";
				cin.getline(lname,30);
				break;
			case 3:
				cout<<"Melli Code: ";
				cin>>temp_mellic;
				cin.ignore();
				while(ppl.checkmellic(temp_mellic)!=-1){
					//cout<<endl<<ppl.checkmellic(mellic)<<endl;
					cout<<"Kode Melli Tekrari Ast. Try Again."<<endl;
					cin>>temp_mellic;
					cin.ignore();
				}
				break;
			case 4:
				cout<<"Born Date: "<<endl;
				born.input();
				cout<<"Born Place: ";
				//cin.ignore(0,'\n');
				break;
			case 5:
				cout<<"Father Name: ";
				//cin.ignore(0,'\n');
				cin.getline(father_name,30);
				cout<<"Mother Name: ";
				cin.getline(mother_name,30);
				break;
			case 6:
				cout<<"Jensiat (0:Zan | 1:Mard): ";
				jensiat=choice(0,1);
				break;
			case 7:
				cout<<"Adress: ";
				//cin.ignore(0,'\n');
				cin.getline(adress,200);
				cout<<"Mobile Number: ";
				cin>>mobile_num;
				cin.ignore();
				cout<<"Telephone: ";
				cin>>telephone;
				cin.ignore();
				break;
			case 8:
				cout<<"Tahsilat: ";
				//cin.ignore(0,'\n');
				cin.getline(tahsilat,60);
				break;		
			case 9:
				cout<<"Tarikhe Ozviat: "<<endl;
				start.input();
				break;
			case 10:
				cout<<"Hoghugh: ";
				cout<<hoghugh<<endl;
				break;
			case 11:
				cout<<"Saate Kar: ";
				cin.getline(saate_kar,120);
				break;
			case 12:
				cout<<"Hoghugh: ";
				//cin.ignore(0,'\n');
				cin.getline(hoghugh,70);
				break;
			case 13: break;
		}
		if(c==13) break;
		cout<<endl<<endl<<"First Name: ";
		cout<<fname<<endl;
		cout<<"Last Name: ";
		cout<<lname<<endl;
		cout<<"Melli Code: ";
		cout<<mellic<<endl;
		cout<<"Born Date: ";
		born.print(); cout<<endl;
		cout<<"Born Place: ";
		cout<<born_place<<endl;
		cout<<"Father Name: ";
		cout<<father_name<<endl;
		cout<<"Mother Name: ";
		cout<<mother_name<<endl;
		cout<<"Jensiat: ";
		if(jensiat) cout<<"Mard"<<endl; else cout<<"Zan"<<endl;
		cout<<"Adress: ";
		cout<<endl<<adress<<endl;
		cout<<"Mobile Number: ";
		cout<<mobile_num<<endl;
		cout<<"Telephone: ";
		cout<<telephone<<endl;
		cout<<"Tahsilat: ";
		cout<<endl<<tahsilat<<endl;
		cout<<"Tarikhe Ozviat: ";
		start.print(); cout<<endl;
		if(!checknum(mellic) || !checknum(mobile_num) || !checknum(telephone)){
			cout<<endl<<RED<<"Error dar vared kardane sahihe adad. Az ebteda etelalat ra vared konid."<<RESET<<endl;
			goto edit;
		}
	}
}	
void book::input(ThingArray tng){
	int c;
	int temp_code;
	input:
	cout<<endl<<"Name Ketab: ";
	//cin.ignore(0,'\n');
	cin.getline(name,120);
	cout<<"Tedade Safahat: ";
	npages=enternum();
	cout<<"Mowzue Ketab: ";
	//cin.ignore(0,'\n');
	cin.getline(subject,50);
	cout<<"Gheimat(Rial): ";
	cost=enternum();
	cout<<"Kode Shenasaeiye Mahsul (Hade Aksar 9 Ragham): ";
	temp_code=enternum();
	while(tng.checkcode(temp_code)!=-1){
		cout<<"Kode Shenasaeiye Mahsul Tekrari Ast. Try Again."<<endl;
		temp_code=enternum();
	}
	code=temp_code;
	cout<<"Name Nevisandeh: ";
	//cin.ignore(0,'\n');
	cin.getline(writer,60);
	cout<<"Nashere Ketab: ";
	cin.getline(nasher,60);
	cout<<"Sale Chap: ";
	chap_sal=enternum();
	cout<<"Shomare Ketab: ";
	number=enternum();
	
	cout<<endl<<endl<<"Name Ketab: ";
	cout<<name<<endl;
	cout<<"Tedade Safahat: ";
	cout<<npages<<endl;
	cout<<"Mowzue Ketab: ";
	cout<<subject<<endl;
	cout<<"Gheimat: ";
	cout<<cost<<" Rials"<<endl;
	cout<<"Kode Shenasaeiye Mahsul: ";
	cout<<code<<endl;
	cout<<"Name Nevisandeh: ";
	cout<<writer<<endl;
	cout<<"Nashere Ketab: ";
	cout<<nasher<<endl;
	cout<<"Sale Chap: ";
	cout<<chap_sal<<endl;
	cout<<"Shomare Ketab: ";
	cout<<number<<endl;
	cout<<endl<<"Do You Want To Edit? (1:No | 2:Yes): ";
	c=choice(1,2);
	if(c==2) goto input;
}
void book::edit(ThingArray tng){
	int c;
	int temp_code;
	while(1){
		cout<<endl<<"Kodam Ghesmat ra Virayesh Mikonid?"<<endl;
		cout<<"1: Hame ra az Ebteda\n2: Name Ketab\n3: Kode Shenasaei\n4: Tedade Safahat\n5: Mowzue Ketab\n6: Gheimat\n7: Name Nevisandeh\n8: Nashere Ketab\n9: Sale Chap\n10: Shomare Ketab\n"
		"11: Enseraf"<<endl;
		c=choice(1,11);
		switch(c){
			case 1: input(tng); break;
			case 2:
				cout<<endl<<"Name Ketab: ";
				//cin.ignore(0,'\n');
				cin.getline(name,120);
				break;
			case 3:
				cout<<"Kode Shenasaeiye Mahsul (Hade Aksar 9 Ragham): ";
				temp_code=enternum();
				while(tng.checkcode(temp_code)!=-1){
					cout<<"Kode Shenasaeiye Mahsul Tekrari Ast. Try Again."<<endl;
					temp_code=enternum();
				}
				code=temp_code;
				break;
			case 4:
				cout<<"Tedade Safahat: ";
				npages=enternum();
				break;
			case 5:
				cout<<"Mowzue Ketab: ";
				//cin.ignore(0,'\n');
				cin.getline(subject,50);
				break;
			case 6:
				cout<<"Gheimat(Rial): ";
				cost=enternum();
				break;
			case 7:
				cout<<"Name Nevisandeh: ";
				//cin.ignore(0,'\n');
				cin.getline(writer,60);
				break;
			case 8:
				cout<<"Nashere Ketab: ";
				cin.getline(nasher,60);
				break;		
			case 9:
				cout<<"Sale Chap: ";
				chap_sal=enternum();
				break;
			case 10:
				cout<<"Shomare Ketab: ";
				number=enternum();
				break;
			case 11: break;
		}
		if(c==11) break;
		cout<<endl<<endl<<"Name Ketab: ";
		cout<<name<<endl;
		cout<<"Tedade Safahat: ";
		cout<<npages<<endl;
		cout<<"Mowzue Ketab: ";
		cout<<subject<<endl;
		cout<<"Gheimat: ";
		cout<<cost<<" Rials"<<endl;
		cout<<"Kode Shenasaeiye Mahsul: ";
		cout<<code<<endl;
		cout<<"Name Nevisandeh: ";
		cout<<writer<<endl;
		cout<<"Nashere Ketab: ";
		cout<<nasher<<endl;
		cout<<"Sale Chap: ";
		cout<<chap_sal<<endl;
		cout<<"Shomare Ketab: ";
		cout<<number<<endl;
	}
}
void mag::input(ThingArray tng){
	int temp_code;
	int c;
	input:
	cout<<endl<<"Name Nashriyeh: ";
	//cin.ignore(0,'\n');
	cin.getline(name,120);
	cout<<"Tedade Safahat: ";
	npages=enternum();
	cout<<"Mowzue Nashriyeh: ";
	//cin.ignore(0,'\n');
	cin.getline(subject,50);
	cout<<"Gheimat(Rial): ";
	cost=enternum();
	cout<<"Kode Shenasaeiye Mahsul: ";
	temp_code=enternum();
	while(tng.checkcode(temp_code)!=-1){
		cout<<"Kode Shenasaeiye Mahsul Tekrari Ast. Try Again."<<endl;
		temp_code=enternum();
	}
	code=temp_code;
	cout<<"Name Sardabir: ";
	//cin.ignore(0,'\n');
	cin.getline(sardabir,60);
	cout<<"Tarikhe Enteshar: ";
	tenteshar.input();
	cout<<"Dowreye Enteshar: ";
	//cin.ignore(0,'\n');
	cin.getline(dowreh,60);
	cout<<"Shomareh: ";
	number=enternum();

	cout<<endl<<endl<<"Name Nashriyeh: ";
	cout<<name<<endl;
	cout<<"Tedade Safahat: ";
	cout<<npages<<endl;
	cout<<"Mowzue Nashriyeh: ";
	cout<<subject<<endl;
	cout<<"Gheimat(Rial): ";
	cout<<cost<<endl;
	cout<<"Kode Shenasaeiye Mahsul: ";
	cout<<code<<endl;
	cout<<"Name Sardabir: ";
	cout<<sardabir<<endl;
	cout<<"Tarikhe Enteshar: ";
	tenteshar.print(); cout<<endl;
	cout<<"Dowreye Enteshar: ";
	cout<<dowreh<<endl;
	cout<<"Shomareh: ";
	cout<<number<<endl;
	cout<<endl<<"Do You Want To Edit? (1:No | 2:Yes): ";
	c=choice(1,2);
	if(c==2) goto input;
}	
void mag::edit(ThingArray tng){
	int c;
	int temp_code;
	while(1){
	cout<<endl<<"Kodam Ghesmat ra Virayesh Mikonid?"<<endl;
		cout<<"1: Hame ra az Ebteda\n2: Name Nashriyeh\n3: Kode Shenasaei\n4: Tedade Safahat\n5: Mowzue Ketab\n6: Gheimat\n7: Name Sardabir\n8: Tarikhe Enteshar\n9: Dowreye Enteshar\n"
		"10: Shomareh\n11: Enseraf"<<endl;
		c=choice(1,11);
		switch(c){
			case 1: input(tng); break;
			case 2:
				cout<<endl<<"Name Nashriyeh: ";
				//cin.ignore(0,'\n');
				cin.getline(name,120);
				break;
			case 3:
				cout<<"Kode Shenasaeiye Mahsul (Hade Aksar 9 Ragham): ";
				temp_code=enternum();
				while(tng.checkcode(temp_code)!=-1){
					cout<<"Kode Shenasaeiye Mahsul Tekrari Ast. Try Again."<<endl;
					temp_code=enternum();
				}
				code=temp_code;
				break;
			case 4:
				cout<<"Tedade Safahat: ";
				npages=enternum();
				break;
			case 5:
				cout<<"Mowzue Ketab: ";
				//cin.ignore(0,'\n');
				cin.getline(subject,50);
				break;
			case 6:
				cout<<"Gheimat(Rial): ";
				cost=enternum();
				break;
			case 7:
				cout<<"Name Sardabir: ";
				//cin.ignore(0,'\n');
				cin.getline(sardabir,60);
				break;
			case 8:
				cout<<"Tarikhe Enteshar: ";
				tenteshar.input();
				break;		
			case 9:
				cout<<"Dowreye Enteshar: ";
				cout<<dowreh<<endl;
				break;
						case 10:
				cout<<"Shomareh: ";
				cout<<number<<endl;
				break;
			case 11: break;
		}
		if(c==11) break;
	cout<<endl<<endl<<"Name Nashriyeh: ";
	cout<<name<<endl;
	cout<<"Tedade Safahat: ";
	cout<<npages<<endl;
	cout<<"Mowzue Nashriyeh: ";
	cout<<subject<<endl;
	cout<<"Gheimat(Rial): ";
	cout<<cost<<endl;
	cout<<"Kode Shenasaeiye Mahsul: ";
	cout<<code<<endl;
	cout<<"Name Sardabir: ";
	cout<<sardabir<<endl;
	cout<<"Tarikhe Enteshar: ";
	tenteshar.print(); cout<<endl;
	cout<<"Dowreye Enteshar: ";
	cout<<dowreh<<endl;
	cout<<"Shomareh: ";
	cout<<number<<endl;
	}
}	
void person_manage(PersonArray &people){
	int c;
	while(1){
	cout<<endl<<BOLDRED<<"People Section: "<<RESET<<endl;
		cout<<"1: Add Person\n2: Edit Person\n3: Show Person\n4: Show All People\n5: Delete Person\n6: Back To Main\n";
		c=choice(1,6);
		switch(c){
			case 1: add_person(people); break;
			case 2: edit_person(people); break;
			case 3: show_person(people); break;
			case 4: for (int i=0; people.data.size()>(unsigned)i && people.data.at(i)!=0; i++) people.data.at(i)->print(); break;
			case 5: delete_person(people); break;
			case 6: break;
		}
		if(c==6) break;
	}
}
void add_person(PersonArray &people){
	int c;
	while(1){
	cout<<endl<<BOLDRED<<"Adding People Section: "<<RESET<<endl;
		cout<<"1: Add Member\n2: Add Librarian\n3: Add Servant\n4: Back To People Section\n"<<endl;
		c=choice(1,4);
		switch(c){
			case 1: people.append("member"); break;
			case 2: people.append("librarian"); break;
			case 3: people.append("servant"); break;
			case 4: break;
		}
		if(c==4) break;
	}
}		
void edit_person(PersonArray &people){	
	char user_mellic[50];
	cout<<endl<<"Enter Melli Code To Edit Person: ";
	cin>>user_mellic;
	cin.ignore();
	if(people.checkmellic(user_mellic)!=-1) people.edit_element(people.checkmellic(user_mellic));
	else cout<<endl<<"User Not Found"<<endl;
}
void delete_person(PersonArray &people){	
	char user_mellic[50];
	int c;
	cout<<endl<<"Enter Melli Code To Delete Person: ";
	cin>>user_mellic;
	cin.ignore();
	if(people.checkmellic(user_mellic)!=-1){
		cout<<"Are You Sure?(1: Yes | 2: Cancel): ";
		c=choice(1,2);
		if(c==1){
			people.delete_element(people.checkmellic(user_mellic));
			cout<<"User Deleted Successfully"<<endl;
		}
	}
	else cout<<endl<<"User Not Found"<<endl;
}	
void show_person(PersonArray &people){	
	char user_mellic[50];
	cout<<endl<<"Enter Melli Code To Show Person: ";
	cin>>user_mellic;
	cin.ignore();
	if(people.checkmellic(user_mellic)!=-1) people[user_mellic]->print();
	else cout<<endl<<"User Not Found"<<endl;
}	
void things_manage(ThingArray &things){
	int c;
	while(1){
	cout<<endl<<BOLDRED<<"Things Section: "<<RESET<<endl;
		cout<<"1: Add Thing\n2: Edit Thing\n3: Show Thing\n4: Show All Things\n5: Delete Thing\n6: Back To Main\n";
		c=choice(1,6);
		switch(c){
			case 1: add_thing(things); break;
			case 2: edit_thing(things); break;
			case 3: show_thing(things); break;
			case 4: for (int i=0; things.data.size()>(unsigned)i && things.data.at(i)!=0; i++) things.data.at(i)->print(); break;
			case 5: delete_thing(things); break;
			case 6: break;
		}
		if(c==6) break;
	}
}
void add_thing(ThingArray &things){
	int c;
	while(1){
	cout<<endl<<BOLDRED<<"Adding Things Section: "<<RESET<<endl;
		cout<<"1: Add Book\n2: Add Magazines\n3: Back To Things Section\n"<<endl;
		c=choice(1,3);
		switch(c){
			case 1: things.append("book"); break;
			case 2: things.append("mag"); break;
			case 4: break;
		}
		if(c==3) break;
	}
}		
void edit_thing(ThingArray &things){	
	int user_code;
	cout<<endl<<"Enter Stuff Code To Edit Thing: ";
	user_code=enternum();
	if(things.checkcode(user_code)!=-1) things.edit_element(things.checkcode(user_code));
	else cout<<endl<<"User Not Found"<<endl;
}
void delete_thing(ThingArray &things){	
	int user_code;
	int c;
	cout<<endl<<"Enter Stuff Code To Delete Stuff: ";
	user_code=enternum();
	if(things.checkcode(user_code)!=-1){
		cout<<"Are You Sure?(1: Yes | 2: Cancel): ";
		c=choice(1,2);
		if(c==1){
			things.delete_element(things.checkcode(user_code));
			cout<<"User Deleted Successfully"<<endl;
		}
	}
	else cout<<endl<<"User Not Found"<<endl;
}	
void show_thing(ThingArray &things){	
	int user_code;
	cout<<endl<<"Enter Stuff Code To Show The Stuff: ";
	user_code=enternum();
	if(things.checkcode(user_code)!=-1) things[user_code]->print();
	else cout<<endl<<"User Not Found"<<endl;
}		
int open_lend(vector<lend>lnd,int tng_code){
	for(int i=0; lnd.size()>(unsigned)i && lnd.at(i).empty==false; i++) if(lnd.at(i).tng->sendcode()==tng_code) if(lnd.at(i).close==false) return i; //yani in ketab parvande baz darad.
	return -1;
}	
void lend_manage(PersonArray &pa, ThingArray &ta,vector<lend>& lends){
	int c;
	while(1){
	cout<<endl<<BOLDRED<<"Liveries Section: "<<RESET<<endl;
		cout<<"1: Add Livery\n2: Closing Livery\n3: Show Liveries\n4: Show All Liveries\n5: Back To Main\n";
		c=choice(1,5);
		switch(c){
			case 1: add_livery(pa,ta,lends); break;
			case 2: closing_livery(pa,ta,lends); break;
			case 3: show_livery(ta,lends); break;
			case 4: for(int i=0; lends.size()>(unsigned)i && lends.at(i).sendempty()==false; i++) lends.at(i).print(); break;
			case 5: break;
		}
		if(c==5) break;
	}
}
void add_livery(PersonArray &pa, ThingArray &ta,vector<lend> &lends){
	int possible, nxt;
	unsigned int oldt,newt;
	possible=0;
	for(nxt=0; lends.size()>(unsigned)nxt; nxt++) if(lends.at(nxt).sendempty()==true){ possible=1; break;}
	if(possible==0){
		oldt=lends.size();
		newt=2*oldt;
		lends.resize(newt);
		possible=1;
		nxt=oldt;
	}
	lends.at(nxt).input(pa,ta,lends);
}
void closing_livery(PersonArray pa, ThingArray &ta,vector<lend> &lends){
	char lib_mellic[15];
	int lib_pass,tng_code;
	int c;
	cout<<endl<<"Kode Melli Va Passworde Ketabdar:"<<endl;
	cout<<"Kode Melli: ";
	cin>>lib_mellic;
	cin.ignore();
	cout<<"Password: ";
	lib_pass=enternum();
	if(pa.checkmellic(lib_mellic)==-1){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
	if(pa[lib_mellic]->sendtype()!=2){ cout<<endl<<"Kode Melli Motabar Nist."; return;}
	if(lib_pass!=pa[lib_mellic]->sendpass()){ cout<<endl<<"Kode Melli Va Password Motabeghat Nadarad"; return;}
	cout<<"Kode Mahsul Ra Vared Konid: ";
	tng_code=enternum();
	while(ta.checkcode(tng_code)==-1 || open_lend(lends,tng_code)==-1){
		if(ta.checkcode(tng_code)==-1) cout<<endl<<"In Mahsul Vojud Nadarad"<<endl;
		else if(open_lend(lends,tng_code)==-1) cout<<endl<<"In Mahsul  dar hale hazer Gharz gerefte nashode ast"<<endl;
		cout<<"Edame midahid?(1:Yes | 2:No): ";
		c=choice(1,2);
		if(c==1){
			cout<<endl<<"Kode Mahsul Ra Vared Konid: ";
			tng_code=enternum();
		}
		if(c==2) break;
	}
	lends.at(open_lend(lends,tng_code)).closing(pa,ta,lib_mellic);
}
void show_livery(ThingArray ta,vector<lend> lends){
	bool exist;
	int tng_code;
	cout<<"Kode Ketab Ra Vared Konid: ";
	tng_code=enternum();
	if(ta.checkcode(tng_code)==-1){
		cout<<endl<<"In Mahsul Vojud Nadarad !";
		return;
	}
	exist=0;
	for(int i=0; lends.size()>(unsigned)i && lends.at(i).sendempty()==false; i++){
		if(lends.at(i).tng->sendcode()==tng_code){
			lends.at(i).print();
			exist=true;
		}
	}
	if(exist==false) cout<<endl<<"In Mahsul Ta Konun Gharz Gerefte Nashode Ast.";
}
void liveries_save_txt(vector<lend> &lends){
	unsigned int tedad;
	fstream f1("liveries.txt", ios::out);
	for(tedad=0 ; lends.size()>tedad; tedad++);
	f1<<tedad<<endl;
	for(unsigned int i=0; lends.size()>i; i++){ lends.at(i).save_txt(f1);}
	f1.close();
}
void liveries_load_txt(vector<lend> &lends){
	unsigned int tedad;
	if(!ifstream("liveries.txt")) return;
	fstream f1("liveries.txt",ios::in);
	f1>>tedad; f1.ignore();
	lends.resize(tedad);
	for(unsigned int i=0; lends.size()>i; i++){
		/*int type;
		cout<<endl<<f1<<endl;
		f1>>lends.at(i).empty;
		f1.ignore();
		cout<<endl<<f1<<endl;
		if(lends.at(i).empty==false){
			f1>>type; f1.ignore(); lends.at(i).lib=new librarian; lends.at(i).lib->load_txt(f1);
			f1>>type; f1.ignore(); lends.at(i).mem=new member; lends.at(i).mem->load_txt(f1);
			f1>>type; f1.ignore();
			if(type==1) lends.at(i).tng=new book;
			else if(type==2) lends.at(i).tng=new mag;
			lends.at(i).tng->load_txt(f1);
			f1>>lends.at(i).close;
			f1.ignore();
			if(lends.at(i).close==true){ f1>>type; f1.ignore(); lends.at(i).lib_back=new librarian; lends.at(i).lib_back->load_txt(f1);}
		}*/
		lends.at(i).load_txt(f1);
	}
	f1.close();
}
void save(PersonArray pa,ThingArray ta,vector<lend> lends){
	int c;
	cout<<endl<<"Are You Sure?(1:YES 2:NO): ";
	c=choice(1,2);
	if(c==1){
		pa.save_txt();
		ta.save_txt();
		liveries_save_txt(lends);
		cout<<BOLDGREEN<<endl<<"File Saved Successfully"<<RESET<<endl;
	}
}
void load(PersonArray &pa,ThingArray &ta,vector<lend> & lends){
	int c;
	cout<<endl<<"Are You Sure?(1:YES 2:NO): ";
	c=choice(1,2);
	if(c==1){
		pa.load_txt();
		ta.load_txt();
		liveries_load_txt(lends);
		cout<<BOLDGREEN<<endl<<"File Loaded Successfully"<<RESET<<endl;
	}
}

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class book{
    public:
        int book_id;
        string title;
        string auth_name;
        float cost;
        int quant;
        book(){
            this->book_id = 0;
            this->title = "";
            this->auth_name = "";
            this->cost = 0.0;
            this->quant = 0;
        }
        void addbooks();
        void loadbook(vector<book> &v);
        void updatebook();
};
void book :: addbooks(){
    cout<<"     ENTER BOOK ID "<<endl;
    cin>>this->book_id;
    cout<<"     ENTER BOOK NAME "<<endl;
    cin.ignore(1,'\n');
    getline(cin,this->title);
    cout<<"     ENTER AUTHOR NAME "<<endl;
    getline(cin,this->auth_name);
    cout<<"     ENTER COST OF THE BOOK "<<endl;
    cin>>this->cost;
    cout<<"     Enter QUANTITY OF THE BOOK "<<endl;
    cin>>this->quant;
}
void book :: loadbook(vector<book> &v){
    v.push_back(*this);
    cout<<"     BOOK IS ADDED SUCCESSFULLY "<<endl;
}
void book :: updatebook(){
    string bname, authname;
    string price;
    string quantity;
    cout<<"   ENTER NA IF YOU DON'T WANT TO UPDATE ANY FIELD"<<endl;
    cout<<"     UPDATE BOOK NAME "<<endl;
    cin.ignore(1,'\n');
    getline(cin,bname);
    if(bname.compare("NA") != 0){
        this->title = bname;
    }
    cout<<"     UPDATE AUTHOR NAME "<<endl;
    getline(cin,authname);
    if(authname.compare("NA") != 0){
        this->auth_name = authname;
    }
    cout<<"     UPDATE COST OF THE BOOK "<<endl;
    cin>>price;
    if(price.compare("NA") != 0){
        float p = stof(price);
        this->cost = p;
    }
    cout<<"    UPDATE QUANTIY OF THE BOOK "<<endl;
    cin>>quantity;
    if(quantity.compare("NA") != 0){
        int q = stoi(quantity);
        this->quant = q;
    }
}
class student{
    public:
        string name;
        string roll;
        vector<book> vb;
        int inx;
        student(){
            this->name = "";
            this->roll = "";
            this->inx = 0;
        }
        void regstudent();
        void addstudent(vector<student> &vr);
        void updatestudent(vector<student> &vr);
        void issuebook(book b, int bid);
        void removebook(int rid, vector<student> &vr);
        void showbooks();
};
void student :: regstudent(){
    cout<<"     ENTER NAME "<<endl;
    cin.ignore(1,'\n');
    getline(cin,this->name);
    cout<<"     ENTER ROLL NUMBER "<<endl;
    cin>>this->roll;
}
void student :: addstudent(vector<student> &vr){
    vr.push_back(*this);
    this->inx = vr.size()-1;

}
void student :: updatestudent(vector<student> &vr){
    vr.erase(vr.begin()+this->inx);
    vr.insert(vr.begin()+this->inx,*this);
}
void student :: issuebook(book b, int bid){
    if(this->vb.size() == 3){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<" YOU ARE NOT ALLOWED TO ISSUE ANY BOOK FURTHER, RETURN A BOOK AND THEN ISSUE AGAIN "<<endl;
        cout<<"--------------------------------------------------------"<<endl;
    }
    else if(this->vb.size() == 0){
        this->vb.push_back(b);
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"     BOOK HAS BEEN ISSUED SUCCESSFULLY "<<endl;
        cout<<"--------------------------------------------------------"<<endl;
    }
    else{
        int flag = 0;
        for(auto item : this->vb){
            if(item.book_id == bid){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"      YOU HAVE ALREADY ISSUED THE BOOK   "<<endl;
            cout<<"--------------------------------------------------------"<<endl;
        }
        else{
            this->vb.push_back(b);
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"      BOOK HAS BEEN ISSUED SUCCESSFULLY "<<endl;
            cout<<"--------------------------------------------------------"<<endl;
        }
    }
}
void student :: removebook(int rid, vector<student> &vr){
    if(this->vb.size() == 0){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"     YOU HAVE NO BOOKS CURRENTLY ISSUED "<<endl;
        cout<<"--------------------------------------------------------"<<endl;
    }
    else{
        int index = -9;
        for(int k=0;k<this->vb.size();k++){
            if(this->vb[k].book_id == rid){
                index = k;
                break;
            }
        }
        if(index == -9){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"    YOU HAVE NOT ISSUED ANY BOOK WITH THIS ID "<<endl;
            cout<<"--------------------------------------------------------"<<endl;
        }
        else{
            this->vb.erase(this->vb.begin()+index);
            this->updatestudent(vr);
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"    YOU HAVE SUCCESSFULLY RETURNED THE BOOK WITH ID : "<<rid<<endl;
            cout<<"--------------------------------------------------------"<<endl;
        }
    }
}
void student :: showbooks(){
    if(this->vb.size() == 0){
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<" YOU HAVE NOT ISSUED ANY BOOK TILL NOW "<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
    }
    else{
        cout<<"     LIST OF ALL THE BOOKS ISSUED BY YOU "<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        for(auto item : this->vb){
            cout<<"   BOOK NAME : "<<item.title<<"   AUTHOR : "<<item.auth_name<<"  COST : "<<item.cost<<endl;
        }
        cout<<"-----------------------------------------------------------------"<<endl;
    }
}
void searchbooks(book ob){
    cout<<"-------------------------------------------"<<endl;
    cout<<"     BOOK NAME : "<<ob.title<<endl;
    cout<<"     AUTHOR NAME : "<<ob.auth_name<<endl;
    cout<<"     BOOK COST : "<<ob.cost<<endl;
    cout<<"     BOOK STOCK : "<<ob.quant<<endl;
    cout<<"-------------------------------------------"<<endl;
}
bool checkstudent(vector<student> &vr, string rnum){
    if(vr.size() == 0){
        return false;
    }
    for(auto item : vr){
        if(item.roll.compare(rnum) == 0){
            return true;
        }
    }
    return false;
}
student findstud(string rnum, vector<student> &vr){
    student flag;
    for(auto item : vr){
        if(item.roll.compare(rnum)==0){
            flag = item;
        }
    }
    return flag;
}
void findallstudent(vector<student> &vs){
    cout<<"--------------------------------------------------------"<<endl;
    if(vs.size() == 0){
        cout<<" NO STUDENT HAS REGISTERED TILL NOW "<<endl;
    }
    else{
        for(student stud : vs){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"  NAME : "<<stud.name<<"   ROLL NUMBER : "<<stud.roll<<endl;
            if(stud.vb.size() == 0){
                cout<<stud.name<<" HAS NOT ISSUED ANY BOOK TILL DATE"<<endl;
            }
            else{
                for(auto item : stud.vb){
                    cout<<"     Book :- "<<item.title<<"    ID:- "<<item.book_id<<endl;
                }
            }
            cout<<"--------------------------------------------------------"<<endl;
        }
        cout<<"--------------------------------------------------------"<<endl;
    }
}
int main(){
    cout<<"                 ----------------------------- LIBRARY MANAGEMENT SYSTEM ---------------------------------"<<endl;
    int choice,chs,chb;
    vector<book> a;
    vector<student> s;
    while(true){
        cout<<"    1. FOR ADMIN "<<endl;
        cout<<"    2. FOR STUDENTS "<<endl;
        cout<<"    3. EXIT "<<endl;
        cout<<"    ENTER YOUR CHOICE "<<endl;
        cin>>choice;
        if(choice == 1){
            string password = "System123?";
            string pass;
            cout<<"     ENTER YOUR PASSWORD "<<endl;
            cin>>pass;
            if(pass.compare(password) != 0){
                cout<<"    YOU ARE NOT THE ADMIN SO YOU ARE NOT ALLOWED TO LOG IN "<<endl;
                continue;;
            }
            cout<<"     WELCOME HERE ADMIN "<<endl;
            cout<<"     HERE ARE THE SEVEN OPTIONS AVAILABLE "<<endl;
            while(true)
            {
                cout<<"     1. ADD BOOKS "<<endl;
                cout<<"     2. SEARCH BOOKS "<<endl;
                cout<<"     3. UPDATE BOOKS "<<endl;
                cout<<"     4. DELETE BOOKS "<<endl;
                cout<<"     5. COUNT BOOKS "<<endl;
                cout<<"     6. LIST OF STUDENTS REGISTERED IN THE SYSTEM "<<endl;
                cout<<"     7. EXIT "<<endl;
                cout<<"     SELECT ANY OPTION YOU WANT "<<endl;
                cin>>chb;
                if(chb == 1){
                    book b;
                    b.addbooks();
                    b.loadbook(a);
                }
                if(chb == 2){
                    cout<<"     ENTER THE ID OF THE BOOK TO BE SEARCHED "<<endl;
                    int bid;
                    cin>>bid;
                    for(auto item : a){
                        if(item.book_id == bid){
                            searchbooks(item);
                            break;
                        }
                    }
                }
                if(chb == 3){
                    cout<<"    ENTER THE ID OF THE BOOK TO BE UPDATED "<<endl;
                    int uid;
                    int ind = -9;
                    cin>>uid;
                    for(int j=0;j<a.size();j++){
                        if(a[j].book_id == uid){
                            ind = j;
                            break;
                        }
                    }
                    if(ind == -9){
                        cout<<"    BOOK IS NOT PRESENT IN THE DATABASE "<<endl;
                    }
                    else{
                        book o = a[ind];
                        o.updatebook();
                        a[ind] = o;
                        cout<<"    BOOK IS UPDATED SUCCESSFULLY "<<endl;
                    }
                }
                if(chb == 4){
                    cout<<"    ENTER THE ID OF THE BOOK TO BE DELETED FROM THE DATABASE "<<endl;
                    int d_id;
                    int index = -9;
                    cin>>d_id;
                    for(int k=0;k<a.size();k++){
                        if(a[k].book_id == d_id){
                            index = k;
                        }
                    }
                    if(index == -9){
                        cout<<"     BOOK IS NOT PRESENT IN THE DATABASE "<<endl;
                    }
                    else{
                        int ip = a[index].book_id;
                        a.erase(a.begin()+index);
                        cout<<"   BOOK WITH ID "<<ip<<" HAS BEEN DELETED "<<endl;
                    }
                }
                if(chb == 5){
                    cout<<"     THE NO.OF BOOKS CURRENTLY IN THE SYSTEM IS "<<a.size()<<endl;
                }
                if(chb == 6){
                    cout<<"     LIST OF ALL THE STUDENTS REGISTERED IN OUR SYSTEM : "<<endl;
                    findallstudent(s);
                }
                if(chb == 7){
                    cout<<"     TERMINATED BY ADMIN "<<endl;
                    break;
                }
            }
        }
        if(choice == 2){
            cout<<"--------------------- WELCOME HERE THIS IS AN INTERFACE FOR THE STUDENTS -----------------------------------"<<endl;
            string rno;
            cout<<"   ENTER YOUR ROLL NUMBER "<<endl;
            cin>>rno;
            student su;
            int f = 0;
            while(true){
                bool exist = checkstudent(s,rno);
                if(!exist){
                    cout<<"     REGISTER YOURSELF IN DATABASE "<<endl;
                    su.regstudent();
                    su.addstudent(s);
                    cout<<"     YOU HAVE BEEN REGISTERED SUCCESSFULLY "<<endl;
                }
                else{
                    su = findstud(rno, s);
                    f = 1;
                    if(f == 1){
                        cout<<"     YOU ARE ALREADY REGISTERED IN OUR DATA BASE "<<endl;
                    }
                    f = 0;
                }
                cout<<"     1. ISSUE BOOKS "<<endl;
                cout<<"     2. SHOW BOOKS I ISSUED "<<endl;
                cout<<"     3. RETURN BOOK "<<endl;
                cout<<"     4. EXIT "<<endl;
                cout<<"         SELECT ANY OF THE OPTION "<<endl;
                cin>>chs;
                if(chs == 1){
                    cout<<"---------------------------- HERE ARE THE LIST OF BOOKS AVAILABLE IN OUR LIBRARY -------------------------------------"<<endl;
                    if(a.size() == 0){
                        cout<<"     THERE ARE NO BOOKS IN THE LIBRARY CURRENTLY SO YOU CANT TO ANY OPERATION SO EXIT "<<endl;
                    }
                    else{
                        for(auto item : a){
                            cout<<"   BOOK ID : "<<item.book_id<<"  BOOK NAME : "<<item.title<<"   AUTHOR : "<<item.auth_name<<"   STOCK : "<<item.quant<<endl;
                        }
                        cout<<" ENTER THE ID OF THE BOOK YOU WANT TO ISSUE "<<endl;
                        int is_id;
                        cin>>is_id;
                        for(auto item : a){
                            if(item.book_id == is_id){
                                su.issuebook(item, item.book_id);
                                su.updatestudent(s);
                                break;
                            }
                        }
                    }

                }
                if(chs == 2){
                    su.showbooks();
                }
                if(chs == 3){
                    cout<<"     ENTER THE ID OF THE BOOK YOU WANT TO RETURN "<<endl;
                    int rid;
                    cin>>rid;
                    su.removebook(rid,s);
                }
                if(chs == 4){
                    cout<<"   TERMINATED BY "<<su.name<<endl;
                    break;
                }
            }

        }
        if(choice == 3){
            cout<<"     YOU HAVE LEFT "<<endl;
            break;
        }
    }
}

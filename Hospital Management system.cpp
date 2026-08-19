#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int MAX_PATIENTS = 100;
const int MAX_DOCTORS = 50;
const int MAX_APPOINTMENTS = 100;

class Person
{
protected:
    int id;
    string name;
    int age;

public:

    Person()
    {
        id = 0;
        name = "";
        age = 0;
    }
string getName()
{
    return name;
}
    virtual void input() = 0;
    virtual void display() = 0;

    int getID()
    {
        return id;
    }

    virtual ~Person(){}
};

class Patient : public Person
{
private:
    string disease;
    string gender;
    string bloodGroup;
    string phone;

public:

    static int totalPatients;

    Patient()
    {
        disease="";
        gender="";
        bloodGroup="";
        phone="";
    }

    void input()
    {
        bool valid;

        cout << "\nEnter Patient ID: ";
        cin >> id;

        while(cin.fail() || id<=0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout << "Invalid ID! Enter Again: ";
            cin >> id;
        }

        cin.ignore();

        valid=false;

        while(!valid)
        {
            valid=true;

            cout<<"Enter Name: ";
            getline(cin,name);

            for(int i=0;i<name.length();i++)
            {
                if(isdigit(name[i]))
                {
                    valid=false;
                    cout<<"Numbers not allowed in Name!\n";
                    break;
                }
            }
        }

        cout<<"Enter Age: ";
        cin>>age;

        while(cin.fail() || age<=0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid Age! Enter Again: ";
            cin>>age;
        }

        cin.ignore();

        valid=false;

        while(!valid)
        {
            valid=true;

            cout<<"Enter Gender: ";
            getline(cin,gender);

            for(int i=0;i<gender.length();i++)
            {
                if(isdigit(gender[i]))
                {
                    valid=false;
                    cout<<"Invalid Gender!\n";
                    break;
                }
            }
        }

        valid=false;

        while(!valid)
        {
            valid=true;

            cout<<"Enter Disease: ";
            getline(cin,disease);

            for(int i=0;i<disease.length();i++)
            {
                if(isdigit(disease[i]))
                {
                    valid=false;
                    cout<<"Invalid Disease!\n";
                    break;
                }
            }
        }

        cout<<"Enter Blood Group: ";
        getline(cin,bloodGroup);

        valid=false;

        while(!valid)
        {
            valid=true;

            cout<<"Enter Phone: ";
            getline(cin,phone);

            for(int i=0;i<phone.length();i++)
            {
                if(!isdigit(phone[i]))
                {
                    valid=false;
                    cout<<"Phone must contain digits only!\n";
                    break;
                }
            }
        }

        totalPatients++;
    }

    void display()
    {
        cout<<"\n-------------------------";
        cout<<"\nPatient ID: "<<id;
        cout<<"\nName: "<<name;
        cout<<"\nAge: "<<age;
        cout<<"\nGender: "<<gender;
        cout<<"\nDisease: "<<disease;
        cout<<"\nBlood Group: "<<bloodGroup;
        cout<<"\nPhone: "<<phone;
        cout<<"\n-------------------------";
    }
};

int Patient::totalPatients=0;
class Staff : public Person
{
protected:
    double salary;

public:

    Staff()
    {
        salary=0;
    }
};

class Doctor : public Staff
{
private:
    string specialization;
    string qualification;
    string timing;

public:

    static int totalDoctors;

    Doctor()
    {
        specialization="";
        qualification="";
        timing="";
    }

    void input()
    {
        bool valid;

        cout<<"\nEnter Doctor ID: ";
        cin>>id;

        while(cin.fail() || id<=0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid ID! Enter Again: ";
            cin>>id;
        }

        cin.ignore();

        valid=false;

        while(!valid)
        {
            valid=true;

            cout<<"Enter Name: ";
            getline(cin,name);

            for(int i=0;i<name.length();i++)
            {
                if(isdigit(name[i]))
                {
                    valid=false;
                    cout<<"Invalid Name!\n";
                    break;
                }
            }
        }

        cout<<"Enter Age: ";
        cin>>age;

        while(cin.fail() || age<=0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid Age! Enter Again: ";
            cin>>age;
        }

        cin.ignore();

        valid=false;

        while(!valid)
        {
            valid=true;

            cout<<"Enter Specialization: ";
            getline(cin,specialization);

            for(int i=0;i<specialization.length();i++)
            {
                if(isdigit(specialization[i]))
                {
                    valid=false;
                    cout<<"Invalid Specialization!\n";
                    break;
                }
            }
        }

        cout<<"Enter Qualification: ";
        getline(cin,qualification);

        cout<<"Enter Timing: ";
        getline(cin,timing);

        cout<<"Enter Salary: ";
        cin>>salary;

        while(cin.fail() || salary<0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid Salary! Enter Again: ";
            cin>>salary;
        }

        totalDoctors++;
    }

    void display()
    {
        cout<<"\n-------------------------";
        cout<<"\nDoctor ID: "<<id;
        cout<<"\nName: "<<name;
        cout<<"\nAge: "<<age;
        cout<<"\nSpecialization: "<<specialization;
        cout<<"\nQualification: "<<qualification;
        cout<<"\nTiming: "<<timing;
        cout<<"\nSalary: "<<salary;
        cout<<"\n-------------------------";
    }
};

int Doctor::totalDoctors=0;
class Appointment
{
private:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;

public:

    Appointment()
    {
        appointmentID=0;
        patientID=0;
        doctorID=0;
    }

    void input()
    {
        bool valid;

        cout<<"Enter Appointment ID: ";
        cin>>appointmentID;

        while(cin.fail() || appointmentID<=0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid Appointment ID: ";
            cin>>appointmentID;
        }

        cout<<"Enter Patient ID: ";
        cin>>patientID;

        while(cin.fail() || patientID<=0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid Patient ID: ";
            cin>>patientID;
        }

        cout<<"Enter Doctor ID: ";
        cin>>doctorID;

        while(cin.fail() || doctorID<=0)
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid Doctor ID: ";
            cin>>doctorID;
        }

        cin.ignore();

        valid=false;

        while(!valid)
        {
            cout<<"\nDate Format: DD/MM/YYYY";
            cout<<"\nEnter Date: ";
            getline(cin,date);

            if(date.length()==10 &&
               date[2]=='/' &&
               date[5]=='/')
            {
                valid=true;
            }
            else
            {
                cout<<"Invalid Date Format!\n";
            }
        }

        valid=false;

        while(!valid)
        {
            cout<<"\nTime Format: HH:MM AM/PM";
            cout<<"\nEnter Time: ";
            getline(cin,time);

            if(time.length()>=7)
            {
                valid=true;
            }
            else
            {
                cout<<"Invalid Time Format!\n";
            }
        }
    }

    void display()
    {
        cout<<"\n-------------------------";
        cout<<"\nAppointment ID: "<<appointmentID;
        cout<<"\nPatient ID: "<<patientID;
        cout<<"\nDoctor ID: "<<doctorID;
        cout<<"\nDate: "<<date;
        cout<<"\nTime: "<<time;
        cout<<"\n-------------------------";
    }
};

class Bill
{
private:
    double amount;

public:

    Bill()
    {
        amount=0;
    }

    Bill(double a)
    {
        amount=a;
    }

    Bill operator +(Bill b)
    {
        Bill temp;
        temp.amount=amount+b.amount;
        return temp;
    }

    void display()
    {
        cout<<"\nTotal Bill = "<<amount<<endl;
    }
};
class Hospital
{
private:

    Patient patients[MAX_PATIENTS];
    Doctor doctors[MAX_DOCTORS];
    Appointment appointments[MAX_APPOINTMENTS];

    int patientCount;
    int doctorCount;
    int appointmentCount;

public:

    Hospital()
    {
        patientCount=0;
        doctorCount=0;
        appointmentCount=0;
    }

    void addPatient()
    {
        if(patientCount>=MAX_PATIENTS)
        {
            cout<<"Patient Storage Full!\n";
            return;
        }

        patients[patientCount].input();
        patientCount++;
    }

    void addDoctor()
    {
        if(doctorCount>=MAX_DOCTORS)
        {
            cout<<"Doctor Storage Full!\n";
            return;
        }

        doctors[doctorCount].input();
        doctorCount++;
    }

    void addAppointment()
    {
        if(appointmentCount>=MAX_APPOINTMENTS)
        {
            cout<<"Appointment Storage Full!\n";
            return;
        }

        appointments[appointmentCount].input();
        appointmentCount++;
    }

    void displayPatients()
    {
        for(int i=0;i<patientCount;i++)
            patients[i].display();
    }

    void displayDoctors()
    {
        for(int i=0;i<doctorCount;i++)
            doctors[i].display();
    }

    void displayAppointments()
    {
        for(int i=0;i<appointmentCount;i++)
            appointments[i].display();
    }
void generateBillForPatient()
{
    int pid;
    bool found = false;

    cout << "\nEnter Patient ID: ";
    cin >> pid;

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].getID() == pid)
        {
            found = true;

            double doctorFee, medicineFee, roomFee;

            cout << "\nPatient Found!";
            cout << "\nPatient Name: " << patients[i].getName();

            cout << "\nEnter Doctor Fee: ";
            cin >> doctorFee;

            while(cin.fail() || doctorFee < 0)
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Invalid Fee: ";
                cin >> doctorFee;
            }

            cout << "Enter Medicine Fee: ";
            cin >> medicineFee;

            while(cin.fail() || medicineFee < 0)
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Invalid Fee: ";
                cin >> medicineFee;
            }

            cout << "Enter Room Fee: ";
            cin >> roomFee;

            while(cin.fail() || roomFee < 0)
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Invalid Fee: ";
                cin >> roomFee;
            }

            Bill total = Bill(doctorFee)
                       + Bill(medicineFee)
                       + Bill(roomFee);

            cout << "\n================================";
            cout << "\n         PATIENT BILL";
            cout << "\n================================";
            cout << "\nPatient ID   : " << pid;
            cout << "\nPatient Name : " << patients[i].getName();
            cout << "\nDoctor Fee   : " << doctorFee;
            cout << "\nMedicine Fee : " << medicineFee;
            cout << "\nRoom Fee     : " << roomFee;

            cout << "\n--------------------------------";
            total.display();
            cout << "================================\n";

            return;
        }
    }

    if(!found)
    {
        cout << "\nPatient ID Not Found!\n";
    }
}
    void showAllPersons()
    {
        Person* p;

        cout<<"\n===== PATIENTS =====\n";

        for(int i=0;i<patientCount;i++)
        {
            p=&patients[i];
            p->display();
        }

        cout<<"\n===== DOCTORS =====\n";

        for(int i=0;i<doctorCount;i++)
        {
            p=&doctors[i];
            p->display();
        }
    }
};

void generateBill()
{
    double doctorFee;
    double medicineFee;
    double roomFee;

    cout<<"Enter Doctor Fee: ";
    cin>>doctorFee;

    while(cin.fail() || doctorFee<0)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid Fee: ";
        cin>>doctorFee;
    }

    cout<<"Enter Medicine Fee: ";
    cin>>medicineFee;

    while(cin.fail() || medicineFee<0)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid Fee: ";
        cin>>medicineFee;
    }

    cout<<"Enter Room Fee: ";
    cin>>roomFee;

    while(cin.fail() || roomFee<0)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid Fee: ";
        cin>>roomFee;
    }

    Bill total = Bill(doctorFee)
               + Bill(medicineFee)
               + Bill(roomFee);

    cout<<"\n===== BILL =====";
    total.display();
}

int main()
{
    Hospital hospital;
    int choice;

    do
    {
        cout<<"\n\n===== HOSPITAL MANAGEMENT SYSTEM =====";
        cout<<"\n1. Add Patient";
        cout<<"\n2. Display Patients";
        cout<<"\n3. Add Doctor";
        cout<<"\n4. Display Doctors";
        cout<<"\n5. Add Appointment";
        cout<<"\n6. Display Appointments";
        cout<<"\n7. Generate Bill";
        cout<<"\n8. Show All Persons (Polymorphism)";
        cout<<"\n0. Exit";

        cout<<"\n\nEnter Choice: ";
        cin>>choice;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout<<"Invalid Choice! Enter Again: ";
            cin>>choice;
        }

        switch(choice)
        {
        case 1:
            hospital.addPatient();
            break;

        case 2:
            hospital.displayPatients();
            break;

        case 3:
            hospital.addDoctor();
            break;

        case 4:
            hospital.displayDoctors();
            break;

        case 5:
            hospital.addAppointment();
            break;

        case 6:
            hospital.displayAppointments();
            break;

        case 7:
    hospital.generateBillForPatient();
    break;

        case 8:
            hospital.showAllPersons();
            break;

        case 0:
            cout<<"Good Bye!\n";
            break;

        default:
            cout<<"Invalid Choice!\n";
        }

    }
    while(choice!=0);

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include <unordered_map>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool doctorLogin();
int patient(int );
void doctor();
void doctorsignup();
void doctorlog();
void patientlogmenu();
void doctorlogmenu();
bool patientLog();
void patientsignup();
void patientlog();
void patientdisease();
void doctorlist();
void scheduleappointment_Addnewappointment();
void updateprofile();
void doctorviewshedule();
void view_records();
void cancel_appointment();
void doctorlist();
void patientappoimnetdeteils();
void cancelappointment();
void update_medical_records();
void markcompleteapp();
void accesshistory();
void conformpatientlist();


struct Doctor{

	string dr1name;
	string dr2name;
	int dtype;
	string dusername;
	string dpassword;
	string dhashpassword;
		int dage;
		int dnumber;

};
struct Patient {
   string p1name;
   string p2name;
   string pusername;
   string ppassword;
   int pnumber;
   int age;
};
struct Appointment {
    string Apppfname;
    string Appplname;
    string Apppnum;
    string Appspeciality;
    string Appdocname;
    string Apptime;
    string Appdate;
    string status;
};
struct records{

   string disease;
    string today;
   string nextday;
   string medicine;
   string scans;
};

struct Appointmentcnf {
    string Apppfname;
    string Appplname;
    string Apppnum;
    string Appspeciality;
    string Appdocname;
    string Apptime;
    string Appdate;
    string status;
    string apnum;
    string diagnosis;
    string medicine;
    string rec;
};
struct Updateinformation {
    string pfname;
    string plname;
    string page;
    string paddress;
    string ppassword;
    string pgender;
    string Appdate;
    string status;
    string apnum;
    string pnumber;
    string pusername;
    string rec;
};
int main() {


    cout<<"\t\t ....CLINICAL MANAGEMENT SYSTEM....\n";
	int choice,choice1,choice2;
	do{
	cout<<"\n\t\t\tMENU\n";
	cout<<"===========================================================\n\n";

	   cout<<"\t\t1.\t For Patients\n";
	   cout<<"\t\t2.\t For Doctors\n";
	   cout<<"\t\t3.\t Exit\n";

	  cout<<"Enter Your Choice:\n";
	   cin>>choice;

	   if(choice==1){
        patientlogmenu();
	   }

	   else if(choice==2){
        doctorlogmenu();
	   }

        else if(choice==3){
                return 0;
	        }

	        else{
                cout<<" Please Enter Valid Command"<<endl;
	        }

            }

            while(choice !=3);
	         cout<<"Thank You For Using Our Service"<<endl;

	return 0;
}
void doctorlogmenu(){
    int choice2;
        cout<<"1. Log in\n" ;
        cout<<"2. Sign up\n" ;
        cout<<"3.\t Exit\n";
	    cout<<"Enter number (1/ 2/3):" ;
	        cin>> choice2;
	        if(choice2==2){
                 // Doctor register
                 doctorsignup();
                  doctorlog();
	        }
	        else if(choice2==1){
                    //Doctor log in
                 doctorlog();
	        }
}
unsigned int Hash(string& data){
    unsigned int result(0);

    for(unsigned int ch:data)
        result = ch + (result<<4)+(result<<10)-result;

  return result;

}
void patientlogmenu(){
    int choice1;
        cout<<"1. Log in\n" ;
        cout<<"2. Sign up\n" ;
        cout<<"3. Exit\n";
	    cout<<"Enter number (1/ 2/3):" ;
	        cin>> choice1;

	        if(choice1 == 1){
              patientlog();
	        }
	        if(choice1 == 2){
                patientsignup();
               patientlog();
	        }
	        if(choice1 == 3){
                return ;
	        }
	        else
                cout<<"Please enter the valid command......\n";


}
bool doctorLogin( string &Dusername,  string &Dpassword) {
    ifstream outputFile("Doctorregister.txt");
    string line;

    while (getline(outputFile, line)) {
        istringstream iss(line);
        string storeD1name,storeD2name, storeDage, storeDSpeciality, storeDPassword,storeDusername,storeDcontactnumber;


        iss >> storeD1name;
        iss >> storeD2name;
        iss >> storeDage;
        iss >> storeDSpeciality;
        iss >> storeDcontactnumber;
        iss >> storeDusername;
        iss >> storeDPassword;

        if (storeDusername == Dusername && storeDPassword == to_string(Hash(Dpassword))) {
            outputFile.close();
            return true; // Login successful
        }
    }
    outputFile.close();
    return false;
}
void doctorlog(){
cout<<"================================================================\n";
	        	cout<<">>>>> LOGIN>>>>>>\n";

				 string Dusername, Dpassword;
    cout << "Enter your Username: ";
    cin >> Dusername;

    cout << "Enter your Password: " ;
      char ch;
    while ((ch = _getch()) != 13) {
        if (ch == 8) {
            if (!Dpassword.empty()) {
                Dpassword.pop_back();
                cout << "\b \b";
            }
        } else if (ch != 32) {
            Dpassword.push_back(ch);
            cout << '*';
        }
    }

     if (doctorLogin(Dusername, Dpassword)) {
        cout << "\nLogin successful..."<< endl;
        cout<<endl;
        cout<<endl;

        doctor();


    } else {
        cout << "Invalid username or password. Please try again." << endl;
        doctorlogmenu();
    }}
void doctorsignup(){
cout<<">>>>>>>SIGN UP>>>>>>>\n";

				 // Open a file named "Doctorregister.txt" for writing
    ofstream outputFile("Doctorregister.txt", ios::app);

	string dr1name, dr2name, dusername, dpassword,dhashpassword;
	string dage, dnumber,dspeciality;



	cout<<"================================================================\n";

//register doctor;
	cout<<"Please Fill This Application\n";
	cout<<endl;

    //disease type



     cout << endl;

	cout<<"Enter Your First Name\n";
	cin>>dr1name;
	 outputFile << dr1name <<" ";

	 cout<<"Enter Your Second Name\n";
	cin>>dr2name;
	 outputFile << dr2name <<" ";

	cout<<"Enter Your  Age\n";
	cin>>dage ;
	outputFile<<dage <<" ";

    cout<<"Enter Your Speciality\n";
	cin>>dspeciality;
	outputFile <<dspeciality << " ";

	cout<<"Enter Your Contact Number\n";
	cin>>dnumber;
	outputFile <<dnumber << " ";

	//create username & password
	cout<<"...............User Name & Password.............\n";


	cout<<"Enter an User Name :\n";
	cin>>dusername;
	  outputFile<<dusername <<" ";
	cout<<"Enter a Password :\n";
	  char ch;
    while ((ch = _getch()) != 13) {
        if (ch == 8) {
            if (!dpassword.empty()) {
                dpassword.pop_back();
                cout << "\b \b";
            }
        } else if (ch != 32) {
            dpassword.push_back(ch);
            cout << '*';
        }
    }

    dhashpassword=to_string(Hash(dpassword));

    outputFile <<dhashpassword <<endl;
outputFile.close();
	cout<<"\nRemember your password & username correctly...............\n\n";


 cout << "Registration successfully.\n\n" << endl;

}
int patient(){
   string Pusername;
    int  n = 0;

	cout<<"For Patient\n\n" ;
		cout<<"================================================================\n";
	cout<<"1.View Medical Records:\n" ;
	cout<<"2.Schedule Appointments/ Add new appointment:\n" ;
	cout<<"3.Cancel Appointments:\n" ;
	cout<<"4.Update Personal Information\n" ;
	cout<<"5.EXIT\n\n" ;
		cout<<"================================================================\n";
	cout<<"Here, Enter your choice number (1/2/3/4/5)\n" ;
	    cin>>n;

	switch (n){

		case 1:
		     cout<<"View Medical Records:" ;
           view_records();
           system("pause");
        patient();

		     break ;

		case 2:
		    cout<<"Schedule Appointments / Add New Appontments:\n" ;
		       scheduleappointment_Addnewappointment();
		       system("pause");
               patient();
		       break ;

			case 3:
			    cout << " Cancel Appointments:\n";

			    cancelappointment();
			    system("pause");
			    patient();

			    break ;

			case 4:
			    cout<<"Update Personal Information:" ;
			    updateprofile();
			    system("pause");
        patient();
			    break ;

			default:
			    cout<<"Wrong number & Try Again";

				break;
	}
	cout << "\n\n";
	return n;
}
void doctor(){
    int a;
		cout<<"For Doctors\n\n" ;
			cout<<"================================================================\n";
			//Doctor menu

	cout<<"1.View Schedule:\n" ;
	cout<<"2.Access Patient Records:\n" ;
	cout<<"3.Update Patient Records:\n" ;
	cout<<"4.Mark Appointment as Complete:\n" ;
	cout<<"5.EXIT\n\n" ;
	cout<<"Here, Enter your choice number (1/2/3/4/5)\n" ;
	    cin>>a ;

	    switch (a){
		case 1:
		     cout<<"View Schedule:" ;

		    doctorviewshedule();
		    system("pause");
        doctor();

		break ;

		case 2:
		    cout<<"Access Patient Records:" ;
		    accesshistory();
		    system("pause");
       doctor();


		break ;
			case 3:
			    cout<<"Update Patient Records:" ;
			    update_medical_records();
			    system("pause");
        doctor();

			break ;
			case 4:
			    cout<<"Mark Appointment as Complete:" ;
			    markcompleteapp();
			    system("pause");
        doctor();

			break ;

			default:
				cout<<"Wrong number & Try Again" ;
				return ;

	}

}
bool patientLog(string &Pusername,  string &Ppassword){
     ifstream outputFile("Patientregister.txt");
    string line;

    while (getline(outputFile, line)) {
        istringstream iss(line);
        string storeP1name,storeP2name, storePage,  storePPassword,storePusername,storePcontactnumber;

        iss >> storeP1name;
        iss >> storeP2name;
        iss >> storePage;
        iss >> storePcontactnumber;
        iss >> storePusername;
        iss >> storePPassword;

        if (storePusername == Pusername && storePPassword == to_string(Hash(Ppassword))) {
            outputFile.close();
            return true; // Login successful
        }
    }
    outputFile.close();
    return false;
}
void patientlog(){
    cout<<"================================================================\n";
	        	cout<<">>>>> LOGIN>>>>>>\n";
        int n;
				 string Pusername, Ppassword;
    cout << "Enter your Username: ";
    cin >> Pusername;

    cout << "Enter your Password: " ;
      char pch;
    while ((pch = _getch()) != 13) {
        if (pch == 8) {
            if (!Ppassword.empty()) {
                Ppassword.pop_back();
                cout << "\b \b";
            }
        } else if (pch != 32) {
            Ppassword.push_back(pch);
            cout << '*';
        }
    }

     if (patientLog(Pusername, Ppassword)){
         cout << "\nLogin successful...\n"<< endl;
        cout<<endl;
        cout<<endl;

        patient();


    } else {
        cout << "\nInvalid username or password. Please try again." << endl;
        patientlogmenu();
    }}
void patientsignup(){

cout<<">>>>>>>SIGN UP>>>>>>>\n";

				 // Open a file named "Doctorregister.txt" for writing
    ofstream outputFile("Patientregister.txt", ios::app);

	string p1name, p2name, pusername, ppassword,phashpassword;
	string page, pnumber;



	cout<<"================================================================\n";


	cout<<"Please Fill This Application\n";
	cout<<endl;

	cout<<"Enter Your First Name:\n";
	cin>>p1name;
	 outputFile << p1name <<" ";

	 cout<<"Enter Your Second Name:\n";
	cin>>p2name;
	 outputFile << p2name <<" ";

	cout<<"Enter Your  Age\n";
	cin.ignore();
	cin>>page ;
	outputFile<<page <<" ";

	cout << "Enter Your Contact Number\n";
	cin >> pnumber;
	outputFile << pnumber << " ";

	//create username & password
	cout << "...............User Name & Password.............\n";


	cout << "Enter an User Name :\n";
	cin >>pusername;
	  outputFile<<pusername <<" ";
	cout<<"Enter a Password :\n";
	  char pch;
    while ((pch = _getch()) != 13) {
        if (pch == 8) {
            if (!ppassword.empty()) {
                ppassword.pop_back();
                cout << "\b \b";
            }
        } else if (pch != 32) {
            ppassword.push_back(pch);
            cout << '*';
        }
    }

    phashpassword=to_string(Hash(ppassword));

    outputFile <<phashpassword <<endl;
outputFile.close();
	cout<<"Remember your password & username correctly...............\n\n";


 cout << "Registation successfully.\n\n" << endl;

}

void scheduleappointment_Addnewappointment(){

int schedule;
string Doctorregister;
cout << "1.Add new Appointment:\n";
cout<<endl;
  cout <<"2. EXIT\n";
  cout << " Enter your choice :";
  cin >> schedule;
cout << endl;
  if( schedule == 1){

   doctorlist();
    patientappoimnetdeteils();

  }

  if ( schedule == 2){
    return ;
  }
}
void updateprofile() {

    // Open the file for reading
    fstream outputFile;
    fstream tempFile;


    string line, pusername;
    bool found = false;

     cout << "\n ----------  Updating patient Details  ----------\n" << endl;

    cout << "\n Enter Your Username : ";
    cin >> pusername ;


    outputFile.open("Patientregister.txt", ios::in);
    tempFile.open("tempPatient.txt", ios::out);



    if (!outputFile || !tempFile) {
        cout << "Error opening files." << endl;
        return ;
    }
    else{

     while (getline(outputFile, line)) {
        istringstream iss(line);
        string storeP1name,storeP2name, storePage, storePcontactnumber, storePusername, storePPassword;

        iss >> storeP1name;
        iss >> storeP2name;
        iss >> storePage;
        iss >> storePcontactnumber;
        iss >> storePusername;
        iss >> storePPassword;

        if (storePusername == pusername) {
            found = true;

            string newP1name,newP2name, newPage, newPcontactnumber;

             cout << "\nYour Current Details:" << endl;
            cout << "First Name: " << storeP1name << endl;
            cout << "Second Name: " << storeP2name << endl;
            cout << "Age: " << storePage << endl;
            cout << "Address: " << storePcontactnumber << endl;
            cout << "Gender: " << storePusername << endl;
            cout << "Contact Number: " << storePPassword << endl;

            cout<<endl;
            cout<<endl;

            cout << "Enter New First Name: ";
            cin >> newP1name;
            cout << "Enter New Second Name: ";
            cin >> newP2name;
            cout << "Enter New Age: ";
            cin >> newPage;
            cout << "Enter New Contact Number: ";
            cin >> newPcontactnumber;

            tempFile << newP1name << " " << newP2name << " " << newPage << " " << newPcontactnumber << " "<<storePusername<<" "<< storePPassword << endl;
            cout << "Profile updated successfully." << endl;

        }
         else {
            tempFile << line << endl;
        }
}
     }

    outputFile.close();
    tempFile.close();

if (found == true) {
        char upOption;
        cout << "\n Are You Sure You Want To Update Your Details (y/n)? ";
        cin >> upOption;

         if (upOption == 'Y' || upOption == 'y') {
            remove("Patientregister.txt");								// delete the original file
            rename("tempPatient.txt", "Patientregister.txt");	//rename the temp file into original file name
            cout << "\n Your Information Has Been Successfully Updated";

            patient();	//calling patient exit function
        }
        else {
            cout<<endl;
            cout<<"No Any Other Information Under Your Name"<<endl;
            patient();	//Function calling to display the patient task menu
        }
    }
else{
		cout << "\n The Name Not Found\n" << endl;
		cout << "\n Do You Want To Retry (y/n)? ";
		char retryOption;
        cin >> retryOption;

        if (retryOption == 'y' || retryOption == 'Y') {
            updateprofile(); 	// Retry the delete operation
        }
		else {
        	remove("tempPatient.txt");		//delete the temp file
        	system("cls");
            patient();		//Function calling to display the librarian task menu
        }
	}
	 system("pause");
        patient();
}

void cancel_appointment() {

    int num;

    cout << "\n=========================================\n";
    cout << " 1. Cancel Appointments\n";
    cout << " 2. EXIT\n";
    cout << "Enter number: ";
    cin >> num;

    if (num == 1) {
        // Open the file for reading
        ifstream inputFile("Patientappointment.txt", ios::app);

        if (!inputFile.is_open()) {
            cout << "Error opening Patientappointment.txt" << endl;
            return;
        }

        string dusername;
        int dtype;

        cout << "\nSchedule Appointments for you:\n";

        while (inputFile >> dtype >> dusername) {
            if (dtype == 1) {
                cout << "Cardio Diseases";
            } else if (dtype == 2) {
                cout << "Respiratory Diseases";
            } else if (dtype == 3) {
                cout << "Infectious Diseases";
            } else if (dtype == 4) {
                cout << "Skin Conditions";
            } else if (dtype == 5) {
                cout << "Neurological Disorders";
            }

            cout << " " << "\t" << dusername << "\n";
        }

        string canceluser;
        cout << "Enter doctor username of appointment to cancel: ";
        cin >> canceluser;

        // Open a temporary file for writing
        ofstream tempFile("tempPatientAppointment.txt");

        string line;
        bool found = false;

        while (inputFile >> dtype >> dusername) {
            if (dusername == canceluser) {
                found = true;
                cout << "Appointment with " << canceluser << " canceled successfully.\n";
            } else {
                tempFile << dtype << " " << dusername << "\n";
            }
        }

        if (!found) {
            cout << "Appointment not found with " << canceluser << ".\n";
        }

        inputFile.close();
        tempFile.close();

        // Rename the temporary file to the original file
        remove("Patientappointment.txt");
        rename("tempPatientAppointment.txt", "Patientappointment.txt");
    }
    system("pause");
        patient();
}

void view_records(){

    string pName;

    cout<<"\n Enter Your First Name : ";
    cin>>pName;

    fstream outputFile("Patientregister.txt");
    string line;



    while (getline(outputFile, line)) {
        istringstream iss(line);
        Updateinformation updatep;


        getline(iss, updatep.pfname, ' ');
        getline(iss, updatep.plname, ' ');
        getline(iss, updatep.page, ' ');
        getline(iss, updatep.paddress, ' ');
        getline(iss, updatep.pgender, ' ');
        getline(iss, updatep.pnumber, ' ');
        getline(iss, updatep.pusername, ' ');
        getline(iss, updatep.ppassword, ' ');

        if (updatep.pfname == pName ) {
            cout << "Patient Name : " << updatep.pfname <<" "<<updatep.plname<< endl;
            cout << "Patient Telephone : " << updatep.pnumber << endl;
            cout << "Age : " << updatep.page << endl;


            fstream apfile("ptappdetails.txt");
          string line;

       while (getline(apfile, line)) {
        istringstream iss(line);
        Appointmentcnf appointmentcnf;

        getline(iss, appointmentcnf.Apppfname, ' ');
        getline(iss, appointmentcnf.Appplname, ' ');
        getline(iss, appointmentcnf.Apppnum, ' ');
        getline(iss, appointmentcnf.Appspeciality, ' ');
        getline(iss, appointmentcnf.Appdocname, ' ');
        getline(iss, appointmentcnf.Apptime, ' ');
        getline(iss, appointmentcnf.Appdate, ' ');
        getline(iss, appointmentcnf.status, ' ');
        getline(iss, appointmentcnf.apnum, ' ');

        if (appointmentcnf.status == "closed" && appointmentcnf.Apppfname == pName){
                cout<<"Closed Appoiments"<<endl;
                cout << "Apppiment Date : " << appointmentcnf.Appdate << endl;
                cout << "Apppiment Time : " << appointmentcnf.Apptime << endl;
}
else if (appointmentcnf.status == "Pending" &&appointmentcnf.Apppfname == pName){
         cout<<"Upcoming Appoiments"<<endl;
                cout << "Apppiment Date : " << appointmentcnf.Appdate << endl;
                cout << "Apppiment Time : " << appointmentcnf.Apptime << endl;
}
else if (appointmentcnf.status == "confirmed" && appointmentcnf.Apppfname == pName){
         cout<<"confirmed Appoiments"<<endl;
                cout << "Apppiment Date : " << appointmentcnf.Appdate << endl;
                cout << "Apppiment Time : " << appointmentcnf.Apptime << endl;
}
else{

    cout<<"You do not have any Appointments yet......"<<endl;
}


       }
apfile.close();
        }





    }
outputFile.close();
}

void doctorlist() {
    ifstream outputFile("Doctorregister.txt");

       cout<<" Available Doctors"<<endl;

     string line;
    while (getline(outputFile, line)) {
        istringstream iss(line);
        string storeDf1name,storeDf2name, storeDlname, storeDage, storeDSpeciality, storeDPassword,storeDusername,storeDcontactnumber;

        iss >> storeDf1name;
        iss >> storeDf2name;
        iss >> storeDage;
        iss >> storeDSpeciality;
        iss >> storeDcontactnumber;
        iss >> storeDusername;
        iss >> storeDPassword;

         cout<<endl;

      cout<<"Doctor  Name - "<<storeDf1name<<" "<<storeDlname<<"  "<<"Speciality - "<<storeDSpeciality<<endl;

    }
    outputFile.close();
    cout<<endl;

}

void patientappoimnetdeteils(){

    ofstream apfile("ptappdetails.txt",ios::app);
    string Appdocname,Apppnum,Appspeciality,Apppfname,Appplname,Apptime,Appdate;

    cout<<"Please Enter Patient First Name"<<endl;
    cin>>Apppfname;
    apfile<<Apppfname<<" ";

    cout<<"Please Enter Patient Second Name"<<endl;
    cin>>Appplname;
    apfile<<Appplname<<" ";

    cout<<"Please Enter Contact Number"<<endl;
    cin>>Apppnum;
    apfile<<Apppnum<<" ";

    cout<<"Please Enter Your Disease Section (speciality ...):"<<endl;
    cin>>Appspeciality;
    apfile<<Appspeciality<<" ";

     cout<<"Please Enter Doctor User name"<<endl;
    cin>>Appdocname;
    apfile<<Appdocname<<" ";

    cout<<endl;
    cout<<"Please Enter Appointment Date(DD/MM/YYYY)"<<endl;
    cin>>Appdate;
    apfile<<Appdate<<" ";

    cout<<endl;
    cout<<"Please Enter Appointment Time(HH:MM)"<<endl;
    cin>>Apptime;
    apfile<<Apptime<<" ";



    apfile<<"Pending"<<endl;
    cout<<endl;
   cout<<endl;

   cout<<"Your Appointment Is Pending"<<endl;



  apfile.close();


}

void cancelappointment() {


    ifstream apfile("ptappdetails.txt");
    ofstream tempFile("temp.txt");

    if (!apfile.is_open() || !tempFile.is_open()) {
        cout << "Error opening files." << endl;
        return;
    }

    string name;

    cout << "\nEnter your First name: ";
    cin >> name;

    bool appointmentCancelled = false;

    while (apfile) {
        string line;
        getline(apfile, line);

        if (line.empty()) {
            continue; // Skip empty lines
        }

        istringstream iss(line);
        Appointment appointment;

        getline(iss, appointment.Apppfname, ' ');
        getline(iss, appointment.Appplname, ' ');
        getline(iss, appointment.Apppnum, ' ');
        getline(iss, appointment.Appspeciality, ' ');
        getline(iss, appointment.Appdocname, ' ');
        getline(iss, appointment.Apptime, ' ');
        getline(iss, appointment.Appdate, ' ');
        getline(iss, appointment.status, ' ');

        if (appointment.Apppfname == name && appointment.status == "Pending") {

            // Display the current appointment information
            cout << "\nYour Current Appointment Details:" << endl;
            cout << "Doctor: " << appointment.Appdocname << endl;
            cout << "Time: " << appointment.Apptime << endl;
            cout << "Date: " << appointment.Appdate << endl;

            // Confirm cancellation
            char confirmation;
            cout << "Do you want to cancel this appointment? (y/n): ";
            cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y') {
                cout << "Appointment cancelled successfully." << endl;
                appointmentCancelled = true;
                continue; // Skip writing cancelled appointment to temp file
            }
        }

        // Write the appointment (cancelled or not) to the temporary file
        tempFile << appointment.Apppfname << " " << appointment.Appplname << " " << appointment.Apppnum << " "
                 << appointment.Appspeciality << " " << appointment.Appdocname << " " << appointment.Apptime << " "
                 << appointment.Appdate << " " << appointment.status << endl;
    }

    apfile.close();
    tempFile.close();

    // Display all pending appointments if no appointment was cancelled
    if (!appointmentCancelled) {
            cout<<endl;
    cout<<"No Any Appoiments Under Your Name"<<endl;
       patient();
    }

    // Rename the temporary file to the original file
    if (appointmentCancelled) {
        remove("ptappdetails.txt");
        rename("temp.txt", "ptappdetails.txt");
    }

}

void update_medical_records(){


  ofstream medifile("medidetails.txt",ios::app);

    string Anum,drname;

    cout<<"Enter Your Name : ";
    cin>>drname;

    cout<<"Enter Appointment Number : ";
    cin>>Anum;

    fstream apfile("ptappdetails.txt");
    string line;



    while (getline(apfile, line)) {
        istringstream iss(line);
        Appointmentcnf appointmentcnf;

        getline(iss, appointmentcnf.Apppfname, ' ');
        getline(iss, appointmentcnf.Appplname, ' ');
        getline(iss, appointmentcnf.Apppnum, ' ');
        getline(iss, appointmentcnf.Appspeciality, ' ');
        getline(iss, appointmentcnf.Appdocname, ' ');
        getline(iss, appointmentcnf.Apptime, ' ');
        getline(iss, appointmentcnf.Appdate, ' ');
        getline(iss, appointmentcnf.status, ' ');
        getline(iss, appointmentcnf.apnum, ' ');

         if (appointmentcnf.apnum == Anum && appointmentcnf.Appdocname == drname) {

            cout << "Patient Name : " << appointmentcnf.Apppfname <<" "<<appointmentcnf.Appplname<< endl;
            cout<<endl;
            cout << "Disease : " << appointmentcnf.Appspeciality << endl;
            cout<<endl;
            cout<<endl;

            string diagnosis,medicine,rec;

            cin.ignore();
            cout<<"Enter diagnosis"<<endl;
            getline(cin,diagnosis);

            cin.ignore();
            cout<<"Enter prescribed medications"<<endl;
            getline(cin,medicine);

            cin.ignore();
            cout<<"Enter Additional recommendations"<<endl;
            getline(cin,rec);



                      medifile<<appointmentcnf.Apppfname <<" "<<appointmentcnf.Appplname<<" "<<appointmentcnf.Appdocname<<" "<<appointmentcnf.apnum<<" "<<diagnosis<<" "<<medicine<<" "<<rec<<" "<<appointmentcnf.status<<endl;
        }

}


    medifile.close();
    apfile.close();

    cout<<endl;
    cout<<"Patient Record Successfully Updated"<<endl;

}

void doctorappoimenteconform() {

    string DruserName,apnum;


    cout<<"Enter Your user Name : ";
    cin>>DruserName;

    fstream apfile("ptappdetails.txt");
    string line;

    cout << "========== Upcoming Appointments ==========" << endl;

    while (getline(apfile, line)) {
        istringstream iss(line);
        Appointmentcnf appointmentcnf;

        getline(iss, appointmentcnf.Apppfname, ' ');
        getline(iss, appointmentcnf.Appplname, ' ');
        getline(iss, appointmentcnf.Apppnum, ' ');
        getline(iss, appointmentcnf.Appspeciality, ' ');
        getline(iss, appointmentcnf.Appdocname, ' ');
        getline(iss, appointmentcnf.Apptime, ' ');
        getline(iss, appointmentcnf.Appdate, ' ');
        getline(iss, appointmentcnf.status, ' ');
        getline(iss, appointmentcnf.apnum, ' ');

        if (appointmentcnf.Appdocname == DruserName && appointmentcnf.status == "Pending") {
            cout << "Patient Name : " << appointmentcnf.Apppfname <<" "<<appointmentcnf.Appplname<< endl;
            cout << "Patient Telephone : " << appointmentcnf.Apppnum << endl;
            cout << "Disease : " << appointmentcnf.Appspeciality << endl;
            cout << "Time : " << appointmentcnf.Apptime << endl;
            cout << "Date : " << appointmentcnf.Appdate << endl;
            cout << "Status : " << appointmentcnf.status << endl << endl;

            string action;
            cout << "Do you want to confirm (C) or cancel (X) this appointment? (C/X): ";
            cin >> action;

            if (action == "C" || action == "c") {
                appointmentcnf.status = "confirmed";
                cout<<"Please Enter Appoiment Number"<<endl;
                cin>>apnum;
                appointmentcnf.apnum = apnum;
                cout<<endl;
                cout<<"Appoiment confirmed Successfully"<<endl;
                                cout<<endl;


            }
            else if (action == "X" || action == "x") {
                appointmentcnf.status = "cancelled";
             cout<<endl;
                cout<<"Appoiment cancelled Successfully"<<endl;
                                cout<<endl;


            }

            fstream tempFile("temp.txt", ios::app);
            tempFile << appointmentcnf.Apppfname<<" "<<appointmentcnf.Appplname << " " << appointmentcnf.Apppnum << " " << appointmentcnf.Appspeciality << " "
                     << appointmentcnf.Appdocname << " " << appointmentcnf.Apptime << " " << appointmentcnf.Appdate << " "
                     << appointmentcnf.status <<" "<<appointmentcnf.apnum<< endl;
                      tempFile.close();
        }
        else {
            fstream tempFile("temp.txt", ios::app);
            tempFile << appointmentcnf.Apppfname<<" "<<appointmentcnf.Appplname << " " << appointmentcnf.Apppnum << " " << appointmentcnf.Appspeciality << " "
                     << appointmentcnf.Appdocname << " " << appointmentcnf.Apptime << " " << appointmentcnf.Appdate << " "
                     << appointmentcnf.status << " "<<appointmentcnf.apnum<<endl;
            tempFile.close();
        }
    }

    apfile.close();

    remove("ptappdetails.txt");
    rename("temp.txt", "ptappdetails.txt");

            cout<<"You do not have any Appointments yet......"<<endl;

}

void doctorviewshedule(){
  int select9;
      cout<<"====View Schedule====="<<endl;
    cout<<endl;
    cout<<endl;
    //appointment conform
    cout<<"1.Conformation"<<endl;
    cout<<endl;
    //appointments
    cout<<"2.Appoiments"<<endl;
    cout<<endl;
    cout<<"3.Back"<<endl;
    cout<<endl;
    cout<<"4.Exit"<<endl;
    cout << "Enter number :";
    cin>>select9;
    cout<<endl;

    if(select9==1){

        cout<<endl;

        doctorappoimenteconform();
            cout<<endl;

        doctorviewshedule();
    }
    else if(select9==2){
                cout<<endl;


        conformpatientlist();
                    cout<<endl;

        doctorviewshedule();
    }
    else if(select9==3){
                cout<<endl;


        doctor();
    }
    cout<<endl;

}
void accesshistory(){

  ifstream medifile("medidetails.txt",ios::app);

    string pname,drname;

    cout<<"Enter Your Name : ";
    cin>>drname;

    cout<<"Enter Patient Name : ";
    cin>>pname;


    string line;



    while (getline(medifile, line)) {
        istringstream iss(line);
        Appointmentcnf appointmentcnf;

        getline(iss, appointmentcnf.Apppfname, ' ');
        getline(iss, appointmentcnf.Appplname, ' ');
        getline(iss, appointmentcnf.Appdocname, ' ');
        getline(iss, appointmentcnf.apnum, ' ');
        getline(iss, appointmentcnf.diagnosis, ' ');
        getline(iss, appointmentcnf.medicine, ' ');
        getline(iss, appointmentcnf.rec, ' ');
        getline(iss, appointmentcnf.status, ' ');


         if (appointmentcnf.Apppfname == pname && appointmentcnf.Appdocname == drname) {
          cout << "Patient Name : " << appointmentcnf.Apppfname <<" "<<appointmentcnf.Appplname<< endl;
            cout<<endl;
             cout << "diagnosis : " << appointmentcnf.diagnosis << endl;
            cout<<endl;
             cout << "prescribed medications : " << appointmentcnf.medicine << endl;
             cout<<endl;
              cout << "Additional recommendations : " << appointmentcnf.rec << endl;
              cout<<endl;
}

    }
    medifile.close();
 cout<<"No Any Records"<<endl;

}
void markcompleteapp() {

    string Anum,drusername;

    cout<<"Enter Your user Name : ";
    cin>>drusername;

    cout<<"Enter Appoiment Number : ";
    cin>>Anum;

    ifstream apfile("ptappdetails.txt");
    string line;
cout << endl;
    while (getline(apfile, line)) {
        istringstream iss(line);
        Appointmentcnf appointmentcnf;

        getline(iss, appointmentcnf.Apppfname, ' ');
        getline(iss, appointmentcnf.Appplname, ' ');
        getline(iss, appointmentcnf.Apppnum, ' ');
        getline(iss, appointmentcnf.Appspeciality, ' ');
        getline(iss, appointmentcnf.Appdocname, ' ');
        getline(iss, appointmentcnf.Apptime, ' ');
        getline(iss, appointmentcnf.Appdate, ' ');
        getline(iss, appointmentcnf.status, ' ');
        getline(iss, appointmentcnf.apnum, ' ');

         if (appointmentcnf.apnum == Anum && appointmentcnf.Appdocname == drusername && appointmentcnf.status == "confirmed") {

            cout << "Patient Name : " << appointmentcnf.Apppfname <<" "<<appointmentcnf.Appplname<< endl;
            cout<<endl;
            cout << "Disease : " << appointmentcnf.Appspeciality << endl;
            cout<<endl;
            cout<<endl;

            string action;
            cout << "Do you want to Close This Case? (y/n): ";
            cin >> action;

            if (action == "Y" || action == "y") {
                appointmentcnf.status = "closed";

                cout<<endl;
                cout<<"Case Successfully closed"<<endl;
                                cout<<endl;
                                }

             else if (action == "N" || action == "n") {
                cout<<endl;
                cout<<"Case Opening"<<endl;

            }
            fstream tempFile("temp.txt", ios::app);
            tempFile << appointmentcnf.Apppfname<<" "<<appointmentcnf.Appplname << " " << appointmentcnf.Apppnum << " " << appointmentcnf.Appspeciality << " "
                     << appointmentcnf.Appdocname << " " << appointmentcnf.Apptime << " " << appointmentcnf.Appdate << " "
                     << appointmentcnf.status <<" "<<appointmentcnf.apnum<< endl;
                      tempFile.close();

        }
        else {
            fstream tempFile("temp.txt", ios::app);
            tempFile << appointmentcnf.Apppfname<<" "<<appointmentcnf.Appplname << " " << appointmentcnf.Apppnum << " " << appointmentcnf.Appspeciality << " "
                     << appointmentcnf.Appdocname << " " << appointmentcnf.Apptime << " " << appointmentcnf.Appdate << " "
                     << appointmentcnf.status << " "<<appointmentcnf.apnum<<endl;
            tempFile.close();
        }
}

    apfile.close();

    remove("ptappdetails.txt");
    rename("temp.txt", "ptappdetails.txt");

}


void conformpatientlist() {
    fstream apfile("ptappdetails.txt");

string line,Dr1Name;

     cout<<"Enter Your First Name : ";
    cin>>Dr1Name;
cout<<endl;
cout<<"     Available Appointments      "<<endl;

         while (getline(apfile, line)) {
        istringstream iss(line);
        Appointment appointmentcnf;

        getline(iss, appointmentcnf.Apppfname, ' ');
        getline(iss, appointmentcnf.Appplname, ' ');
        getline(iss, appointmentcnf.Apppnum, ' ');
        getline(iss, appointmentcnf.Appspeciality, ' ');
        getline(iss, appointmentcnf.Appdocname, ' ');
        getline(iss, appointmentcnf.Apptime, ' ');
        getline(iss, appointmentcnf.Appdate, ' ');
        getline(iss, appointmentcnf.status, ' ');

         cout<<endl;
 if (appointmentcnf.Appdocname == Dr1Name && appointmentcnf.status == "confirmed"){

       cout<<endl;
      cout<<"Patient Name - "<<appointmentcnf.Apppfname<<" "<<appointmentcnf.Appplname<<"     "<<"Disease - "<< appointmentcnf.Appspeciality<<"     "<<" Date -"<<appointmentcnf.Appdate<<"     "<<"Time -"<<appointmentcnf.Apptime<<endl;

 }
}

    cout<<endl;
apfile.close();
cout<<"\n You do not have any Appointments yet......"<<endl;

}

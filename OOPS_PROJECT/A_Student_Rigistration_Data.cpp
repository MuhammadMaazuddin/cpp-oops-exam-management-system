#include<iostream>
#include<fstream>
using namespace std;


class STUD_RIGIST_DATA
{
    private:
        string Student_Name[216];
        string Student_Email_ID[216];
        string Student_Roll_No[216]; 
        string Student_Password[216];
        string SR[216]; 
        string Programming_Fundmental[216]; 
        string Object_Oriented_Programming[216];
        string Introduction_To_Computing[216];
        string Data_Structure[216];
        string Analysis_Of_Algorithms[216];
        string Software_Requirements_Engineering[216];
        string Reserch_Methadology[216];
        string Big_Data_Analytics[216];
        string Artificial_Intelligence[216];
        string Deep_Learning[216];
        string Digital_Image_Processing[216];
        int Student_Data_Index;
    public:
        int Get_Student_Data_Index();
        void Set_Data_Index(int Data_Index);
        int Registration_Data();
        void Display_All_Institute_Registration_Data();
        void Store_New_Student_Password(string password);
        string* Get_Student_Name();
        string* Get_Student_Email_Id();
        string* Get_Student_Roll_No();
        string* Get_Student_Password();
        string* GET_SR_Number();
        string* Get_Programming_Fundmental_Registration_Data();
        string* Get_Object_Oriented_Programming_Registration_Data();
        string* Get_Introduction_To_Computing_Registration_Data();
        string* Get_Data_Structure_Registration_Data();
        string* Get_Software_Requirements_Engineering_Registration_Data();
        string* Get_Analysis_Of_Algorithms_Rigistration_Data();
        string* Get_Reserch_Methadology_Registration_Data();
        string* Get_Big_Data_Analyticss_Registration_Data();
        string* Get_Artificial_Intelligence_Registration_Data();
        string* Get_Deep_Learning_Registration_Data();
        string* Get_Digital_Image_Processing_Registration_Data();
        bool Verify_Student_Password(string spassword);
        void Change_Student_Password();
        int Get_Present_SR_Number();
    
};
//************************    reading data from csv file   ****************************************
int STUD_RIGIST_DATA::Get_Present_SR_Number()
{int num;
    for(int i=0;i<216;i++)
    {
        if(Student_Data_Index == i)
        {
            num = stoi(SR[i]);break;
        }
    }
return num;
}
int STUD_RIGIST_DATA::Registration_Data()
{
    string value1_str;
    int num_data = 0;  
    ifstream file("STUD_DATA.csv");  
    string line;
    while (getline(file, line)) 
    {   
int num1=0,num2=0,num3=0;
for(num1;num1<line.size();num1++){if(line[num1]==','){value1_str = line.substr(0, num1);num2=num1;break;}}SR[num_data]=value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}} Student_Roll_No[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}} Student_Name[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}} Student_Email_ID[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}} Student_Password[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Programming_Fundmental[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Object_Oriented_Programming[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Introduction_To_Computing[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Data_Structure[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Analysis_Of_Algorithms[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Software_Requirements_Engineering[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Reserch_Methadology[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Big_Data_Analytics[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Artificial_Intelligence[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Deep_Learning[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}}  Digital_Image_Processing[num_data] = value1_str;

    num_data++;
}
return num_data;
}

//*******************************   displaying data present in csv file   ***********************************

void STUD_RIGIST_DATA::Display_All_Institute_Registration_Data()
{
    for(int i=0;i<216;i++)
        {cout<<SR[i]<<"\t"<<Student_Roll_No[i]<<"\t"<<Student_Name[i]<<"\t"<<Student_Email_ID[i]<<"\t"<<Student_Password[i]<<"\t"<<Programming_Fundmental[i]<<"\t"<<Object_Oriented_Programming[i]<<"\t"<<Software_Requirements_Engineering[i]<<"\t"<<Reserch_Methadology[i]<<"\t"<<Data_Structure[i]<<" "<<Analysis_Of_Algorithms[i]<<"\t"<<Introduction_To_Computing[i]<<"\t"<<Introduction_To_Computing[i]<<endl;}
}

//*******************************    returning data that is present in csv file     ***********************

string* STUD_RIGIST_DATA::Get_Student_Email_Id(){return Student_Email_ID;}
string* STUD_RIGIST_DATA::Get_Student_Roll_No(){return Student_Roll_No;}
string* STUD_RIGIST_DATA::Get_Student_Password(){return Student_Password;}
string* STUD_RIGIST_DATA::Get_Student_Name(){return Student_Name;}
string* STUD_RIGIST_DATA::GET_SR_Number(){return SR;}
string* STUD_RIGIST_DATA::Get_Programming_Fundmental_Registration_Data(){return Programming_Fundmental;}
string* STUD_RIGIST_DATA::Get_Object_Oriented_Programming_Registration_Data(){return Object_Oriented_Programming;}
string* STUD_RIGIST_DATA::Get_Introduction_To_Computing_Registration_Data(){return Introduction_To_Computing;}
string* STUD_RIGIST_DATA::Get_Data_Structure_Registration_Data(){return Data_Structure;}
string* STUD_RIGIST_DATA::Get_Analysis_Of_Algorithms_Rigistration_Data(){return Analysis_Of_Algorithms;}
string* STUD_RIGIST_DATA::Get_Software_Requirements_Engineering_Registration_Data(){return Software_Requirements_Engineering;}
string* STUD_RIGIST_DATA::Get_Reserch_Methadology_Registration_Data(){return Reserch_Methadology;}
string* STUD_RIGIST_DATA::Get_Big_Data_Analyticss_Registration_Data(){return Big_Data_Analytics;}
string* STUD_RIGIST_DATA::Get_Artificial_Intelligence_Registration_Data(){return Artificial_Intelligence;}
string* STUD_RIGIST_DATA::Get_Deep_Learning_Registration_Data(){return Deep_Learning;}
string* STUD_RIGIST_DATA::Get_Digital_Image_Processing_Registration_Data(){return Digital_Image_Processing;}
int STUD_RIGIST_DATA::Get_Student_Data_Index(){return Student_Data_Index;}



//*************************************************************************************************
void STUD_RIGIST_DATA::Change_Student_Password()
{
    string Password;
    int User_Option;
    cout<<"Enter the password...";
    cin>>Password;
    if(Verify_Student_Password(Password) == false)
    {
        for(int i=0;i<3;i++)
        {
            cout<<"So, if you want to enter Password again then press 1 and if you want to quit then press 2 ";cin>>User_Option;
            if(User_Option == 2){break;}
            else if(User_Option == 1){cout<<"Enter the password = ";cin>>Password;if(Verify_Student_Password(Password) == true){break;}}
            else if(i == 2){cout<<"Sorry! you can not try more then three times go back to main menu...\n";}
        }
    }
    Store_New_Student_Password(Password);
    
}


//**************************************** verifying password ********************************************
bool STUD_RIGIST_DATA::Verify_Student_Password(string password)
{
    bool flag_4 = false; bool flag_1 = false;bool flag_2 = false;bool flag_3 = false;int i=0;
    for( i=0;password[i]!='\0';i++){}
    if(i<6){cout<<"!!!  short legnth ";}

    for(int  j=0;password[j]!='\0';j++)
    {
        if(password[j]>=65&&password[j]<=90){flag_1 = true;}
        else if(password[j]>=97&&password[j]<=122){flag_2 = true;}
        else if(password[j]>='0' && password[j]<='9'){flag_3 = true;}
    }

    if(flag_1 == true && flag_2 == true && flag_3 == true){cout<<"Your have been changed successfully \n\n";flag_4=true;}
    else{cout<<" !!!incorrect format !!!  ";}
    if(flag_1 != true ){cout<<" !!!uppercase letters missing!!!  ";}
    if(flag_2 != true){cout<<" !!!lowercase letters missing!!!  ";}
    if(flag_3 != true){cout<<" !!!Digit  missing!!!  ";}
    cout<<endl<<endl;
   
return flag_4;
}
//*********************************** storing the changed password in csv file ********************************************
void STUD_RIGIST_DATA::Store_New_Student_Password(string password)
{
        int i = Student_Data_Index; // i because it is easy to use
        Student_Password[i] = password;
        string filename = "STUD_DATA.csv";
        string new_row = SR[i]+","+Student_Roll_No[i]+","+Student_Name[i]+","+Student_Email_ID[i]+","+Student_Password[i]+","+Programming_Fundmental[i]+","+Object_Oriented_Programming[i]+","+Introduction_To_Computing[i]+","+Data_Structure[i]+","+Analysis_Of_Algorithms[i]+","+Software_Requirements_Engineering[i]+","+Reserch_Methadology[i]+","+Big_Data_Analytics[i]+","+Artificial_Intelligence[i]+","+Deep_Learning[i]+","+Digital_Image_Processing[i]+",";
        cout<<new_row<<endl;
        i++;
        fstream file(filename, ios::in);
        string temp_filename = "temp.csv";
        fstream temp_file(temp_filename, ios::out);
        string line;
    int current_row = 1;
    while (getline(file, line)) 
    {
        if (current_row == i){temp_file<<new_row<<endl;}
        else{temp_file<<line<<endl;}
        current_row++;
    }
    file.close();
    temp_file.close();
    remove(filename.c_str());
    rename(temp_filename.c_str(), filename.c_str());

}
void STUD_RIGIST_DATA::Set_Data_Index(int Data_Index)
{
    Student_Data_Index = Data_Index;
}
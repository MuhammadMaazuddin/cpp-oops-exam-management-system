
#include<iostream>
#include<fstream>
#include<cstring>
#include<dirent.h>
#include"F_Teacher_Rigistration_Data.cpp"
using namespace std;

class TEACH: public TEACH_RIGIST  
{
    private:
        int Tecaher_Data_Index;
    public:
        bool Verify_Teacher_Email_ID(string User_ID);
        bool Verify_Teacher_Password(string User_Password);
        void Management_System_In_Teacher_Mode();
        void Enter_To_The_Class(const char* Class_Name);
        bool Check_File_Name_EITHER_PRESENT_OR_NOT(const char* Class_Name, string Assighment_Name);
        void Upload_Assighemnt(const char* Class_Name);
        string* MCQ_Question_Bank(string ClassName);
        string* T_F_Question_Bank(string ClassName);
        string* Fill_Question_Bank(string ClassName);
        string* Discriptive_Question_Bank(string ClassName);



};
string* TEACH::T_F_Question_Bank(string ClassName)
{
string Path = "/";
    string folder = "Q_Bank";
    string file1 = "TF.txt";
    string file_name = folder+Path+ClassName+Path+file1;
    string line;
    string* question= new string[10*4];
    fstream file(file_name);
    int count=0;
    while(getline(file,line))
    {
        question[count] = line;
        count++;
    }

return question;
}
string* TEACH::Fill_Question_Bank(string ClassName)
{
string Path = "/";
    string folder = "Q_Bank";
    string file1 = "fill.txt";
    string file_name = folder+Path+ClassName+Path+file1;
    string line;
    string* question= new string[10*4];
    fstream file(file_name);
    int count=0;
    while(getline(file,line))
    {
        question[count] = line;
        count++;
    }

return question;
}
string* TEACH::Discriptive_Question_Bank(string ClassName)
{
string Path = "/";
    string folder = "Q_Bank";
    string file1 = "DSC.txt";
    string file_name = folder+Path+ClassName+Path+file1;
    string line;
    string* question= new string[20];
    fstream file(file_name);
    int count=0;
    while(getline(file,line))
    {
        question[count] = line;
        count++;
    }

return question;
}



string* TEACH::MCQ_Question_Bank(string ClassName)
{

    string Path = "/";
    string folder = "Q_Bank";
    string file1 = "MCQ.txt";
    string file_name = folder+Path+ClassName+Path+file1;
    string line;
    string* question= new string[25*6];
    fstream file(file_name);
    int count=0;
    while(getline(file,line))
    {
        question[count] = line;
        count++;
    }

return question;

}

bool TEACH::Verify_Teacher_Email_ID(string User_ID)
{
    string* Teacher_Stored_ID_Data = new string[11];
    Teacher_Stored_ID_Data = Get_Teacher_Email_ID();
    bool ID_Verification = false;
    for(int i=0;i<11;i++){if(Teacher_Stored_ID_Data[i] == User_ID){ID_Verification = true;Tecaher_Data_Index=i;break;}else{ID_Verification = false;}}
    return ID_Verification;
}
bool TEACH::Verify_Teacher_Password(string User_Password)
{
    string* Teacher_Stored_Password_Data = new string[216];
    Teacher_Stored_Password_Data = Get_Teacher_Password();
    bool Password_Verification = false;
    for(int i=0;i<216;i++){if(Teacher_Stored_Password_Data[i] == User_Password){Password_Verification=true;break;}else{Password_Verification=false;}}
   return Password_Verification;

}
void TEACH::Management_System_In_Teacher_Mode()
{
if(Tecaher_Data_Index == 0){Enter_To_The_Class("PF");}
else if(Tecaher_Data_Index == 1){Enter_To_The_Class("OOPs");}
else if(Tecaher_Data_Index == 2){Enter_To_The_Class("ITC");}
else if(Tecaher_Data_Index == 3){Enter_To_The_Class("DS");}
else if(Tecaher_Data_Index == 4){Enter_To_The_Class("AOA");}
else if(Tecaher_Data_Index == 5){Enter_To_The_Class("SRE");}
else if(Tecaher_Data_Index == 6){Enter_To_The_Class("RM");}
else if(Tecaher_Data_Index == 7){Enter_To_The_Class("BDA");}
else if(Tecaher_Data_Index == 8){Enter_To_The_Class("AI");}
else if(Tecaher_Data_Index == 9){Enter_To_The_Class("DL");}
else if(Tecaher_Data_Index == 10){Enter_To_The_Class("DIP");}


}
void TEACH::Enter_To_The_Class(const char* Class_Name)
{
    string Email_ID;
    string* Teacher_Stored_ID_Data = new string[11];
    Teacher_Stored_ID_Data = Get_Teacher_Email_ID();
    for(int i=0;i<11;i++){if(i==Tecaher_Data_Index){Email_ID = Teacher_Stored_ID_Data[i];}}
    int user_option = 0;

    for(int i=0;i<10;i++)
    {

cout<<"*******************************************************************\n";
cout<<"*                        TEACHER MODE                             *\n";
cout<<"*******************************************************************\n";
cout<<"*  PRESS 1 if you want to upload Assighment                       *\n";
cout<<"*  PRESS 2 if you want to go back to main menu                    *\n";
cout<<"*******************************************************************\n";
cout<<"   PRESS : ";cin>>user_option;


if(user_option == 1){Upload_Assighemnt(Class_Name);}
else if(user_option == 2){break;}

    }

}



void TEACH::Upload_Assighemnt(const char* Class_Name)
{
    for(int i=0;i<10;i++)
    {

    
int user_option=0;
string Assighment_Name;
string Path = "/";
string File_Path = Class_Name+Path;
string File_Extension = ".txt";
string Assighment_Type;
string Total_Number_Of_Qusetions = "Numbers of Questions=";
string Submission_Time = "Submission Time:";
string Assighment_Duration_Time = "Assighmnet Duration Time:" ;
int num_of_qs;
string Time;
string check;
string CMA = ",";
string STP = ".";

cout<<"*******************************************************************\n";
cout<<"* PRESS 1 if you want to upload MCQs type question                *\n";
cout<<"* PRESS 2 if you want to upload Fill in the blanks type question  *\n";
cout<<"* PRESS 3 if you want to upload True False type qusetion          *\n";
cout<<"* PRESS 4 if you want to upload Discriptive type question         *\n";
cout<<"* PRESS 5 if you want to go to back menu                          *\n";
cout<<"*******************************************************************\n";
cout<<" PRESS : ";cin>>user_option;


if(user_option == 1){Assighment_Type = "Assighment type: MCQs.";}
else if(user_option == 2){Assighment_Type = "Assighment type: Fill in the blanks.";}
else if(user_option == 3){Assighment_Type = "Assighment type: T/F's.";}
else if(user_option == 4){Assighment_Type = "Assighment type: Q/A's.";}
else if(user_option == 5){break;}
cout<<"*******************************************************************\n";
cout<<"*  ENTER the name of you Assighment                               *\n";
cout<<"*******************************************************************\n";
cout<<" ENTER : ";cin>>Assighment_Name;check=Assighment_Name+File_Extension;Assighment_Name=File_Path+Assighment_Name+File_Extension;
for(int i=0;i<10;i++){if(Check_File_Name_EITHER_PRESENT_OR_NOT(Class_Name,check)==true)
{cout<<"The file on this name already Exist ! PLZ try again\n";
cout<<"*******************************************************************\n";
cout<<"*  ENTER the name of you Assighment again                         *\n";
cout<<"*******************************************************************\n";
cout<<" ENTER : ";cin>>Assighment_Name;check=Assighment_Name+File_Extension;Assighment_Name=File_Path+Assighment_Name+File_Extension;
}else{break;}}
int num=0;
cout<<"*******************************************************************\n";
cout<<"* ENTER Submission Date-time --> format DD/MM/YYYY,HRMN  (24hrs)  *\n";
cout<<"*******************************************************************\n";
cout<<"* ENTER : ";cin>>Time;Submission_Time+=Time+STP;
cout<<"*******************************************************************\n";
cout<<"* ENTER the Assighment Duration Time in minutes                   *\n";
cout<<"*******************************************************************\n";
cout<<" ENTER : ";cin>>Time;num=stoi(Time);num*=60;Time=to_string(num);Assighment_Duration_Time+=Time+CMA;
cout<<"*******************************************************************\n";
cout<<"* ENTER total Number of questions                                 *\n";
cout<<"*******************************************************************\n";
cout<<" ENTER : ";cin>>Time;Total_Number_Of_Qusetions+=Time+STP;
num_of_qs = stoi(Time);


if(Assighment_Type == "Assighment type: MCQs.")
{

string quiz[(num_of_qs*6)+4];
quiz[0]=Assighment_Type;
quiz[1]=Total_Number_Of_Qusetions;
quiz[2]=Submission_Time;
quiz[3]=Assighment_Duration_Time;

string* question_Bank = new string[25*6];
question_Bank = MCQ_Question_Bank(Class_Name);
cout<<"*******************************************************************\n";
cout<<"*          Question Bank                                          *\n";
cout<<"*******************************************************************\n";
int INDEX=1;
int __COUNT=0;
for(int i=0;i<25;i++)
{
    cout<<INDEX<<"."<<question_Bank[__COUNT];cout<<endl;
    cout<<question_Bank[__COUNT+1];cout<<endl;
    cout<<question_Bank[__COUNT+2];cout<<endl;
    cout<<question_Bank[__COUNT+3];cout<<endl;
    cout<<question_Bank[__COUNT+4];cout<<endl;
    cout<<question_Bank[__COUNT+5];cout<<endl;

    __COUNT+=6;INDEX++;

}
int option = 0;
int COUNT=4;
for(int i=0;i<num_of_qs;i++)
{

string q_num = to_string(i+1);

cout<<"*******************************************************************\n";
cout<<"Which question due you want to add in assignment                  *\n";
cout<<"*******************************************************************\n";
 cout<<"ENTER : ";cin>>option;

 int Q_NUM=0;
 Q_NUM = ((option-1)*6);
 string qs = question_Bank[Q_NUM];
 string fullStr = q_num+STP+qs;
quiz[COUNT] = fullStr;
quiz[COUNT+1] = question_Bank[Q_NUM+1];
quiz[COUNT+2] = question_Bank[Q_NUM+2];
quiz[COUNT+3] = question_Bank[Q_NUM+3];
quiz[COUNT+4] = question_Bank[Q_NUM+4];
quiz[COUNT+5] = question_Bank[Q_NUM+5];
COUNT+=6;
}






        ofstream file(Assighment_Name);
    if (file.is_open()) {
        for (int i = 0; i < (num_of_qs*6)+4; ++i) {
            file << quiz[i] << endl;
        }
        file.close();
    } 











}
else if(Assighment_Type == "Assighment type: Fill in the blanks.")
{
string quiz[(num_of_qs*4)+4];
quiz[0]=Assighment_Type;
quiz[1]=Total_Number_Of_Qusetions;
quiz[2]=Submission_Time;
quiz[3]=Assighment_Duration_Time;

string* question_Bank = new string[10*4];
question_Bank = Fill_Question_Bank(Class_Name);
cout<<"*******************************************************************\n";
cout<<"*          Question Bank                                          *\n";
cout<<"*******************************************************************\n";
int INDEX=1;
int __COUNT=0;
for(int i=0;i<10;i++)
{
    cout<<INDEX<<"."<<question_Bank[__COUNT];cout<<endl;
    cout<<question_Bank[__COUNT+1];cout<<endl;
    cout<<question_Bank[__COUNT+2];cout<<endl;
    cout<<question_Bank[__COUNT+3];cout<<endl;
   

    __COUNT+=4;INDEX++;

}
int option = 0;
int COUNT=4;
for(int i=0;i<num_of_qs;i++)
{

string q_num = to_string(i+1);

cout<<"*******************************************************************\n";
cout<<"Which question due you want to add in assignment                  *\n";
cout<<"*******************************************************************\n";
 cout<<"ENTER : ";cin>>option;

 int Q_NUM=0;
 Q_NUM = ((option-1)*4);
 string qs = question_Bank[Q_NUM];
 string fullStr = q_num+STP+qs;
quiz[COUNT] = fullStr;
quiz[COUNT+1] = question_Bank[Q_NUM+1];
quiz[COUNT+2] = question_Bank[Q_NUM+2];
quiz[COUNT+3] = question_Bank[Q_NUM+3];

COUNT+=4;
}






        ofstream file(Assighment_Name);
    if (file.is_open()) {
        for (int i = 0; i < (num_of_qs*4)+4; ++i) {
            file << quiz[i] << endl;
        }
        file.close();
    } 











}
else if(Assighment_Type == "Assighment type: T/F's.")
{
string quiz[(num_of_qs*4)+4];
quiz[0]=Assighment_Type;
quiz[1]=Total_Number_Of_Qusetions;
quiz[2]=Submission_Time;
quiz[3]=Assighment_Duration_Time;

string* question_Bank = new string[10*4];
question_Bank = T_F_Question_Bank(Class_Name);
cout<<"*******************************************************************\n";
cout<<"*          Question Bank                                          *\n";
cout<<"*******************************************************************\n";
int INDEX=1;
int __COUNT=0;
for(int i=0;i<10;i++)
{
    cout<<INDEX<<"."<<question_Bank[__COUNT];cout<<endl;
    cout<<question_Bank[__COUNT+1];cout<<endl;
    cout<<question_Bank[__COUNT+2];cout<<endl;
    cout<<question_Bank[__COUNT+3];cout<<endl;
   

    __COUNT+=4;INDEX++;

}
int option = 0;
int COUNT=4;
for(int i=0;i<num_of_qs;i++)
{

string q_num = to_string(i+1);

cout<<"*******************************************************************\n";
cout<<"Which question due you want to add in assignment                  *\n";
cout<<"*******************************************************************\n";
 cout<<"ENTER : ";cin>>option;

 int Q_NUM=0;
 Q_NUM = ((option-1)*4);
 string qs = question_Bank[Q_NUM];
 string fullStr = q_num+STP+qs;
quiz[COUNT] = fullStr;
quiz[COUNT+1] = question_Bank[Q_NUM+1];
quiz[COUNT+2] = question_Bank[Q_NUM+2];
quiz[COUNT+3] = question_Bank[Q_NUM+3];

COUNT+=4;
}






        ofstream file(Assighment_Name);
    if (file.is_open()) {
        for (int i = 0; i < (num_of_qs*4)+4; ++i) {
            file << quiz[i] << endl;
        }
        file.close();
    } 










}
else if(Assighment_Type == "Assighment type: Q/A's.")
{
string quiz[(num_of_qs)];
quiz[0]=Assighment_Type;
quiz[1]=Total_Number_Of_Qusetions;
quiz[2]=Submission_Time;
quiz[3]=Assighment_Duration_Time;

string* question_Bank = new string[20];
question_Bank = Discriptive_Question_Bank(Class_Name);
cout<<"*******************************************************************\n";
cout<<"*          Question Bank                                          *\n";
cout<<"*******************************************************************\n";
int __COUNT=0;
for(int i=0;i<10;i++)
{
    cout<<i+1<<"."<<question_Bank[i];cout<<endl;
    
   


}
int option = 0;
int COUNT=4;
for(int i=0;i<num_of_qs;i++)
{

string q_num = to_string(i+1);

cout<<"*******************************************************************\n";
cout<<"Which question due you want to add in assignment                  *\n";
cout<<"*******************************************************************\n";
 cout<<"ENTER : ";cin>>option;


 string qs = question_Bank[option-1];
 string fullStr = q_num+STP+qs;
quiz[COUNT] = fullStr;


COUNT++;
}





        ofstream file(Assighment_Name);
    if (file.is_open()) {
        for (int i = 0; i < num_of_qs+4; ++i) {
            file << quiz[i] << endl;
        }
        file.close();
    } 










}








    }

}
bool TEACH::Check_File_Name_EITHER_PRESENT_OR_NOT(const char* Class_Name, string Assighment_Name)
{
    bool flag=false;
    DIR* dir;
    int count;
    struct dirent* entry;
    char file_names[50][50];
    for(int i=0;i<50;i++)
    {    
    count = 0;
        if ((dir = opendir(Class_Name))) 
        {
            while ((entry = readdir(dir))) 
            {
                if (entry->d_type == DT_REG && count < 10) 
                {
                    strncpy(file_names[count], entry->d_name, 50);
                    string name = file_names[count];
                    if(name == Assighment_Name){flag=true;break;}
                    count++;
                }
            }
        }
    }
return flag;
}
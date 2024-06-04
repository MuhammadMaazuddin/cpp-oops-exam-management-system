#include<iostream>
#include <dirent.h>
#include<cstring>
#include"C_Assignment_Conduction.cpp"
using namespace std;
class ASSIGNMENT_IN_CLASS : public ASSIGNMENT_CONDUCTION
{
    private:
        int Student_Index;
    public:
        void Display_Classes_Menu();
        void Programming_Fundmental_Class(const char* class_name); 
        void Object_Oriented_Programming_Class(const char* class_name);
        void Introduction_To_Computing_Class(const char* class_name);
        void Data_Structure_Class(const char* class_name);
        void Analysis_Of_Algorithms_Class(const char* class_name);
        void Software_Requirements_Engineering_Class(const char* class_name);
        void Reserch_Methadology_Class(const char* class_name);
        void Big_Data_Analytics_Class(const char* class_name);
        void Artificial_Intelligence_Class(const char* class_name);
        void Deep_Learning_Class(const char* class_name);
        void Digital_Image_Processing_Class(const char* class_name);
        bool Check_User_Registration_Verifucation(string subject);
        int get_Student_Data_Index();
        void Display_Classes_Instruction();
        void Show_Class(const char* class_name, string teacher_name, string File_Name);


};
void ASSIGNMENT_IN_CLASS::Show_Class(const char* class_name, string teacher_name, string File_Name)
{

DIR* dir;
int count;
string Path="/";
string Present_File_Name;
    struct dirent* entry;
    char file_names[50][50];
    for(int i=0;i<50;i++)
    {    
Display_Classes_Instruction();
    count = 0;

    if ((dir = opendir(class_name))) 
    {
        cout << "Files in class " << class_name << ":" << endl;
        while ((entry = readdir(dir))) 
        {
            if (entry->d_type == DT_REG && count < 10) 
            {
                strncpy(file_names[count], entry->d_name, 50);
                string name = file_names[count];
                string task = file_names[count];
                Present_File_Name = class_name+Path+task;
                string Status = file_names[count];
                string Status_Check = File_Name + Path + Status;
           bool check =     Check_file_Slot_In_CSV_File(name,File_Name);
                           name +=",,,";

                if(check == true){Add_New_Col_Of_New_Assighment_File(name,File_Name);}
                                

                count++;


                
cout<<"*******************************************************************\n";
cout<<"* "<<count <<"."<< teacher_name<< " Posted a new Assighment"<<" "<<entry->d_name<<"\n"; 
cout<<"*                                   ";Show_Submission_Time(class_name,task,1);;
if(Check_Assighment_Status(File_Name,task)=="P")
{
cout<<"*                                                      Turned in  *\n";
}
else if(Check_Assighment_Status(File_Name,task)=="PL")
{
cout<<"*                                                 Turned in late  *\n";
}
else if(Check_Assighment_Status(File_Name,task)=="A")
{
    
    if(Check_Live_And_Submission_Time(Present_File_Name) == true)
    {
cout<<"*                                                    Remaining    *\n";
    }
    else if(Check_Live_And_Submission_Time(Present_File_Name) == false)
    {
cout<<"*                                                      Missing    *\n";
    }
}
cout<<"*******************************************************************\n";

            }
        }
        
        closedir(dir);
        if (count > 0) 
        {
            cout << "Which Task do you want to edit? (Enter a number between 1 and " << count << ")" << endl;
             
            int file_num;
            cin >> file_num;
            if (file_num >= 1 && file_num <= count) 
            {
                string file_name = file_names[file_num - 1];
                string path = "/";
                file_name =  class_name + path + file_name;
            

                cout<<File_Name<<" "<<file_name<<endl;
                if(Check_Assighment_Status(File_Name,file_name) == "A")
                {
                    Open_The_Corresonding_Assighment(file_name,File_Name);

                }
                else
                {
cout<<"*******************************************************************\n";
cout<<"* Sorry! you can not do the Task Again                            *\n";
cout<<"*******************************************************************\n";


                }
            }
        }
    } 
            char user_option;
            cout<<"If you want to leave the class then press a... and if not then press b... = ";cin>>user_option;if(user_option == 'a'){break;}
            else{continue;}
}

}

void ASSIGNMENT_IN_CLASS::Display_Classes_Instruction()
{
cout<<"*******************************************************************\n";
cout<<"*                             INSTRUCTION                         *\n";
cout<<"*  1. Once you enter the Assighment you will have to complete it  *\n";
cout<<"*  other wise you cannot leave the Assighment.                    *\n";
cout<<"*  2. You can do your Assighmnet only one time.                   *\n";
cout<<"*  3. If you want to leave your task then PRESS 555 but remmember *\n";
cout<<"*  PRESS 555 but remmember your marks will be deducted.           *\n";
cout<<"*******************************************************************\n";
}


void ASSIGNMENT_IN_CLASS::Programming_Fundmental_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Programming Fundmental                                    AI_C  *\n";
cout<<"* Adil Majeed                                                     *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Sir Adil Majeed","Flex/PF.csv");
}
void ASSIGNMENT_IN_CLASS::Object_Oriented_Programming_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Object Oreiented Programming                              AI_C  *\n";
cout<<"* Hassan Mujthaba                                                 *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Hassan Mujthaba","Flex/OOPs.csv");
}
void ASSIGNMENT_IN_CLASS::Introduction_To_Computing_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Introduction To Computing                                 AI_C  *\n";
cout<<"* Omer Beg                                                        *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Omer Beg","Flex/ITC.csv");

}
void ASSIGNMENT_IN_CLASS::Data_Structure_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Data Structure                                            AI_C  *\n";
cout<<"* Irfaan Shah                                                     *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Irfaan Shah","Flex/DS.csv");

}
void ASSIGNMENT_IN_CLASS::Analysis_Of_Algorithms_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Analysis Of Algorithms                                    AI_C  *\n";
cout<<"* Muhammad Ishtiaq                                                *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Muhammad Ishtiaq","Flex/AOA.csv");

}
void ASSIGNMENT_IN_CLASS::Software_Requirements_Engineering_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Software Requirements Engineering                         AI_C  *\n";
cout<<"* Muhammad Ibrahim                                                *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Muhammad Ibrahim","Flex/SRE.csv");

}
void ASSIGNMENT_IN_CLASS::Reserch_Methadology_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Reserch Methadology                                       AI_C  *\n";
cout<<"* Muhammad Munawar                                                *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Muhammad Munawar","Flex/RM.csv");

}
void ASSIGNMENT_IN_CLASS::Big_Data_Analytics_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Big Data Analytics                                        AI_C  *\n";
cout<<"* Hammad Majeed                                                   *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Hammad Majeed","Flex/BDA.csv");

}
void ASSIGNMENT_IN_CLASS::Artificial_Intelligence_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* ARTIFICIAL INTELLIHENCE                                   AI_C  *\n";
cout<<"* Ansa Liaqat                                                     *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Ansa Liaqat","Flex/AI.csv");

}
void ASSIGNMENT_IN_CLASS::Deep_Learning_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Deep Learning                                             AI_C  *\n";
cout<<"* Maryam Nawaz                                                    *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Maryam Nawaz","Flex/DL.csv");

}
void ASSIGNMENT_IN_CLASS::Digital_Image_Processing_Class(const char* class_name)
{
cout<<"*******************************************************************\n";
cout<<"* Digital Image Processing                                  AI_C  *\n";
cout<<"* Sobia Qamar                                                     *\n";
cout<<"*******************************************************************\n";
Show_Class(class_name,"Sobia Qamar","Flex/DIPcsv");

}
bool ASSIGNMENT_IN_CLASS::Check_User_Registration_Verifucation(string subject)
{
    string* Subject = new string[216];
    int Data_Index = Get_Student_Data_Index();
    bool Registration_Verification = false;
if(subject == "PF")
{
    Subject = Get_Programming_Fundmental_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "OOPs")
{
    Subject = Get_Object_Oriented_Programming_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "ITC")
{
    Subject = Get_Introduction_To_Computing_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "DS")
{
    Subject = Get_Data_Structure_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "DL")
{
    Subject = Get_Deep_Learning_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "BDA")
{
    Subject = Get_Big_Data_Analyticss_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "RM")
{
    Subject = Get_Reserch_Methadology_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "SRE")
{
    Subject = Get_Software_Requirements_Engineering_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "DIP")
{
    Subject = Get_Digital_Image_Processing_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "AI")
{
    Subject = Get_Artificial_Intelligence_Registration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}
else if(subject == "AOA")
{
    Subject = Get_Analysis_Of_Algorithms_Rigistration_Data();
    if(Subject[Data_Index] == "1"){Registration_Verification = true;}else if(Subject[Data_Index] == "0"){Registration_Verification = false;}
}

return Registration_Verification;

}

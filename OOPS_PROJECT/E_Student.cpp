#include<iostream>
#include<fstream>
#include"D_Assignment_In_Classes.cpp"
using namespace std;
class STUD: public ASSIGNMENT_IN_CLASS
{
    private:
        int Student_Data_Index;
    public:
        bool User_Entered_ID_Verification(string User_ID);
        bool User_Entered_Password_Verification(string User_Password);
        void Management_System_In_Student_Mode();

};




bool STUD::User_Entered_ID_Verification(string User_ID)
{
    string* Student_Stored_ID_Data = new string[216];
    Student_Stored_ID_Data = Get_Student_Email_Id();
    bool ID_Verification = false;
    for(int i=0;i<216;i++){if(Student_Stored_ID_Data[i] == User_ID){ID_Verification = true;Student_Data_Index=i;break;}else{ID_Verification = false;}}
    return ID_Verification;
}

bool STUD::User_Entered_Password_Verification(string User_Password)
{
    string* Student_Stored_Password_Data = new string[216];
    Student_Stored_Password_Data = Get_Student_Password();
    bool Password_Verification = false;
 if(Student_Stored_Password_Data[Student_Data_Index] == User_Password){Password_Verification=true;}else{Password_Verification=false;}
    Set_Data_Index(Student_Data_Index);
   return Password_Verification;

}
// taking option from students in the menues

void STUD::Management_System_In_Student_Mode()
{
    //cout<<Get_Present_SR_Number()<<endl;
    int User_Option;
    for(int i=0;i<50;i++)
    {
cout<<"*******************************************************************\n";
cout<<"*  PRESS 1 if you want to check or solve your quizes/assighments  *\n";
cout<<"*  PRESS 2 if you want to see your attendence and marks           *\n";
cout<<"*  PRESS 3 if you want to change your Password                    *\n";
cout<<"*  PRESS 4 if you want to go back to main menu                    *\n";
cout<<"*******************************************************************\n";
cout<<"  PRESS : ";cin>>User_Option;


if(User_Option == 1)
{
Display_Classes_Menu();
}
else if(User_Option == 2)
{
Display_Marks_and_Attendence_Menue();
}
else if(User_Option == 3)
{
Change_Student_Password();
}
else if(User_Option == 4){break;}

    }
}



// shows only rigitered classes
void ASSIGNMENT_IN_CLASS::Display_Classes_Menu()
{
    string* Student_Email_Id = new string[216];
    Student_Email_Id = Get_Student_Email_Id();
    Student_Index = Get_Student_Data_Index();
    Set_Student_Index(Student_Index);
    int User_Option;
    for(int i=0;i<50;i++)
    {
// entering to the class
cout<<"*******************************************************************\n";
cout<<"*                               CLASSES                           *\n";
cout<<"*******************************************************************\n";
cout<<"*******************************************************************\n";
if(Check_User_Registration_Verifucation("PF")==true)
{cout<<"*  PRESS 1 to enter Programming fundmental Class                  *\n";}
if(Check_User_Registration_Verifucation("OOPs")==true)
{cout<<"*  PRESS 2 to enter object oreiented programming                  *\n";}
if(Check_User_Registration_Verifucation("ITC")==true)
{cout<<"*  PRESS 3 to enter introdeuction to computing                    *\n";}
if(Check_User_Registration_Verifucation("DS")==true)
{cout<<"*  PRESS 4 to enter Data structure class                          *\n";}
if(Check_User_Registration_Verifucation("AOA")==true)
{cout<<"*  PRESS 5 to enter to the analysis of Algorithm                  *\n";}
if(Check_User_Registration_Verifucation("SRE")==true)
{cout<<"*  PRESS 6 to enter software requirement engineering              *\n";}
if(Check_User_Registration_Verifucation("RM")==true)
{cout<<"*  PRESS 7 to enter Reserch Methadology                           *\n";}
if(Check_User_Registration_Verifucation("BDA")==true)
{cout<<"*  PRESS 8 to enter Big Data Analysis                             *\n";}
if(Check_User_Registration_Verifucation("AI")==true)
{cout<<"*  PRESS 9 to enter Artificail Intelligence                       *\n";}
if(Check_User_Registration_Verifucation("DL")==true)
{cout<<"*  PRESS 10 to enter Deep Learning                                *\n";}
if(Check_User_Registration_Verifucation("DIP")==true)
{cout<<"*  PRESS 11 to enter Digital Image processing                     *\n";}
cout<<"*  PRESS 12 to Go back to MAIN MANU                               *\n";
cout<<"*******************************************************************\n";
cout<<"  PRESS : ";cin>>User_Option;
cout<<endl;


if(User_Option == 1){if(Check_User_Registration_Verifucation("PF") == true){Programming_Fundmental_Class("PF");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 2){if(Check_User_Registration_Verifucation("OOPs") == true){Object_Oriented_Programming_Class("OOPs");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 3){if(Check_User_Registration_Verifucation("ITC") == true){Introduction_To_Computing_Class("ITC");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 4){if(Check_User_Registration_Verifucation("DS") == true){Data_Structure_Class("DS");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 5){if(Check_User_Registration_Verifucation("AOA") == true){Analysis_Of_Algorithms_Class("AOA");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 6){if(Check_User_Registration_Verifucation("SRE") == true){Software_Requirements_Engineering_Class("SRE");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 7){if(Check_User_Registration_Verifucation("RM") == true){Reserch_Methadology_Class("RM");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 8){if(Check_User_Registration_Verifucation("BDA") == true){Big_Data_Analytics_Class("BDA");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 9){if(Check_User_Registration_Verifucation("AI") == true){Artificial_Intelligence_Class("AI");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 10){if(Check_User_Registration_Verifucation("DL") == true){Deep_Learning_Class("DL");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 11){if(Check_User_Registration_Verifucation("DIP") == true){Digital_Image_Processing_Class("DIP");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 12){break;}


    }
}

void MARKS_ATTEND::Display_Marks_and_Attendence_Menue()
{
    string* Student_Email_Id = new string[216];
    Student_Email_Id = Get_Student_Email_Id();
    Student_Index = Get_Student_Data_Index();
    Set_Student_Index(Student_Index);
    int User_Option;
    for(int i=0;i<50;i++)
    {




cout<<"*******************************************************************\n";
cout<<"*                                FLEX                             *\n";
cout<<"*******************************************************************\n";
cout<<"*******************************************************************\n";

if(User_Registration_Verification_Data("PF")==true)
{cout<<"*  PRESS 1 to enter Programming fundmental                        *\n";}
if(User_Registration_Verification_Data("OOPs")==true)
{cout<<"*  PRESS 2 to enter object oreiented programming                  *\n";}
if(User_Registration_Verification_Data("ITC")==true)
{cout<<"*  PRESS 3 to enter introdeuction to computing                    *\n";}
if(User_Registration_Verification_Data("DS")==true)
{cout<<"*  PRESS 4 to enter Data structure class                          *\n";}
if(User_Registration_Verification_Data("AOA")==true)
{cout<<"*  PRESS 5 to enter to the analysis of Algorithm                  *\n";}
if(User_Registration_Verification_Data("SRE")==true)
{cout<<"*  PRESS 6 to enter software requirement engineering              *\n";}
if(User_Registration_Verification_Data("RM")==true)
{cout<<"*  PRESS 7 to enter Reserch Methadology                           *\n";}
if(User_Registration_Verification_Data("BDA")==true)
{cout<<"*  PRESS 8 to enter Big Data Analysis                             *\n";}
if(User_Registration_Verification_Data("AI")==true)
{cout<<"*  PRESS 9 to enter Artificail Intelligence                       *\n";}
if(User_Registration_Verification_Data("DL")==true)
{cout<<"*  PRESS 10 to enter Deep Learning                                *\n";}
if(User_Registration_Verification_Data("DIP")==true)
{cout<<"*  PRESS 11 to enter Digital Image processing                     *\n";}
cout<<"*  PRESS 12 to Go back to MAIN MANU                               *\n";
cout<<"*******************************************************************\n";
cout<<"  PRESS : ";cin>>User_Option;
cout<<endl;


if(User_Option == 1){if(User_Registration_Verification_Data("PF") == true){Show_Marks_And_Attendence("Flex/PF.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 2){if(User_Registration_Verification_Data("OOPs") == true){Show_Marks_And_Attendence("Flex/OOPs.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 3){if(User_Registration_Verification_Data("ITC") == true){Show_Marks_And_Attendence("Flex/ITC.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 4){if(User_Registration_Verification_Data("DS") == true){Show_Marks_And_Attendence("Flex/DS.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 5){if(User_Registration_Verification_Data("AOA") == true){Show_Marks_And_Attendence("Flex/AOA.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 6){if(User_Registration_Verification_Data("SRE") == true){Show_Marks_And_Attendence("Flex/SRE.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 7){if(User_Registration_Verification_Data("RM") == true){Show_Marks_And_Attendence("Flex/RM.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 8){if(User_Registration_Verification_Data("BDA") == true){Show_Marks_And_Attendence("Flex/BDA.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 9){if(User_Registration_Verification_Data("AI") == true){Show_Marks_And_Attendence("Flex/AI.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 10){if(User_Registration_Verification_Data("DL") == true){Show_Marks_And_Attendence("Flex/DL.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 11){if(User_Registration_Verification_Data("DIP") == true){Show_Marks_And_Attendence("Flex/DIP.csv");}else{cout<<"Sorry! you are not register...\n";}}
else if(User_Option == 12){break;}


    }
}
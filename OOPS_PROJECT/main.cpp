#include <iostream>
#include <fstream>
#include <string>
#include"E_Student.cpp"
#include"G_Teacher.cpp"
using namespace std;
int main()
{
    
    STUD S1;
    TEACH T1;
    T1.Teacher_Data();
    S1.Registration_Data();
    //S1.Display_All_Institute_Registration_Data();
    int User_Option;
    string ID;
    string Password;
    bool Pass_And_ID_Verification = false;
cout<<"*******************************************************************\n";
cout<<"*                            WellCome!                            *\n";
cout<<"*******************************************************************\n";
for(int i=0;i<100;i++)
{
//***************************** taking user option *****************************************************

cout<<"*******************************************************************\n";
cout<<"* PRESS 1 if you are student                                      *\n";
cout<<"* PRESS 2 if you are a teacher                                    *\n";
cout<<"* PRESS 3 if you want to quit                                     *\n";
cout<<"*******************************************************************\n";
cout<<" PRESS : ";cin>>User_Option;
//***********************************************************************************************************

// first emai id will be verified if email id is verified then the student
// can enter the password
    if(User_Option == 1)
{
    bool flag = false;
    cout<<"Enter your NU email ID : ";cin>>ID;
    if(S1.User_Entered_ID_Verification(ID) == true){flag = true;}
    else if(S1.User_Entered_ID_Verification(ID) == false)
    {
        for(int i=0;i<3;i++)
        {
            cout<<"The Email ID you entered does not matches \nso, if you want to enter email ID again then press 1 if then press 2 ";cin>>User_Option;
            if(User_Option == 2){break;flag = false;}
            else if(User_Option == 1){cout<<"Enter your Email ID again = ";cin>>ID;if(S1.User_Entered_ID_Verification(ID) == true){flag = true;break;}}
            if(i == 2){cout<<"Sorry! you can not try more then three times go back to main menu...\n\n";}
        }
    }

// when pasword will be verified then the programm will enter the student to the
// corresponding class
    if(flag == true)
    {   
        cout<<"Enter password : ";
        
        cin>>Password;
        if(S1.User_Entered_Password_Verification(Password) == true){Pass_And_ID_Verification = true;}
    else if(S1.User_Entered_Password_Verification(Password) == false)
    {
        for(int i=0;i<3;i++)
        {
            cout<<"The password you entered does not matches \nso, if you want to enter Password again then press 1 if then press 2 ";cin>>User_Option;
            if(User_Option == 2){break;Pass_And_ID_Verification = false;}
            else if(User_Option == 1){cout<<"Enter your password Again = ";
            cin>>Password;
            if(S1.User_Entered_Password_Verification(Password) == true){Pass_And_ID_Verification = true;break;}}
            if(i == 2){cout<<"Sorry! you can not try more then three times go back to main menu...\n\n";}
        }
    }
    }
    //the student email id and password are verified 
    //so now we will enter the student to the management system 
    //the student can now check and do his quiz/assighment/tasks
    //and can check his marks and attendence of all subject to whom he is registered



    //*********************** MANAGEMENT SYSTEM **********************************************
if(Pass_And_ID_Verification == true)
{
    S1.Management_System_In_Student_Mode(); // going to student
}



}


//********************************** teacher mode **************************************************************
// first email id will be verified if email id is verified then the teacher
// can enter the password

else if(User_Option == 2)
{
    cout<<"Enter id : ";cin>>ID;
    if(T1.Verify_Teacher_Email_ID(ID) == true){Pass_And_ID_Verification = true;}
    else if(T1.Verify_Teacher_Email_ID(ID) == false)
    {
        for(int i=0;i<3;i++)
        {
            cout<<"The Email ID you entered does not matches \nso, if you want to enter email ID again then press 1 if then press 2 ";cin>>User_Option;
            if(User_Option == 2){break;Pass_And_ID_Verification = false;}
            else if(User_Option == 1){cin>>ID;if(T1.Verify_Teacher_Email_ID(ID) == true){Pass_And_ID_Verification = true;break;}}
            else if(i == 2){cout<<"Sorry! you can not try more then three times go back to main menu...\n";}
        }
    }

    // when pasword will be verified then the programm will enter the teacher to the
// corresponding class
    if(Pass_And_ID_Verification == true)
    {   
        cout<<"Enter password : ";cin>>Password;
        
        if(T1.Verify_Teacher_Password(Password) == true){Pass_And_ID_Verification = true;}
    else if(T1.Verify_Teacher_Password(Password) == false)
    {
        for(int i=0;i<3;i++)
        {
            cout<<"The Password you entered does not matches \nso, if you want to enter Password again then press 1 and if qiut then press 2 ";cin>>User_Option;
            if(User_Option == 2){break;Pass_And_ID_Verification = false;}
            else if(User_Option == 1){cin>>Password;if(T1.Verify_Teacher_Password(Password) == true){Pass_And_ID_Verification = true;break;}}
            else if(i == 2){cout<<"Sorry! you can not try more then three times go back to main menu...\n";}
        }
    }
    }
    //the teacher email id and password are verified 
    //so now we will enter the teacher to the management system 
    //the teacher can now check and do his quiz/assighment/tasks
    //and can check his marks and attendence of all subject to whom he is registered



    //*********************** MANAGEMENT SYSTEM **********************************************
if(Pass_And_ID_Verification == true)
{
    T1.Management_System_In_Teacher_Mode(); // going to teacher mode
}
}
else if(User_Option == 3){break;}
















}
    return 0;
}
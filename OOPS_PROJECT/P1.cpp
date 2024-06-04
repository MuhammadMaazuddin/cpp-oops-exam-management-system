//,,,
//Roll No,Student Name,Student ID,
#include<iostream>
#include<fstream>
#include"A_Student_Rigistration_Data.cpp"
using namespace std;
int main()
{
    STUD_RIGIST_DATA S1;
    S1.Registration_Data();
    string* M1 = new string[216];
    string* M2 = new string[216];
    string* M3 = new string[216];
    string* M4 = new string[216];
    string* M5 = new string[216];
    M1 = S1.GET_SR_Number();
    M2 = S1.Get_Student_Roll_No();
    M3 = S1.Get_Student_Name();
    M4 = S1.Get_Student_Email_Id();
    M5 = S1.Get_Object_Oriented_Programming_Registration_Data();
int num =0;
    for(int i=0;i<216;i++)
    {
        if(M5[i] == "1")
        {
            num++;
        }
    }
string Line[num];
int index;

for(int i=0;i<216;i++)
{



    if(M5[i] == "1")
    {
        Line[index] = M1[i]+"," + M2[i]+"," + M3[i] +","+ M4[i] + ",";index++;
    }
}
fstream file("Flex/OOPs.csv",ios::out);
int num2;
for(int i=0;i<num+2;i++)
{
    if(i == 0)
    {
        file<<" , , , ,"<<endl;
    }
    else if(i == 1)
    {
        file<<" ,Roll No,Student Name,Student ID,"<<endl;
    }
    else if(i >1)
    {
        file<<Line[num2]<<endl;num2++;
    }
}

    



}

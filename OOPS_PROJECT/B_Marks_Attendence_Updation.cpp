
#include<iostream>
#include<fstream>
#include"A_Student_Rigistration_Data.cpp"
using namespace std;
class MARKS_ATTEND: public STUD_RIGIST_DATA  
{
    private:
    int Student_Index;
    int Number_Of_Files;

    public:
        void Display_Marks_and_Attendence_Menue();
        void Classes();
        bool User_Registration_Verification_Data(string subject);
        void Set_Student_Index(int  data_Index);
        void Show_Marks_And_Attendence(string Class_Name);
        


};



void MARKS_ATTEND::Show_Marks_And_Attendence(string Class_Name)
{

    int SR = Get_Present_SR_Number();
    string line;
    string Show_Result;
    string Tasks_line;
    string Marks_line;
    string Check_SR;
    string Convert_SR;
    fstream file(Class_Name);
    int count =0;
    while(getline(file,line))
    {
        if(count==0){Tasks_line = line;}
        if(count == 1){Marks_line  = line;}
        bool flag = false;
        if(count>1)
        {
            for(int i=0;i<line.size();i++)
            {
                if(line[i] == ',')
                {
                    Check_SR = line.substr(0,i);
                    Convert_SR = to_string(SR);
                    if(Check_SR == Convert_SR)
                    {
                        Show_Result = line;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(flag == true)
        {
            break;
        }

        count++;
    }


int num__FILES;
int INDEX=0;
for(int i=0;i<Tasks_line.size();i++)
{
    if(Tasks_line[i] == ',')
    {
        INDEX++;
    }
}
INDEX-=4;
num__FILES = INDEX/3;
cout<<num__FILES<<endl;






int col1 =0, col2 = 0, col3 = 0;
for(int i=0;i<Show_Result.size();i++){col1 = 0;for (char c : line){if (c == ',') {col1++;}}}
for(int i=0;i<Tasks_line.size();i++){col2 = 0;for (char c : line){if (c == ',') {col2++;}}}
for(int i=0;i<Marks_line.size();i++){col3 = 0;for (char c : line){if (c == ',') {col3++;}}}
int newcol1=col1;
int newcol2=col2;
int newcol3=col3;
string line1[col1];
string line2[col2];
string line3[col3];
int index=0;
col1 = 0, col2 = 0, col3 = 0;
for(int i=0;i<Show_Result.size();i++)
{
    if(Show_Result[i] == ',')
    {
        col2=i;
        col3 = col2-col1;
        line1[index] = Show_Result.substr(col1, col3);
        col1 = i+1;
        index++;
    }
}
index=0;
col1 = 0, col2 = 0, col3 = 0;
for(int i=0;i<Tasks_line.size();i++)
{
    if(Tasks_line[i] == ',')
    {
        col2=i;
        col3 = col2-col1;
        line3[index] = Tasks_line.substr(col1, col3);
        col1 = i+1;
        index++;
    }
}
index=0;
col1 = 0, col2 = 0, col3 = 0;
for(int i=0;i<Marks_line.size();i++)
{
    if(Marks_line[i] == ',')
    {
        col2=i;
        col3 = col2-col1;
        line2[index] = Marks_line.substr(col1, col3);
        col1 = i+1;
        index++;
    }
}

int num1=4;
int num2=4;
int num3=4;



for(int i=0;i<num__FILES;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<line3[num1]<<"\t";

        num1++;
    }
    cout<<endl;
    cout<<"====================\n";

     for(int j=0;j<3;j++)
    {
        cout<<line2[num2]<<"\t";
        num2++;
    }
        cout<<endl;
        cout<<"--------------------------------\n";


     for(int j=0;j<3;j++)
    {
        cout<<line1[num3]<<"\t";
        num3++;
    }    cout<<endl;
    cout<<"--------------------------------\n";


}





}
void MARKS_ATTEND::Set_Student_Index(int data_Index)
{
    Student_Index = data_Index;
}
bool MARKS_ATTEND::User_Registration_Verification_Data(string subject)
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

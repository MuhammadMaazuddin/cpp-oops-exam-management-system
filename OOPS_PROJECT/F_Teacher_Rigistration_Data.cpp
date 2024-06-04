
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class TEACH_RIGIST
{
    private:
       string Teacher_Name[11];
       string Teacher_Email_Id[11];
       string Teacher_Password[11];
       string Teacher_Subject[11];
    public:
        string* Get_Teacher_Name();
        string* Get_Teacher_Email_ID();
        string* Get_Teacher_Password();
        string* Get_Teacher_Subject();
        void Teacher_Data();
        void Display_Teacher_Data();
};

string* TEACH_RIGIST::Get_Teacher_Name(){return Teacher_Name; }
string* TEACH_RIGIST::Get_Teacher_Email_ID(){return Teacher_Email_Id;}
string* TEACH_RIGIST::Get_Teacher_Password(){return Teacher_Password;}
string* TEACH_RIGIST::Get_Teacher_Subject(){return Teacher_Subject;}

void TEACH_RIGIST::Teacher_Data()
{
     string value1_str;
    int num_data = 0;  
    ifstream file("TEACH_DATA.csv");  
    string line;
    while (getline(file, line)) 
    {   
int num1=0,num2=0,num3=0;
for(num1;num1<line.size();num1++){if(line[num1]==','){value1_str = line.substr(0, num1);num2=num1;break;}}Teacher_Name[num_data]=value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}} Teacher_Email_Id[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}} Teacher_Password[num_data] = value1_str;
for(num1=num1+1;num1<line.size();num1++){if(line[num1]==','){num3=num1-num2;value1_str = line.substr(num2+1, num3-1);num2=num1;break;}} Teacher_Subject[num_data] = value1_str;


    num_data++;
}

}
void TEACH_RIGIST::Display_Teacher_Data()
{

    for(int i=0;i<11;i++)
    {
        cout<<Teacher_Name[i]<<"\t\t\t"<<Teacher_Email_Id[i]<<"\t\t\t"<<Teacher_Password[i]<<"\t\t\t"<<Teacher_Subject[i]<<endl;
    }
}
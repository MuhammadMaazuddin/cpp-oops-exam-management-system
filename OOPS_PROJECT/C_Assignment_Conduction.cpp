#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include"B_Marks_Attendence_Updation.cpp"
#include <chrono>
#include <thread>
using namespace this_thread;
using namespace chrono;
using namespace std;
class ASSIGNMENT_CONDUCTION: public MARKS_ATTEND
{
    private:
        int Student_Index_Data;
        int Number_Of_Qs;
        int Assighment_Time;
        string Marks_Attendence_File_Name;
    public:
        void Set_Marks_Attendence_File_Name(string name);
        void Set_Student_Index(int data_Index);
        void Solve_MCQs_Type_Assighment(string Assighment);
        void Solve_Fill_In_The_Blanks_Type_Assighment(string Assighment);
        void Solve_Q_And_A_s_Type_Assighment(string Assighment);
        void Solve_True_False_Type_Assighment(string Assighment);
        void Set_No_Of_Qs_In_Assighment(string Assighment);
        void Open_The_Corresonding_Assighment(string Assighment,string Marks_Attendence_File_Name);
        string Check_Assighment_Type(string File_Name);
        string Check_Assighment_Status(string CSV_File_Name, string Assighment);
        bool Check_file_Slot_In_CSV_File(string file_name, string Data_file_name);
        void Add_New_Col_Of_New_Assighment_File(string Assighment, string file_name);
        void Upload_Marks_And_Attendence(string Marks, string Attendence,string total_Marks, string Assighment);
        int Return_Number_Of_Student_In_A_Class(string CSV_File_Name);
        void Show_Submission_Time(string Class_name, string Assighment_Name,int flag);
        bool Check_Student_Submission_time(string Class_name, string Assighment_Name);
        int* Return_Submmision_Time_From_File(string Assighment_Name);
        bool Check_Live_And_Submission_Time(string Assighment_Name);
        void Set_Extracted_Time_From_File(string Assighment);


        


};
void ASSIGNMENT_CONDUCTION::Set_Extracted_Time_From_File(string Assighment)
{
    string value1_str;int num_data = 0;  ifstream file(Assighment);  int num1,num2,num3;string line;
    while (getline(file, line)) {if(num_data==3){for(int i=0;i<line.size();i++)
    {if(line[i] == ':'){num1=i;}else if(line[i] == ','){num2 = i;}}
    num3 = num2-num1;value1_str = line.substr(num1+1, num3-1);break;}
    num_data++;}int num = stoi(value1_str);Assighment_Time = num; 
}


int* ASSIGNMENT_CONDUCTION::Return_Submmision_Time_From_File(string Assighment_Name)
{
    fstream file(Assighment_Name);
    string line;int count=0,num=0,num1=0,num2=0,num3=0;string Date,time;
    string EMtime;string Month;while(getline(file,line))
    {if(count==2){for(num=0;num<line.size();num++){if(line[num] == ':'){num1=num;}else if(line[num] == ',')
    {num2 = num;break;}}num3 = num2-num1;Date = line.substr(num1+1, num3-1);num1=num2,num2=0,num3=0;
    for(num=0;num<line.size();num++){if(line[num] == '.'){num2=num;break;}}num3 = (num2-num1)-1;
    time =line.substr(num1+1, num3);break;}count++;}

    int* Extracted_Data= new int[5];
    string a,b,c,d,e;a=Date[0];b=Date[1];c=a+b;Extracted_Data[0] = stoi(c);
    a=Date[3];b=Date[4];c=a+b;Extracted_Data[1]=stoi(c);
    a=Date[6];b=Date[7];c=Date[8];d=Date[9];e=a+b+c+d;Extracted_Data[2]=stoi(e);
    a=time[0];b=time[1];c=a+b;Extracted_Data[3]=stoi(c);
    a=time[2];b=time[3];c=a+b;Extracted_Data[4]=stoi(c);

    return Extracted_Data;
}

void ASSIGNMENT_CONDUCTION::Show_Submission_Time(string Class_name, string Assighment_Name, int flag)
{
    string path="/";string File_name=Class_name+path+Assighment_Name;fstream file(File_name);
    string line;int count=0,num=0,num1=0,num2=0,num3=0;string Date,time;string* Extracted_Data= new string[5];
    string EMtime;string Month;while(getline(file,line))
    {if(count==2){for(num=0;num<line.size();num++){if(line[num] == ':'){num1=num;}else if(line[num] == ',')
    {num2 = num;break;}}num3 = num2-num1;Date = line.substr(num1+1, num3-1);num1=num2,num2=0,num3=0;
    for(num=0;num<line.size();num++){if(line[num] == '.'){num2=num;break;}}num3 = (num2-num1)-1;
    time =line.substr(num1+1, num3);break;}count++;}

    
    //setting Month
    string MH,f,g;f=Date[3];g=Date[4];MH=f+g;
    if(MH == "01"){Month="JANUARY";}else if(MH == "02"){Month="FEBRUARY";}else if(MH == "03"){Month="MARCH";}
    else if(MH == "04"){Month="APRIL";}else if(MH == "05"){Month="MAY";}else if(MH == "06"){Month="JUNE";}
    else if(MH == "07"){Month="JULY";}else if(MH == "08"){Month="August";}else if(MH == "09"){Month="SEPTEMBER";}
    else if(MH == "10"){Month="OCTOBER";}else if(MH == "11"){Month="NOVENBER";}else if(MH == "12"){Month="DECEMBER";}
    //logic
    if(flag == 1){
    string a,b,hr;a=time[0];b=time[1];hr=a+b;int HR=stoi(hr);
    string c,d,mn;c=time[2];d=time[3];mn=c+d;int MN=stoi(mn);
    if(HR>12 ){HR-=12;if(HR<10){hr=to_string(HR);a="0";hr=a+hr;EMtime = ".pm";}}else{EMtime = ".am";}
    cout<<"Due: "<<Date[0]<<Date[1]<<" "<<Month<<" "<<Date[6]<<Date[7]<<Date[8]<<Date[9]<<"  "<<hr<<":"<<mn<<EMtime<<"   "<<endl;}


    
  

    
}


int ASSIGNMENT_CONDUCTION::Return_Number_Of_Student_In_A_Class(string CSV_File_Name)
{
    string line1;int data=0;fstream file(CSV_File_Name);while (getline(file, line1)) {data++;}data-=1;
return data;
}

void ASSIGNMENT_CONDUCTION::Set_Marks_Attendence_File_Name(string name)
{
    Marks_Attendence_File_Name = name;
}

void ASSIGNMENT_CONDUCTION::Upload_Marks_And_Attendence(string Marks, string Attendence, string total_Marks,string Assighment)
{

    // removing path from file slot name
    int Index = 0;int Student_index=0;for(int i=0;i<Assighment.size();i++){if(Assighment[i] == '/'){Index = i+1;break;}}
    int count = 0;string newr[Assighment.size()-Index];for(int i=Index;i<Assighment.size();i++){newr[count] = Assighment[i];count++;}
    string dont_sleep;for(int i=0;i<Assighment.size()-Index;i++){dont_sleep +=newr[i];}
    //taking line from file that is of the corresponding student
    int num_cols ;int DATA=0;int DATA1=0;fstream fiLe(Marks_Attendence_File_Name);
    string line;string New_line;string edit_line;
    int SR = Get_Present_SR_Number();while (getline(fiLe, line)) {num_cols = 0;for (char c : line)
    {if (c == ',') {num_cols++;}}bool flag = false;for(int i=0;i<line.size();i++){if(line[i] == ',')
    {New_line = line.substr(0,i);string Alpha;Alpha= to_string(SR);if(New_line == Alpha)
    {edit_line = line;DATA=DATA1;Student_index=DATA1;flag = true;}  DATA1++;break;}}if(flag == true){break;}}
    string newR[num_cols];fstream file(Marks_Attendence_File_Name);
    string str;int luck=0;int index=0;int num1 = 0, num2 = 0, num3 = 0;
    while (getline(file, line)) {for(int i=0;i<line.size();i++){if(line[i] == ',')
    {num2 = i;num3 = num2-num1;str = line.substr(num1,num3);
    if(str == dont_sleep){index = luck;}luck++;num1=i+1;}}break;}int Data=0;num1 = 0, num2 = 0, num3 = 0;
    for(int i=0;i<edit_line.size();i++){if(edit_line[i] == ',')
    {num2 = i;num3 = num2-num1;str = edit_line.substr(num1,num3);newR[Data] = str;Data++;num1=i+1;}}
    Data=0;for(int i=0;i<edit_line.size();i++){if(edit_line[i] == ','){if(Data == index)
    {newR[index] = Attendence;newR[index+1] = Marks;newR[index+2] = total_Marks;}Data++;}}
    for(int i=0;i<num_cols;i++){newR[i]+=",";}string sleep;for(int i=0;i<num_cols;i++){sleep+=newR[i];}
    fstream File(Marks_Attendence_File_Name, ios::in);string temp_filename = "temp.csv";
    fstream temp_file(temp_filename, ios::out);string Line;int current_row = 0;int row=0;
    while (getline(File, Line)) {if(current_row == 0)
    {temp_file<<Line<<endl;}else if(current_row ==1){temp_file<<Line<<endl;}
    else if(current_row>1){if(current_row == Student_index){temp_file<<sleep<<endl;}
    else{temp_file<<Line<<endl;}row++;}current_row++;}File.close();temp_file.close();
    remove(Marks_Attendence_File_Name.c_str());rename(temp_filename.c_str(), Marks_Attendence_File_Name.c_str());
            





}




void ASSIGNMENT_CONDUCTION::Set_Student_Index(int data_Index)
{
    Student_Index_Data = data_Index;
}

void ASSIGNMENT_CONDUCTION::Add_New_Col_Of_New_Assighment_File(string Assighment,string file_name)
{
    
    string new_row1;string new_row2;fstream file(file_name);
    int index=0;int data=Return_Number_Of_Student_In_A_Class(file_name);int data_index=0;
    string new_row3[data];string line;while (getline(file, line)) {if(index>1){new_row3[data_index]=line;data_index++;}index++;}
    index=0;fstream fiLe(file_name);for(int i=0;i<data;i++){string add = "A,0,0,";new_row3[i] += add;}
    while (getline(fiLe, line)) {if(index == 0){new_row1 = line;}else if(index == 1){new_row2 = line;break;}index++;}
    new_row1 += Assighment;string new1 = "Attend,"; string new2 = "O_Marks,";string new3 = "T_Marks,";string new5 = new1+new2+new3;new_row2 += new5;

    data=0;fstream File(file_name, ios::in);string temp_filename = "temp.csv";
    fstream temp_file(temp_filename, ios::out);string Line;int current_row = 0;
    while (getline(File, Line)) {if (current_row == 0){temp_file<<new_row1<<endl;}else if(current_row == 1)
    {temp_file<<new_row2<<endl;}else if(current_row >1){temp_file<<new_row3[data]<<endl;data++;}else{temp_file<<Line<<endl;}current_row++;}
    File.close();temp_file.close();remove(file_name.c_str());rename(temp_filename.c_str(), file_name.c_str());
}

bool ASSIGNMENT_CONDUCTION::Check_file_Slot_In_CSV_File(string file_name,string Data_file_name)
{
    bool flag = false;string value1_str;int num_data = 0;  ifstream file(Data_file_name); 
     int num1=0,num2=0,num3=0;string line;int count = 0;while (getline(file, line)) 
    {int num_cols = 1;for (char c : line){if (c == ',') {num_cols++;}}string values[num_cols];
    int i = 0;size_t pos = 0;while ((pos = line.find(",")) != string::npos) {values[i] = line.substr(0, pos);
    line.erase(0, pos + 1);i++;}values[i] = line;for(int i=0;i<num_cols;i++){if(values[i] == file_name){flag = false;break;}else{flag = true;}}break;}
    return flag;
}

string ASSIGNMENT_CONDUCTION::Check_Assighment_Status(string CSV_File_Name, string Assighment)
{
    // removing path from file slot name
    int Index = 0;int Student_index=0;for(int i=0;i<Assighment.size();i++){if(Assighment[i] == '/'){Index = i+1;break;}}
    int count = 0;string newr[Assighment.size()-Index];for(int i=Index;i<Assighment.size();i++)
    {newr[count] = Assighment[i];count++;}string dont_sleep;for(int i=0;i<Assighment.size()-Index;i++){dont_sleep +=newr[i];}



    //taking line from file that is of the corresponding student
    int num_cols ;int DATA=0;int DATA1=0;fstream fiLe(CSV_File_Name);string line;string New_line;string edit_line;string Bool;
    int SR = Get_Present_SR_Number();while (getline(fiLe, line)) {num_cols = 0;for (char c : line){if (c == ',') {num_cols++;}}
    bool flag = false;for(int i=0;i<line.size();i++){if(line[i] == ','){New_line = line.substr(0,i);
    string Alpha;Alpha= to_string(SR);if(New_line == Alpha){edit_line = line;DATA=DATA1;Student_index=DATA1;flag = true;}DATA1++;break;}}
    if(flag == true){break;}}string newR[num_cols];fstream file(CSV_File_Name);string str;int luck=0;int index=0;int num1 = 0, num2 = 0, num3 = 0;



    // column of "Ass1.txt"
    while (getline(file, line)) {for(int i=0;i<line.size();i++){if(line[i] == ',')
    {num2 = i;num3 = num2-num1;str = line.substr(num1,num3);if(str == dont_sleep)
    {index = luck;}luck++;num1=i+1;}}break;}

    bool Flag=false;int Relax =0;fstream mental(CSV_File_Name);string LastApproch;int current_row=0;
    while(getline(mental,LastApproch)){if(current_row == Student_index)
    {for(int i=0;i<LastApproch.size();i++){if(LastApproch[i] == ','){if(Relax == index)
    {if(LastApproch[i-1] == 'P'){Bool= "P";}else if(LastApproch[i-2]=='P'){Bool="PL";}else if(LastApproch[i-1]=='A'){Bool="A";}}Relax++;}}}current_row++;}
  return Bool;         
}

string ASSIGNMENT_CONDUCTION::Check_Assighment_Type(string File_Name)
{
    string value1_str;int num_data = 0;ifstream file(File_Name);string line;
    while (getline(file, line)) {for(int i=0;i<line.size();i++)
    {if(line[i] == '.'){value1_str = line.substr(0,i+1);break;}}break;}
return value1_str;
}

void ASSIGNMENT_CONDUCTION::Open_The_Corresonding_Assighment(string Assighment,string Marks_Attendence_File_Name)
{
    Set_Marks_Attendence_File_Name(Marks_Attendence_File_Name);
    string Assighment_Type = Check_Assighment_Type(Assighment);
    cout<<Assighment_Type<<endl;cout<<Assighment<<endl;
    if(Assighment_Type == "Assighment type: MCQs."){Solve_MCQs_Type_Assighment(Assighment);}
    if(Assighment_Type == "Assighment type: Q/A's."){Solve_Q_And_A_s_Type_Assighment(Assighment);}
    if(Assighment_Type == "Assighment type: Fill in the blanks."){Solve_Fill_In_The_Blanks_Type_Assighment(Assighment);}
    if(Assighment_Type == "Assighment type: T/F's."){Solve_True_False_Type_Assighment(Assighment);}
}


void ASSIGNMENT_CONDUCTION::Set_No_Of_Qs_In_Assighment(string Assighment)
{

    string value1_str;int num_data = 0;  ifstream file(Assighment);  int num1,num2,num3;string line;
    while (getline(file, line)) {if(num_data==1){for(int i=0;i<line.size();i++)
    {if(line[i] == '='){num1=i;}else if(line[i] == '.'){num2 = i;}}
    num3 = num2-num1;value1_str = line.substr(num1+1, num3-1);break;}
    num_data++;}int num = stoi(value1_str);Number_Of_Qs = num; 


}

void ASSIGNMENT_CONDUCTION::Solve_MCQs_Type_Assighment(string Assighment)
{
Set_Extracted_Time_From_File(Assighment);
Set_No_Of_Qs_In_Assighment(Assighment);




    //storing questions and answers from file into string array
    string value1_str;int num_data = 0;  ifstream file(Assighment);  int num1=0;
    string line;string Test[Number_Of_Qs][6];  string MCQ[Number_Of_Qs*6];
    string Correct_Answer[Number_Of_Qs];while (getline(file, line)) 
    {if(num_data>3){MCQ[num1] = line;num1++;}num_data++;}int index = 0;for(int i=0;i<Number_Of_Qs;i++)
    {for(int j=0;j<6;j++){Test[i][j] = MCQ[index];index++;}}



    
    //setting up correct answres
    for(int i=0;i<Number_Of_Qs;i++){for(int j=0;j<6;j++){if(j==5){int num1 = 0, num2 =0, num3=0;
    string Line = Test[i][j];for(int i=0;i<Line.size();i++){if(Line[i] == ':'){num1=i;}else if(Line[i] == ','){num2 = i;}}
    num3 = num2-num1;Correct_Answer[i] = Line.substr(num1+1, num3-1);}}}

    //randomizing qusetions
    srand(time(0));for(int i = 0; i < Number_Of_Qs; i++){int randomIndex = rand() % Number_Of_Qs;
    swap_ranges(Test[i], Test[i] + 6, Test[randomIndex]);}for(int i = 0; i < Number_Of_Qs; i++)
    {for(int j = 1; j < 5; j++){int randomIndex = j + (rand() % (6 - 1 - j));swap(Test[i][j], Test[i][randomIndex]);}}




    //showing amd conducting test from the students
    for(int i=0;i<Number_Of_Qs;i++){for(int j=0;j<5;j++){cout<<Test[i][j]<<endl;}cout<<endl;}cout<<"\n\n";
int Time = Assighment_Time/60;
cout<<"*******************************************************************\n";
cout<<"* You have "<<Time<<":mins for The task \n";
cout<<"*******************************************************************\n";
    int option[Number_Of_Qs]={0};string User_Option;int Marks=0;
    seconds loopDuration(Assighment_Time);auto startTime = steady_clock::now();
    for(int i=0;i<Number_Of_Qs;i++)
    {int num4=0;bool flag = false;cout<<"Which Mcq do you want to do... So, enter the Mcq number = ";
    cin>>num4;auto currentTime = std::chrono::steady_clock::now();
    if (currentTime - startTime >= loopDuration) 
{
cout<<"*******************************************************************\n";
cout << " your quiz Time limit exceeded." << endl;
cout<<"*******************************************************************\n";
break;
}
    if(num4 == 555){break;}for(int j=0;j<Number_Of_Qs;j++)
    {if(num4 == option[j]){cout<<"You cannot do any of the mcq again...\n";flag = false;i--;break;}
    else{flag = true;}}if(flag == true){cout<<"Enter the CORRECT option = ";cin>>User_Option;
    if(Correct_Answer[num4-1]==User_Option){Marks++;}option[i]=num4;}}


    if(Check_Live_And_Submission_Time(Assighment)==true)
    {
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
//uploading marks of students
cout<<"\nObtained Marks : "<<Marks+1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";
    string Mark = to_string(Marks+1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"P",T_Mark,Assighment);
    }
    else if(Check_Live_And_Submission_Time(Assighment)==false)
    {
cout<<"*******************************************************************\n";
cout<<"* You have Submmited your task late so 2 marks will be deducted   *\n";
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
        //uploading marks of students
cout<<"\nObtained Marks : "<<Marks-1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";

    string Mark = to_string(Marks-1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"PL",T_Mark,Assighment);
    }
    
}
void ASSIGNMENT_CONDUCTION::Solve_Fill_In_The_Blanks_Type_Assighment(string Assighment)
{   Set_Extracted_Time_From_File(Assighment);
    Set_No_Of_Qs_In_Assighment(Assighment);
   
    //storing questions and answers from file into string array
    string value1_str;int num_data = 0;  ifstream file(Assighment);int num1=0;string line;
    string Test[Number_Of_Qs][4];  string MCQ[Number_Of_Qs*4];string Correct_Answer[Number_Of_Qs];
    while (getline(file, line)) {if(num_data>3){MCQ[num1] = line;num1++;}num_data++;}int index = 0;
    for(int i=0;i<Number_Of_Qs;i++){for(int j=0;j<4;j++){Test[i][j] = MCQ[index];index++;}}

    //setting up correct answres
    for(int i=0;i<Number_Of_Qs;i++){for(int j=0;j<4;j++){if(j==3)
    {int num1 = 0, num2 =0, num3=0;string Line = Test[i][j];
    for(int i=0;i<Line.size();i++){if(Line[i] == ':'){num1=i;}else if(Line[i] == ','){num2 = i;}}
    num3 = num2-num1;Correct_Answer[i] = Line.substr(num1+1, num3-1);}}}

    // randomizing correct answers
    srand(time(0));for(int i = 0; i < Number_Of_Qs; i++){int randomIndex = rand() % Number_Of_Qs;
    swap_ranges(Test[i], Test[i] + 4, Test[randomIndex]);}
    for(int i = 0; i < Number_Of_Qs; i++){for(int j = 1; j < 3; j++){int randomIndex = j + (rand() % (4 - 1 - j));
    swap(Test[i][j], Test[i][randomIndex]);}}

   


 
    //showing ans conducting test from students

    for(int i=0;i<Number_Of_Qs;i++){for(int j=0;j<3;j++){cout<<Test[i][j]<<endl;}cout<<endl;}cout<<"\n\n";
    int Time = Assighment_Time/60;
cout<<"*******************************************************************\n";
cout<<"* You have "<<Time<<":mins for The task \n";
cout<<"*******************************************************************\n";
    int option[Number_Of_Qs]={0};string User_Option;int Marks=0;
    std::chrono::seconds loopDuration(Assighment_Time);
    auto startTime = std::chrono::steady_clock::now();
    for(int i=0;i<Number_Of_Qs;i++){int num4=0;bool flag = false;
    cout<<"Which Mcq do you want to do... So, enter the Mcq number = ";cin>>num4;
    auto currentTime = std::chrono::steady_clock::now();
    if (currentTime - startTime >= loopDuration) {
cout<<"*******************************************************************\n";
cout << " your quiz Time limit exceeded." << endl;
cout<<"*******************************************************************\n";  
  break;}if(num4 == 555){break;}
    for(int j=0;j<Number_Of_Qs;j++){if(num4 == option[j]){cout<<"You cannot do any of the mcq again...\n";
    flag = false;i--;break;}else{flag = true;}}if(flag == true){cout<<"Enter the CORRECT option = ";
    cin>>User_Option;if(Correct_Answer[num4-1]==User_Option){Marks++;}option[i]=num4;}}

     if(Check_Live_And_Submission_Time(Assighment)==true)
    {
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
//uploading marks of students
cout<<"\nObtained Marks : "<<Marks+1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";
    string Mark = to_string(Marks+1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"P",T_Mark,Assighment);
    }
    else if(Check_Live_And_Submission_Time(Assighment)==false)
    {
cout<<"*******************************************************************\n";
cout<<"* You have Submmited your task late so 2 marks will be deducted   *\n";
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
        //uploading marks of students
cout<<"\nObtained Marks : "<<Marks-1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";

    string Mark = to_string(Marks-1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"PL",T_Mark,Assighment);
    }

    
}
void ASSIGNMENT_CONDUCTION::Solve_Q_And_A_s_Type_Assighment(string Assighment)
{
        Set_Extracted_Time_From_File(Assighment);
        Set_No_Of_Qs_In_Assighment(Assighment);


    //storing questions and answers from file into string array
    string value1_str;int num_data = 0;  ifstream file(Assighment);  int num1=0;
    string line;string Test[Number_Of_Qs];  string Student_Answer[Number_Of_Qs];
    while (getline(file, line)) {if(num_data>3){Test[num1] = line;num1++;}num_data++;}int index = 0;
    

    //conducting test from user
    int option[Number_Of_Qs]={0};for(int i=0;i<Number_Of_Qs;i++){cout<<Test[i]<<endl;}
int Time = Assighment_Time/60;
cout<<"*******************************************************************\n";
cout<<"* You have "<<Time<<":mins for The task \n";
cout<<"*******************************************************************\n";

    float Marks=0;std::chrono::seconds loopDuration(Assighment_Time);
    auto startTime = std::chrono::steady_clock::now();for(int i=0;i<Number_Of_Qs;i++)
    {int num4=0;bool flag = false;cout<<"Which Question do you want to answer : ";
    cin>>num4; auto currentTime = std::chrono::steady_clock::now();
    if (currentTime - startTime >= loopDuration) {
cout<<"*******************************************************************\n";
cout << " your quiz Time limit exceeded." << endl;
cout<<"*******************************************************************\n";       
 break;}
    if(num4 == 555){break;}for(int j=0;j<Number_Of_Qs;j++)
    {if(num4 == option[j]){cout<<"You cannot do any of the mcq again...\n";flag = false;i--;break;}
    else{flag = true;}}if(flag == true){option[i] = num4;cout<<"Write your answer  \n";cout<<"ANS: ";
    cin.ignore();getline(cin,Student_Answer[num4]);string Check_Marks = Student_Answer[num4];
    for(int i=0;i<Check_Marks.size();i++){if(Check_Marks[i] == ' '){Marks+=0.01;}}}}

     if(Check_Live_And_Submission_Time(Assighment)==true)
    {
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
//uploading marks of students
cout<<"\nObtained Marks : "<<Marks+1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";
    string Mark = to_string(Marks+1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"P",T_Mark,Assighment);
    }
    else if(Check_Live_And_Submission_Time(Assighment)==false)
    {
cout<<"*******************************************************************\n";
cout<<"* You have Submmited your task late so 2 marks will be deducted   *\n";
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
        //uploading marks of students
cout<<"\nObtained Marks : "<<Marks-1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";

    string Mark = to_string(Marks-1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"PL",T_Mark,Assighment);
    }

}



void ASSIGNMENT_CONDUCTION::Solve_True_False_Type_Assighment(string Assighment)
{
    Set_Extracted_Time_From_File(Assighment);

    Set_No_Of_Qs_In_Assighment(Assighment);

    //storing questions and answers from file into string array
    string value1_str;int num_data = 0;ifstream file(Assighment);  int num1=0;string line;
    string Test[Number_Of_Qs][4];  string MCQ[Number_Of_Qs*4];string Correct_Answer[Number_Of_Qs];
    while (getline(file, line)) {if(num_data>3){MCQ[num1] = line;num1++;}num_data++;}

    //showing questions to students
    int index = 0;for(int i=0;i<Number_Of_Qs;i++)
    {for(int j=0;j<4;j++){Test[i][j] = MCQ[index];index++;}}

    //setting up correct answres
    for(int i=0;i<Number_Of_Qs;i++){for(int j=0;j<4;j++){if(j==3){int num1 = 0, num2 =0, num3=0;
    string Line = Test[i][j];for(int i=0;i<Line.size();i++)
    {if(Line[i] == ':'){num1=i;}else if(Line[i] == ','){num2 = i;}}
    num3 = num2-num1;Correct_Answer[i] = Line.substr(num1+1, num3-1);}}}

    //randomizing correct answer
    srand(time(0));
    for(int i = 0; i < Number_Of_Qs; i++){int randomIndex = rand() % Number_Of_Qs;
    swap_ranges(Test[i], Test[i] + 4, Test[randomIndex]);}
    for(int i = 0; i < Number_Of_Qs; i++){for(int j = 1; j < 3; j++)
    {int randomIndex = j + (rand() % (4 - 1 - j));swap(Test[i][j], Test[i][randomIndex]);}}

   


int Time = Assighment_Time/60;
cout<<"*******************************************************************\n";
cout<<"* You have "<<Time<<":mins for The task \n";
cout<<"*******************************************************************\n";
    //conducting test from user

    for(int i=0;i<Number_Of_Qs;i++){for(int j=0;j<3;j++)
    {cout<<Test[i][j]<<endl;}cout<<endl;}cout<<"\n\n";
    int option[Number_Of_Qs]={0};string User_Option;int Marks=0;
    std::chrono::seconds loopDuration(Assighment_Time);auto startTime = std::chrono::steady_clock::now();
    for(int i=0;i<Number_Of_Qs;i++){int num4=0;bool flag = false;
    cout<<"Which Mcq do you want to do... So, enter the Mcq number = ";cin>>num4;
    auto currentTime = std::chrono::steady_clock::now();if(currentTime - startTime >= loopDuration) {
cout<<"*******************************************************************\n";
cout << " your quiz Time limit exceeded." << endl;
cout<<"*******************************************************************\n";    break;}if(num4 == 555){break;}
    for(int j=0;j<Number_Of_Qs;j++){if(num4 == option[j])
    {cout<<"You cannot do any of the mcq again...\n";flag = false;i--;break;}else{flag = true;}}
    if(flag == true){cout<<"Enter the CORRECT option = ";cin>>User_Option;
    if(Correct_Answer[num4-1]==User_Option){Marks++;}option[i]=num4;}
}
    if(Check_Live_And_Submission_Time(Assighment)==true)
    {
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
//uploading marks of students
cout<<"\nObtained Marks : "<<Marks+1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";
    string Mark = to_string(Marks+1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"P",T_Mark,Assighment);
    }
    else if(Check_Live_And_Submission_Time(Assighment)==false)
    {
cout<<"*******************************************************************\n";
cout<<"* You have Submmited your task late so 2 marks will be deducted   *\n";
cout<<"*******************************************************************\n";
cout<<"* Total number of Questions correct : "<<Marks<<endl;
        //uploading marks of students
cout<<"\nObtained Marks : "<<Marks-1<<"/"<<Number_Of_Qs<<"\nYour Marks will be uploaded soon on the flex\n\n";
cout<<"*******************************************************************\n";

    string Mark = to_string(Marks-1);string T_Mark = to_string(Number_Of_Qs);
    Upload_Marks_And_Attendence(Mark,"PL",T_Mark,Assighment);
    }

}
bool ASSIGNMENT_CONDUCTION::Check_Live_And_Submission_Time(string Assighment_Name)
{
        int*  Extracted_Data = new int[5];
        Extracted_Data = Return_Submmision_Time_From_File(Assighment_Name);
        time_t now = time(0);
        char* timeString = ctime(&now);
        string Date_Time_Now = timeString;

        string a,b,c,d,e;a=Date_Time_Now[4];b=Date_Time_Now[5];c=Date_Time_Now[6];
        string Month=a+b+c;a=Date_Time_Now[8];b=Date_Time_Now[9];
        string day = a+b;a=Date_Time_Now[20];b=Date_Time_Now[21];c=Date_Time_Now[22];d=Date_Time_Now[23];
        string year=a+b+c+d;a=Date_Time_Now[11];b=Date_Time_Now[12];
        string hours = a+b;a=Date_Time_Now[14];b=Date_Time_Now[15];
        string mins = a+b;

        int dy = stoi(day);int yr=stoi(year);int hr= stoi(hours);int mn=stoi(mins);int mon=0;
        if(Month=="Jan"){mon=1;}else if(Month=="Feb"){mon=2;}else if(Month=="Mar"){mon=3;}
        else if(Month=="Apr"){mon=4;}else if(Month=="May"){mon=5;}else if(Month=="Jun"){mon=6;}
        else if(Month=="Jul"){mon=7;}else if(Month=="Aug"){mon=8;}else if(Month=="Sep"){mon=9;}
        else if(Month=="Oct"){mon=10;}else if(Month=="Nov"){mon=11;}else if(Month=="Dec"){mon=12;}





        bool flag=false;
        bool flag1=false;
        if(Extracted_Data[2]>yr)
        {
        flag1=true;
        }
        else if(Extracted_Data[2]==yr)
        {
            flag=true;
            if(flag==true)
            {

                if(Extracted_Data[1]>mon)
                {
                    flag1=true;
                }
                else if(Extracted_Data[1]==mon)
                {
                    flag=true;
                    if(flag==true)
                    {

                        if(Extracted_Data[0]>dy)
                        {
                            flag1=true;
                        }
                        else if(Extracted_Data[0]==dy)
                        {
                            flag=true;
                            if(flag==true)
                            {

                                if(Extracted_Data[3]>hr)
                                {
                                    flag1=true;
                                }
                                else if(Extracted_Data[3]==hr)
                                {

                                    if(Extracted_Data[4]>mn)
                                    {
                                        flag1=true;
                                    }
                                   
                                }
                                
                            }
                        }
                    }
                }
            }
        }


return flag1;


}
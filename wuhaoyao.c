
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<iostream>
#include<cstring>
#include<sys/stat.h>
#include<dirent.h>
#include<queue>
#include<fcntl.h>
#include<stdlib.h>
using namespace std;


void mypwd(){
char ptr[100];
getcwd(ptr,sizeof(ptr));
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<ptr<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}


void mylist(){
DIR * dir;
struct dirent* ptr;
int count=0;
char *dirname;
cin>>dirname;
dir=opendir(dirname);
if(dir==NULL){
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<"can not open directory"<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
while((ptr=readdir(dir))!=NULL){
if(strcmp(ptr->d_name,".")==0||strcmp(ptr->d_name,"..")==0){}
else
cout<<ptr->d_name<<" ";
count++;
if(count%10==0)
cout<<endl;
}
closedir(dir);
cout<<endl;
}


void mycd(){
char dirname[20];
cin>>dirname;
if(chdir(dirname)==-1){
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<"the directory is not exit"<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
else{
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<"change directory success"<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
}

void mymkdir(){
char filename[20];
cin>>filename;
if(mkdir(filename,0777)==0){
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<filename<<" "<<"indecates successful"<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
else{
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<filename<<" "<<"indecates failure"<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
}



void myrmdir(){
char filename[20];
cin>>filename;
if(rmdir(filename)==0){
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<filename<<" "<<"delete successsful"<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
else{
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<filename<<" "<<"delete failure"<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
}

void myrename(){
char filename1[20],filename2[20];
cin>>filename1>>filename2;
if(rename(filename1,filename2)==0){
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<filename1<<" "<<"success change to"<<" "<<filename2<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
else{
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
cout<<filename1<<" "<<"failure change to "<<" "<<filename2<<endl;
cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
}
}



int main(int argc,char *argv[]){
cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
cout<<">>>>>Welcome cmd line>>>>>"<<endl;
cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;



string str;
while(str!="exit"){
cout<<"[wuhaoyao@]$";
cin>>str;
if(str=="pwd"){
mypwd();
}
if(str=="dir"){
mylist();
}
if(str=="cd"){
mycd();
}
if(str=="newdir"){
mymkdir();
}
if(str=="deldir"){
myrmdir();
}
if(str=="rename"){
myrename();
}
}
return 0;
}







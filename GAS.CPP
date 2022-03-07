#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
class gas_reg
{
char add[30];
int age;
long tel;
public:
long regno;
char name[20];

void read();
void writetofile();
void disp();
int readfromfile();
int search(long);
int modify(long);
void registration();
int deleterecord(long);

};
int gas_reg::deleterecord(long reg)
{
char choice;
ifstream fin("gas_reg",ios::in|ios::binary);
if(fin==NULL)
return 0;
ofstream fout("tempgas",ios::out);
fin.seekg(0);
int x=0;
while(fin.read((char*)this,sizeof(*this))!=NULL)
{
if(regno!=reg)
fout.write((char*)this,sizeof(*this));
else
{
clrscr();
cout<<"\n***************************************************************";
disp();
cout<<"\n***************************************************************";
cout<<"\nAre You Sure To Delete(Y/N)\t";
cin>>choice;
if(choice!='y'&&choice!='Y')
fout.write((char*)this,sizeof(*this));
else
{
x=1;
}//close of else
}//close of else
}//close of while
fin.close();
fout.close();
remove("gas_reg");
rename("tempgas","gas_reg");
if(x==0)
return 1;
else
return 2;


}

int gas_reg::modify(long reg)
{
char choice;
ifstream fin("gas_reg",ios::in|ios::binary);
if(fin==NULL)
return 0;
ofstream fout("tempgas",ios::out|ios::binary);
fin.seekg(0);
int x=0;
while(fin.read((char*)this,sizeof(*this))!=NULL)
{
if(regno!=reg)
fout.write((char*)this,sizeof(*this));
else
{
clrscr();
cout<<"\n***************************************************************";
disp();
cout<<"\n***************************************************************";
cout<<"\nAre You Sure To Modify(Y/N)\t";
cin>>choice;
if(choice!='y'&&choice!='Y')
fout.write((char*)this,sizeof(*this));
else
{
read();
x=1;
fout.write((char*)this,sizeof(*this));
}//close of else
}//close of else
}//close of while
fin.close();
fout.close();
remove("gas_reg");
rename("tempgas","gas_reg");
if(x==0)
return 1;
else
return 2;


}//close of modify function

void  gas_reg::registration()
{
ifstream fin("gas_reg",ios::in|ios::binary);
if(fin==NULL)
{
regno=1958;
}//close of if
else
{

fin.seekg(0);
int x=0;
int max;
while(fin.read((char*)this,sizeof(*this))!=NULL)
{
cout<<regno;
if(x==0)
max=regno;

if(max<regno)
max=regno;
x++;
}//close of while loop
fin.close();
regno=max+1;

}//close of else
}//close of registration

int gas_reg::search(long reg)
{
ifstream fin("gas_reg",ios::in|ios::binary);
if(fin==NULL)
return 0;
fin.seekg(0);
cout<<"\n***************************************************************";
while(fin.read((char*)this,sizeof(*this))!=NULL)
{
if(regno==reg)
disp();
}
cout<<"\n***************************************************************";
fin.close();
return 1;
}//close of search



void gas_reg::read()
{
cout<<"\nYour Registration No. is\t"<<regno;
cout<<"\nEnter the Name\t";
gets(name);
fflush(stdin);
cout<<"\nEnter the Age\t";
cin>>age;
cout<<"\nEnter the Telephone\t";
cin>>tel;
cout<<"\nEnter the Address\t";
gets(add);
fflush(stdin);

}//close of function
//writing data on to file
void gas_reg::writetofile()
{
ofstream fout("gas_reg",ios::app|ios::binary);
fout.write((char*)this,sizeof(*this));
fout.close();
}
//reading data from file
void gas_reg::disp()
{
cout<<"\nREG No:"<<regno<<"\t\t";
cout<<"Name:\t"<<name;
cout<<"\t\t\tAge:\t"<<age;
cout<<"\nAddress:\t"<<add;
cout<<"\tTel:\t"<<tel;
}
int gas_reg::readfromfile()
{
ifstream fin("gas_reg",ios::in|ios::binary);
if(fin==NULL)
return 0;
fin.seekg(0);
cout<<"\n***************************************************************";
while(fin.read((char*)this,sizeof(*this))!=NULL)
disp();
cout<<"\n***************************************************************";
fin.close();
return 1;
}//close of reading from file


// ---Closing of class GAS REGISTRATION ---
// --- start of menu for GAS REGISTRATION ---

int registration()
{
int ch;
long regno;
menu:
clrscr();
cout<<"\n\t\t****************************************************";
cout<<"\n\t\t\t\tGas Registration Menu";
cout<<"\n\t\t****************************************************";
cout<<"\n\t\t\t1.Registration\n\t\t\t2.View All\n\t\t\t3.View by REG NO.\n\t\t\t4.Modify Details\n\t\t\t5.Delete Record\n\t\t\t6.Previous Menu";
cout<<"\n\t\t****************************************************";

cout<<"\n\t\t\tEnter Your Choice\t";
cin>>ch;
gas_reg gr;
switch(ch)
{
case 1:
gr.registration();
gr.read();
gr.writetofile();
cout<<"\nThanks";
getch();
goto menu;
case 2:
clrscr();
int result=gr.readfromfile();
if(result==0)
cout<<"\nNo Records";
getch();
goto menu;
case 3:
cout<<"\nEnter the Registration No\t";
cin>>regno;
clrscr();
result =gr.search(regno);
if(result==0)
cout<<"\nNo Such Record";
getch();
goto menu;
case 4:
cout<<"\nEnter the REG No\t";
cin>>regno;
result=gr.modify(regno);
if(result==0)
cout<<"\nRecord Not Founded";
else if(result==1)
cout<<"\nRecord Not Modified";
else
cout<<"\nThanks for Modification";
getch();
goto menu;
case 5:
cout<<"\nEnter the REG No\t";
cin>>regno;
result=gr.deleterecord(regno);
if(result==0)
cout<<"\nRecord Not Founded";
else if(result==1)
cout<<"\nRecord Not Deleted";
else
cout<<"\nThanks for Deletion";
getch();
goto menu;


case 6:
return 0;
}
}

// ---CLOSE OF GAS REGISTRATION MENU AND ITS CLASS
// ---START OF BOOKING OF GAS
class booking
{
char name[20];
public:
long regno;
date bookingdate;
date deliverydate;
char status;
int  read();
void writetofile();
int readfromfile();
void disp();
int checkbooking(long);
int delivery();
};

int booking::delivery()
{
long reg;
char choice;
cout<<"\nEnter the Registration No\t";
cin>>reg;
ifstream fin("booking",ios::in|ios::binary);
if(fin==NULL)
return 0;
fin.seekg(0);
booking t;
//int found=0;
ofstream fout("tempbooking",ios::out|ios::binary);
while(fin.read((char*)&t,sizeof(t))!=NULL)
{
if(t.regno!=reg)
fout.write((char*)&t,sizeof(t));
else
{
disp();
cout<<"\nAre you sure to For this Delivery(Y/N)\t";
cin>>choice;
if(choice!='y'&&choice!='Y')
fout.write((char*)&t,sizeof(t));
else
{
t.status='y';
fout.write((char*)&t,sizeof(t));
}//close of else
}//close of else
}//close of while loop
fin.close();
fout.close();
remove("booking");
rename("tempbooking","booking");
return 1;
}//close of delivery

int  booking::checkbooking(long reg)
{
date tempdate;
ifstream fin("booking",ios::in|ios::binary);
if (fin==NULL)
return 1;
fin.seekg(0);
booking temp;
getdate(&tempdate);
while(fin.read((char*)&temp,sizeof(temp))!=NULL)
{
if(reg==temp.regno && tempdate.da_mon==temp.bookingdate.da_mon && tempdate.da_year==temp.bookingdate.da_year)
{
cout<<"\nBooking Date:"<<(int)temp.bookingdate.da_day<<"-"<<(int)temp.bookingdate.da_mon<<"-"<<(int)temp.bookingdate.da_year;
fin.close();
return 2;
}
fin.close();
return 1;
}//close of while loop
}//close of checkbooking function


int booking::read()
{
cout<<"\nEnter the Reg No:\t";
cin>>regno;
gas_reg g;
ifstream fin("gas_reg",ios::in|ios::binary);
if(fin==NULL)
return 0;
fin.seekg(0);
int found=0;
while(fin.read((char*)&g,sizeof(g))!=NULL)
{
if(g.regno==regno)
{
found=1;
strcpy(name,g.name);
}
}//close of while loop
fin.close();
if (found==0)
return 0;
booking t;
int result=t.checkbooking(regno);
if(result==2)
return 2;

getdate(&bookingdate);
cout<<"\nBooking Date";
cout<<"\t"<<(int)bookingdate.da_day<<"-"<<(int)bookingdate.da_mon<<"-"<<(int)bookingdate.da_year;
status='n';
return 1;
}//close of read for booking
void booking::writetofile()
{
ofstream fout("booking",ios::app|ios::binary);
fout.write((char*)this,sizeof(*this));
fout.close();
}//close of write function

void booking::disp()
{
cout<<"\nReg No:\t"<<regno;
cout<<"\tName:\t\t"<<name;
cout<<"\t\tBooking Date:"<<(int)bookingdate.da_day<<"-"<<(int)bookingdate.da_mon<<"-"<<(int)bookingdate.da_year;
cout<<"\n-------------------------------------------------------------------";
}//close of display function

int booking::readfromfile()
{
ifstream fin("booking",ios::in|ios::binary);
if(fin==NULL)
return 0;
fin.seekg(0);
clrscr();
cout<<"\n***************************************************************";
while(fin.read((char*)this,sizeof(*this))!=NULL)
{
if(status=='n')
disp();
}//close of while loop
cout<<"\n***************************************************************";
fin.close();
return 1;
}//close of reading from file

int  bookingmenu()
{
booking bk;
int choice;
bookmenu:
clrscr();
cout<<"\n\t\t**************************************************";
cout<<"\n\t\t\tBOOKING MENU";
cout<<"\n\t\t**************************************************";
cout<<"\n\t\t1.Booking of Gas\n\t\t2.View Bookings\n\t\t3.Delivery of Gas\n\t\t4.Previous Menu";
cout<<"\n\t\t**************************************************";
cout<<"\n\t\tEnter your choice\t";
cin>>choice;
switch(choice)
{
case 1:
int result=bk.read();
if (result==0)
cout<<"\nNo Such Registration";
else if (result==2)
cout<<"\nBooking Already been done...";
else
bk.writetofile();
getch();
goto bookmenu;

case 2:
result=bk.readfromfile();
if(result==0)
cout<<"\nNo Records";

getch();
goto bookmenu;

case 3:
result=bk.delivery();
if(result==0)
cout<<"\nNo Such Booking";
else
cout<<"\nThanks for Delivery";
getch();
goto bookmenu;

case 4:
return 0;
}
}
void firstscreen();
//close of booking class and its main menu
void main()
{
int choice;
firstscreen();

mainmenu:
clrscr();
cout<<"\n\t\t**************************************************";
cout<<"\n\t\t\tMAIN MENU";
cout<<"\n\t\t**************************************************";
cout<<"\n\t\t\t1.Registration\n\t\t\t2.Booking Menu\n\t\t\t3.Exit";
cout<<"\n\t\t**************************************************";
cout<<"\n\t\t\tEnter Your choice\t";
cin>>choice;
switch(choice)
{
case 1:
registration();
goto mainmenu;
case 2:
bookingmenu();
goto mainmenu;
case 3:
exit(0);
}
}


/*GRAPHICS FUNCTION */
void firstscreen()
{
int gm=DETECT;
initgraph(&gm,&gm,"c:\\TC\\BGI");
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
/*for(int i=0;i<=1000;i++)
putpixel(random(639),random(479),random(15)+1);
  */
ellipse(300,150,0,360,20,10);
line(280,150,280,200);
line(320,150,320,200);
fillellipse(300,200,40,20);
fillellipse(300,300,40,20);
line(260,200,260,300);
line(340,200,340,300);
floodfill(300,230,RED);

setcolor(YELLOW);
circle(50,50,50);
circle(30,30,5);
circle(70,30,5);
ellipse(50,70,180,0,10,5);

circle(550,50,50);
circle(530,30,5);
circle(570,30,5);
ellipse(550,70,180,0,10,5);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
setcolor(YELLOW);
sound(1345);
outtextxy(140,30,"GAS BOOKING & REGISTRATION");
sleep(3);
outtextxy(240,330,"Indane Gas");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(300,190,"I");
outtextxy(300,210,"N");
outtextxy(300,230,"D");
outtextxy(300,250,"A");
outtextxy(300,270,"N");
outtextxy(300,290,"E");
setcolor(GREEN);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(10,450,"Developed By Manpreet Singh Khokhar");
nosound();
getch();
closegraph();
}

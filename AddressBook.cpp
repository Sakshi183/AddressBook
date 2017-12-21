#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void welcome_screen();
void welcome_screen()
     {
	clrscr();
	gotoxy(20,10);
	cputs("**************** W E L C O M E  *********************** ");
	gotoxy(25,12);
	cputs("*** IIIT Vadodara *** " );
	gotoxy(20,14);
	cputs(" A D D R E S S  B O O K ");
	gotoxy(38,16);
	cputs(" M A D E  B Y :  ");
	gotoxy(50,18);
	cputs(" SAKSHI SHARMA ");
	gotoxy(50,20);
	cputs("");
      gotoxy(40,30);
	cputs(" *** PRESS ANY KEY TO CONTINUE***");
	getch();
     }
class directory
     {
       public:
	       int record;
	       long h;
	       char address1[50];
	       char address2[50];
	       char Name[25];
	       char emailadd[25];
	       char internetadd[25];
	       void modification();
	       void addition();
	       void deletae ();
	       void menu();
	       void search();
	       void view1();
	       void init();
	       void display();
	       void view();
	       char check(char *);
	       int test();
	    }obj;
void directory::addition()  //ADDING  INFORMATION
    {
      ofstream fout;
      fout.open("heera",ios::out|ios::app);
      init();
      fout.write((char*)&obj,sizeof(obj));
      fout.close();
    }
int directory::test()    //FIND NO. OF RECORDS
    {
      ifstream fin;
      fin.open("heera");
      fin.seekg(0,ios::end);
      int n;
      n=fin.tellg()/sizeof(obj);
      cout<<" \n NUMBER OF RECORDS = "<<n ;
      return n ;
    }
void directory::search()  //SEARCHING FOR A PARTICULAR NUMBER
    {
      ifstream fin;
      fin.open("heera");
      if(fin.fail())
	{
	  cout<<" \n FILE NOT FOUND ";
	  getch();
	  return;
	}
      clrscr();
      gotoxy(30,1);
      cprintf(" [SEARCHING] ");
      cout<<" \n ENTER HOUSE NUMBER TO BE SEARCHED: ";
      long z;
      cin>>z;
      int n;
      n=test();
      for(int i=0;i<n ;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  if(z==h)
	    {
	      view1();
	      return;
	    }
	}
      if(!fin.eof())
	{
	  cout<<" \n RECORD NOT FOUND ";
	  getch();
	}
    }
void directory::init()  // ENTERING THE DETAILS
    {

      clrscr();
      char ch;
      gotoxy(30,1);
      cprintf(" [ADDITION] ");
      char y;
      cin.get(y);
      cout<<" \n ENTER NAME : ";
      cin.getline(Name,25,'\n ');
      cout<<" \n ENTER HOUSE ADDRESS : ";
      cin.getline(address1,50,'\n');
      cout<<" \n ENTER OFFICE ADDRESS : ";
      cin.getline(address2,50,'\n');
      cout<<" \n ENTER EMAIL ADDRESS : ";
      cin.getline(emailadd,25,'\n');
      cout<<" \n ENTER INTERNET ADDRESS : ";
      cin.getline(internetadd,25,'\n');
      cout<<" \n ENTER HOUSE NUMBER : ";
      cin>>h;

      cout<<"\n RECORD HAS BEEN UPDATED";
      getch();
    }

void directory::view1() //TO DISPLAY ALL THE RECORDS
    {
      cout<<"\n";
      cout<<" HOUSE NUMBER : "<<obj.h<<"\n";
      cout<<" NAME : "<<obj.Name<<"\n";
      cout<<" HOUSE ADDRESS : "<<obj.address1<<"\n";
      cout<<" OFFICE ADDRESS : "<<obj.address2<<"\n";
      cout<<" EMAIL ADDRESS : "<<obj.emailadd<<"\n";
      cout<<" INTERNET ADDRESS : "<<obj.internetadd<<"\n";
      getch();
    }
void directory::modification()

   {
     clrscr();
     gotoxy(30,1);
     cprintf(" [ MODIFICATION ] ");
     long pn;
     int n,i;
     ifstream fin;
     ofstream fout;
     fin.open("heera");
     if(fin.fail())
       {
	 cout<<"\n FILE NOT FOUND !";
	 fout.close();
	 exit(-1);
       }
    fout.open("new");
    n=test();
    if(n==0)
      {
	cout<<"\n FILE IS EMPTY ! ";
	getch();
	return;
      }
   while(fin.good())
      {
	fin.read((char*)&obj,sizeof(obj));
	fout.write((char*)&obj,sizeof(obj));
      }
   fin.close();
   fout.close();
   fout.open("heera",ios::trunc);
   fin.open("new");
   if(fin.fail())
     {
      cout<<"\n FILE NOT FOUND !";
      exit(-1);
     }
   char ch;
   int z;
   cout<<"\n ENTER HOUSE NUMBER :";
   cin>>z;

   for(i=0;i<n;i++)
	{
	   fin.read((char*)&obj,sizeof(obj));
	   char d;
	   if(z==h)
	      {
		view1();
		d=check("HOUSE NUMBER ");
		if((d=='y') || (d=='Y'))
		  {
		    cout<<"\n ENTER NEW HOUSE NUMBER :";
		    cin>>h;
		  }

		if(check("NAME")=='y')
		  {
		    cout<<"\n ENTER NEW NAME : ";
		    cin.getline(Name,25,'\n');
		  }
		if(check("HOME ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW ADDRESS :";
		    cin.getline(address1,50,'\n');
		  }
		if(check("OFFICE ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW ADDRESS :";
		    cin.getline(address2,50,'\n');
		  }
		if(check("EMAIL ADDRESS:")=='y')
		  {
		    cout<<"\n ENTER NEW MAIL ADDRESS :";
		    cin.getline(emailadd,25,'\n');
		  }
		if(check("INTERNET ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW INTERNET ADDRESS";

		    cin.getline(internetadd,25,'\n');
		  }
	     cout<<"\n RECORD HAS BEEN MODIFIED";
	     getch();
	      }
	   fout.write((char*)&obj,sizeof(obj));
	}
   fout.close();
   fin.close();
    }
char  directory::check(char *s)
    {
       cout<<"\n MODIFY \t "<<s<<"\t"<<"Y/N";
       char ch;
      ch =getch();
      //cin.get(ch);
      if((ch=='y')||(ch=='Y'))
	return 'y';
       else
	return 'n';
    }
void  directory::deletae()
    {
       clrscr();
       window(1,1,80,25);
       gotoxy(30,1);
       cprintf("[DELETION]");
       long pn;
       int n,i;
       ifstream fin;
       ofstream fout;
       fin.open("heera");
       if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
       fout.open("new");
       n=test();
       if(n==0)
	{
	  cout<<"\n FILE IS EMPTY ! ";
	  getch();
	  return;
	}
      for(i=0;i<n;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  fout.write((char*)&obj,sizeof(obj));
	}
      fin.close();
      fout.close();
      fout.open("heera",ios::trunc);
      fin.open("new");
      if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
     int z;
     cout<<"\n ENTER HOUSE NUMBER TO BE DELETED:";
     cin>>z;
     int k=0;
     for(i=0;i<n ;i++)
       {
	 fin.read((char*)&obj,sizeof(obj));
	  if(z!=h)
	   { fout.write((char*)&obj,sizeof(obj));
	   k++;
	   }
       }
       if(k<n)
     cout<<"\n RECORD WITH HOUSE NUMBER "<<z<<" DELETED";
     else
     cout<<"Record not found";
     getch();
     fout.close();
     fin.close();

    }
 void directory::view()
   {
     ifstream fin;
     int n,j;
     fin.open("heera");
     if(fin.fail()||fin.bad())
       {
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
       }
     clrscr();
     int i=0;
     n=test();
     for(j=0;j<n;j++)
       {
	 cout<<"\n RECORD "<<i+1<<"\n";
	 fin.read((char*)&obj,sizeof(obj));
	 cout<<"\n HOUSE NUMBER :"<<obj.h<<"\n";
	 cout<<"\n NAME :"<<obj.Name<<"\n";
	 cout<<"\n HOUSE ADDRESS :"<<obj.address1<<"\n";
	 cout<<"\n OFFICE ADDRESS :"<<obj.address2<<"\n";
	 cout<<"\n INTERNET ADDRESS :"<<obj.internetadd<<"\n";
	 cout<<"\n EMAIL ADDRESS : "<<obj.emailadd<<"\n";
	 i+=1;
       }
      fin.close();
      getch();

   }

void  directory::menu()
    {
       char ch;
       clrscr();
       gotoxy(30,8);
       cprintf(" A:ADDITION ");
       gotoxy(30,9);
       cprintf(" D: DELETION \n  \r ");
       gotoxy(30,10);
       cprintf(" M:MODIFICATION \n \r ");
       gotoxy(30,11);
       cprintf(" V:VIEW \n \r ");
       gotoxy(30,12);
       cprintf(" S:SEARCH \n \r ");
       gotoxy(30,13);
       cprintf(" E:EXIT \n \r ");
       cout<<" ENTER A CHARACTER....(A,D,M,V,S)";
       cin>>ch;

      switch(ch)
	   {
	     case 'a':
	     case 'A':
		addition();
		break;
	     case 'd' :
	     case 'D' :
		deletae();
		break;
	     case 'm':
	     case 'M':
		modification();
		break;
	     case 'v':
	     case 'V':
		view();
		break;
	     case 's':
	     case 'S':
		search();
		break;
	     case 'e':
	     case 'E':
		system("cls");
		exit(0);
	 }
}
void main()
    {
      welcome_screen();
      for(;;)
      obj.menu();
   }


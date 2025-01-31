#include<iostream>
#include<conio.h>
#include<string.h>
#include<cctype>
#include<iomanip>
using namespace std;

int cart[30];    // Array for storing id's of ordered books
int record[30];  // Array for having record of names of books ordered to show in cart
char genre[20];  // String for storing ganre information
int limit;       // Variable for calculating values entered in cart & record variables

  // 2D strings for storing books name one in a row
char fiction_books[5][70] = {"To Kill a Mockingbird by Harper Lee","1984 by George Orwell","The Great Gatsby by F. Scott Fitzgerald","Beloved by Tony Morrison","Pride and Prejudice by  Jane Austen"};  // 2D string for fiction books
char fantacy_books[5][70] = {"The Name of the Wind by Patrick Rothfuss","The Hobbit by J.R.R. Tolkien","Mistborn: The Final Empire by Brandon Sanderson","The Lies of Locke Lamora by Scott Lynch","A Court of Thorns and Roses by Sarah J. Maas"};  // 2D string for fantacy books
char science_fiction_books[5][80] = {"Dune by Frank Herbert","Neuromancer by William Gibson","The Left Hand of Darkness by Ursula K Le Guin","Foundation by Isaac Asimov","Snow Crash by Neal Stephenson"};  // 2D string for science fiction books
char drama_books[5][70] = {"Hamlet by William Shakespeare","Death of a Salesman by Arthur Miller","A Streetcar Named Desire by Tennessee Williams","The Glass Menagerie by Tennessee Williams","Waiting for Godot by Samuel Beckett"};   // 2D string for drama books
char philosophy_books[5][70] = {"Meditations by Marcus Aurelius","The Republic by Plato","Being and Nothingness by Jean-Paul Sartre","Critique of Pure Reason by Immanuel Kant","The Incoherence of philosophers by Al Ghazali"};   // 2D string for philosophy books
char romance_books[5][70] = {"Pride and Prejudice by Jane Austen","The Fault in Our Stars by John Green","Outlander by Diana Gabaldon","Me Before You by Jojo Moyes","The Notebook by Nicholas Sparks"};   // 2D string for romance books

void menu(char genreinmenu[20])  // Function for showing available books in a genre
{
	system("cls");
	
	// If else for display of avaiable books in desired genre

	if (strcmp(genreinmenu,"FICTION") == 0)  // If fiction books are desired
	{
		cout<<"\n\tBooks available in fiction are : \n";
		cout<<"\n\tBook ID"<<setw(30)<<"Book Name";
		cout<<"\n\t_______________________________________________________________\n";
	for (int i=0 ; i<5 ; i++)  // Loop for displaying book names
	{
		cout<<"\n\t   "<<i<<setw(15);
		for (int j=0 ; fiction_books[i][j]!='\0' ; j++)
		{
			cout<<fiction_books[i][j];
		}
		cout<<endl;
	}
	}

	else if (strcmp(genreinmenu,"FANTACY") == 0)  // If fantacy books are desired
	{
		cout<<"\n\tBooks available in fantacy are : \n";
		cout<<"\n\tBook ID"<<setw(30)<<"Book Name";
		cout<<"\n\t_______________________________________________________________\n";
	for (int i=0 ; i<5 ; i++)  
	{
		cout<<"\n\t"<<i<<setw(15);
		for (int j=0 ; fantacy_books[i][j]!='\0' ; j++)
		{
			cout<<fantacy_books[i][j];
		}
		cout<<endl;
	}
	}

	else if ((strcmp(genreinmenu,"SCIENCE FICTION") == 0) || (strcmp(genreinmenu,"SCIENCEFICTION") == 0))  // If science fiction books are desired
	{
		cout<<"\n\tBooks available in science fiction are : \n";
		cout<<"\n\tBook ID"<<setw(30)<<"Book Name";
		cout<<"\n\t_______________________________________________________________\n";
	for (int i=0 ; i<5 ; i++)
	{
		cout<<"\n\t"<<i<<setw(15);
		for (int j=0 ; science_fiction_books[i][j]!='\0' ; j++)
		{
			cout<<science_fiction_books[i][j];
		}
		cout<<endl;
	}
	}

	else if (strcmp(genreinmenu,"DRAMA") == 0)  // If drama books are desired
	{
		cout<<"\n\tBooks available in drama are : \n";
		cout<<"\n\tBook ID"<<setw(30)<<"Book Name";
		cout<<"\n\t_______________________________________________________________\n";
	for (int i=0 ; i<5 ; i++)
	{
		cout<<"\n\t"<<i<<setw(15);
		for (int j=0 ; drama_books[i][j]!='\0' ; j++)
		{
			cout<<drama_books[i][j];
		}
		cout<<endl;
	}
	}

	else if (strcmp(genreinmenu,"PHILOSOPHY") == 0)  // If philosophy books are desired
	{
		cout<<"\n\tBooks available in philosophy are : \n";
		cout<<"\n\tBook ID"<<setw(30)<<"Book Name";
		cout<<"\n\t_______________________________________________________________\n";
	for (int i=0 ; i<5 ; i++)
	{
		cout<<"\n\t"<<i<<setw(15);
		for (int j=0 ; philosophy_books[i][j]!='\0' ; j++)
		{
			cout<<philosophy_books[i][j];
		}
		cout<<endl;
	}
	}

	else if (strcmp(genreinmenu,"ROMANCE") == 0)  // If romance books are desired
	{
		cout<<"\n\tBooks available in romance are : \n";
		cout<<"\n\tBook ID"<<setw(30)<<"Book Name";
		cout<<"\n\t_______________________________________________________________\n";
	for (int i=0 ; i<5 ; i++)
	{
		cout<<"\n\t"<<i<<setw(15);
		for (int j=0 ; romance_books[i][j]!='\0' ; j++)
		{
			cout<<romance_books[i][j];
		}
		cout<<endl;
	}
	}
}

void book_order_input()  // Function for getting book order
{
	char choice[10];  // Variable for getting choice of ordering more books
	for (int i=0 ; i>=0 ; i++)  // Loop for getting correct order information
	{
		cout<<"\n\n\tEnter ID of book you want to order : ";
		while (!(cin>>cart[i]))  // Loop for input validation
		{
			cout<<"\tInvalid entry do again!";
			cout<<"\n\n\tEnter ID of book you want to order : ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		if ((cart[i]<0) || (cart[i]>4))  // Condition for checking whether right book ID entered
		{
			cout<<"\tInvalid entry do again! ";
			i--;
		}
		else  // For asking whether user wants to order more books as inputed book ID is right
		{
			record[i] = cart[i];
			limit = i;
			
			for (int j=0 ; j>=0 ; j++)  // Loop for getting correct input for choice variable
			{
				cout<<"\n\n\tDo you want to order more books (yes/no) : "; 
				cin>>choice;
				for (int k=0 ; choice[k]!='\0' ; k++)  // Loop for converting each choice string character to uppercase
				{
					choice[k] = toupper (choice[k]);
				}
			if ((strcmp (choice,"YES") == 0) || (strcmp (choice,"NO") == 0)) // Condition if choice is right
			    break;  // Break to exit inner loop in case of right input in choice variable
			else
				cout<<"\tInvalid entry do again! ";
			}
			
			if (strcmp(choice,"NO") == 0)  // If user does not wants to order more books
			break;
		}
	}
}

void cart_display()  // Function for displaying cart
{
	system("cls");
	cout<<"\n\t\t\t******************* CART *******************\n";
	cout<<"\n\tBooks ordered by you : \n";
	cout<<"\n\tBook ID"<<setw(30)<<"Name";
	cout<<"\n\t___________________________________________________________________________________\n\n";
	
	if (strcmp(genre,"FICTION") == 0)  // Display of cart if genre was fiction
	{
		for (int i=0 ; i<=limit ; i++)  // Loop for indexing cart values and also rows of book names variables in form of record variable
		{
			cout<<"\t   "<<cart[i]<<setw(30);
			for (int j=0 ; j<70 ; j++)  // Loop for circulating throw all columns of single row in printing book name
			{
				cout<<fiction_books[record[i]][j];  // Will print each book name charachter by charachter
			}
			cout<<endl;
		}
	}
	
	else if (strcmp(genre,"FANTACY") == 0)  // Display of cart if genre was fantacy
	{
		for (int i=0 ; i<=limit ; i++)  // Loop for indexing cart values and also rows of book names variables in form of record variable
		{
			cout<<"\t   "<<cart[i]<<setw(30);
			for (int j=0 ; j<70 ; j++)  // Loop for circulating throw all columns of single row in printing book name
			{
				cout<<fantacy_books[record[i]][j];  // Will print each book name charachter by charachter
			}
			cout<<endl;
		}
	}
	
	else if ((strcmp(genre,"SCIENCE FICTION") == 0) || (strcmp(genre,"SCIENCEFICTION") == 0)) // Display of cart if genre was science fiction
	{
		for (int i=0 ; i<=limit ; i++)  // Loop for indexing cart values and also rows of book names variables in form of record variable
		{
			cout<<"\t   "<<cart[i]<<setw(30);
			for (int j=0 ; j<70 ; j++)  // Loop for circulating throw all columns of single row in printing book name
			{
				cout<<science_fiction_books[record[i]][j];  // Will print each book name charachter by charachter
			}
			cout<<endl;
		}
	}
	
	else if (strcmp(genre,"DRAMA") == 0)  // Display of cart if genre was drama
	{
		for (int i=0 ; i<=limit ; i++)  // Loop for indexing cart values and also rows of book names variables in form of record variable
		{
			cout<<"\t   "<<cart[i]<<setw(30);
			for (int j=0 ; j<70 ; j++)  // Loop for circulating throw all columns of single row in printing book name
			{
				cout<<drama_books[record[i]][j];  // Will print each book name charachter by charachter
			}
			cout<<endl;
		}
	}
	
	else if (strcmp(genre,"PHILOSOPHY") == 0)  // Display of cart if genre was philosophy
	{
		for (int i=0 ; i<=limit ; i++)  // Loop for indexing cart values and also rows of book names variables in form of record variable
		{
			cout<<"\t   "<<cart[i]<<setw(30);
			for (int j=0 ; j<70 ; j++)  // Loop for circulating throw all columns of single row in printing book name
			{
				cout<<philosophy_books[record[i]][j];  // Will print each book name charachter by charachter
			}
			cout<<endl;
		}
	}
	
	else if (strcmp(genre,"ROMANCE") == 0)  // Display of cart if genre was romance
	{
		for (int i=0 ; i<=limit ; i++)  // Loop for indexing cart values and also rows of book names variables in form of record variable
		{
			cout<<"\t   "<<cart[i]<<setw(30);
			for (int j=0 ; j<70 ; j++)  // Loop for circulating throw all columns of single row in printing book name
			{
				cout<<romance_books[record[i]][j];  // Will print each book name charachter by charachter
			}
			cout<<endl;
		}
	}
	cout<<"\n\t___________________________________________________________________________________\n";
}

int main ()
{
	char address[50],account[50],order_completion[10];  // Strings for storing delivery address,account number & order completion info
	cout<<"\n\t************************** Book Order Store **************************\n\n";
	cout<<"\tBooks from following generes are available : \n";
	cout<<"\t-> Fiction\n\t-> Fantacy\n\t-> Science Fiction\n\t-> Drama\n\t-> Philosophy\n\t-> Romance\n";
	for (int i=1 ; i>=1 ; i++)  // Loop for getting correct input about genre
	{

	cout<<"\n\n\tPlease select a genre of books : ";
    cin.get(genre,20);

	for (int j=0 ; genre[j]!='\0' ;j++)  // Loop for doing all the input genre characters to uppercase
	{
	genre[j] = toupper (genre[j]);
    }

    if ((strcmp (genre , "FICTION") == 0) || (strcmp (genre , "FANTACY") == 0) || (strcmp (genre , "SCIENCE FICTION") == 0) || (strcmp(genre,"SCIENCEFICTION") == 0) || (strcmp (genre , "DRAMA") == 0) || (strcmp (genre , "PHILOSOPHY") == 0) || (strcmp (genre , "ROMANCE") == 0))  // Long if condition for correct input and calling menu
    {
	menu(genre);
	book_order_input();
	cart_display();
	break;
    }

	else
	{
	cout<<"\tInvalid Input try again! ";
	cin.ignore();
	}
    }
    cout<<"\n\tEnter your delivery address : ";  // Getting address for delivering books
    cin>>address;cin.ignore(123,'\n');  // cin.ignore() for clearing buffer from garbage values entered i.e spaces in input
    cout<<"\n\tEnter account no. for payment : "; // Getting account no. for payment
    cin>>account;cin.ignore(123,'\n');  // cin.ignore() for clearing buffer from garbage values entered i.e spaces in input
    for (int j=0; j>=0 ; j++)  // Loop for completing order
    {
    	cout<<"\n\tComplete order (yes/no) : ";
    	cin>>order_completion;cin.ignore(123,'\n');  // cin.ignore() for clearing buffer from garbage values entered i.e spaces in input
    	for (int k=0 ; order_completion[k]!='\0' ; k++)  // Loop for turning all order completion characters uppercase
    	{
    		order_completion[k] = toupper (order_completion[k]);
		}
    	if (strcmp(order_completion,"YES") == 0)  // If user inputed yes to finish order
    	{
    		cout<<"\n\n\t------------------------: Books delivered. Thank you! for ordering :-------------------------\n\n\n\n\n";
    		break;
		}
		else if (strcmp(order_completion,"NO") == 0)  // If user entered no
		{
			cout<<"\tEnter yes to complete order";
			continue;
		}
		else 
		{
			cout<<"\tInvalid entry do again! ";
		}
	}    
}

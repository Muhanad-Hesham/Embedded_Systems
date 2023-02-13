/*
 * main.c
 *
 *  Created on: Jan 16, 2023
 *      Author: Muhand
 */

#include "linked_list.h"
/*
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define Dprintf(...)        fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);

//effective data
struct Sdata{
	int id;
	char name[40];
	float height;
};

//Node for Data and Pointer to the next node
struct Sstudent{
	struct Sdata student;
	struct Sstudent* Pnextstudent;
};


struct Sstudent* gpfirststudent = NULL;

void add_student()
{
	struct Sstudent* Pnewstudent;
	struct Sstudent* Plaststudent;
	char temp_text[40];

	//check if list is empty or no
	if(gpfirststudent == NULL)
	{
		//create new record
		Pnewstudent =(struct Sstudent*) malloc(sizeof(struct Sstudent));
		//assign it to gpfirststudent
		gpfirststudent = Pnewstudent;
	}
	else // list contain old records
	{
		Plaststudent = gpfirststudent;
		//will navigate till reach to the last record
		while(Plaststudent->Pnextstudent)
			Plaststudent = Plaststudent->Pnextstudent;
		//create new record
		Pnewstudent =(struct Sstudent*) malloc(sizeof(struct Sstudent));
		//assigning
		Plaststudent->Pnextstudent = Pnewstudent;
	}
	//fill new record
	Dprintf("\nEnter your ID: ");
	gets(temp_text);
	Pnewstudent->student.id = atoi(temp_text);
	Dprintf("\nEnter your Name: ");
	gets(Pnewstudent->student.name);
	Dprintf("\nEnter your Height: ");
	gets(temp_text);
	Pnewstudent->student.height = atof(temp_text);
	//set the next pointer of the new student to null
	Pnewstudent->Pnextstudent = NULL;
}

int delete_student()
{
	char temp_text[40];
	unsigned selected_id;
	struct Sstudent* Pselectedstudent;
	struct Sstudent* Ppreviousstudent;
	//get the selected id
	Dprintf("\nEnter student ID to be Deleted: ");
	gets(temp_text);
	selected_id = atoi(temp_text);
	//list is not empty
	if(gpfirststudent)
	{
		Ppreviousstudent = NULL;
		Pselectedstudent = gpfirststudent;
		//loop on all records to find the matched id
		while(Pselectedstudent) // pointer to the selected student is not equal null
		{
			//compare each node with the selected id
			if(Pselectedstudent->student.id == selected_id)
			{
				if(Ppreviousstudent) // if previous pointer is not points to null
				{
					Ppreviousstudent->Pnextstudent = Pselectedstudent->Pnextstudent;
				}
				else // first student match the selected id
				{
					gpfirststudent = Pselectedstudent->Pnextstudent;
				}
				free(Pselectedstudent);
				return 1 ;
			}
			Ppreviousstudent = Pselectedstudent;
			Pselectedstudent = Pselectedstudent->Pnextstudent;
		}
	}
	Dprintf("\nCan't find the selected ID");
	return 0;

}

void view_student()
{
	struct Sstudent* Pcurrentstudent;
	int count = 0;
	Pcurrentstudent = gpfirststudent;
	if(gpfirststudent == NULL)
	{
		Dprintf("\nEmpty list");
	}
	else
	{
		while(Pcurrentstudent)
		{
			Dprintf("\nRecord number (%d)", count+1);
			Dprintf("\n ID: %d ", Pcurrentstudent->student.id);
			Dprintf("\n Name: %s ", Pcurrentstudent->student.name);
			Dprintf("\n Height: %f ", Pcurrentstudent->student.height);
			Pcurrentstudent = Pcurrentstudent->Pnextstudent;
			count++;

		}
	}

}

void delete_all()
{
	struct Sstudent* Pcurrentstudent;
	Pcurrentstudent = gpfirststudent;
	if(gpfirststudent == NULL)
	{
		Dprintf("\nEmpty list");
	}
	else
	{
		while(Pcurrentstudent)
		{
			struct Sstudent* Ptempstudent = Pcurrentstudent;
			Pcurrentstudent = Pcurrentstudent->Pnextstudent;
			free(Ptempstudent);
		}
		gpfirststudent = NULL;
	}
}

int get_node(int index)
{
	struct Sstudent* Pcurrentstudent;
	int count = 1;
	if(gpfirststudent == NULL)
	{
		Dprintf("\nEmpty List");
	}
	else
	{
		Pcurrentstudent = gpfirststudent;
		while(Pcurrentstudent)
		{
			if(index == count)
			{
				Dprintf("\nThe wanted node to be shown is node number (%d):",index);
				Dprintf("\n ID: %d",Pcurrentstudent->student.id);
				Dprintf("\n Name: %s",Pcurrentstudent->student.name);
				Dprintf("\n ID: %f",Pcurrentstudent->student.height);
				return 1;
			}
			else
			{
				Pcurrentstudent = Pcurrentstudent->Pnextstudent;
				count++;
			}
		}
	}
	Dprintf("\nYour index dind't match any node");
	return 0;
}

int students_numbers_iterative()
{
	int count = 1;
	struct Sstudent* Pcurrentstudent;
	if(gpfirststudent == NULL)
	{
		Dprintf("\nEmpty List");
		return 0;
	}
	else
	{
		Pcurrentstudent = gpfirststudent;
		while(Pcurrentstudent->Pnextstudent)
		{
			count++;
			Pcurrentstudent = Pcurrentstudent->Pnextstudent;
		}

	}
	return count;
}

int students_numbers_recursive(struct Sstudent* gpfirststudent )
{
	struct Sstudent* Pcurrentstudent;
	Pcurrentstudent = gpfirststudent;
	if(gpfirststudent == NULL)
		return 0;
	else
		return (1 + (students_numbers_recursive(Pcurrentstudent->Pnextstudent)));

}

int get_node_from_end(int index)
{
	struct Sstudent* Pmainstudent;
	struct Sstudent* Prefstudent;
	int count = 0;
	if(gpfirststudent == NULL)
	{
		Dprintf("\nEmpty List");
	}
	else
	{
		Pmainstudent = gpfirststudent;
		Prefstudent = gpfirststudent;
		if(index)
		{
			while(index>count)
			{
				Prefstudent = Prefstudent->Pnextstudent;
				count++;
				if(Prefstudent == NULL && index == count)
				{
					Dprintf("\nThe wanted node from the end to be shown is node number (%d):",index);
					Dprintf("\n ID: %d",Pmainstudent->student.id);
					Dprintf("\n Name: %s",Pmainstudent->student.name);
					Dprintf("\n ID: %f",Pmainstudent->student.height);
					return 1;
				}
				else
				{
					Dprintf("\nYour index dind't match any node(out of scope)");
					return 0;

				}
			}
			while(Prefstudent)
			{
				Prefstudent = Prefstudent->Pnextstudent;
				Pmainstudent = Pmainstudent->Pnextstudent;
			}
			Dprintf("\nThe wanted node from the end to be shown is node number (%d):",index);
			Dprintf("\n ID: %d",Pmainstudent->student.id);
			Dprintf("\n Name: %s",Pmainstudent->student.name);
			Dprintf("\n ID: %f",Pmainstudent->student.height);
			return 1;
		}
		Dprintf("\nYour index dind't match any node");
		return 0;
	}
	Dprintf("\nYour index dind't match any node");
	return 0;
}

int middle_node()
{
	struct Sstudent* Pslowstudent;
	struct Sstudent* Pfaststudent;
	if(gpfirststudent == NULL)
	{
		Dprintf("\nEmpty List");
	}
	else
	{
		Pslowstudent = gpfirststudent;
		Pfaststudent = gpfirststudent;

		if(Pfaststudent->Pnextstudent)
		{
			Pfaststudent = Pfaststudent->Pnextstudent->Pnextstudent;
			if(Pfaststudent)
			{
				while(Pfaststudent)
				{
					Pslowstudent = Pslowstudent->Pnextstudent;
					Pfaststudent = Pfaststudent->Pnextstudent;
				}
				Dprintf("\nThe Middle Node is: ");
				Dprintf("\n ID: %d",Pslowstudent->student.id);
				Dprintf("\n Name: %s",Pslowstudent->student.name);
				Dprintf("\n ID: %f",Pslowstudent->student.height);
				return 1;

			}
			Pslowstudent = Pslowstudent->Pnextstudent;
			Dprintf("\nThe Middle Node is: ");
			Dprintf("\n ID: %d",Pslowstudent->student.id);
			Dprintf("\n Name: %s",Pslowstudent->student.name);
			Dprintf("\n ID: %f",Pslowstudent->student.height);
			return 1;
		}
	}
	Dprintf("\nNo Middle Node as there is only one node ");
	return 0;
}

void Reverse_records()
{
	struct Sstudent* Pcurrentstudent = gpfirststudent;
	struct Sstudent* Ppreviousstudent = NULL;
	struct Sstudent* Pnext = NULL;
	while(Pcurrentstudent)
	{
		Pnext = Pcurrentstudent->Pnextstudent;
		Pcurrentstudent->Pnextstudent = Ppreviousstudent;
		Ppreviousstudent = Pcurrentstudent;
		Pcurrentstudent = Pnext;
	}
	gpfirststudent = Ppreviousstudent;
	while(Ppreviousstudent)
	{
		Dprintf("\nThe Reversed records: ");
		Dprintf("\n ID: %d",Ppreviousstudent->student.id);
		Dprintf("\n Name: %s",Ppreviousstudent->student.name);
		Dprintf("\n ID: %f",Ppreviousstudent->student.height);
		Ppreviousstudent = Ppreviousstudent->Pnextstudent;
	}

} */
extern Sstudent_t* gpfirststudent;
int main()
{
	char temp[20];
	int choice;
	int num;
	while(1)
	{
		Dprintf("\n\nChoose one of the following:\n");
		Dprintf("\n1: Add Student");
		Dprintf("\n2: Delete Student");
		Dprintf("\n3: View Records");
		Dprintf("\n4: Delete All");
		Dprintf("\n5: Get Certain Node");
		Dprintf("\n6: Get Students Numbers by Iteration");
		Dprintf("\n7: Get Students Numbers by Recursion");
		Dprintf("\n8: Get Certain Node from the End");
		Dprintf("\n9: Get Middle Node");
		Dprintf("\n10: Reverse Records");
		Dprintf("\n11: Exit");
		Dprintf("\nEnter option number: ");
		gets(temp);
		choice = atoi(temp);
		switch(choice)
		{
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_student();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			Dprintf("\nEnter Node Number: ");
			scanf("%d",&num);
			get_node(num);
			break;
		case 6:
			num = students_numbers_iterative();
			Dprintf("\nNumber of students is: %d ",num);
			break;
		case 7:
			num = students_numbers_recursive(gpfirststudent);
			Dprintf("\nNumber of students is: %d ",num);
			break;
		case 8:
			Dprintf("\nEnter Node Number from the End: ");
			scanf("%d",&num);
			get_node_from_end(num);
			break;
		case 9:
			middle_node();
			break;
		case 10:
			Reverse_records();
			break;
		case 11:
			Dprintf("\nThank You");
			return 0;
			break;
		default:
			Dprintf("\nYour choice is not between choices");
			Dprintf("\nTry Again");
			break;

		}
	}
	return 0;
}



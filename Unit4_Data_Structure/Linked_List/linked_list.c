/*
 * linked_list.c
 *
 *  Created on: Feb 13, 2023
 *      Author: Muhand
 */

#include "linked_list.h"
Sstudent_t* gpfirststudent = NULL;
void add_student()
{
	Sstudent_t* Pnewstudent;
	Sstudent_t* Plaststudent;
	char temp_text[40];

	//check if list is empty or no
	if(gpfirststudent == NULL)
	{
		//create new record
		Pnewstudent =(Sstudent_t*) malloc(sizeof(Sstudent_t));
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
		Pnewstudent =(Sstudent_t*) malloc(sizeof(Sstudent_t));
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
	Sstudent_t* Pselectedstudent;
	Sstudent_t* Ppreviousstudent;
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
	Sstudent_t* Pcurrentstudent;
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
	Sstudent_t* Pcurrentstudent;
	Pcurrentstudent = gpfirststudent;
	if(gpfirststudent == NULL)
	{
		Dprintf("\nEmpty list");
	}
	else
	{
		while(Pcurrentstudent)
		{
			Sstudent_t* Ptempstudent = Pcurrentstudent;
			Pcurrentstudent = Pcurrentstudent->Pnextstudent;
			free(Ptempstudent);
		}
		gpfirststudent = NULL;
	}
}

int get_node(int index)
{
	Sstudent_t* Pcurrentstudent;
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
	Sstudent_t* Pcurrentstudent;
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

int students_numbers_recursive(Sstudent_t* gpfirststudent )
{
	Sstudent_t* Pcurrentstudent;
	Pcurrentstudent = gpfirststudent;
	if(gpfirststudent == NULL)
		return 0;
	else
		return (1 + (students_numbers_recursive(Pcurrentstudent->Pnextstudent)));

}

int get_node_from_end(int index)
{
	Sstudent_t* Pmainstudent;
	Sstudent_t* Prefstudent;
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
	Sstudent_t* Pslowstudent;
	Sstudent_t* Pfaststudent;
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
	Sstudent_t* Pcurrentstudent = gpfirststudent;
	Sstudent_t* Ppreviousstudent = NULL;
	Sstudent_t* Pnext = NULL;
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

}


/*
 * main.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Muhand
 */
#include "students.h"

void main()
{


	int temp;
	fifo_buf_t buffer_controller;  // that controls student buffer
	FIFO_INIT(&buffer_controller,buffer,100);

	DPRINTF("Welcome to the Student Management System\n");
	while(1)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Choose The Task that you want to perform\n\n");
		DPRINTF("1. Add the Student Details Manually\n");
		DPRINTF("2. Add the Student Details From Text File\n");
		DPRINTF("3. Find the Student Details by Roll Number\n");
		DPRINTF("4. Find the Student Details by First Name\n");
		DPRINTF("5. Find the Student Details by Course ID\n");
		DPRINTF("6. Find the Total number of Students\n");
		DPRINTF("7. Delete the Student Details by Roll Number \n");
		DPRINTF("8. Update the Student Details by Roll Number \n");
		DPRINTF("9. Show all information\n");
		DPRINTF(" Enter your choice to perform the task\n");
		scanf("%d",&temp);
		switch(temp)
		{
		case 1 :
		{
			Add_Student_Manually(&buffer_controller);
			break;
		}
		case 2 :
		{
			Add_Student_File(&buffer_controller);
			break;
		}
		case 3 :
		{
			Find_Using_Roll(&buffer_controller);
			break;
		}
		case 4 :
		{
			Find_Using_Fname(&buffer_controller);
			break;
		}
		case 5 :
		{
			Display_Using_cid(&buffer_controller);
			break;
		}
		case 6 :
		{
			Total_No_Students(&buffer_controller);
			break;
		}
		case 7 :
		{
			Delete_Student_by_roll(&buffer_controller);
			break;
		}
		case 8 :
		{
			Update_Student_by_roll(&buffer_controller);
			break;
		}
		case 9 :
		{
			Show_All_Info(&buffer_controller);
			break;
		}
		default :
		{
			DPRINTF("Wrong choice Try Again\n");

		}
		}

	}


}

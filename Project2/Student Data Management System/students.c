/*
 * students.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Muhand
 */
#include "students.h"

fifo_buff_status FIFO_INIT(fifo_buf_t* fifo,info_t* buf,unsigned int length)
{
	if(buf == NULL)
		return fifo_null;
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;
	fifo->length = length;
	return fifo_no_error;
}
check_t Check_Roll(fifo_buf_t* fifo,int roll)
{
	int i;
	info_t* ptr = fifo->base;
	for(i = 0; i < (fifo->count); i++)
	{
		if(ptr->roll == roll )
			return exist;
		ptr++;
	}
	return not_exist;
}
fifo_buff_status Add_Student_File(fifo_buf_t* fifo)
{
	char f_name[40], l_name[50];
	int roll_num,cid[5],i,file_count=0,flag=0;
	float GPA;
	int line = 0;
	//check if not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//check if fifo is full
	if(fifo->count == fifo->length)
	{
		DPRINTF("Database Is Full\n");
		return fifo_full;
	}
	FILE *p_file = fopen("text.txt","r");
	if(p_file==NULL)
	{
		DPRINTF("------------------------------ \n");
		DPRINTF("[ERROR] File not found \n");
		return fifo_error;
	}

	while(fscanf(p_file,"%d %s %s %f %d %d %d %d %d [^\n]", &roll_num, f_name,l_name,&GPA,&cid[0],&cid[1],&cid[2],&cid[3],&cid[4])!=EOF)
	{
		if(fifo->count == fifo->length)
		{
			DPRINTF("----------------------------\n");
			DPRINTF("[ERROR] Data Base is full\n");
			DPRINTF("[INFO] students added : %d\n",file_count);
			DPRINTF("[INFO] remaining students due to size or errors are :%d\n",line-file_count);
			return fifo_full;
		}
		if(Check_Roll(fifo,roll_num)==exist)
		{
			DPRINTF("[ERROR] IN line %d : Roll Number is already taken before \n",line);
			line++;
			continue;
		}
		fifo->head->roll = roll_num;
		fifo->head->gpa = GPA;
		strcpy(fifo->head->Fname,f_name);
		strcpy(fifo->head->Lname,l_name);
		for(i=0;i<5;i++)
		{
			flag=0;
			if(cid[i]<0 || cid[i]>30)
			{
				flag=1;
				break;
			}
			fifo->head->cid[i] = cid[i];
		}
		if(flag==1)
		{
			DPRINTF("[ERROR] IN line %d : non valid course id we will skip this student \n",line);
			line++;
			continue;
		}
		fifo->head++;
		fifo->count++;
		line++;
		file_count++;
	}
	DPRINTF("\nEnd of file.\n");

	fclose(p_file);
	DPRINTF("[INFO] students added : %d\n",file_count);
	DPRINTF("[INFO] remaining students due to errors are :%d\n",line-file_count);
	return fifo_no_error;


}
fifo_buff_status Add_Student_Manually(fifo_buf_t* fifo)
{
	char temp_str[40]; int temp_roll, i, temp_id;
	//check if not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//check if fifo is full
	if(fifo->count == fifo->length)
	{
		DPRINTF("Database Is Full\n");
		return fifo_full;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Add Student Details \n");
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Enter the Roll Number\n");
	gets(temp_str);
	temp_roll = atoi(temp_str);
	if(Check_Roll(fifo,temp_roll) == exist)
	{
		DPRINTF("[ERROR] Roll Number is already taken before \n");
		return fifo_error;
	}
	fifo->head->roll = temp_roll;
	DPRINTF("Enter First name of the student:\n");
	gets(fifo->head->Fname);
	DPRINTF("Enter Last name of the student:\n");
	gets(fifo->head->Lname);
	DPRINTF("Enter the GPA\n");
	gets(temp_str);
	fifo->head->gpa = atof(temp_str);
	DPRINTF("Enter the course id of each course\n");
	for(i=0;i<5;i++)
	{
		DPRINTF("course (%d) id :\n",i+1);
		gets(temp_str);
		temp_id = atoi(temp_str);
		if((temp_id>0) && (temp_id<30))
			fifo->head->cid[i] = temp_id;
		else
		{
			DPRINTF("Course id is not correct\n");
			i--;
		}


	}
	fifo->head++;
	fifo->count++;
	DPRINTF("[INFO] Student Details are added successfully \n");
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[INFO] The total number of students is : %d\n",fifo->count);
	DPRINTF("[INFO] You can add up to %d students \n",fifo->length);
	DPRINTF("[INFO] You can add more about %d students \n",(fifo->length - fifo->count));
	DPRINTF("--------------------------------------------\n");
	return fifo_no_error;

}
fifo_buff_status Find_Using_Roll(fifo_buf_t* fifo)
{
	char temp_str[40]; info_t* ptr = fifo->base;
	int i,j,temp_roll;
	//if fifo is not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//if fifo is empty
	if(fifo->count == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] database is empty \n");
		return fifo_empty;
	}
	DPRINTF("Enter student roll number:  \n");
	gets(temp_str);
	temp_roll = atoi(temp_str);
	for(i=0;i<fifo->count;i++)
	{
		if(ptr->roll == temp_roll)
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",ptr->roll);
			DPRINTF("Student first name : %s\n",ptr->Fname);
			DPRINTF("Student last name : %s\n",ptr->Lname);
			DPRINTF("Student GPA : %.2f\n",ptr->gpa);
			for(j=0;j<5;j++)
			{
				DPRINTF("course (%d) id : %d \n",j+1,ptr->cid[j]);
			}
			return fifo_no_error;
		}
		ptr++;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR] Roll number is not found\n");
	DPRINTF("--------------------------------------------\n");
	return fifo_error;

}
fifo_buff_status Find_Using_Fname(fifo_buf_t* fifo)
{
	char temp_str[40]; info_t* ptr = fifo->base;
	int i,j,flag=0;
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//if fifo is empty
	if(fifo->count == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] database is empty \n");
		return fifo_empty;
	}
	DPRINTF("Enter student first name:   \n");
	gets(temp_str);
	for(i=0;i<fifo->count;i++)
	{
		if(strcmpi(ptr->Fname,temp_str) ==0 )
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",ptr->roll);
			DPRINTF("Student first name : %s\n",ptr->Fname);
			DPRINTF("Student last name : %s\n",ptr->Lname);
			DPRINTF("Student GPA : %.2f\n",ptr->gpa);
			for(j=0;j<5;j++)
			{
				DPRINTF("course (%d) id : %d \n",j+1,ptr->cid[j]);
			}
			DPRINTF("--------------------------------------------\n");
			flag=1;
		}
		ptr++;
	}
	if(flag==0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] No Student has this First Name\n");                 // loop finished and roll not found
		DPRINTF("--------------------------------------------\n");
		return fifo_error;
	}
	return fifo_no_error;

}
fifo_buff_status Display_Using_cid(fifo_buf_t* fifo)
{
	char temp_str; int i,j,flag=0;
	int temp_cid;
	info_t* ptr = fifo->base;
	//if fifo is not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//if fifo is empty
	if(fifo->count == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] database is empty \n");
		return fifo_empty;
	}
	DPRINTF("Enter course id number  \n");
	gets(temp_str);
	temp_cid=atoi(temp_str);
	for(i=0;i<fifo->count;i++)
	{
		for(j=0;j<5;j++)
		{
			if(ptr->cid[j] == temp_cid)
			{
				DPRINTF("--------------------------------------------\n");
				DPRINTF("Student Roll number : %d\n",ptr->roll);
				DPRINTF("Student first name : %s\n",ptr->Fname);
				DPRINTF("Student last name : %s\n",ptr->Lname);
				DPRINTF("Student GPA : %.2f\n",ptr->gpa);
				for(j=0;j<5;j++)
				{
					DPRINTF("course (%d) id : %d \n",j+1,ptr->cid[j]);
				}
				DPRINTF("--------------------------------------------\n");
				flag=1;
			}
		}
		ptr++;
	}
	if(flag==0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] Entered Course ID Is Wrong  \n");
		DPRINTF("--------------------------------------------\n");
		return fifo_error;
	}
	return fifo_no_error;
}
fifo_buff_status Total_No_Students(fifo_buf_t* fifo)
{
	//if fifo is not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//if fifo is empty
	if(fifo->count == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] database is empty \n");
		return fifo_empty;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[INFO] the total number of students is : %d\n",fifo->count);
	DPRINTF("[INFO] you can add up to %d students \n",fifo->length);
	DPRINTF("[INFO] you can add more about %d students \n",(fifo->length - fifo->count));
	DPRINTF("--------------------------------------------\n");
	return fifo_no_error;

}
fifo_buff_status Delete_Student_by_roll(fifo_buf_t* fifo)
{
	char temp_str[40]; int i,j,temp_roll,index=0;
	info_t* ptr = fifo->base;
	//if fifo is not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//if fifo is empty
	if(fifo->count == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] database is empty \n");
		return fifo_empty;
	}
	DPRINTF("Enter student roll number  \n");
	gets(temp_str);
	temp_roll=atoi(temp_str);
	for(i=0;i<fifo->count;i++)
	{
		if(ptr->roll == temp_roll)
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",ptr->roll);
			DPRINTF("Student first name : %s\n",ptr->Fname);
			DPRINTF("Student last name : %s\n",ptr->Lname);
			DPRINTF("Student GPA : %.2f\n",ptr->gpa);
			for(j=0;j<5;j++)
			{
				DPRINTF("course (%d) id : %d \n",j+1,ptr->cid[j]);
			}
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Delete student If Yes Enter -> 1 If No Enter -> 0\n");
			DPRINTF("--------------------------------------------\n");
			gets(temp_str);
			temp_roll=atoi(temp_str);
			if(temp_roll == 1)
			{
				Shift_Buffer(index,fifo);
				fifo->head--;
				fifo->count--;
				return fifo_no_error;
			}
			else if(temp_roll == 0)
			{
				DPRINTF("--------------------------------------------\n");
				DPRINTF("--------Deleting canceled-------\n");
				return fifo_no_error;
			}
			else
			{
				DPRINTF("--------------------------------------------\n");
				DPRINTF("[ERROR] Wrong Choice ..\n");
				return fifo_error;
			}
		}
		ptr++;
		index++;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR] Roll number is not found\n");
	DPRINTF("--------------------------------------------\n");
	return fifo_error;
}
fifo_buff_status Shift_Buffer(int index,fifo_buf_t* fifo)
{
	int i;
	for(i=index;i<fifo->count;i++)
	{
		buffer[i] = buffer[i+1];
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Student Deleted Successfully\n");
	DPRINTF("--------------------------------------------\n");
	return fifo_no_error;

}
fifo_buff_status Update_Student_by_roll(fifo_buf_t* fifo)
{
	char temp_str[40];
	int i,j,k,temp_id,temp_roll;
	info_t* ptr = fifo->base;
	//if fifo is not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//if fifo is empty
	if(fifo->count == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] database is empty \n");
		return fifo_empty;
	}
	DPRINTF("Enter student roll number  \n");
	gets(temp_str);
	temp_roll=atoi(temp_str);
	for(i=0;i<fifo->count;i++)
	{
		if(ptr->roll == temp_roll)
		{
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",ptr->roll);
			DPRINTF("Student first name : %s\n",ptr->Fname);
			DPRINTF("Student last name : %s\n",ptr->Lname);
			DPRINTF("Student GPA : %.2f\n",ptr->gpa);
			for(j=0;j<5;j++)
			{
				DPRINTF("course (%d) id : %d \n",j+1,ptr->cid[j]);
			}
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Enter Number of Data You Want to Update\n");
			DPRINTF("1- First name\n");
			DPRINTF("2- Last name \n");
			DPRINTF("3- GPA\n");
			DPRINTF("4- courses \n");
			DPRINTF("--------------------------------------------\n");
			gets(temp_str);
			temp_roll = atoi(temp_str);
			switch(temp_roll)
			{
			case 1:
				DPRINTF("Enter New first name\n");
				gets(ptr->Fname);
				break;
			case 2:
				DPRINTF("Enter New second name\n");
				gets(ptr->Lname);
				break;
			case 3:
				DPRINTF("Enter New GPA \n");
				gets(temp_str);
				ptr->gpa=atof(temp_str);
				break;
			case 4:
				DPRINTF("Enter the course id of each course\n");
				for(k=0;k<5;k++)
				{
					DPRINTF("course (%d) id :\n",i+1);
					gets(temp_str);
					temp_id = atoi(temp_str);
					if(temp_id>0 && temp_id<30)
					{
						ptr->cid[k]=j;
					}
					else
					{
						DPRINTF("[ERROR] course id is not correct\n");
						k--;
					}
				}
				break;
			default:
				DPRINTF("[ERROR] Wrong Choice \n");
				return fifo_error;
			}
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Information Updated Successfully \n");
			DPRINTF("Student Information After Update \n");
			DPRINTF("--------------------------------------------\n");
			DPRINTF("Student Roll number : %d\n",ptr->roll);
			DPRINTF("Student first name : %s\n",ptr->Fname);
			DPRINTF("Student last name : %s\n",ptr->Lname);
			DPRINTF("Student GPA : %.2f\n",ptr->gpa);
			for(j=0;j<5;j++)
			{
				DPRINTF("course %d id : %d \n",j+1,ptr->cid[j]);
			}
			return fifo_no_error;
		}
		ptr++;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR] Roll number is not found\n");
	DPRINTF("--------------------------------------------\n");
	return fifo_error;

}
fifo_buff_status Show_All_Info(fifo_buf_t* fifo)
{
	info_t* ptr = fifo->base; int i,j;
	//if fifo is not exist
	if(!fifo->base || !fifo->head || !fifo->tail)
	{
		DPRINTF("Database Not Exist\n");
		return fifo_null;
	}
	//if fifo is empty
	if(fifo->count == 0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("[ERROR] database is empty \n");
		return fifo_empty;
	}
	for (i = 0;i<fifo->count;i++)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Student Roll number : %d\n",ptr->roll);
		DPRINTF("Student first name : %s\n",ptr->Fname);
		DPRINTF("Student last name : %s\n",ptr->Lname);
		DPRINTF("Student GPA : %.2f\n",ptr->gpa);
		for(j=0;j<5;j++)
		{
			DPRINTF("course (%d) id : %d \n",j+1,ptr->cid[j]);
		}
		ptr++;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("total number of students : %d\n",fifo->count);
	return fifo_no_error;
}


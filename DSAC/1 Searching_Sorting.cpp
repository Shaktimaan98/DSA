/*
Experiment no 1;
problem statement: Experiment no. 1
  *
Consider a student database of SEIT class (at least 15 records).
Database contains different fields of every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
Roll no:
Name:

*/
#include <iostream>
#include <stdlib.h>
#include<cstring>
using namespace std;
typedef struct SEIT_student_details{
	int roll;
	char name[10];
	float sgpa;
}stud;

void accept(stud s[], int n){
	int i;
	cout<<"\n Enter student details (roll, name, SGPA)";
	for(i=0;i<n;i++){
		cin>>s[i].roll>>s[i].name>>s[i].sgpa;
	}
}

void display(stud s[], int n){
	int i;
	cout<<"\n Sr.No \t Roll Number\t Name\t SGPA"<<endl;
	for(i=0; i<n; i++){
	cout<<"\n i="<<i<<"\t"<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].sgpa;
	}
}

void lSearch(stud s[], int n, float key){
	int i=0, flag = 0;
	while(i<n){
		if(key==s[i].sgpa){
			cout<<"\n Student found at location "<<i<<endl;
			cout<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].sgpa;
			flag = 1;
		}
		i++;
	}
	if(flag==0)
		cout<<"\nStudent not found";
}

void bubblesort_name(stud s[], int n){
	int i,j;
	stud temp;
	for(i=0; i<n-1;i++){
		for(j=0;j<n-1; j++){
			if(strcmp(s[j].name, s[j+1].name)>0){
				temp = s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
}

void bubblesort_roll(stud s[], int n){
int i, j;
stud temp;
for(i=0;i<n-1;i++){
	for(j=0; j<n-1; j++){
		if(s[j].roll > s[j+1].roll){
			temp = s[j];
			s[j] = s[j+1];
			s[j+1] = temp;
		}
	}
}

}

void insertionsort(stud s[], int n){
	int i,j;
	stud temp;
	for(i=1; i<n; i++){
		temp=s[i];
		for(j=i-1; j>=0&&strcmp(temp.name, s[j].name)<0; j--){
			s[j+1]=s[j];
		}
		s[j+1]=temp;
	}
	cout<<"\n after sorting name, the deatil as followes";
	display(s,n);
}

int partition(stud s[],int l, int h){
	int i, j;
	stud temp, pvt;
	pvt = s[l];
	i=l+1;
	j=h;
	while(i<j){
		while(s[i].sgpa <=pvt.sgpa){
			i++;
			while(s[j].sgpa>pvt.sgpa){
			j--;
				if(i<j){
					temp = s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
		}
		
	}
	s[l]=s[j];
	s[j]=pvt;
	return j;

}

void quick_sort(stud a[], int l, int h){
	int j;
	if(l<h){
		j=partition(a,l,h);
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,h);
	}
}

void quick_display(stud s[], int n, int t){
	int i;
	int cnt=1;
	for(i=n;cnt<=t;i--){
		cout<<"\n i="<<i<<"\t"<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].sgpa;
		cnt++;
	}

}

int bsearch_name(stud s[], int n, char key1[]){
	int l=0, h= n-1, m = 0;
	while(l<=h){
		m=(l+h)/2;
		if(strcmp(s[m].name, key1)==0)
			return m;
		else if(strcmp(s[m].name, key1)>0)
			h=m-1;
		else
			l=m+1;
		}
	return -1;
}



int main(){
	int ch,n,r;
	char key1[20];
	float key_sgpa;
	stud s[10];
	cout<<"\n Enter no of students";
	cin>>n;
	accept(s,n);
	cout<<"\n Entered student details";
	while(1){
	cout<<"\n ___MENU___";
	cout<<"\n 1.Linear Search for SGPA\n 2.Binary search for name\n 3.Buble sort for roll no\n 4.Insertion sort for wrt name\n 5. Quick sort for toppers\n 6. Exit\n";
	cout<<"Enter the choice: ";
	cin>>ch;

	display(s,n);

	switch (ch){
		case 1:
	 		cout<<"\n Enter key (SGPA) to search";
			cin>>key_sgpa;
			lSearch(s,n,key_sgpa);
			break;
		case 2:
			cout<<"\n Enter key(NAME) to search";
			cin>>key1;
			bubblesort_name(s,n);
			r = bsearch_name(s,n,key1);
			if(r==-1)
				cout<<"\n key is not found"<<endl;
			else
				cout<<key1<<" found at location "<<r;
			break;
		case 3:
			bubblesort_roll(s,n);
			cout<<"\n After sorting the roll no, details are as below";
			display(s,n);
			break;
		case 4:
			insertionsort(s,n);
			/*
			OR 
				bubblesort_name(s,n);
				cout<<"\n After sorting, the details are as follows";
				display(s,n);
			*/
			break;
		case 5:
			quick_sort(s,0,n-1);
			cout<<"\n after sorting according to SGPA: Toppers";
			quick_display(s, n-1, 3);
			break;
			
		case 6:
			exit(0);
	
		}
	}
	

	return 0;
}

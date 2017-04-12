#include "Student.h"
#ifndef LIST_H
#define LIST_H 


class List
{
public:
	List();//default constructor
	~List();//destructor
	List(const List& l);//copy constructor
	bool empty() const;//judge if the list is empty
	bool full() const;//judege if the list is full
	int size() const;//get the current length of the list
	bool sorted() const;//judge if the list is sorted
	Student* getList();//return the data set

	void insert_sort();											 /*			     */
	void select_sort();											/*			    */ 			
	void shell_sort(); 										   /*			   */
	void quick_sort(int left, int right);					  /* sort methods */
	void merge_sort(Student *arr, int low, int high);		 /*			     */
	void bubble_sort();										/*			    */
	void heap_sort();									   /*			   */

	bool binarySearch1(const int id, Student& get) const;//forgetful interactive version									/*						 */
	bool binarySearch2(const int id, Student& get) const;//recognizable interactive version								   /*						*/
	bool binarySearch3(const int id, Student& get, int low, int high) const;//forgetful recursive version				  /* binary search versions*/
	bool binarySearch4(const int id, Student& get, int low, int high) const;//recognizable recursive version			 /*						  */

	bool add(const Student &stu);//add a student's info to the list
	List& append(const Student& stu);//add a student's info to the last positon of the data base
	bool erase(const int id);//delete a strudent's info from the list
	void modify(const int id);//modify a certain student's infomation
	bool unique(const int id) const;//judge if the given value has existed

	void operator =(const List& l);//assignment operator overloaded
	void output(ostream& os) const;//send the datas to the buffer
	friend ostream& operator <<(ostream& os, List& l);//print all the datas, operator overloaded
private:
	Student *info;//store the students' infomations
	int maxSize;//the max size of the list
	int length;//the current length of the list
	bool flag;//mark the list whether it is in order
protected:
	void merge(Student *arr, int low, int mid, int high);
	void heap(int current, int high);
};

ostream& operator <<(ostream& os, List& l);


#endif 
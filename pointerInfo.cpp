//////////////////////////////////////////////////////////////////////
// 						CSE241 Object Oriented Programming 			//
// Autor:İbrahim ÇETİNKAYA  			Date: Due Date>> October 13	//
// Student Number:121044072 								2014    //
//				HW02_121044072                                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////
/*################################################################*/
/* Includes                                                       */
/*################################################################*/
#include <iostream>
using namespace std;
class DayOfYear
{
public:
	int month;
	int day;
};
struct Person{
    char name[100];
    int age[100];
};


/*----------------------------------------------------------------*/
/* Function Implementations										  */
int comparatorInt (const void *elem1, const void *elem2);

int comparatorDouble(const void *elem1, const void *elem2);

int comparatorChar(const void *elem1, const void *elem2);

void *return_nth(const void *base,
                       size_t num,
                       size_t size,
                       int nth,
                       int (*comparator)(const void *elem1, const void *elem2));
int comparatorStruct(const void * elem1, const void * elem2);
/*-------------------------------------------------------------------
* Return-nth
* -----------
* This function that returns a pointer to the nth element of a given array.
*
* Parameters
* -----------
* base
*   Pointer to the base of the array where the search is performed.
* num
*   Number of elements in the array pointed by base.
* size
*   Width of each element in the array, like sizeof(int), sizeof(DayOfYear) etc.
* nth
*   Nth element on the array.
* Comparator function
*   Function that compares two elements. This should be provided by the caller to
*   this function and must follow or be casted to a declaration like:
*
*       int comparator (const void * elem1, const void * elem2 );
*
* Return Value
* ----------
* A pointer to a nth element in the array.
* If nth is not out of range, a NULL pointer is returned.
* */

int main()
{
    char *charTest;
    int *intTest;
    double *doubleTest;
   	Person *personTest;
   	DayOfYear *classTest;
   	const int values_int[] = { 4,3,1,5};

	const char values_char[] = { "abcdefgh"};

	const double values_double[] = {2.0,3.0,1.0,5.0};

	const Person person[] = { {"Ali",18}, {"Veli", 40}, {"İbrahim",25} };


    /* Char test */
    charTest = (char*) return_nth(values_char, 8, sizeof(char), 2, comparatorChar);

    if(charTest == NULL)
        cerr << "[-]Error Occured: nth is out of range! " <<endl;
    else
        cout<< *charTest << " is in the array" << endl ;

    /* Integer test */
    intTest = (int*) return_nth(values_int, 4, sizeof(int), 2, comparatorInt);

    if(intTest == NULL)
       cerr << "[-]Error Occured: nth is out of range! " <<endl;
    else
        cout << *intTest << " is in the array "<<endl;

    /* Double test */
    doubleTest = (double*)return_nth(values_double,4, sizeof(double),1,comparatorDouble);

     if(doubleTest == NULL)
     	cerr << "[-]Error Occured: nth is out of range! " <<endl;
    else
        cout << *doubleTest << " is in the array "<<endl;

    personTest = (Person*)return_nth(person,3, sizeof(Person),1,comparatorStruct);
     if(personTest == NULL)
        cerr << "[-]Error Occured: nth is out of range! " <<endl;
    else
    	cout << person -> age << " is in the array "<<endl;
  
    return 0;
}
void *return_nth(const void *base,
                       size_t num,
                       size_t size,
                       int nth,
                       int (*comparator)(const void *elem1, const void *elem2))
{
    /* now i assume that the given array is sorted. */
    void *result;
    int indexArray[num];
    for (int index = 0; index < num; ++index)
    {

        indexArray[index] = index;
        cout << "indexArray[ "<< index <<"] -- > "<<indexArray[index]<< endl;
    }
    for (int i = 0; i < num ; ++i)
    {
       for (int j = i+1; j < num; ++j)
        {
            char* p1 = (char*)base;
            //printf("&p1[j*size]:%\n",&p1[j*size] );
            if ( comparator(   &p1[j*size] , &p1[i*size]) )
            {
                int temp = indexArray[i];

                indexArray[i] = indexArray[j];

                indexArray[j] = temp;
            }
        }
    }
    
    cout << "Sorted in indexArray "<< endl;
    for (int k = 0; k < num ; ++k)
    {
        cout << "indexArray[ "<< k <<"] -- > "<<indexArray[k]<< endl;
    }
    /* Out of range */
    if(nth > num)
        return NULL;

    result = (char*)base + (size * indexArray[nth]);

    return result;
}
int comparatorInt (const void *elem1, const void *elem2)
{
    return ( *(int*) elem1 < *(int*) elem2);
}
int comparatorDouble(const void *elem1, const void *elem2)
{
    return ( *(double*) elem1 < *(double*) elem2);
}
int comparatorChar(const void *elem1, const void *elem2){

    char *temp1 = (char*)elem1;
    char *temp2 = (char*)elem2;
     return (int)(*temp1) < (int)(*temp2);
}
int comparatorStruct(const void * elem1, const void * elem2)
{
    Person *x1 = (Person*)elem1;
    Person *x2 = (Person*)elem2;
    cout << (Person *)x1-> age   << "1.eleman \n";
    cout << (Person*)x2->age <<"2.eleman\n" ;
	if (   (((Person *)x1-> age ) - ((Person*)x2->age ))  > 0 )   
    	return -1;
    else if (  ((Person *)x1-> age)  < ((Person*)x2->age) )
    	return 1;
 

} 

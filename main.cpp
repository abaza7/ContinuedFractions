/*************************************************
Task No.: H2
Family Name: Abaza
First Name: Ahmed
Matriculation number: 3035482
Uni-Email: ahmed.abaza@stud.uni-due.de
Course of Studies: ISE CE
*************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

struct contFrac{                                    //Task1
    int realVal;
    struct contFrac *next;
};

contFrac *append(contFrac *formula, int realVal)    //Task2
{
    contFrac *newcontFrac = formula;
    while(formula->next != NULL)
    {
        formula = formula->next;
    }
    contFrac *newStruct = new contFrac;
    newStruct->realVal = realVal;
    newStruct->next = NULL;
    formula->next = newStruct;
    return newcontFrac;
}

void deleteAll(contFrac *&formula)                  //Task3
{
    contFrac *entf = new contFrac;
    while(formula != nullptr)
    {
        entf = formula;
        formula = formula->next;
        cout << entf->realVal << " ";
        delete entf;
    }
}

double newVal(contFrac *formula)
{
    if(formula->next == NULL)
    {
        return (double)formula->realVal;
    }
    else
    {
        return  formula->realVal + (1.0 / newVal(formula->next));
    }
}

contFrac *structcontFrac()
{
    int n, i = 2;
    contFrac *newptr = new contFrac;
    cout<<"Continued formula, enter first realVal f_0:";
    cin>>n;
    newptr->realVal = n;
    newptr->next = NULL;
    cout<<"Enter next part denominator f_1 (<= 0 for end):";
    cin>>n;
    while(n > 0)
    {
        newptr = append(newptr, n);
        cout<<"Enter next part denominator f_"<< i << " (<= 0 for end):";
        i++;
        cin>>n;
    }
    return newptr;
}

int main()
{
    contFrac *one = new contFrac;
    contFrac *two = new contFrac;
    contFrac *three = new contFrac;
    one->realVal = 1;
    one->next = NULL;
    one = append(append(append(append(one,4), 2), 1), 7);
	cout<<"cf1 = 123/100 = "<<newVal(one)<<endl;
    cout<<"Deleted: ";
    deleteAll(one);
    cout<< endl;

    two->realVal = 1;
    two->next = NULL;
    two = append(append(append(two, 1), 2), 3);
	cout<<"cf2 = 17/10 = "<<newVal(two)<<endl;
    cout<<"Deleted: ";
    deleteAll(two);
    cout<< endl;

    three = structcontFrac();
    cout <<fixed;
    cout <<setprecision(15);
    cout<<"Value inputted continued formula cf3 = "<<newVal(three)<<endl;
    cout<<"Deleted: " ;
    deleteAll(three);
    cout<< endl;
	return 0;
}

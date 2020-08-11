#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person
{
    private:
        vector<int> testScores;  
        
    public:
        /*    
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        Student(string fName, string lName, int id, vector<int> score) 
        : Person(fName, lName, id), testScores(score) {} // THIS IS CALLED INITIALIZER LIST

        /*    
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        char calculate()
        {
            int sum = 0;
            int avg = 0;

            for(int i = 0; i < testScores.size(); i++)
            {
                sum += testScores[i];
            }

            avg = sum / testScores.size();

            if(avg >= 90)
            {
                return 'O';
            }
            else if(avg >= 80)
            {
                return 'E';
            }
            else if(avg >= 70)
            {
                return 'A';
            }
            else if(avg >= 55)
            {
                return 'P';
            }
            else if(avg >= 40)
            {
                return 'D';
            }
            else
            {
                return 'T';
            }
        }
};

int main() {

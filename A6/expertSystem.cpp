#include<iostream>
#include<string>
#include<vector>
using namespace std;

string attributes[5] = {"Productivity" , "Problem Solving" , "TeamWork" , "Communication" , "Punctuality"};

float weights[5] = {0.4 , 0.3 , 0.15 , 0.10 , 0.05};

class Employee{
    private:

    string name;
    float rating[5];
    float finalScore;
    string performance;

    public:
    Employee(string name){
        this -> name = name;
    }

    void showRatings(){
        cout << "-----ScoreCard for Employee "<< this -> name <<" -----\n";
        for(int i = 0 ; i < 5 ; i ++){
            cout << "Ratings in "<<attributes[i]<<" : "<<this -> rating[i] <<"\n";
        }cout << "Final Score : " << this -> finalScore << endl;
        cout << "Performance: "<< this -> performance << endl;
    }

    void setRatings(){
        for(int i = 0 ; i < 5 ; i ++){
            cout << "Enter rating for " << attributes[i] << "(0 to 10)" << endl;
            cin >> this -> rating[i];
            if(this -> rating[i] < 0 || this -> rating[i] > 10){
                cout << "Invalid Rating Entered for "<<attributes[i] << " Marking it 0" << endl;
                this -> rating[i] = 0;
            }
            this -> finalScore += rating[i] * weights[i];
        }
        if(finalScore >= 9){
            this -> performance = "Excellent";
        }else if(finalScore < 9 && finalScore >= 8){
            this -> performance = "Very Good";
        }
        else if(finalScore < 8 && finalScore >= 7){
            this -> performance = "Good";
        }
        else if(finalScore < 7 && finalScore >= 6){
            this -> performance = "Average";
        }
        else{
            this -> performance = "Poor";
        }
    }

};
int main(){
    int n;
    vector<Employee*> employees; //Pointer to all the Employees

    cout << "Enter Number of Employees\n";
    cin >> n;
    string name;
    for(int i = 0 ; i < n ; i ++){
        cout << "Enter name of employee "<<i + 1 << endl;
        cin >> name;
        Employee* emp = new Employee(name);
        emp -> setRatings();
        employees.push_back(emp);
    }

    // Performance of all the employees
    for(int i = 0 ; i < n ; i ++){
        employees[i] -> showRatings();
    }


    return 0;
}

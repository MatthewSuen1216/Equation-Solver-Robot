//Matthew Suen Nov 10 2019
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

//Function to solve log equations
void logarithmSolver(ofstream &out,double a,double b,double k,double c){
	//Check if there is a solution, return solution if there is, return NS if not
	if (a!=0 && k!=0){
		out << "x = " << pow(b,(c/a))/k;
	} else{
		out << "NS";
	}
}

//Funciton to solve exponential equations
void exponentialSolver(ofstream &out,double a,double base,double k,double c){
	//Check if there is a solution, return solution if there is, return NS if not
	if (base > 0 && a != 0 && k != 0 && c * a > 0){
		out << "x = " << (log(c/a)/log(base))/k;
	}else {
		out << "NS";
	}
}

//Function to solve linear equations
void linearSolver(ofstream &out,double m,double b){
	//Check if there is a solution, return solution if there is, return NS if not
	if(m!=0){
		out << "x = "<< (-b)/m;
	} else {
		out << "NS";
	}
}

//Function to solve quadratic equations
void quadraticSolver(ofstream &out,double a, double b, double c){	
	//Find the discriminant
	double discriminant= b*b - 4*a*c;
	
	//If discriminant > 0 there are two solutions, use quadratic equaiton to solve for both and output
	if (discriminant>0){
		out<<"x1="<<((-b)+sqrt(discriminant))/(2*a)<<" ";
		out<<"x2="<<((-b)-sqrt(discriminant))/(2*a)<<" ";
	//If discriminant is 0, there is one solution which is -b/2a
	} else if (discriminant==0){
		out<<"x="<<((-b)/(2*a));
	//If discriminant < 0, there are two complex solutions, use quadratic equation to find the complex solution
	}else {
		out<<"x1="<<((-b)/(2*a))<<"+"<<sqrt(-discriminant)/(2*a)<<"i ";
		out<<"x2="<<((-b)/(2*a))<<"-"<<sqrt(-discriminant)/(2*a)<<"i ";
	}		
}
//Function to solve trigonometric equations
void trigSolver(ofstream & out,string type,double a,double k,double p, double c){
	
	//call arc fucntions according to trig type	
	if (type=="sin"){
		out<<"x="<<(asin(c/a)/k)+p;
	} else if (type=="cos"){
		out<<"x="<<(acos(c/a)/k)+p;
	} else if (type=="tan"){
		out<<"x="<<(atan2(c,a)/k)+p;
	}		
}

int main(){
	//Create solution.txt for output
	ofstream fout("solution.txt");
	//Variable indicating type of equation
	string type="";
	//Variable  keeping track whether type of equation entered is valid or not, true if valid false if not
	bool success=false;
	
	//While user has not input correct type, repeat
	while (!success){
		
		//Prompt user for equation type and record into type
		cout << "Enter if the equation is 'logarithm','exponential','linear','quadratic','trigonometric'" << endl;
		cin >> type;
		
		//For log equations
		if (type=="logarithm"){
			
			success=true;
			
			//create variables for equation
			double a = 0,b = 0,k = 0,c = 0;
			
			//Prompt user to input values
			cout << "Equation in the form of alogb(kx) = c" << endl;
			cout << "a: ";
			cin >> a;
			cout << "b: ";
			cin >> b;
			cout << "k: ";
			cin >> k;
			cout << "c: ";
			cin >> c;
			
			//call function to solve equation
			logarithmSolver(fout,a,b,k,c);
		//For Exponential equations
		}else if (type=="exponential"){
			
			success=true;
			//create variables for equation
			double b=0, a=0, k=0,c=0;
			//Prompt user for values
			cout << "Equation in the form of a*b^(kx) = c" << endl;
			cout << "a: ";
			cin >>a;
			cout <<"b: ";
			cin >>b;
			cout <<"k: ";
			cin >>k;
			cout <<"c: ";
			cin >>c;
			
			//call function to solve equation
			exponentialSolver(fout,a,b,k,c);
		//For linear equations
		}else if (type=="linear"){
			
			success=true;
			//Create variables for values
			double m=0,b=0;

			//Prompt user for values
			cout << "Equation in the form of mx + b = 0" << endl;
			cout<<"m: ";
			cin>>m;
			cout<<endl<<"b: ";
			cin>>b;
			//call funciton to solve equation
			linearSolver(fout,m,b);
		//For quadratic equations
		} else if (type=="quadratic"){
			
			success=true;
			//Create variables for values
			double a=0,b=0,c=0;
			
			//Prompt user for values
			cout << "Equation in the form of ax^2 + bx + c = 0" << endl;
			cout <<"a: ";
			cin >>a;
			cout <<"b: ";
			cin >>b;
			cout <<"c: ";
			cin >>c;
			
			//if equation is linear (a=0) call linear solver, if not then quadratic solver
			if (a==0){
				linearSolver(fout,b,c);
			}else {
				quadraticSolver(fout,a,b,c);
			}
		//For trigonometric equaitons
		}else if (type=="trigonometric"){
			
			success=true;
			//Prompt for trigonometric type sin/cos/tan
			string trigType="";
			cout<<"type: ";
			cin>>trigType;
			
			//Create variables for values
			double a=0,k=0,p=0, c=0;
			
			//prompt user for values
			cout << "Equations in the following forms asin(k(x-p))=c, acos(k(x-p))=c, or atan(k(x-p)=c"
			cout<<"a: ";
			cin>>a;
			cout<<endl<<"k: ";
			cin>>k;
			cout<<endl<<"p: ";
			cin>>p;
			cout<<endl<<"c: ";
			cin>>c;
			
			//call equation to solve
			trigSolver(fout,trigType,a,k,p,c);
		}
	}
	//Prompt user to transfer file
	cout<<"Transfer 'solution.txt' to robot";
	//close file
	fout.close();
	
	return 0;
	
}




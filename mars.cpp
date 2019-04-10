#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int lower_left_x_coordinate=0,lower_left_y_coordinate=0;    // since the lower-left coordinates of the plateau are assumed to be 0,0.

int upper_right_x_coordinate_plateau,upper_right_y_coordinate_plateau;            //upper-right coordinates of the plateau

class Rover{
private:
    int x_coordinate_;
    int y_coordinate_;
    char current_orientation_;

public :
    Rover();
    Rover( int , int , char );
    void RotateLeft();                       //function to rotate rover left
    void RotateRight();                      //function to rotate rover right
    bool IfValidMove(int, int);              //function to check if coordinates can be increased due to fixed size of plateau
    void MovePosition();                     //function to move the rover by 1 unit
    void DisplayPosition();                  //function to print the Position of Rover

};    

Rover :: Rover() : x_coordinate_(0), y_coordinate_(0), current_orientation_('N'){

}

Rover :: Rover ( int position_x , int position_y , char target_orientation ){
    x_coordinate_= position_x;
    y_coordinate_= position_y;
    current_orientation_ = target_orientation ;
}

void Rover::  DisplayPosition(){
    cout<<x_coordinate_<<" "<<y_coordinate_<<" "<<current_orientation_<<endl;
}

void Rover :: RotateLeft(){
    switch (current_orientation_) { 
        case 'N': current_orientation_ = 'W'; break;
        case 'W': current_orientation_ = 'S'; break;
        case 'S': current_orientation_ = 'E'; break;
        case 'E': current_orientation_ = 'N'; break;
    }
}

void Rover :: RotateRight()
{
    switch (current_orientation_) { 
        case 'N': current_orientation_ = 'E'; break;
        case 'W': current_orientation_ = 'N'; break;
        case 'S': current_orientation_ = 'W'; break;
        case 'E': current_orientation_ = 'S'; break;
    }
}

bool Rover :: IfValidMove(int x_coordinate_check,int y_coordinate_check){
    if(x_coordinate_check<=upper_right_x_coordinate_plateau && y_coordinate_check<=upper_right_y_coordinate_plateau && x_coordinate_check>=lower_left_x_coordinate && y_coordinate_check>=lower_left_y_coordinate)
        return true;
    return false;
}

void Rover ::MovePosition(){
    if(current_orientation_=='N' && IfValidMove(x_coordinate_,y_coordinate_+1))
        y_coordinate_++;
    else if(current_orientation_=='W' && IfValidMove(x_coordinate_-1,y_coordinate_))
        x_coordinate_--;
    else if(current_orientation_=='S' && IfValidMove(x_coordinate_,y_coordinate_-1))
        y_coordinate_--;
    else if(current_orientation_=='E' && IfValidMove(x_coordinate_+1,y_coordinate_))
        x_coordinate_++;   
}


int main()
{
    cin>>upper_right_x_coordinate_plateau>>upper_right_y_coordinate_plateau;
    while(1){
        int x_coordinate,y_coordinate; char current_orientation ;
        cin>>x_coordinate>>y_coordinate>>current_orientation;

        Rover firstRover(x_coordinate,y_coordinate,current_orientation);

        string rover_movement;
        cin>>rover_movement;

        for(int i=0; i < rover_movement.size(); i++  )
        {
            if(rover_movement[i]=='L')
                firstRover.RotateLeft();

            else if(rover_movement[i]=='R')
                firstRover.RotateRight();

            else if(rover_movement[i]=='M')
                firstRover.MovePosition();
            else{
                cout<<"invalid STRING! Try typing L R or M only"<<endl;
                return 0;
            }
        }
        firstRover.DisplayPosition();
    }
    return 0;  
}
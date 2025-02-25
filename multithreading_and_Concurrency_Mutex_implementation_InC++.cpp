// there are 3 drivers but a single car in this program but condition is that no two drivers can access the car at the same time so we need to lock the car when any driver is using is to prevent concurrent access
#include<iostream>
#include<thread>
#include<unistd.h>
#include<mutex>
#include <chrono>
using namespace std;

mutex car;

void driveCar(string driverName){
    car.lock();
    
    cout<<"**"<<driverName<<"**"<<" is driving  the car"<<endl;
    this_thread::sleep_for(chrono::seconds(2)); // delay/sleep for 2 seconds
    
    cout<<driverName<<" has completed driving  the car"<<endl;
    
    this_thread::sleep_for(chrono::seconds(2));
    cout<<driverName<<" handover keys to next driver"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    
    car.unlock();
    
}
int main(){
  // creating threads
    thread driver1(driveCar, "Raj");
    thread driver2(driveCar, "Ramesh");
    thread driver3(driveCar, "Gaurav");

  // join() is used to prevent main() from finishing earlier than all threads
    driver1.join();
    driver2.join();
    driver3.join();
    return 0;
}

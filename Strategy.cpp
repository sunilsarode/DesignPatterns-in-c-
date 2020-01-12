#include<bits/stdc++.h>

using namespace std;

class FlyBehavior{
   
public:
   virtual void fly()=0;
};

class QuackBehavior{
   
public:
   virtual void quack()=0;
};


class FlyWithWings:public FlyBehavior {

public:
 void fly() {
   cout<<"I'm flying!!"<<endl;
 }
};

class FlyNoWay:public FlyBehavior {

public:
 void fly() {
   cout<<"I can't fly"<<endl;
 }
};

class FlyRocketPowered:public FlyBehavior {

public:
 void fly() {
  /*
      if you want to write some logic to fly behavior , you write the private method , to hide the implementation details and 
       call it from this method to get the result. This is abstraction and class is encapsulating the methods using private and public access specifier , it is encapsulation.  
  */
   cout<<"I'm flying  flying with a rocket !"<<endl;
 }
};

class Quack:public QuackBehavior {

public:
 void quack() {
   cout<<"Quack"<<endl;
 }
};

class MuteQuack:public QuackBehavior {

public:
 void quack() {
   cout<<"Silence"<<endl;
 }
};

class Squeak:public QuackBehavior {

public:
 void quack() {
   cout<<"Squeak"<<endl;
 }
};


class Duck{

public:
   
 FlyBehavior* flyBehavior;
 QuackBehavior* quackBehavior;
 
 Duck() {
 }

 virtual void display()=0;

 void performFly() {
    flyBehavior->fly();
 }
 void performQuack() {
    quackBehavior->quack();
 }
 void swim() {
    cout<<"All ducks float, even decoys!"<<endl;
 }

 void setFlyBehavior(FlyBehavior* fb){
    flyBehavior=fb;
 }
 void setQuackBehavior(QuackBehavior* qb){
    quackBehavior=qb;
 }
   
};

class MallardDuck :public Duck{

public:
   MallardDuck(){
       flyBehavior=new FlyWithWings();
       quackBehavior=new Quack();
   }

   void display(){
          cout<<"I'm a real Mallard duck"<<endl;
   }

    
};

class ModelDuck :public Duck{

public:
   ModelDuck(){
       quackBehavior=new Quack();
       flyBehavior=new FlyNoWay();
   }

   void display(){
          cout<<"I'm a real model duck"<<endl;
   }

    
};

int main(){

 Duck* mallard = new MallardDuck();
 mallard->performQuack();
 mallard->performFly();

 Duck* model=new ModelDuck();
 model->performQuack();
 model->performFly();
 model->setFlyBehavior(new FlyRocketPowered());
 model->performFly();

 delete mallard;
 delete model;
 
  return 0;
}

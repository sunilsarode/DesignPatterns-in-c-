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
   cout<<"I'm flying  fl ying with a rocket !"<<endl;
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
   

 
 Duck() {
 }

 virtual void display()=0;

 void performFly( FlyBehavior* flyBehavior ) {
    flyBehavior->fly();
 }
 void performQuack(QuackBehavior* quackBehavior) {
    quackBehavior->quack();
 }
 void swim() {
    cout<<"All ducks float, even decoys!"<<endl;
 }


   
};

class MallardDuck :public Duck{

public:
   MallardDuck(){
       
   }

   void display(){
          cout<<"I'm a real Mallard duck"<<endl;
   }

    
};

class ModelDuck :public Duck{

public:
   ModelDuck(){
       
   }

   void display(){
          cout<<"I'm a real model duck"<<endl;
   }

    
};

int main(){

 Duck* mallard = new MallardDuck();
 mallard->performQuack(new Quack());
 mallard->performFly(new FlyWithWings());

 Duck* model=new ModelDuck();
 model->performQuack(new Quack());
 model->performFly(new FlyNoWay());
 model->performFly(new FlyRocketPowered());

 delete mallard;
 delete model;
 
  return 0;
}

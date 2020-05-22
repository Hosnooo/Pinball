#pragma once
#include "Drawable.h"
#include<string>

using namespace std;

class Score :public Drawable


{
private:
     
    
    Vector2D center;

public:

   Score();
   
   explicit Score(Vector2D center);  // Constructor

   void draw(Interface& interface) override;


};

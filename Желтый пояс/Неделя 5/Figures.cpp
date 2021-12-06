#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

class Figure {
public:
    Figure(const string& in_name) : name(in_name) {}
   
    virtual const string Name() const 
        { return name; };
        
    virtual float Perimeter() = 0;
    virtual float Area() = 0;
    
public:   
    const string name;
}; 

class Triangle : public Figure {
public:
    Triangle(const string& in_name, const float& in_a, const float& in_b, const float& in_c) : Figure(in_name),
          a(in_a),
          b(in_b),
          c(in_c) {}
   
    virtual float Perimeter() override
        { return a + b + c; }
        
    virtual float Area() override 
    {
        // Формула Герона
        float p = (a + b + c) / 2;
        
        return sqrt(p * ((p - a) * (p - b) * (p - c)));
    };

private:
    float a, b, c;
}; 

class Rect : public Figure {
public:
    Rect(const string& in_name, const float& in_width, const float& in_height) : Figure(in_name),
          width(in_width),
          height(in_height) {}
   
    virtual float Perimeter() override
        { return 2 * (width + height); }
        
    virtual float Area() override 
        { return width * height; };

private:
    float width, height;
};

class Circle : public Figure {
public:
    Circle(const string& in_name, const float& in_radius) : Figure(in_name),
          radius(in_radius) {}
   
    virtual float Perimeter() override
        { return 2 * pi * radius; }
        
    virtual float Area() override 
        { return pi * pow(radius, 2); };

private:
    float radius;
    const float pi = 3.14;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    
    string figure;
    is >> figure;
    
    if(figure == "RECT")
    {
        float width, height;
        is >> width >> height;
        
        return make_shared<Rect>(figure, width, height);
    }
    
    else if (figure == "TRIANGLE")
    {
        float a, b, c;
        is >> a >> b >> c;
        
        return make_shared<Triangle>(figure, a, b, c);
    }
    
    else if (figure == "CIRCLE")
    {
        float r;
        is >> r;
        
        return make_shared<Circle>(figure, r);
    }
    
    else
        return make_shared<Rect>(figure, 0, 0);
}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
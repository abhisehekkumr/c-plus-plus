#include<bits/stdc++.h>
using namespace std;

class Polynomial {
    int *degCoeff;
    int size;
    int capacity;

public:

    Polynomial(){
        capacity = 1000;
        degCoeff = new int[capacity];
        size = 0;
        for(int i = 0; i < 1000; i++)
            degCoeff[i] = 0;
    }

    Polynomial(int capacity){
        this->capacity = capacity;
        size = 0;
        degCoeff = new int[capacity];
        for(int i = 0; i < capacity; i++)
            degCoeff[i] = 0;
    }

    Polynomial(Polynomial const &poly){

        this->degCoeff = new int[poly.capacity];
        for(int i = 0; i < poly.capacity; i++)
            this->degCoeff[i] = poly.degCoeff[i];

        this->size = poly.size;
        this->capacity = poly.capacity;
    }


    void setCoefficient(int degree, int coeff){

        if(degree >= capacity){
            while(degree >= capacity){

                int *temp = new int[this->capacity*2];

                for(int i = 0; i < capacity; i++)
                    temp[i] = this->degCoeff[i];
                for(int i = capacity; i < 2*capacity; i++)
                    temp[i] = 0;

                delete [] degCoeff;
                this->degCoeff = temp;
                this->capacity *= 2;
            }
        }

        this->degCoeff[degree] = coeff;
        this->size += 1;
    }

    void print(){
         for(int i = 0; i < capacity; i++){

              if(degCoeff[i] != 0)
                    std::cout << degCoeff[i] << "x" << i << ' ';
         }
         std::cout << '\n';
    }

    Polynomial operator+(Polynomial const &Poly){
        Polynomial newPoly(max(this->capacity, Poly.capacity));
        int i = 0, j = 0,k = 0;
        while(i < this->capacity && j < Poly.capacity)
            newPoly.degCoeff[k++] = this->degCoeff[i++] + Poly.degCoeff[j++];
        while(i < this->capacity)
            newPoly.degCoeff[k++] = this->degCoeff[i++];
        while(j < Poly.capacity)
            newPoly.degCoeff[k++] = Poly.degCoeff[j++];

        newPoly.size = max(this->size, Poly.size);
        return newPoly;
    }

    Polynomial operator-(Polynomial const &Poly){
         Polynomial newPoly(max(this->capacity, Poly.capacity));
         int i  = 0, j = 0,k = 0;
        while(i < this->capacity && j < Poly.capacity)
            newPoly.degCoeff[k++] = this->degCoeff[i++] - Poly.degCoeff[j++];
        while(i < this->capacity)
            newPoly.degCoeff[k++] = this->degCoeff[i++];
        while(j < Poly.capacity)
            newPoly.degCoeff[k++] = Poly.degCoeff[j++];

        newPoly.size = max(this->size, Poly.size);
        return newPoly;
    }

    Polynomial operator=(Polynomial const &Poly){
         Polynomial newPoly(Poly.capacity);
         for(int i = 0; i < Poly.capacity; i++)
               newPoly.degCoeff[i] = Poly.degCoeff[i];
          newPoly.size = Poly.size;
          newPoly.capacity = Poly.capacity;
          return newPoly;
    }

    Polynomial operator*(Polynomial const &Poly){
          Polynomial newPoly(this->capacity* Poly.capacity);
          for(int i = 0; i < this->capacity; i++){
               for(int j = 0; j < Poly.capacity; j++)
                     newPoly.degCoeff[i + j] += this->degCoeff[i]*Poly.degCoeff[j];
          }
          newPoly.capacity = this->capacity*Poly.capacity;
          newPoly.size = this->size*Poly.size;
          return newPoly;
     }

};


int main()
{
   int count1,count2,choice;
   cin >> count1;

   int *degree1 = new int[count1];
   int *coeff1 = new int[count1];

   for(int i=0;i < count1; i++) {
       cin >> degree1[i];
   }

   for(int i=0;i < count1; i++) {
       cin >> coeff1[i];
   }

   Polynomial first;
   for(int i = 0; i < count1; i++){
       first.setCoefficient(degree1[i],coeff1[i]);
   }

   cin >> count2;

   int *degree2 = new int[count2];
   int *coeff2 = new int[count2];

   for(int i=0;i < count2; i++) {
       cin >> degree2[i];
   }

   for(int i=0;i < count2; i++) {
       cin >> coeff2[i];
   }

   Polynomial second;
   for(int i = 0; i < count2; i++){
       second.setCoefficient(degree2[i],coeff2[i]);
   }

  // first.print();
   //second.print();
   Polynomial third = first +  second;
   third.print();
   //Polynomial third = first + second;
/*
   cin >> choice;

   Polynomial result;
   switch(choice){
          // Add
       case 1:
          //result = first + second;
          //result.print();
          break;
          // Subtract
       case 2 :
          //result = first - second;
          //result.print();
          break;
          // Multiply
       case 3 :
          result = first * second;
          //result.print();
          break;

       case 4 : // Copy constructor
       {
          Polynomial third(first);
          if(third.degCoeff == first.degCoeff) {
               cout << "false" << endl;
          }
          else {
               cout << "true" << endl;
          }
          break;
       }

       case 5 : // Copy assignment operator
       {
          Polynomial fourth(first);
          if(fourth.degCoeff == first.degCoeff) {
               cout << "false" << endl;
          }
          else {
               cout << "true" << endl;
          }
          break;
       }

   }
*/
   return 0;
}


/*
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1

*/

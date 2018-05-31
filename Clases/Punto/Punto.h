
class Punto
{
      private:
              int x, y;  //Coordenadas del punto
      public:
             Punto (int x_, int y_) //constructor con parametros
             {
                   x = x_;
                   y = y_;
             }
             Punto ()   //constructor sin parametros (vacio)
             {
                   x = y = 0;
             }
             int leerX() const;
             int leerY() const;
             void fijarX(int valorX);
             void fijarY(int valorY);
};

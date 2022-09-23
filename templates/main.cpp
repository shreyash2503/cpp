#include <iostream>
using namespace std ;
template<typename T,typename V>
class Pair{
  T x;
  V y;
  public:
  void setX(T x)
  {
    this->x = x;
  }
  T getX()
  {
    return this->x;
  }
  void setY(V y)
  {
    this->y = y;
  }
  V getY()
  {
    return this->y;
  }
};
int main()
{
  Pair<int,double> p;
  p.setX(5);
  p.setY(7);
  cout<<p.getX()<<" "<<p.getY()<<endl;
  Pair<Pair<int, int>,int> a;
  a.setY(30);
  Pair<int, int> r;
  r.setX(20);r.setY(100);
  a.setX(r);

  Pair<int,int> t;
  t = a.getX();
  cout<<a.getX().getX()<<" "<<a.getX().getY()<<" "<<a.getY()<<endl;
  return 0;
}

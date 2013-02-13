
#include "proj09.pqueue.h"

int main()
{
  bool Flag;
  unsigned Len;
  int Item = 55;

  PQueue<int> A;

  PQueue<int> B( A );

  A = B;

  A.reset();

  Len = A.length();

  A.display( cout, front_to_back );
  A.display( cout, back_to_front );

  Flag = A.front( Item );
  Flag = A.back( Item );

  Flag = A.put( Item, 5 );

  Flag = A.get( Item );

  Flag = A.discard( 20 );
}


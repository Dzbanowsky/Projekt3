#include <iostream>

using namespace std;

// Typ elementów listy

struct slistEl
{
  slistEl * next;
  int data;
};

// Definicja typu obiektowego slist

class slist
{
  public:
    slistEl * head;

    slist( );  // konstruktor
    ~slist( ); // destruktor
    unsigned size( );
    void printl( );
    void push_front ( int v );
    void push_back ( int v );
    void insert_before ( slistEl * e, int v );
    void insert_after ( slistEl * e, int v );
    void pop_front( );
    void pop_back( );
    void remove ( slistEl * e );
};

// Konstruktor listy

slist::slist( )
{
  head = NULL;
}

// Destruktor listy

slist::~slist( )
{
  while( head ) pop_front( );
}

// Funkcja oblicza liczbę elementow listy

unsigned slist::size( )
{
  unsigned c = 0;
  slistEl * p = head;
  while( p )
  {
    c++;
    p = p->next;
  }
  return c;
}

// Procedura wyświetla zawartosc elementów listy

void slist::printl( )
{
  unsigned i;
  slistEl * p = head;

  cout << "Liczba elementow : " << size( ) << endl;
  for( i = 1; p; p = p->next ) cout << "Element #" << i++ << "  data = " << p->data << endl;
  cout << endl;
}

//  Dolaczanie na początek listy

void slist::push_front ( int v )
{
  slistEl * p;

  p = new slistEl;
  p->next = head;
  p->data = v;
  head = p;
}

// Dolaczanie na koniec listy

void slist::push_back ( int v )
{
  slistEl * p, * e;

  e = new slistEl;  // tworzymy nowy element
  e->next = NULL;   // inicjujemy element
  e->data = v;
  p = head;
  if( p )
  {
     while( p->next ) p = p->next;
     p->next = e;
  }
  else head = e;
}

// Procedura dolaczania przed elementem e

void slist::insert_before ( slistEl * e, int v )
{
  slistEl * p = head;

  if( p == e ) push_front ( v );
  else
  {
    while( p->next != e ) p = p->next;
    p->next = new slistEl;
    p->next->next = e;
    p->next->data = v;
  }
}

// Procedura dolaczania za elementem e

void slist::insert_after ( slistEl * e, int v )
{
  slistEl * p = new slistEl;

  p->next = e->next;
  p->data = v;
  e->next = p;
}

// Usuwanie pierwszego elementu

void slist::pop_front( )
{
  slistEl * p = head; // zapamiętujemy początek

  if( p )
  {
    head = p->next;   // nowy początek
    delete p;         // usuń element z pamięci
  }
}

// Usuwanie ostatniego elementu

void slist::pop_back( )
{
  slistEl * p = head; // zapamietujemy poczatek

  if( p )
  {
    if( p->next )
    {
      while( p->next->next ) p = p->next;
      delete p->next;
      p->next = NULL;
    }
    else
    {
      delete p;
      head = NULL;
    }
  }
}

// Usuwanie wybranego elementu

void slist::remove ( slistEl * e )
{
  slistEl * p;

  if( head == e ) pop_front( );
  else
  {
    p = head;
    while( p->next != e ) p = p->next;
    p->next = e->next;
    delete e;
  }
}

int main( )
{
  slist L;     // zawiera adres poczatku listy
  slistEl * e; // do wskazywania elementow listy
  int i;

  for( i = 1; i <= 7; i++ ) L.push_back ( i );
  L.printl( );

  // Przechodzimy do elementu o wartosci 4 w naszym przypadku czyli e

  e = L.head;

  for( i = 1; i <= 3; i++ ) e = e->next;

  //dodawanie przed
  L.insert_before ( e, i );
  //dodawanie po
  L.insert_after ( e, i );

  L.printl( );

  // Usuwamy element 4 oraz element pierwszy i ostatni

  L.remove ( e );
  L.pop_front();
  L.pop_back( );
  L.printl( );

  return 0;
}
